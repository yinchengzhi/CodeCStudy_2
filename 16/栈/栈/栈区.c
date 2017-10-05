#include<stdio.h>
#include<stdlib.h>


void run() {
	int a[5] = { 1,2,3,4,5 };			//栈区
	printf("%p", a);

	printf("\n");
}


void main() {

	run();
	printf("\n\n");
	//栈有一个最大的特点，可以进行自动回收


	getchar();
}