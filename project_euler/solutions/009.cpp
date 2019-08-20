/*
https://projecteuler.net/problem=9
Solution: 31875000
*/

#include <iostream>

//Unoptimized
int pythag_trip(int size){
	for(int a = 0; a <= size; ++a){
		for(int  b = 0; b <= size - a; ++b){
			int c = size - b - a;
			if(a * a + b * b == c * c) 
				std::cout << a * b * c << '\n';
		}
	}
}

int main() {
	pythag_trip(1000);
	return 0;
}