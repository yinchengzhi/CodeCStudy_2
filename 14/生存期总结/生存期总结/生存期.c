#include<stdio.h>
#include<stdlib.h>

//extern 是一个可有可无的角色
extern int a;
extern int a = 10;

static void run() {			//限定本文件

}

static void run();			//限定本文件
extern void run1();			//声明

void main() {

	run1();
}

extern void run1() {		//extern 可写可不写，默认函数extern属性,全局调用

}