/*
https://open.kattis.com/problems/hissingmicrophone
*/

#include <iostream>

int main() {
	std::string s;
	std::cin >> s;
	
	if(s.find("ss") == std::string::npos)
		std::cout << "no ";
	std::cout << "hiss";
	return 0;
}