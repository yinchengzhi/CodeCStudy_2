#include<Windows.h>
#include<stdio.h>
#include<stdlib.h>

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

void main() {


	system("pause");
}