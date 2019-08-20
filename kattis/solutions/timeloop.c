/*
https://open.kattis.com/problems/timeloop
*/

#include <stdio.h>
int main(void)
{
	int s;
	scanf("%d", &s);
	for (int i = 1; i <= s; i++) {
		printf("%d Abracadabra\n", i);
	}
	return 0;
}