/*
https://open.kattis.com/problems/dicecup
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

int main(){
	int N,M;
	std::cin >> N >> M;

	int sum = N + M;
	int counter = std::min(N, M) - 1;

	for(int i = 2 + counter; i <= sum - counter; ++i)
		std::cout << i << '\n';

	return 0;
}