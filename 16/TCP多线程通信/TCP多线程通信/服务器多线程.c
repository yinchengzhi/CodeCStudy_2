#define _CRT_SECURE_NO_WARNINGS
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<WinSock2.h>
#pragma comment(lib, "ws2_32.lib")

#define port 5529
#define ip_addr "127.0.0.1"

//�����߳�
DWORD WINAPI clientthread(void *p) {
	SOCKET client = (SOCKET)p;					//����ָ������ת��
	int Ret = 0;
	char receivebuf[256];
	while (1) {
		memset(receivebuf, 0, 256);					//����
		Ret = recv(client, receivebuf, 256, 0);		//��ȡ
		if (Ret == SOCKET_ERROR) {
			puts("�ͻ���send ʧ��");
			break;
		}
		printf("\n�յ�%s", receivebuf);
	}
	return 0;
}

//������

void main() {
	WSADATA WSA;							  //�ԱȰ汾
	SOCKET client, server;					  //�ͻ���
	struct sockaddr_in serveraddr;			  //��������ַ
	int addr_length = 0;
	HANDLE hthread = NULL;				      //�߳̾��
	int Ret = 0;							  //
	char senbuf[256] = { 0 };

	if (WSAStartup(MAKEWORD(2, 2), &WSA) != 0) {
		puts("�汾��һ�£�ͨ��ʧ��");
		system("pause");
		return;
	}
}