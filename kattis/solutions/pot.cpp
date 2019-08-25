/*
https://open.kattis.com/problems/pot
*/

#include <iostream>
#include <math.h>

int main() {
	int n;
	std::cin >> n;
	int sum = 0;
	for(int i = 0; i < n; ++i){
		int a, b;
		std::cin >> a;
		b = a % 10;
		a /= 10;
		sum += pow(a, b);
	}
	std::cout << sum;
	return 0;
}