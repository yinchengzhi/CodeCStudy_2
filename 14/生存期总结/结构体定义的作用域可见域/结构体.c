#include<stdio.h>
#include<stdlib.h>

////作用域就是当前到文件结束,无法提示作用域
//struct MyStruct{
//	int a;
//};

struct my {
	int a;
};

void run() {
	//函数内部的结构体定义，从定义到函数结束
	struct my{
		int a;
	};
}

void main() {

}