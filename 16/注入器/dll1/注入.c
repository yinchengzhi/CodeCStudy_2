#include<Windows.h>

_declspec(dllexport) void go() {

	MessageBoxA(0, "go", "go", 0);

}

BOOL APIENTRY DllMain(HMODULE hmodule, DWORD reason, void *p) {
	switch (reason){

	case DLL_PROCESS_ATTACH:
		MessageBoxA(0, "ע��ɹ�AAA", "ע��ɹ�AAA", 0);
		break;
	}
	return TRUE;
}