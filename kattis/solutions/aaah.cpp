/*
https://open.kattis.com/problems/aaah
*/

#include <iostream>

int main(){
	std::string jon, doc;
	std::cin >> jon >> doc;
	std::cout << (jon.length() >= doc.length()? "go": "no");
	return 0;
}
