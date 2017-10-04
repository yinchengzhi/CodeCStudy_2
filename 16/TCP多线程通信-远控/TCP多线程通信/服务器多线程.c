#define _CRT_SECURE_NO_WARNINGS
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<WinSock2.h>
#include<process.h>
#pragma comment(lib, "ws2_32.lib")

#define port 5529
#define ip_addr "192.168.191.1"

char sendbuf[256] = { 0 };
HANDLE event;			//�¼�
HANDLE mutex = NULL;

//�����߳�
DWORD WINAPI clientthread(void *p) {
	SOCKET client = (SOCKET)p;					              //����ָ������ת��
	int Ret = 0;
	char receivebuf[256];
	while (1) {
		//memset(receivebuf, 0, 256);					          //����
		//Ret = recv(client, receivebuf, 256, 0);		          //��ȡ
		//if (Ret == SOCKET_ERROR) {
		//	puts("�ͻ���send ʧ��");
		//	break;
		//}
		//printf("\n�յ�%s", receivebuf);
		WaitForSingleObject(event, INFINITE);
		if (strlen(sendbuf) != 0) {
			Ret = send(client, sendbuf, strlen(sendbuf), 0);		          //��ȡ
		}

		ResetEvent(event);										//�ֶ���λ
	}
	return 0;
}

//������

void mains(void *p) {
	WSADATA WSA;							                 //�ԱȰ汾
	SOCKET client, server;					                 //�ͻ���
	struct sockaddr_in localeaddr,clientaddr;                //��������ַ
	int addrlength = 0;
	HANDLE hthread = NULL;				                     //�߳̾��
	int Ret = 0;							                 //
	char senbuf[256] = { 0 };

	if (WSAStartup(MAKEWORD(2, 2), &WSA) != 0) {
		puts("�汾��һ�£�ͨ��ʧ��");
		system("pause");
		return;
	}

	server = socket(AF_INET, SOCK_STREAM, 0);		         //ͨ��
	if (server==INVALID_SOCKET) {
		puts("����������ʧ��");
		system("pause");
		return;
	}
	localeaddr.sin_family = AF_INET;
	localeaddr.sin_addr.S_un.S_addr = inet_addr(ip_addr);
	localeaddr.sin_port = htons(port);

	memset(localeaddr.sin_zero, 0x00, 8);			        //����
	Ret = bind(server, (struct sockaddr*)&localeaddr, sizeof(localeaddr));	//��
	if (Ret != 0) {
		puts("��ʧ��");
		system("pause");
		return;
	}
	Ret = listen(server, 5);
	if (Ret != 0) {
		puts("����ʧ��");
		system("pause");
		return;
	}
	puts("����������\n");
	while (1) {
		addrlength = sizeof(clientaddr);						                   //��ȡ����
		client = accept(server, (struct sockaddr*)&clientaddr, &addrlength);		//���տͻ�������
		if (client == INVALID_SOCKET) {
			puts("����ʧ��");
			system("pause");
			return;
		}
		printf("\n�ͻ�������%s %d", inet_ntoa(clientaddr.sin_addr),clientaddr.sin_port);

		hthread = CreateThread(NULL, 0, clientthread, (void *)client, 0, NULL);

	}

	closesocket(server);
	closesocket(client);
	WSACleanup();
}


void main() {

	event = CreateEvent(NULL, TRUE, FALSE, NULL);
	_beginthread(mains, 0, NULL);
	while (1) {
		scanf("%s", sendbuf);
		SetEvent(event);

	}

	system("pause");
}

