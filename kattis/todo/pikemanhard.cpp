/*
https://open.kattis.com/problems/pikemanhard
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

long long int mod = pow(10, 9) + 7;

int main(){
	int N, T;
	std::cin >> N >> T;
	int A, B, C, t0;
	std::cin >> A >> B >> C >> t0;

	std::vector<long long int> times;
	times.push_back(t0);
	for(int i = 1; i < N; ++i){
		long long int n = A;
		n *= times[i - 1];
		n += B;
		n %= C;
		++n;
		times.push_back(n);
	}

	std::sort(times.begin(), times.end());

	int time = 0;
	int solved = 0;
	while(time + times[solved] <= T && solved < N){
		time += times[solved];
		++solved;
	}
	
	long long int mod_penalty = 0;
	for(int i = 0; i < solved; ++i){
		for(int j = 0; j < solved - i; ++j){
			mod_penalty += times[i];
			mod_penalty %= mod;
		}
	}

	std::cout << solved << ' ' << mod_penalty;

	return 0;
}