/*
https://open.kattis.com/problems/pikemaneasy
*/

// Overflow
// Likely something to do with the % operator not working on large numbers.

#include <iostream>
#include <vector>
#include <algorithm>

int main(){
	int N, T;
	std::cin >> N >> T;
	int A, B, C, t0;
	std::cin >> A >> B >> C >> t0;

	std::vector<int> times;
	times.push_back(t0);
	for(int i = 1; i < N; ++i){
		times.push_back(((A * times[i - 1] + B) % C) + 1);
	}

	std::sort(times.begin(), times.end());

	int time = 0;
	int solved = 0;
	while(time <= T && solved < N){
		time += times[solved];
		++solved;
	}
	
	// Trying to prevent overflow
	// doesn't owrk
	long long int mod_penalty = 0;
	for(int i = 0; i < solved; ++i){
		for(int j = 0; j < solved - i; ++j){
			mod_penalty += times[i];
			mod_penalty %= 10^9 + 7;
			if(mod_penalty < 0){
				std::cout << "overflow";
				return 1;
			}
		}
	}

	std::cout << solved << ' ' << mod_penalty;

	return 0;
}