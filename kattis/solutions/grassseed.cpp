/*
https://open.kattis.com/problems/grassseed
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

int main(){
	double C;
	int L;
	std::cin >> C >> L;

	double area = 0;

	for(int i = 0; i < L; ++i){
		double l, w;
		std::cin >> l >> w;
		area += l * w;
	}

	std::cout.precision(floor(log10(area*C)) + 1 + 6);
	std::cout << C * area;

	return 0;
}