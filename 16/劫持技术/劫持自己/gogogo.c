#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include"detours.h"                                         //����ͷ�ļ�

#pragma comment(lib,"detours.lib");

int (*poldsystem)(char const* _Command) = system;           //��¼ԭ�������ĵ�ַ

int newsystem(_In_opt_z_ char const* _Command) {
	printf("��ִֹ��%s",_Command);
	return 1;
}


void hook() {
	DetourRestoreAfterWith();                              //�ָ�״̬�����ⷴ�����ظı��ַ
	DetourTransactionBegin();                              //��ʼ����
	DetourUpdateThread(GetCurrentThread());                //���ص�ǰ�߳�
	DetourAttach((void**)&poldsystem, newsystem);          //����
	DetourTransactionCommit();                             //��Ч
}

void main() {

	system("notepad");
	hook();

	system("notepad");                                     //��ֹsystem�򿪼��±���ô��
	//��Ҫ����detours�޸Ĵ�����

	getchar();
}