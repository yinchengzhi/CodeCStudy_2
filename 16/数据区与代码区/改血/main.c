#include<stdio.h>

//
_declspec(dllexport) void go() {

	int *p = 0xAE0720;					//指针最大的用途之一，间接修改数据
	*p = 63;

}