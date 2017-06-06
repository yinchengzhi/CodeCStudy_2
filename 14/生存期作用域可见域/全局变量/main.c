#include<stdio.h>

extern int num;		//extern 加不加都可以 声明全局变量

//全局变量默认内存全部清零
int data;
int a = 10;
//int b = a + 1;		全局变量，静态全局变量，初始化不能使用变量初始化，只能常量

void main() {			//extern可以将全局变量x,y作用域扩展到局部变量
	printf("%d", data);
	getchar();
}

int data = 20;