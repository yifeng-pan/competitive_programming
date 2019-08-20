/*
https://open.kattis.com/problems/thanosthehero
*/

#include <iostream>
#include <vector>

int main() {
	int N;
	std::cin >> N;

	//Vector of populations.
	std::vector<int> as;
	for (int i = 0; i < N; ++i) {
		int pop;
		std::cin >> pop;
		as.push_back(pop);
	}

	//If It's impossible to creat a perfect universe
	for (int i = 0; i < as.size(); ++i) {
		if (as[i] < i) {
			std::cout << 1;
			return 0;
		}
	}
	
	//How many to kill.
	long long int sum = 0;
	for (int i = as.size() - 1; i >= 1; --i) {
		int dif = as[i - 1] - as[i];
		if (dif >= 0) {
			sum += dif + 1;
			as[i - 1] -= dif + 1;
		}
	}
	std::cout << sum;
	return 0;
}