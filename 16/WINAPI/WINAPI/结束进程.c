#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<TlHelp32.h>																	//快照

void showall() {
	PROCESSENTRY32 pe32 = { 0 };													    //进程快照信息
	
	pe32.dwSize = sizeof(pe32);															//设置结构体大小

	HANDLE hprocess = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);					//创建快照

	BOOL bmore = Process32First(hprocess, &pe32);										//寻找，通过指针改变外部变量

	while (bmore) {
		printf("\n%s,%d", pe32.szExeFile, pe32.th32ParentProcessID);
		//bmore = Process32First(hprocess, &pe32);										//查找第一个
		bmore = Process32Next(hprocess, &pe32);											//编号为0的是系统进程
	}
}

void close(char *name) {
	PROCESSENTRY32 pe32 = { 0 };													    //进程快照信息

	pe32.dwSize = sizeof(pe32);															//设置结构体大小

	HANDLE hprocess = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);					//创建快照

	BOOL bmore = Process32First(hprocess, &pe32);										//寻找，通过指针改变外部变量

	while (bmore) {
		//printf("\n%s,%d", pe32.szExeFile, pe32.th32ParentProcessID);
		//bmore = Process32First(hprocess, &pe32);										//查找第一个
		if (strcmp(name, pe32.szExeFile) == 0) {
			puts("find");
			HANDLE hpro = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pe32.th32ProcessID);	//打开进程
			TerminateProcess(hpro, 0);
		}
		bmore = Process32Next(hprocess, &pe32);											//编号为0的是系统进程
	}
}


void closeById(unsigned long id) {
	PROCESSENTRY32 pe32 = { 0 };													    //进程快照信息

	pe32.dwSize = sizeof(pe32);															//设置结构体大小

	HANDLE hprocess = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);					//创建快照

	BOOL bmore = Process32First(hprocess, &pe32);										//寻找，通过指针改变外部变量

	while (bmore) {
		//printf("\n%s,%d", pe32.szExeFile, pe32.th32ParentProcessID);
		//bmore = Process32First(hprocess, &pe32);										//查找第一个
		if (id == pe32.th32ProcessID) {
			puts("find");
			HANDLE hpro = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pe32.th32ProcessID);	//打开进程
			TerminateProcess(hpro, 0);
		}
		bmore = Process32Next(hprocess, &pe32);											//编号为0的是系统进程
	}
}



void main() {

	//close("FeiQ.exe");

	closeById(3056);

	system("pause");

}