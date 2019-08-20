/*
https://open.kattis.com/problems/faktor
*/

#include <stdio.h>
int main(void)
{
	int x,y,q;
	scanf("%d%d", &x, &y);
	q = x * (y - 1);
	q++;
	printf("%d", q);
	return 0;
}