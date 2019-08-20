/*
https://projecteuler.net/problem=23
Solution: 4179871
*/

#include <iostream>
#include <vector>

//returns an vector of the proper divisors of n
//from problem_21
std::vector<int> proper_divisors(int n){
	std::vector<int> divisors;
	if(n < 1) return divisors;
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

//if a n is abundant
bool abundant(int n){
	int sum = 0;
	for(int i : proper_divisors(n)) sum += i;
	return n < sum;
}

int main() {
	const int TOP = 30 * 1000;//30,000 > 28,123

	std::vector<int> abundants;
	for(int i = 1; i < TOP; ++i)
		if(abundant(i))
			abundants.push_back(i);
			
	bool num[TOP];
	for(bool b : num) b = false;

	for(int a = 0; a < abundants.size(); ++a){
		for(int b = a; b < abundants.size(); ++b){
			if(abundants[a] + abundants[b] < TOP)
				num[abundants[a] + abundants[b]] = true;
		}
	}

	int sum = 0;
	for(int i = 0; i < TOP; ++i)
		if(!num[i]) sum += i;

	std::cout << sum;
	return 0;
}