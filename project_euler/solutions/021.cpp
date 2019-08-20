/*
https://projecteuler.net/problem=21
Solution: 31626
*/

#include <iostream>
#include <vector>

//returns an vector of the proper divisors of n
//based on problem_12
std::vector<int> proper_divisors(int n ){
	std::vector<int> divisors;
	divisors.push_back(1);
	int i = 2;
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

//returns the sum of the proper divisors of n
int sum_pd(int n){
	int sum = 0;
	std::vector<int> pd = proper_divisors(n);
	for(int i : pd) sum += i;
	return sum;
}

//if a and b are amicable pairs
bool amicable(int a, int b){
	if(a == b) return false;
	return sum_pd(a) == b
		&& sum_pd(b) == a;
}

//if n is amicable
bool amicable(int n){
	return n != sum_pd(n)
		&& n == sum_pd(sum_pd(n));
}

int main() {
	int sum = 0;
	const int TOP = 10 * 1000;
	for(int i = 0; i < TOP; ++i)
		if(amicable(i))
			sum += i;
	std::cout << sum;
	return 0;
}