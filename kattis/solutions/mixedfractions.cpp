/*
https://open.kattis.com/problems/mixedfractions
*/

#include <iostream>

void print_mixed(int a, int b){
	std::cout << a / b
		<< ' ' << a % b << " / " << b
		<< std::endl;
}

int main() {
	int a, b;
	while(std::cin >> a >> b && b != 0)
		print_mixed(a,b);
	return 0;
}