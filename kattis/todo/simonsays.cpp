/*
https://open.kattis.com/problems/simonsays
*/

//cpp doesnt read strings with spaces

#include <iostream>

int main() {
	std::string phrase = "Simon says ";

	int n;
	std::cin >> n;
	for(int i = 0; i < n; ++i){
		std::string s;
		std::cin >> s;
		if(s.find(phrase) == 0){
			std::cout << s.substr(phrase.length())
				<< std::endl;
		}
	}
	return 0;
}