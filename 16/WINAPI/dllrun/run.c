#include<stdio.h>
#include<Windows.h>

//typedef void(*MYFARPROC)();					//����ָ��

void(*p)();										//����ָ��
//_declspec(dllimport) int a;						//����

void main() {

	//FARPROC p;

	HINSTANCE hlib = LoadLibrary("DLL.dll");
	if (hlib != NULL) {
		p = (void (*)())GetProcAddress(hlib, "go");				//��ȡ��ַ��ǿ��ת��
		if (p != NULL) {
			printf("��ַ���ҳɹ�");
			p();
		}
		else {
			printf("��ַ����ʧ��");
		}
	}
	else {
		printf("�ļ�����ʧ��");
	}

	FreeLibrary(hlib);

	system("pause");
}