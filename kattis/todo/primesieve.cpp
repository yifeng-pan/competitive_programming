/*
https://open.kattis.com/problems/primesieve
*/

#include <iostream>
#include <vector>

int count_prime(std::vector<bool> sieve){
	int count = 0;
	for(int i = 0; i < sieve.size(); ++i)
		if(sieve[i])
			++count;
	return count;
}

std::vector<bool> gen_sieve(int n){
	std::vector<bool> sieve;
	for(int i = 0; i <= n; ++i) 
		sieve.push_back(true);
	sieve[0] = false;
	sieve[1] = false;
	int i = 2;
	while(i < n){
		for(int j = 2; i * j <= n; ++j)
			sieve[i * j] = false;

		do{
			++i;
		} while(sieve[i] == false);
	}
	return sieve;
}

int main() {
	int n, q;
	std::cin >> n >> q;

	std::vector<bool> sieve = gen_sieve(n);

	std::cout << count_prime(sieve) << std::endl;

	for(int i = 0; i < q; ++i){
		int x;
		std::cin >> x;
		std::cout << (sieve[x]? 1 : 0) << std::endl;
	}
	return 0;
}