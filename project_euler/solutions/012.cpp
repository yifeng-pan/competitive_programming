/*
https://projecteuler.net/problem=12
Solution: 76576500
*/

//not the best, but works

#include <iostream>
#include <vector>

//returns the n^th triangle number
//From problem_6
int sum_n(int n) {
	return n * (n + 1) / 2;
}

//returns an vector of the divisors of n
std::vector<int> divisors(int n){
	std::vector<int> divisors;
	int i = 1;
	for(; i * i < n; ++i){
		if(n % i == 0){
			divisors.push_back(i);
			divisors.push_back(n / i);
		}
	}
	if(i * i == n)
		divisors.push_back(i);
	return divisors;
}

int main() {
	int i = 1;
	int n = sum_n(i);
	while(divisors(n).size() < 500){
		++i;
		n = sum_n(i);
	}
	std::cout << n;
	return 0;
}