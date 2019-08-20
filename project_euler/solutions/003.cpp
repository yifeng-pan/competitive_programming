/*
https://projecteuler.net/problem=3
Solution: 6857
*/

#include <iostream>
#include <vector>
using namespace std;

//Returns if a number is Prime.
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

//Returns the next Prime larger then n
int next_prime(int n) {
	do {
		++n;
	} while (!primality(n));
	return n;
}

//Returns a vector of a number's prime factors
vector<int> prime_fact(long long n) {
	vector<int> factors;
	int prime = 2;
	while (n != 1) {
		while (n % prime == 0) {
			factors.push_back(prime);
			n /= prime;
		}
		prime = next_prime(prime);
	}
	return factors;
}

int main() {
	long long n = 600851475143;
	vector<int> factors = prime_fact(n);
	cout << factors[factors.size() - 1];
	return 0;
}