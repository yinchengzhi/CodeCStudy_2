#include<Windows.h>
#include<stdio.h>
#include<stdlib.h>

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

void main() {


	system("pause");
}