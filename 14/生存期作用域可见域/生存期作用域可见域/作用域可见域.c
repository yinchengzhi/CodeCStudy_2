#include<stdio.h>
#include<stdlib.h>

static int A;

extern int a;				//声明全局变量

int runx() {
	int b = 0;
	a = 1;					//此时此刻可以访问的作用范围可见域名

}

int a = 10;					//作用域，全局变量，作用域全局，不等价作用范围

void main1() {

	//能否访问哪个变量称之为可见域
	a = 10;
}