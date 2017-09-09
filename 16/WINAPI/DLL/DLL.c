#include<Windows.h>
#include<stdio.h>

_declspec(dllexport) int a = 10;

_declspec(dllexport) void go() {
	printf("Hello go");
	MessageBoxA(0, "go", "go", 0);
}