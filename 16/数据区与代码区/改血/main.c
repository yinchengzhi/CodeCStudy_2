#include<stdio.h>

//
_declspec(dllexport) void go() {

	int *p = 0xAE0720;					//ָ��������;֮һ������޸�����
	*p = 63;

}