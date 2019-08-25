/*
https://open.kattis.com/problems/trik
*/

#include <iostream>

int main() {
	char move;
	int ball = 1;
	while(std::cin >> move)
		switch (move) {
			case 'A': 
				if(ball == 1) ball = 2;
				else if(ball == 2) ball = 1;
				break;
			case 'B': 
				if(ball == 2) ball = 3;
				else if(ball == 3) ball = 2;
				break;
			case 'C': 
				if(ball == 1) ball = 3;
				else if(ball == 3) ball = 1;
				break;
			default:
				break;
		}
	std::cout << ball;
	return 0;
}