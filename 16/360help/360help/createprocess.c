#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

//WINBASEAPI
//BOOL
//WINAPI
//CreateProcessW(
//	_In_opt_ LPCWSTR lpApplicationName,                              //要执行应用程序的名字
//	_Inout_opt_ LPWSTR lpCommandLine,                                //要执行的命令行
//	_In_opt_ LPSECURITY_ATTRIBUTES lpProcessAttributes,              //进程的安全特性
//	_In_opt_ LPSECURITY_ATTRIBUTES lpThreadAttributes,               //进程之主线程的安全特性
//	_In_ BOOL bInheritHandles,                                       //附加参数
//	_In_ DWORD dwCreationFlags,                                      //创建的参数
//	_In_opt_ LPVOID lpEnvironment,                                   //指向一个环境块的指针
//	_In_opt_ LPCWSTR lpCurrentDirectory,                             //新进程的当前目录的路径
//	_In_ LPSTARTUPINFOW lpStartupInfo,                               //进程时使用的附加信息
//	_Out_ LPPROCESS_INFORMATION lpProcessInformation
//);

void mainadsdasd() {

	STARTUPINFO si = { sizeof(si) };                     //保存启动信息
	PROCESS_INFORMATION pi;                              //保存进程信息
	si.wShowWindow = 1;
	si.dwFlags = STARTF_USESHOWWINDOW;                   //显示窗口

	wchar_t str[100] = L"notepad";
	CreateProcessW(NULL, str, NULL, NULL, 0, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);


	getchar();
}

