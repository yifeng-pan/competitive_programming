/*
https://open.kattis.com/problems/twostones
*/

#include <stdio.h>
int main(void)
{
	long s;
	scanf("%ld", &s);
	if (s % 2 == 0) {
		printf("Bob");
	}
	else {
		printf("Alice");
	}
	return 0;
}