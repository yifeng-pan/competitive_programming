/*
https://open.kattis.com/problems/sibice
*/

#include <iostream>
#include <cmath>

int main() {
	int n, w, h;
	std::cin >> n >> w >> h;

	int max = sqrt(pow(w,2) + pow(h,2));

	for(int i = 0; i < n; ++i){
		int m;
		std::cin >> m;
		if(m <= max)
			std::cout << "DA" << std::endl;
		else
			std::cout << "NE" << std::endl;
	}
	return 0;
}