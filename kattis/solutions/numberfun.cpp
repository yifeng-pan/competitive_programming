/*
https://open.kattis.com/problems/numberfun
*/

#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>

int main(){
	int N;
	std::cin >> N;
	int a, b, c;
	for (int i = 0; i < N; ++i) {
		std::cin >> a >> b >> c;
		if (c == a + b || a == b + c || b == a + c || c == a * b || b == a * c || a == c * b) {
			std::cout << "Possible\n";
		}
		else {
			std::cout << "Impossible\n";
		}
	}
}