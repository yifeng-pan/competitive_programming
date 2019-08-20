/*
https://projecteuler.net/problem=6
Solution: 25164150
*/

#include <iostream>
#include <cmath>
using namespace std;

//Sum of k from k = 1 to n. Return sum
int sum_n(int n) {
	return n * (n + 1) / 2;
}

//Sum of k^2 from k = 1 to n. Return sum
int sum_nn(int n) {
	return n * (n + 1) * (2 * n + 1) / 6;
}

int main() {
	int max = 100;
	int sum_square = sum_nn(max);
	int square_sum = pow(sum_n(max), 2);
	cout << abs(square_sum - sum_square);
	return 0;
}