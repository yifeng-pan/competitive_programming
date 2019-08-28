/*
https://open.kattis.com/problems/primesieve
*/

// Memory limit exceeded

#include <iostream>

int main() {
	int n, q;
	std::cin >> n >> q;

	++n; // counting 0 aswell.
	bool sieve[n];
	for(int i = 0; i <= n; ++i) 
		sieve[i] = true;
	sieve[0] = false;
	sieve[1] = false;
	int target = 2;
	while(target < n){
		for(int j = 2; target * j <= n; ++j)
			sieve[target * j] = false;

		do{
			++target;
		} while(sieve[target] == false);
	}

	int count = 0;
	for(int i = 0; i < n; ++i)
		if(sieve[i])
			++count;

	std::cout << count << std::endl;

	for(int i = 0; i < q; ++i){
		int x;
		std::cin >> x;
		std::cout << sieve[x] << std::endl;
	}
	return 0;
}