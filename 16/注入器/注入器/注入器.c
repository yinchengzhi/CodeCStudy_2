#include<Windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<TlHelp32.h>


BOOL opendebug() {
	HANDLE htoken;					//令牌
	BOOL fok = FALSE;

	//打开进程令牌，提升调试权限
	if (OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY | TOKEN_ADJUST_PRIVILEGES, &htoken)) {
		TOKEN_PRIVILEGES tp;
		tp.PrivilegeCount = 1;					//设置默认权限
		if (!LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &tp.Privileges[0].Luid)) {		//遍历权限

		}
		tp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
		if (!AdjustTokenPrivileges(htoken, FALSE, &tp, sizeof(tp), NULL, NULL)) {

		}
		else {
			fok = TRUE;
		}
		CloseHandle(htoken);							//关闭令牌
	}
	return fok;
}

DWORD findprocessid(char * name) {
	HANDLE hsnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);				//使用快照，开启准备
	PROCESSENTRY32 pe32;
	pe32.dwSize = sizeof(PROCESSENTRY32);
	Process32First(hsnap, &pe32);							//查找

	do {
		if (_strcmpi(pe32.szExeFile, name) == 0) {
			puts("find it");
			return pe32.th32ProcessID;						//找到
		}

	} while (Process32Next(hsnap, &pe32));					//没有找到

	CloseHandle(hsnap);										//关闭

	return 0;
}




//loadlibrary

void dllinject(HANDLE process, const char *dllname, const char *funname) {
	
	unsigned int off_set = 0;
	void(*pfun)() = NULL;											//函数
	HANDLE hthread = NULL;
	HMODULE dllit = NULL;
	
	dllit = LoadLibrary(dllname);									//调用dll,dllit就是首地址
	if (dllit == NULL) {
		printf("载入失败");
	}
	else {
		printf("载入ok");
		pfun = (void(*)()) GetProcAddress(dllit, funname);			//获取地址

		if (pfun == NULL) {
			printf("获取失败");
		}
		else {
			off_set = (char*)pfun - (char*)dllit;					//计算偏移位置
			printf("获取成功, offset=%u", off_set);
			//pfun();												//调用策划死
			FreeLibrary(dllit);									    //释放
		}
	}
	
	int dllnamelength = strlen(dllname) + 1;						 //获取字符串长度
	LPVOID paddr = VirtualAllocEx(process, NULL, dllnamelength, MEM_COMMIT, PAGE_READWRITE);		//在别人的进程分配内存
	if (paddr == NULL) {
		printf("内存分配失败");
	}
	else {
		WriteProcessMemory(process, paddr, (void *)dllname, dllnamelength, 0);
		printf("\n进程内存分配成功，并且拷贝成功");

		// xp
	
		/*
		hthread = CreateRemoteThread(process, NULL, 0, (LPTHREAD_START_ROUTINE)LoadLibraryA, paddr, 0, 0);	//不稳定，开启线程win32 
		printf("\n%ld", GetLastError());

		if (hthread == NULL) {
			puts("\n线程失败");
		}
		WaitForSingleObject(hthread, INFINITE);
		printf("\n远程线程成功开启");
		*/
	
		
		HMODULE hmode = GetModuleHandleA("Kernel32.dll");			//开启内核
		LPTHREAD_START_ROUTINE funstart = (LPTHREAD_START_ROUTINE)GetProcAddress(hmode, "LoadLibaryA");		//获取地址
		hthread = CreateRemoteThread(process, NULL, 0, funstart, paddr, 0, 0);		//开启线程
		printf("\n%ld", GetLastError());
		//只能调用开始的那个函数
		if (hthread == NULL) {
			puts("\n线程失败");
		}
		WaitForSingleObject(hthread, INFINITE);
		printf("\n远程线程结束");

		DWORD dllmodule = 0;
		GetExitCodeThread(hthread, &dllmodule);						//获取地址,退出
		void(*pfunX)() = NULL;										//函数指针
		pfunX = (void(*)())(dllmodule + off_set);					//获取地址

		hthread = CreateRemoteThread(process, NULL, 0, (LPTHREAD_START_ROUTINE)pfunX, paddr, 0, 0);		//开启线程
		printf("\n%ld", GetLastError());
		//只能调用开始的那个函数
		if (hthread == NULL) {
			puts("\n线程失败");
		}
		WaitForSingleObject(hthread, INFINITE);
		printf("\n远程线程结束");

		VirtualFreeEx(process, paddr, dllnamelength, MEM_DECOMMIT);		//释放内存
	}
}


//进程名，模块名，模块中的函数名
int insertdll(char *exename, const char *dllname,const char *funname) {

	opendebug();				//开启权限
	DWORD processId = findprocessid(exename);
	if (processId != 0) {
		HANDLE process = OpenProcess(PROCESS_ALL_ACCESS|PROCESS_CREATE_PROCESS | PROCESS_VM_OPERATION 
			                       | PROCESS_VM_WRITE, FALSE, processId);
		if (process != NULL) {
			dllinject(process, dllname, funname);
		}
		CloseHandle(process);
	}
	else {
		printf("进程查找失败");
	}
	return 0;
}


void main() {
	char *dllname = "D:\\GitHub_Respository\\CodeCStudy_2\\16\\注入器\\Debug\\A.dll";

	insertdll("explorer.exe", dllname, "go");

	system("pause");
}