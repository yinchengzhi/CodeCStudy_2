#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include "detours.h"                                       //����ͷ�ļ�

#pragma comment(lib,"detours.lib")

int(*poldsystem)(char const* _Command) = system;           //��¼ԭ�������ĵ�ַ

int newsystem(_In_opt_z_ char const* _Command) {
	char *p = strstr(_Command, "calc");                    //�����ַ���������û��calc
	if (p == NULL) {
		poldsystem(_Command);                              //û������ִ��
	}
	else {
		//printf("��ִֹ��%s\n", _Command);                //��ִֹ��
		MessageBoxA(0, "��ִֹ��calc", "��ִֹ��calc", 0);
	}
	return 1;
}


void hook() {
	DetourRestoreAfterWith();                              //�ָ�״̬�����ⷴ�����ظı��ַ
	DetourTransactionBegin();                              //��ʼ����
	DetourUpdateThread(GetCurrentThread());                //���ص�ǰ�߳�
	DetourAttach((void**)&poldsystem, newsystem);          //����
	DetourTransactionCommit();                             //��Ч
}

_declspec(dllexport) go() {

	hook();                                                //��Ҫ����detours�޸Ĵ�����

}