/*
https://open.kattis.com/problems/conundrum
*/

#include <iostream>

int main() {
	char p, e, r;
	int sum = 0;
	while(std::cin >> p >> e >> r){
		if(p != 'P') sum += 1;
		if(e != 'E') sum += 1;
		if(r != 'R') sum += 1;
	}
	std::cout << sum;
	return 0;
}