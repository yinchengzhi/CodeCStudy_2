#include<stdio.h>
#include<stdlib.h>

int a[5] = { 1,2,3,4,5 };			//ȫ�ֱ������ھ�̬��������򹲴���

//���� �Ӵ�����������ʱ��
//ջ������������������
//�ѣ�������ʼ��free

char *p = "123456";					//��̬����������������򹲴������������ˣ��ѵ��ڴ�Ҳ����

void run() {

	int b;
	//int a[5] = { 1,2,3,4,5 };
	//int *a = malloc(20);
	//for (int i = 0; i < 5; i++) {
	//	a[i] = i;
	//}

	printf("%p", a);

	printf("\n");
}

void main123() {
	
	run();

	printf("\n\n\n\n");

	run();

	printf("\n\n\n\n");

	run();

	printf("\n\n\n\n");

	system("pause");
}