#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char str[100] = "123456";
char *p = "hello fupo";

//����֮�䴫������	�����Դ���ָ��ָ��ջ�ϵ�����
char * getmem() {
	//char str[100] = "hello fang";
	//�ڴ���ջ�ϣ��Զ�����
	//char *str = malloc(100);
	//strcpy(str, "hello fang");
	char *l = "hello fang";
	return l;
}

void main() {
	char *p = getmem();
	printf("%s", p);

	getchar();
}