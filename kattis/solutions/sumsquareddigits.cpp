/*
https://open.kattis.com/problems/sumsquareddigits
*/

#include <iostream>
int ssd(int n, int b) {
	int sum = 0;
	while (n != 0) {
		sum += (n % b) * (n % b);
		n /= b;
	}
	return sum;
}

int main()
{
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		int b, k;
		std::cin >> b >> b >> k;
		std::cout << i + 1 << " " << ssd(k, b) << "\n";
	}
	return 0;
}