/*
https://open.kattis.com/problems/abc
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main() {
	std::vector<int> n;
	for(int i = 0; i < 3; ++i){
		int x;
		std::cin >> x;
		n.push_back(x);
	}

	std::sort(n.begin(), n.end());

	std::string order;
	std::cin >> order;

	for(char c : order){
		std::cout << n[c - 'A'] << ' ';
	}

	return 0;
}