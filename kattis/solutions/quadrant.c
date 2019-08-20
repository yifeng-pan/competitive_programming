/*
https://open.kattis.com/problems/quadrant
*/

#include <stdio.h>
int main(void)
{
	int x,y,q;
	scanf("%d%d", &x, &y);
	if (x > 0) {
		if (y > 0) {
			q = 1;
		}
		else {
			q = 4;
		}
	}
	else {
		if (y > 0) {
			q = 2;
		}
		else {
			q = 3;
		}
	}
	printf("%d", q);
	return 0;
}