#include<stdio.h>
#include<stdlib.h>

void go(int num) {

	//printf("%d", a);				C语言是从上往下开始编译,前面没有定义，就无法访问
	num = 11;						//num也是局部变量
	int a = 10;						//a是局部变量
	printf("%d", a);
	printf("%d", num);
}

void run(int num) {					//形式参数局部变量
	int data = 10;					//局部变量
	num = 9;						//局部变量
	printf("%x,%x", &num, &data);
	
	printf("\n");
}

void main1() {

	//printf("%d",a);				//a的作用范围就是第7行到函数结束
	//printf("%d",num);				//num只能从函数开始到函数结束的范围来访问 

	system("pause");
}

//局部变量，在函数调用的时候，才分配内存，函数执行完成的时候
//就回收内存，然后用作他用
//局部变量一般定义在函数内部
void main2() {

	run(5);

	printf("\n\n");

	run(5);

	printf("\n\n");

	system("pause");
}

void print() {
	//printf("%d", a);					//a是局部变量无法访问
}

void main3() {
	// printf("%d",a);					//C语言从上往下开始编译，前面没有检测到，就无法调用
	int a = 10;							//局部变量，作用范围从定义开始到main函数结束
	printf("%d", a);
}

void test1() {
	int a = 10;
	printf("%d,%p\n", a, &a);			//局部变量用完了就马上释放

	printf("\n");
}

void test2() {
	int a = 101;
	printf("%d,%p\n", a, &a);

	printf("\n");
}

//不同函数的同名变量，有些编译器为了优化，所以地址是一样的
//他们的生命周期不一样，所以不会混淆，
//地址先分配给test1的a，用完了释放，再次分配test2的a
//所以重名不会有影响,因为生命周期是错开的

void main4() {

	test1();

	printf("\n");

	test2();

	system("pause");
}

//生存周期有重合的变量，我们就要安排给不同的地址,加以区分

//不同的函数，可以定义同名的局部变量
//如果生命周期不重合，编译器不优化，会使用同一内存单元
//生命周期重合，就会使用不同的内存单元，这个时候就不会冲突

void testlast() {
	int num = 10;
	printf("testlast = %d,%x", num, &num);
}


void main5() {
	int num = 11;
	printf("main = %d,%x\n", num, &num);
	testlast();

	getchar();
}

//不同的块语句，可以定义同名的局部变量，编译器会自动安排不同的地址
void main6() {
	int num = 11;
	//int num = 111;		同一个块语句内部，不能有两个名称相同的变量
	//违反
	printf("main = %d,%x\n", num, &num);
	{
		int num = 11;
		printf("main1 = %d,%x\n", num, &num);
		{
			int num = 11;
			printf("main2 = %d,%x\n", num, &num);
		}
	}

	getchar();
}