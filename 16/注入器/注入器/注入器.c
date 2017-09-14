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
}

DWORD findprocessid(char * name) {
	HANDLE hsnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);				//使用快照，开启准备
	PROCESSENTRY32 pe32;
	pe32.dwSize = sizeof(PROCESSENTRY32);
	Process32First(hsnap, &pe32);							//查找

	do {
		if (strcmp(pe32.szExeFile, name) == 0) {
			return pe32.th32ProcessID;						//找到
		}

	} while (Process32Next(hsnap, &pe32));					//没有找到

	CloseHandle(hsnap);										//关闭

	return 0;
}

//进程名，模块名，模块中的函数名
int insertdll(char *exename, const char *dllname,const char *funname) {

	opendebug();				//开启权限
	DWORD processId = findprocessid(exename);
	if (processId != 0) {
		HANDLE process = OpenProcess(PROCESS_CREATE_PROCESS | PROCESS_VM_OPERATION 
			                       | PROCESS_VM_WRITE, FALSE, processId);

	}
}


void main() {


	system("pause");
}