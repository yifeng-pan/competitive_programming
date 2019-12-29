/*
https://open.kattis.com/problems/sevenwonders
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

int main(){
	std::string s;
	std::cin >> s;
	
	std::vector<int> tcg;
	for(int i = 0; i < 3; ++i)
		tcg.push_back(0);

	for(char c : s){
		switch(c){
			case 'T' : 
				++tcg[0];
				break;
			case 'C' : 
				++tcg[1];
				break;
			case 'G' : 
				++tcg[2];
				break;
		}
	}

	int score = 0;

	for(int i = 0; i < 3; ++i){
		score += pow(tcg[i], 2);
	}

	score += *std::min_element(tcg.begin(), tcg.end()) * 7;

	std::cout << score;

	return 0;
}