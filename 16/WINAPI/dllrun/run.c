#include<stdio.h>
#include<Windows.h>

void(*p)();					//����ָ��

void main() {

	HINSTANCE hlib = LoadLibrary("DLL.dll");
	if (hlib != NULL) {
		p = (void(*))GetProcAddress("hlib", "go");				//��ȡ��ַ��ǿ��ת��
		if (p != NULL) {

		}
	}


	system("pause");
}