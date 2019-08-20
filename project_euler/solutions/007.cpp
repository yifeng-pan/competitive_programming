/*
https://projecteuler.net/problem=7
Solution: 104743
*/

#include <iostream>
using namespace std;

//Returns if a number is Prime.
//From problem_3
bool primality(int n) {
	if (n < 2) return false;
	if (n < 4) return true;
	if (n % 2 == 0 || n % 3 == 0) return false;
	if (n == 5) return true;
	for (int i = 5; i * i <= n; i += 6)
		if (n % i == 0 || n % (i + 2) == 0)
			return false;
	return true;
}

//Returns the n^th prime from start
int nth_prime(int start, int n) {
	int x = start;
	while (n > 0) {
		++x;
		if (primality(x)) --n;
	}
	return x;
}

int main() {
	cout << nth_prime(1, 10001);
	return 0;
}