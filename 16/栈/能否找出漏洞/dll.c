
#include<Windows.h>

//导出声明加载模块的时候可以直接调用

_declspec(dllexport) void go() {

	//double db[1234567];			//超过栈的大小
	wihle(-1){
		double db[1024 * 100];			//8*100*1024 近似于 1M
	}

	//栈会自动分配，自动释放，大量消耗cpu资源

	//dll可以移花接木
}

//导出声明加载模块的时候可以直接调用

_declspec(dllexport) void goA() {

	//double db[1234567];			//超过栈的大小

	MessageBox(0, "test", "test1", 0);
	//dll 移花接木


}