#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include "detours.h"                                        //����ͷ�ļ�

#pragma comment(lib,"detours.lib")                          //���ؿ⺯��

//WINBASEAPI
BOOL(WINAPI *poldCreateProcessW)(
	LPCWSTR lpApplicationName,                                 //Ҫִ��Ӧ�ó��������
	LPWSTR lpCommandLine,                                      //Ҫִ�е�������
	LPSECURITY_ATTRIBUTES lpProcessAttributes,                 //���̵İ�ȫ����
	LPSECURITY_ATTRIBUTES lpThreadAttributes,                  //����֮���̵߳İ�ȫ����
	BOOL bInheritHandles,                                      //���Ӳ���
	DWORD dwCreationFlags,                                     //�����Ĳ���
	LPVOID lpEnvironment,                                      //ָ��һ���������ָ��
	LPCWSTR lpCurrentDirectory,                                //�½��̵ĵ�ǰĿ¼��·��
	LPSTARTUPINFOW lpStartupInfo,                              //����ʱʹ�õĸ�����Ϣ
	LPPROCESS_INFORMATION lpProcessInformation
	) = CreateProcessW;                                        //����ָ��ԭ��������ַ

BOOL NewCreateProcessW(
	LPCWSTR lpApplicationName,                                 //Ҫִ��Ӧ�ó��������
	LPWSTR lpCommandLine,                                      //Ҫִ�е�������
	LPSECURITY_ATTRIBUTES lpProcessAttributes,                 //���̵İ�ȫ����
	LPSECURITY_ATTRIBUTES lpThreadAttributes,                  //����֮���̵߳İ�ȫ����
	BOOL bInheritHandles,                                      //���Ӳ���
	DWORD dwCreationFlags,                                     //�����Ĳ���
	LPVOID lpEnvironment,                                      //ָ��һ���������ָ��
	LPCWSTR lpCurrentDirectory,                                //�½��̵ĵ�ǰĿ¼��·��
	LPSTARTUPINFOW lpStartupInfo,                              //����ʱʹ�õĸ�����Ϣ
	LPPROCESS_INFORMATION lpProcessInformation
){
	wchar_t *p1;
	wchar_t *p2;                                                 //������360�ͽ�ֹ
	p1 = wcsstr(lpApplicationName,L"360");                      //�ȼ���խ�ַ���strstr
	p2 = wcsstr(lpCommandLine, L"360");
	if (p1 != NULL||p2!=NULL) {
		MessageBox(0, "������ͨ��", "������ͨ��", 0);
	}
	else{
		MessageBox(0, "����ͨ��", "����ͨ��", 0);
		poldCreateProcessW(lpApplicationName,                   //Ҫִ��Ӧ�ó��������
			lpCommandLine,                                      //Ҫִ�е�������
			lpProcessAttributes,                                //���̵İ�ȫ����
			lpThreadAttributes,                                 //����֮���̵߳İ�ȫ����
			bInheritHandles,                                    //���Ӳ���
			dwCreationFlags,                                    //�����Ĳ���
			lpEnvironment,                                      //ָ��һ���������ָ��
			lpCurrentDirectory,                                 //�½��̵ĵ�ǰĿ¼��·��
			lpStartupInfo,                                       //����ʱʹ�õĸ�����Ϣ
			lpProcessInformation);

		return 1;
	}
}


void hook() {
	DetourRestoreAfterWith();                                        //�ָ�״̬�����ⷴ�����ظı��ַ
	DetourTransactionBegin();                                        //��ʼ����
	DetourUpdateThread(GetCurrentThread());                          //���ص�ǰ�߳�
	DetourAttach((void**)&poldCreateProcessW, NewCreateProcessW);    //����
	DetourTransactionCommit();                                       //��Ч
}


_declspec(dllexport) go() {

	hook();                                                         //��Ҫ����detours�޸Ĵ�����

}
