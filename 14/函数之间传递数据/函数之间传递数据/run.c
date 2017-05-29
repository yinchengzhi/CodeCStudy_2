#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char str[100] = "123456";
char *p = "hello fupo";

//函数之间传递数据	不可以传递指针指向栈上的数据
char * getmem() {
	//char str[100] = "hello fang";
	//内存在栈上，自动回收
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