#include<stdio.h>
#include<stdlib.h>


//堆手动释放内存，栈自动释放内存

void main1() {

	//数组,在栈上分配数组，不需要管理回收，C99的最新语法
	int *p = (int[]) { [5] = 8 };	//[5]=8 第六个元素为8，没有指定的都是0 
	// int[] 代表int[]数组
	int *px = malloc(50);

	for (int i = 0; i < 6; i++) {
		printf("%d,%p\n", p[i], p + i);
	}

	getchar();
}


void run() {
	int *p = (int[]) { [3] = 8 };	//现在只有4，栈区
	int *pm = malloc(40);			//堆区
	for (int i = 0; i < 10; i++) {
		pm[i] = i;					//初始化堆区
	}

	printf("%p,%p\n", p, pm);

	printf("\n");
}


void main2() {

	run();


	printf("\n\n\n");

	getchar();
}

