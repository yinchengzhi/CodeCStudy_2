#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<TlHelp32.h>																	//����

void showall() {
	PROCESSENTRY32 pe32 = { 0 };													    //���̿�����Ϣ
	
	pe32.dwSize = sizeof(pe32);															//���ýṹ���С

	HANDLE hprocess = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);					//��������

	BOOL bmore = Process32First(hprocess, &pe32);										//Ѱ�ң�ͨ��ָ��ı��ⲿ����

	while (bmore) {
		printf("\n%s,%d", pe32.szExeFile, pe32.th32ParentProcessID);
		//bmore = Process32First(hprocess, &pe32);										//���ҵ�һ��
		bmore = Process32Next(hprocess, &pe32);											//���Ϊ0����ϵͳ����
	}
}

void close(char *name) {
	PROCESSENTRY32 pe32 = { 0 };													    //���̿�����Ϣ

	pe32.dwSize = sizeof(pe32);															//���ýṹ���С

	HANDLE hprocess = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);					//��������

	BOOL bmore = Process32First(hprocess, &pe32);										//Ѱ�ң�ͨ��ָ��ı��ⲿ����

	while (bmore) {
		//printf("\n%s,%d", pe32.szExeFile, pe32.th32ParentProcessID);
		//bmore = Process32First(hprocess, &pe32);										//���ҵ�һ��
		if (strcmp(name, pe32.szExeFile) == 0) {
			puts("find");
			HANDLE hpro = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pe32.th32ProcessID);	//�򿪽���
			TerminateProcess(hpro, 0);
		}
		bmore = Process32Next(hprocess, &pe32);											//���Ϊ0����ϵͳ����
	}
}


void closeById(unsigned long id) {
	PROCESSENTRY32 pe32 = { 0 };													    //���̿�����Ϣ

	pe32.dwSize = sizeof(pe32);															//���ýṹ���С

	HANDLE hprocess = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);					//��������

	BOOL bmore = Process32First(hprocess, &pe32);										//Ѱ�ң�ͨ��ָ��ı��ⲿ����

	while (bmore) {
		//printf("\n%s,%d", pe32.szExeFile, pe32.th32ParentProcessID);
		//bmore = Process32First(hprocess, &pe32);										//���ҵ�һ��
		if (id == pe32.th32ProcessID) {
			puts("find");
			HANDLE hpro = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pe32.th32ProcessID);	//�򿪽���
			TerminateProcess(hpro, 0);
		}
		bmore = Process32Next(hprocess, &pe32);											//���Ϊ0����ϵͳ����
	}
}



void main() {

	//close("FeiQ.exe");

	closeById(3056);

	system("pause");

}