/*
https://projecteuler.net/problem=10
Solution: 142913828922
*/

#include <iostream>

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

//Unoptimized
unsigned long long sum_prime(int n){
	unsigned long long sum = 0;
	for(int i = 0; i < n; ++i)
		if(primality(i))
			sum += i;
	return sum;
}

int main() {
	std::cout << sum_prime(2 * 1000 * 1000);
	return 0;
}