#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main1() {
	
	char *src = "Hello World";
	int len = strlen(src);
	char *dest = (char *)malloc(len + 1);				//要为'\0'分配一个空间

	char *d = dest;
	char *s = &src[len - 1];

	while (len-- != 0) {
		*d++ = *s--;
	}

	*d = '\0';

	printf("%s\n", dest);

	free(dest);

	unsigned int a = 6;
	int b = -20;

	(a + b > 6) ? puts(">6") : puts("<=6");

	system("pause");
}