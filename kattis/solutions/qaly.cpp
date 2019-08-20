/*
https://open.kattis.com/problems/qaly
*/

#include <iostream>

int main()
{
	int N;
	double q, y;
	double qaly = 0;
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		std::cin >> q >> y;
		qaly += q * y;
	}
	std::cout << qaly;
}