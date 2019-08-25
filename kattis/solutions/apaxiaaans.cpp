/*
https://open.kattis.com/problems/apaxiaaans
*/

#include <iostream>
#include <vector>

int main() {
	std::vector<char> cs;
	char c;
	while(std::cin >> c) 
		cs.push_back(c);

	std::cout << cs[0];
	for(int i = 1; i < cs.size(); ++i)
		if(cs[i] != cs[i - 1])
			std::cout << cs[i];

	return 0;
}