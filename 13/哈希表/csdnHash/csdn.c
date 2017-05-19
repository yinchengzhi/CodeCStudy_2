#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char path[256] = "C:\\Users\\olydebug\\Downloads\\1.txt";
#define N 4330

struct info{
	char *pstr;
};

struct info *pall = NULL;

void init() {
	pall = malloc(N * sizeof(struct info));
	memset(pall, 0, N * sizeof(struct info));
	FILE *pf = fopen(path, "r");
	for (int i = 0; i < N; i++) {

	}
	fclose(pf);
}

// BKDR Hash Function
unsigned int BKDRHash(char *str){
	unsigned int seed = 131313; // 31 131 1313 13131 131313 etc..
	unsigned int hash = 0;

	while (*str){
		hash = hash * seed + (*str++);
	}

	return (hash & 0x7FFFFFFF);
}

int getN() {
	FILE *pf = fopen(path, "r");
	if (pf==NULL) {
		return -1;
	}
	else {
		int i = 0;
		while (!feof(pf)) {
			char str[100] = { 0 };
			fgets(str, 100, pf);					//¶ÁÈ¡
			i++;
		}
		fclose(pf);
		return i;
	}
}

void main() {

	printf("%d\n", getN());

	system("pause");
}