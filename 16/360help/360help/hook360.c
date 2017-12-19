#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include "detours.h"                                        //加载头文件

#pragma comment(lib,"detours.lib")                          //加载库函数

//WINBASEAPI
BOOL(WINAPI *poldCreateProcessW)(
	LPCWSTR lpApplicationName,                                 //要执行应用程序的名字
	LPWSTR lpCommandLine,                                      //要执行的命令行
	LPSECURITY_ATTRIBUTES lpProcessAttributes,                 //进程的安全特性
	LPSECURITY_ATTRIBUTES lpThreadAttributes,                  //进程之主线程的安全特性
	BOOL bInheritHandles,                                      //附加参数
	DWORD dwCreationFlags,                                     //创建的参数
	LPVOID lpEnvironment,                                      //指向一个环境块的指针
	LPCWSTR lpCurrentDirectory,                                //新进程的当前目录的路径
	LPSTARTUPINFOW lpStartupInfo,                              //进程时使用的附加信息
	LPPROCESS_INFORMATION lpProcessInformation
	) = CreateProcessW;                                        //函数指针原来函数地址

BOOL NewCreateProcessW(
	LPCWSTR lpApplicationName,                                 //要执行应用程序的名字
	LPWSTR lpCommandLine,                                      //要执行的命令行
	LPSECURITY_ATTRIBUTES lpProcessAttributes,                 //进程的安全特性
	LPSECURITY_ATTRIBUTES lpThreadAttributes,                  //进程之主线程的安全特性
	BOOL bInheritHandles,                                      //附加参数
	DWORD dwCreationFlags,                                     //创建的参数
	LPVOID lpEnvironment,                                      //指向一个环境块的指针
	LPCWSTR lpCurrentDirectory,                                //新进程的当前目录的路径
	LPSTARTUPINFOW lpStartupInfo,                              //进程时使用的附加信息
	LPPROCESS_INFORMATION lpProcessInformation
){
	wchar_t *p1;
	wchar_t *p2;                                                 //检索到360就禁止
	p1 = wcsstr(lpApplicationName,L"360");                      //等价于窄字符的strstr
	p2 = wcsstr(lpCommandLine, L"360");
	if (p1 != NULL||p2!=NULL) {
		MessageBox(0, "不允许通过", "不允许通过", 0);
	}
	else{
		MessageBox(0, "允许通过", "允许通过", 0);
		poldCreateProcessW(lpApplicationName,                   //要执行应用程序的名字
			lpCommandLine,                                      //要执行的命令行
			lpProcessAttributes,                                //进程的安全特性
			lpThreadAttributes,                                 //进程之主线程的安全特性
			bInheritHandles,                                    //附加参数
			dwCreationFlags,                                    //创建的参数
			lpEnvironment,                                      //指向一个环境块的指针
			lpCurrentDirectory,                                 //新进程的当前目录的路径
			lpStartupInfo,                                       //进程时使用的附加信息
			lpProcessInformation);

		return 1;
	}
}


void hook() {
	DetourRestoreAfterWith();                                        //恢复状态，避免反复拦截改变地址
	DetourTransactionBegin();                                        //开始拦截
	DetourUpdateThread(GetCurrentThread());                          //拦截当前线程
	DetourAttach((void**)&poldCreateProcessW, NewCreateProcessW);    //拦截
	DetourTransactionCommit();                                       //生效
}


_declspec(dllexport) go() {

	hook();                                                         //需要借助detours修改代码区

}
