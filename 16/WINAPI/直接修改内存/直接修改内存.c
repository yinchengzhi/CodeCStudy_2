#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<TlHelp32.h>		

#define exename "PlantsVsZombies.exe"

void read() {
	PROCESSENTRY32 pe32 = { 0 };													    //进程快照信息

	pe32.dwSize = sizeof(pe32);															//设置结构体大小

	HANDLE hprocess = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);					//创建快照

	BOOL bmore = Process32First(hprocess, &pe32);										//寻找，通过指针改变外部变量

	while (bmore) {
		if (strcmp(exename, pe32.szExeFile) == 0) {
			HANDLE hpro = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pe32.th32ProcessID);	//打开进程
			break;
		}
		bmore = Process32Next(hprocess, &pe32);											//编号为0的是系统进程
	}
}

void write() {

}

void main() {

	/*int *p = 0xde52580;
	printf("%d", *p);*/

	system("pause");
}