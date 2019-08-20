/*
https://open.kattis.com/problems/differentdistances
*/

#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>

int main()
{
	double x1, y1, x2, y2, p;
	double x, y;
	while (std::cin >> x1 >> y1 >> x2 >> y2 >> p) {
		x = abs(x1 - x2);
		y = abs(y1 - y2);
		std::cout << pow(pow(x, p) + pow(y, p), 1.0/p) << '\n';
	}
}