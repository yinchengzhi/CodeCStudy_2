#include<stdio.h>
#include<Windows.h>

void(*p)();					//函数指针

void main() {

	HINSTANCE hlib = LoadLibrary("DLL.dll");
	if (hlib != NULL) {
		p = (void(*))GetProcAddress("hlib", "go");				//获取地址，强制转换
		if (p != NULL) {

		}
	}


	system("pause");
}