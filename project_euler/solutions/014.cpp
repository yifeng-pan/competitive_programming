/*
https://projecteuler.net/problem=14
Solution: 837799
*/

#include <iostream>
#include <vector>

//from kattis/problem_collatz
//Generates the next number of the Collatz sequence
unsigned long long next(unsigned long long n) {
	return (n % 2 == 0) ? n / 2 : n * 3 + 1;
}

//Generates the Collatz sequence from n to 1. Store in S.
//Modifies S.
void gen_seq(std::vector<unsigned long long>& S, unsigned long long n) {
	S.push_back(n);
	while (n != 1) {
		n = next(n);
		S.push_back(n);
	}
}

int main() {
	int max = 0;
	int top = 1000 * 1000;
	for(int i = 1; i <= top; ++i){
		std::vector<unsigned long long> S;
		gen_seq(S, i);
		if(S.size() > max){
			max = S.size();
			std::cout << max << ", " << i << '\n';
		}
	}
	return 0;
}