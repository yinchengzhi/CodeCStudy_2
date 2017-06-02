#include<stdio.h>
#include<stdlib.h>

int a[5] = { 1,2,3,4,5 };			//全局变量，在静态区，与程序共存亡

//变量 从创建到死亡的时间
//栈，创建，到函数结束
//堆，创建开始到free

char *p = "123456";					//静态区，代码区，与程序共存亡，程序亡了，堆的内存也挂了

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