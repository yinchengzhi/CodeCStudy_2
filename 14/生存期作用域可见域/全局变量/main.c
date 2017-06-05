#include<stdio.h>

extern int num;		//extern 加不加都可以 声明全局变量

//全局变量默认内存全部清零
int data;

void main() {			//extern可以将全局变量x,y作用域扩展到局部变量
	printf("%d", data);
	getchar();
}

int data = 20;