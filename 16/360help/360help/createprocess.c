#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

//WINBASEAPI
//BOOL
//WINAPI
//CreateProcessW(
//	_In_opt_ LPCWSTR lpApplicationName,                              //Ҫִ��Ӧ�ó��������
//	_Inout_opt_ LPWSTR lpCommandLine,                                //Ҫִ�е�������
//	_In_opt_ LPSECURITY_ATTRIBUTES lpProcessAttributes,              //���̵İ�ȫ����
//	_In_opt_ LPSECURITY_ATTRIBUTES lpThreadAttributes,               //����֮���̵߳İ�ȫ����
//	_In_ BOOL bInheritHandles,                                       //���Ӳ���
//	_In_ DWORD dwCreationFlags,                                      //�����Ĳ���
//	_In_opt_ LPVOID lpEnvironment,                                   //ָ��һ���������ָ��
//	_In_opt_ LPCWSTR lpCurrentDirectory,                             //�½��̵ĵ�ǰĿ¼��·��
//	_In_ LPSTARTUPINFOW lpStartupInfo,                               //����ʱʹ�õĸ�����Ϣ
//	_Out_ LPPROCESS_INFORMATION lpProcessInformation
//);

void mainadsdasd() {

	STARTUPINFO si = { sizeof(si) };                     //����������Ϣ
	PROCESS_INFORMATION pi;                              //���������Ϣ
	si.wShowWindow = 1;
	si.dwFlags = STARTF_USESHOWWINDOW;                   //��ʾ����

	wchar_t str[100] = L"notepad";
	CreateProcessW(NULL, str, NULL, NULL, 0, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);


	getchar();
}

