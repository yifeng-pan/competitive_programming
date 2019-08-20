/*
https://open.kattis.com/problems/reversebinary
*/

#include <iostream>
#include <vector>
#include <cmath>

int main() {
	int N;
	std::cin >> N;
	std::vector<bool> Nbin;
	while(N != 0){
		Nbin.push_back(N % 2 != 0);
		N /= 2;
	}

	int rN = 0;
	for(int i = 0; i < Nbin.size(); ++i){
		rN += Nbin[i]? pow(2, Nbin.size() - i - 1) : 0;
	}
	std::cout << rN;
}