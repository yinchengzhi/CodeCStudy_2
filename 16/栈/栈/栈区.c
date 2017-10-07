#include<stdio.h>
#include<stdlib.h>


void run() {
	int a[5] = { 1,2,3,4,5 };			//栈区

	printf("%p", a);

	printf("\n");
}


void main1() {

	run();

	printf("\n\n");
	//栈有一个最大的特点，可以进行自动回收

	printf("\n\n");

	getchar();
}

void main2() {

	//栈可以大量消耗CPU

	while (-1) {
		double db[1024 * 200];
	}



	getchar();
}

void main() {
	int a1 = 10;				//
	int a2 = 20;				//都是栈上的变量

	printf("%p,%p", &a1, &a2);


	system("pause");
}