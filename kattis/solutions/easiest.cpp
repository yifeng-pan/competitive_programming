/*
https://open.kattis.com/problems/easiest
*/
#include <iostream>
int sumd(int n) {
	int sum = 0;
	while (n != 0) {
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

int main(){
	int N;
	std::cin >> N;
	int sumN, summN, m;
	while (N != 0) {
		sumN = sumd(N);
		m = 11;
		summN = sumd(m * N);
		while (summN != sumN) {
			++m;
			summN = sumd(m * N);
		}
		std::cout << m << "\n";
		std::cin >> N;
	}
	return 0;
}