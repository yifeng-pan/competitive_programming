/*
https://open.kattis.com/problems/pizza2
*/

#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <math.h>

int main()
{
	int c, r;
	std::cin >> r >> c;
	std::cout << std::fixed;
	std::cout << std::setprecision(10) << (1.0 * (c - r) * (c - r)) * 100 / (1.0 *r * r);
	return 0;
}