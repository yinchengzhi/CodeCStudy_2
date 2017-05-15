#include<stdio.h>
#include<stdlib.h>

//md5哈希，瞬间秒传	数据抽象

unsigned int SDBMHash(char *str) {
	unsigned int hash = 0;

	while (*str) {
		//equivalent to : hash = 65599*hash +（*str++);
		hash = (*str++) + (hash << 6) + (hash << 16) - hash;
	}
	return (hash & 0x7FFFFFFF);
}

void main() {
	printf("%u", SDBMHash("haihua"));
	printf("\n%u", SDBMHash("haihuai"));
	printf("\n%u", SDBMHash("haihuaiaifang"));

	getchar();

}