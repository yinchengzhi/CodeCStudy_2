#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int a = 10;;

void main() {

	int a = 3;
	printf("%d,%d", a, ::a);				//::����ȫ�ֱ�����C++֧��

	char b;
	char *str = &b;
	strcpy(str, "Hello");
	printf(str);

	getchar();

}