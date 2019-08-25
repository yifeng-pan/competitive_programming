/*
https://open.kattis.com/problems/pet
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::vector<int> scores;
	int a, b, c, d;
	while(std::cin >> a >> b >> c >> d)
		scores.push_back(a + b + c + d);

	int n = std::distance(scores.begin(), max_element(scores.begin(), scores.end()));
	std::cout << n + 1 << ' ' << scores[n];
	return 0;
}