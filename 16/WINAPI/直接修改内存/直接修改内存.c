#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<TlHelp32.h>		

#define exename "PlantsVsZombies.exe"

void read() {
	PROCESSENTRY32 pe32 = { 0 };													    //���̿�����Ϣ

	pe32.dwSize = sizeof(pe32);															//���ýṹ���С

	HANDLE hprocess = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);					//��������

	BOOL bmore = Process32First(hprocess, &pe32);										//Ѱ�ң�ͨ��ָ��ı��ⲿ����

	while (bmore) {
		if (strcmp(exename, pe32.szExeFile) == 0) {
			HANDLE hpro = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pe32.th32ProcessID);	//�򿪽���
			break;
		}
		bmore = Process32Next(hprocess, &pe32);											//���Ϊ0����ϵͳ����
	}
}

void write() {

}

void main() {

	/*int *p = 0xde52580;
	printf("%d", *p);*/

	system("pause");
}