#include<Windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<TlHelp32.h>


BOOL opendebug() {
	HANDLE htoken;					//����
	BOOL fok = FALSE;

	//�򿪽������ƣ���������Ȩ��
	if (OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY | TOKEN_ADJUST_PRIVILEGES, &htoken)) {
		TOKEN_PRIVILEGES tp;
		tp.PrivilegeCount = 1;					//����Ĭ��Ȩ��
		if (!LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &tp.Privileges[0].Luid)) {		//����Ȩ��

		}
		tp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
		if (!AdjustTokenPrivileges(htoken, FALSE, &tp, sizeof(tp), NULL, NULL)) {

		}
		else {
			fok = TRUE;
		}
		CloseHandle(htoken);							//�ر�����
	}
	return fok;
}

DWORD findprocessid(char * name) {
	HANDLE hsnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);				//ʹ�ÿ��գ�����׼��
	PROCESSENTRY32 pe32;
	pe32.dwSize = sizeof(PROCESSENTRY32);
	Process32First(hsnap, &pe32);							//����

	do {
		if (_strcmpi(pe32.szExeFile, name) == 0) {
			puts("find it");
			return pe32.th32ProcessID;						//�ҵ�
		}

	} while (Process32Next(hsnap, &pe32));					//û���ҵ�

	CloseHandle(hsnap);										//�ر�

	return 0;
}




//loadlibrary

void dllinject(HANDLE process, const char *dllname, const char *funname) {
	
	unsigned int off_set = 0;
	void(*pfun)() = NULL;											//����
	HANDLE hthread = NULL;
	HMODULE dllit = NULL;
	
	dllit = LoadLibrary(dllname);									//����dll,dllit�����׵�ַ
	if (dllit == NULL) {
		printf("����ʧ��");
	}
	else {
		printf("����ok");
		pfun = (void(*)()) GetProcAddress(dllit, funname);			//��ȡ��ַ

		if (pfun == NULL) {
			printf("��ȡʧ��");
		}
		else {
			off_set = (char*)pfun - (char*)dllit;					//����ƫ��λ��
			printf("��ȡ�ɹ�, offset=%u", off_set);
			//pfun();												//���ò߻���
			FreeLibrary(dllit);									    //�ͷ�
		}
	}
	
	int dllnamelength = strlen(dllname) + 1;						 //��ȡ�ַ�������
	LPVOID paddr = VirtualAllocEx(process, NULL, dllnamelength, MEM_COMMIT, PAGE_READWRITE);		//�ڱ��˵Ľ��̷����ڴ�
	if (paddr == NULL) {
		printf("�ڴ����ʧ��");
	}
	else {
		WriteProcessMemory(process, paddr, (void *)dllname, dllnamelength, 0);
		printf("\n�����ڴ����ɹ������ҿ����ɹ�");

		// xp
	
		/*
		hthread = CreateRemoteThread(process, NULL, 0, (LPTHREAD_START_ROUTINE)LoadLibraryA, paddr, 0, 0);	//���ȶ��������߳�win32 
		printf("\n%ld", GetLastError());

		if (hthread == NULL) {
			puts("\n�߳�ʧ��");
		}
		WaitForSingleObject(hthread, INFINITE);
		printf("\nԶ���̳߳ɹ�����");
		*/
	
		
		HMODULE hmode = GetModuleHandleA("Kernel32.dll");			//�����ں�
		LPTHREAD_START_ROUTINE funstart = (LPTHREAD_START_ROUTINE)GetProcAddress(hmode, "LoadLibaryA");		//��ȡ��ַ
		hthread = CreateRemoteThread(process, NULL, 0, funstart, paddr, 0, 0);		//�����߳�
		printf("\n%ld", GetLastError());
		//ֻ�ܵ��ÿ�ʼ���Ǹ�����
		if (hthread == NULL) {
			puts("\n�߳�ʧ��");
		}
		WaitForSingleObject(hthread, INFINITE);
		printf("\nԶ���߳̽���");

		DWORD dllmodule = 0;
		GetExitCodeThread(hthread, &dllmodule);						//��ȡ��ַ,�˳�
		void(*pfunX)() = NULL;										//����ָ��
		pfunX = (void(*)())(dllmodule + off_set);					//��ȡ��ַ

		hthread = CreateRemoteThread(process, NULL, 0, (LPTHREAD_START_ROUTINE)pfunX, paddr, 0, 0);		//�����߳�
		printf("\n%ld", GetLastError());
		//ֻ�ܵ��ÿ�ʼ���Ǹ�����
		if (hthread == NULL) {
			puts("\n�߳�ʧ��");
		}
		WaitForSingleObject(hthread, INFINITE);
		printf("\nԶ���߳̽���");

		VirtualFreeEx(process, paddr, dllnamelength, MEM_DECOMMIT);		//�ͷ��ڴ�
	}
}


//��������ģ������ģ���еĺ�����
int insertdll(char *exename, const char *dllname,const char *funname) {

	opendebug();				//����Ȩ��
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
		printf("���̲���ʧ��");
	}
	return 0;
}


void main() {
	char *dllname = "D:\\GitHub_Respository\\CodeCStudy_2\\16\\ע����\\Debug\\A.dll";

	insertdll("explorer.exe", dllname, "go");

	system("pause");
}