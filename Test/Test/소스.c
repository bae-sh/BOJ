#include<stdio.h>

int main() {
	char* a = "abc";
	char b[123] = "dfe";
	char* c;
	c = a;
	a = "cdf";
	printf("%s", c);
}