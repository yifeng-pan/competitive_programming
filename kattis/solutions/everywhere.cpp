/*
https://open.kattis.com/problems/everywhere
*/

#include <iostream>
#include <vector>
#include <set>

void t_case(){
	int n;
	std::cin >> n;

    std::vector<std::string> sv;
	for(int i = 0; i < n; ++i){
		std::string city;
		std::cin >> city;
		sv.push_back(city);
	}

    std::cout 
		<< std::set<std::string>(sv.begin(), sv.end()).size()
		<< std::endl;
}

int main(){
	int t;
	std::cin >> t;
	
	for(int i = 0; i < t; ++i) 
		t_case();

    return 0;
}