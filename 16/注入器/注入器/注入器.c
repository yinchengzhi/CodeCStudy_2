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
}

DWORD findprocessid(char * name) {
	HANDLE hsnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);				//ʹ�ÿ��գ�����׼��
	PROCESSENTRY32 pe32;
	pe32.dwSize = sizeof(PROCESSENTRY32);
	Process32First(hsnap, &pe32);							//����

	do {
		if (strcmp(pe32.szExeFile, name) == 0) {
			return pe32.th32ProcessID;						//�ҵ�
		}

	} while (Process32Next(hsnap, &pe32));					//û���ҵ�

	CloseHandle(hsnap);										//�ر�

	return 0;
}

//��������ģ������ģ���еĺ�����
int insertdll(char *exename, const char *dllname,const char *funname) {

	opendebug();				//����Ȩ��
	DWORD processId = findprocessid(exename);
	if (processId != 0) {
		HANDLE process = OpenProcess(PROCESS_CREATE_PROCESS | PROCESS_VM_OPERATION 
			                       | PROCESS_VM_WRITE, FALSE, processId);

	}
}


void main() {


	system("pause");
}