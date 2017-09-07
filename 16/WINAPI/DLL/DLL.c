#include<Windows.h>

_declspec(dllexport) int a = 10;

_declspec(dllexport) void go() {

	MessageBoxA(0, "go", "go", 10);
}