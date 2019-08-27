/*
https://open.kattis.com/problems/prsteni
*/

#include <iostream>
#include <vector>

//bad and unoptimized
void print_reduce(int a, int b){
	for(int i = 2; i <= a; ++i){
		if(a % i == 0 && b % i == 0){
			a /= i;
			b /= i;
			--i;
		}
	}
	std::cout << a << '/' << b
		<< std::endl;
}

int main(){
	int N, fst;
	std::cin >> N >> fst;
	for(int i = 0; i < N - 1; ++i){
		int n;
		std::cin >> n;
		print_reduce(fst, n);
	}
	return 0;
}