/*
https://open.kattis.com/problems/estimatingtheareaofacircle
*/

#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>

int main()
{
	double r;
	int m, c;
	while (std::cin >> r >> m >> c) {
		if (r == 0 && m == 0 && c == 0) {
			return 0;
		}
		std::cout << r * r * M_PI << " " << (1.0 * c / m) * r * r * 4 << "\n";
	}
}