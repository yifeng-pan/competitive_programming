/*
https://projecteuler.net/problem=5
Solution: 232792560
*/

#include <iostream>
using namespace std;

//Returns if a number is divisible by every number up to x
bool divide_to_x(int n, int x) {
	for (int i = 2; i <= x; ++i)
		if (n % i != 0) return false;
	return true;
}

int small_multi(int d) {
	int n = 2;
	while (!divide_to_x(n, d)) n += 2;
	return n;
}

int main() {
	cout << small_multi(20);
	return 0;
}