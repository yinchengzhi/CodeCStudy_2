#include<stdio.h>
#include<Windows.h>

//typedef void(*MYFARPROC)();					//函数指针

void(*p)();										//函数指针
//_declspec(dllimport) int a;						//导入

void main() {

	//FARPROC p;

	HINSTANCE hlib = LoadLibrary("DLL.dll");
	if (hlib != NULL) {
		p = (void (*)())GetProcAddress(hlib, "go");				//获取地址，强制转换
		if (p != NULL) {
			printf("地址查找成功");
			p();
		}
		else {
			printf("地址查找失败");
		}
	}
	else {
		printf("文件加载失败");
	}

	FreeLibrary(hlib);

	system("pause");
}