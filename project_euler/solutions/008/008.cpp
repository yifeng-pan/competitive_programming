/*
https://projecteuler.net/problem=8
Solution: 23514624000
*/

#include <iostream>
#include <fstream>
#include <string>

//returns the greatest product of adj number of adjacent digits in num_string
unsigned long long max_adj_product(std::string num_string, int adj){
	unsigned long long max = 0;
	for(int i = 0; i < num_string.length() - adj; ++i){
		unsigned long long current = 1;
		for(int j = 0; j < adj; ++j)
			current *= num_string[i + j] - '0';
		if(current > max)
			max = current;
	}
	return max;
}

int main() {
	//opens file f
	std::string file_name = "1000_digit_number.txt";
	std::ifstream f {file_name};
	if(!f) std::cout << "error";
	
	//creats the big number string
	std::string num_string;
	for(std::string s; f >> s;) num_string.append(s);
	std::cout << num_string << '\n';

	//
	std::cout << max_adj_product(num_string, 13);
	return 0;
}