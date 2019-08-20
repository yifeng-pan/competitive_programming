/*
https://open.kattis.com/problems/tarifa
*/

#include <iostream>

int main()
{
	int X, N, n;
	int count = 0;
	int data = 0;
	std::cin >> X >> N;
	for (int i = 0; i < N; i++) {
		std::cin >> n;
		data += X - n;
	}
	data += X;
	std::cout << data;
}