/*
https://open.kattis.com/problems/different
*/
#include <stdio.h>
int main(void)
{
	long long a, b;
	while (scanf("%lld%lld", &a, &b) == 2) {
		long long dif = a - b;
		if (dif > 0) {
			printf("%lld\n", dif);
		}
		else {
			printf("%lld\n", -dif);
		}
	}
	return 0;
}