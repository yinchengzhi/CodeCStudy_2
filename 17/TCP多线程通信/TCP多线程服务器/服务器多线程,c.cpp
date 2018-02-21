#include<stdio.h>
#include<stdlib.h>
#include<winsock.h>
#include<process.h>

#pragma comment(lib,"ws2_32.lib")

#define port 5529
#define ip_addr "192.168.1.198"
char senbuf[256] = { 0 };
HANDLE event = NULL;					//�¼�
HANDLE mutex = NULL;

//�����߳�
DWORD WINAPI clientthread(void* p) {
	SOCKET client = (SOCKET)p;            ////��ָ������ת��
	int Ret = 0;
	//char receivebuf[256]
	while (1) {
		WaitForSingleObject(event, INFINITE);			//�ȴ��¼�

		if (strlen(senbuf) != 0) {
			Ret = send(client, senbuf, strlen(senbuf), 0);
		}
		ResetEvent(event);                //�ֶ���λ
	}
}

//�����߳�
//������

void main(void *p) {
	WSADATA WSA;                                   //�ԱȰ汾
	SOCKET client, server;                         //�ͻ���

	struct sockaddr_in localaddr, clientaddr;      //��������ַ
	int addrlength = 0;
	HANDLE hthread = NULL;                         //�߳̾��
	int Ret = 0;
	char senbuf[256] = { 0 };

	if (WSAStartup(MAKEWORD(2, 2), &WSA)) {
		puts("�汾��һ��, ͨ��ʧ��");
		system("pause");
		return;
	}
	server = socket(AF_INET, SOCK_STREAM, 0);       //ͨ��
	if (server == INVALID_SOCKET) {
		puts("����������ʧ��");
		system("pause");
		return;
	}
	localaddr.sin_family = AF_INET;
	localaddr.sin_addr.S_un.S_addr = inet_addr(ip_addr);
	localaddr.sin_port = htons(port);
	memset(localaddr.sin_zero, 0x00, 8);			//����

	Ret = bind(server, (struct sockaddr*)&localaddr, sizeof(localaddr));
	
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
		addrlength = sizeof(clientaddr);			//��ȡ����
		client = accept(server, (struct sockaddr*)&clientaddr, &addrlength);		//���ܿͻ�������
		if (client == INVALID_SOCKET) {
			puts("����ʧ��");
			system("pause");
		}
	}

}









