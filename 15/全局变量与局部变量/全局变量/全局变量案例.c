#include<stdio.h>
#include<stdlib.h>

int RMB = 100;
//ȫ�ֱ����ú���ͨ�Ų�������������return

void cun(int num) {
	RMB += num;
}

void qu(int num) {
	RMB -= num;
}

void main() {

	printf("��ʱRMB=%d\n", RMB);
	cun(200);
	printf("��ʱRMB=%d\n", RMB);
	qu(30);
	printf("��ʱRMB=%d\n", RMB);


	system("pause");
}