#include<stdio.h>
#include<stdlib.h>
#include<WinSock2.h>
#pragma comment(lib, "ws2_32.lib")

#define port 5529
#define ip_addr "127.0.0.1"

void main() {

	WSADATA WSA;							  //�ԱȰ汾
	SOCKET client;							  //�ͻ���
	struct sockaddr_in serveraddr;			  //��������ַ
	int addr_length = 0;
	HANDLE hthread = NULL;				      //�߳̾��
	int Ret = 0;							  //
	char senbuf[256] = { 0 };

	if (WSAStartup(MAKEWORD(2,2), &WSA) != 0) {
		puts("�汾��һ�£�ͨ��ʧ��");
		system("pause");
		return;
	}
	client = socket(AF_INET, SOCK_STREAM, 0);	//����
	if (client == INVALID_SOCKET) {

	}
}