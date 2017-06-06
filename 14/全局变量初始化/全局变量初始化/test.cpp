#include<iostream>

using namespace std;

class myclass {			//类型

public:					//公开
	myclass() {			//类的构造函数
		puts("create\n");
	}
};

myclass my1;			//全局变量，优先于main创建

void main() {
	getchar();

}