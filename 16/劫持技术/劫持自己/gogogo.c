#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include"detours.h"                                         //加载头文件

#pragma comment(lib,"detours.lib");

int (*poldsystem)(char const* _Command) = system;           //记录原来函数的地址

int newsystem(_In_opt_z_ char const* _Command) {
	printf("禁止执行%s",_Command);
	return 1;
}


void hook() {
	DetourRestoreAfterWith();                              //恢复状态，避免反复拦截改变地址
	DetourTransactionBegin();                              //开始拦截
	DetourUpdateThread(GetCurrentThread());                //拦截当前线程
	DetourAttach((void**)&poldsystem, newsystem);          //拦截
	DetourTransactionCommit();                             //生效
}

void main() {

	system("notepad");
	hook();

	system("notepad");                                     //禁止system打开记事本怎么办
	//需要借助detours修改代码区

	getchar();
}