#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include "detours.h"                                       //加载头文件

#pragma comment(lib,"detours.lib")

int(*poldsystem)(char const* _Command) = system;           //记录原来函数的地址

int newsystem(_In_opt_z_ char const* _Command) {
	char *p = strstr(_Command, "calc");                    //检索字符串里面有没有calc
	if (p == NULL) {
		poldsystem(_Command);                              //没有允许执行
	}
	else {
		//printf("禁止执行%s\n", _Command);                //禁止执行
		MessageBoxA(0, "禁止执行calc", "禁止执行calc", 0);
	}
	return 1;
}


void hook() {
	DetourRestoreAfterWith();                              //恢复状态，避免反复拦截改变地址
	DetourTransactionBegin();                              //开始拦截
	DetourUpdateThread(GetCurrentThread());                //拦截当前线程
	DetourAttach((void**)&poldsystem, newsystem);          //拦截
	DetourTransactionCommit();                             //生效
}

_declspec(dllexport) go() {

	hook();                                                //需要借助detours修改代码区

}