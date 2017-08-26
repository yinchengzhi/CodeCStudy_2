#include<stdio.h>
#include<stdlib.h>

int RMB = 100;
//全局变量让函数通信不依赖参数还有return

void cun(int num) {
	RMB += num;
}

void qu(int num) {
	RMB -= num;
}

void main() {

	printf("此时RMB=%d\n", RMB);
	cun(200);
	printf("此时RMB=%d\n", RMB);
	qu(30);
	printf("此时RMB=%d\n", RMB);


	system("pause");
}