#include<stdio.h>
#include<stdlib.h>


//���ֶ��ͷ��ڴ棬ջ�Զ��ͷ��ڴ�

void main1() {

	//����,��ջ�Ϸ������飬����Ҫ������գ�C99�������﷨
	int *p = (int[]) { [5] = 8 };	//[5]=8 ������Ԫ��Ϊ8��û��ָ���Ķ���0 
	// int[] ����int[]����
	int *px = malloc(50);

	for (int i = 0; i < 6; i++) {
		printf("%d,%p\n", p[i], p + i);
	}

	getchar();
}


void run() {
	int *p = (int[]) { [3] = 8 };	//����ֻ��4��ջ��
	int *pm = malloc(40);			//����
	for (int i = 0; i < 10; i++) {
		pm[i] = i;					//��ʼ������
	}

	printf("%p,%p\n", p, pm);

	printf("\n");
}


void main2() {

	run();


	printf("\n\n\n");

	getchar();
}

