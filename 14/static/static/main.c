#include<stdio.h>
#include<stdlib.h>

static void run() {				//�ı�Ϊ�ֲ�������������ǰ�ļ�������ȫ�ֺ���
	puts("huahua");
	getchar();
}

//int a;							//ȫ�ֱ��������ļ�ʹ��
static int a = 35;					//���������ⲿ���������÷�Χ��ǰ�ļ�
//��̬ȫ�ֱ��������÷�Χ����ǰ�ļ�

void main() {
	//run();

	printf("%d", a);

	getchar();
}