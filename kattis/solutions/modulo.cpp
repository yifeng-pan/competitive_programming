/*
https://open.kattis.com/problems/modulo
*/

#include <iostream>
#include <vector>
#include <set>

int main(){
    std::vector<int> iv;
	for(int i = 0; i < 10; ++i){
		int n;
		std::cin >> n;
		iv.push_back(n % 42);
	}

    std::cout 
		<< std::set<int>(iv.begin(), iv.end()).size()
		<< std::endl;
	
    return 0;
}