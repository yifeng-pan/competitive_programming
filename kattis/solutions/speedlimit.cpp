/*
https://open.kattis.com/problems/speedlimit
*/

#include <iostream>

int main() {
	int n;
	while(std::cin >> n && n != -1){
		int miles = 0;
		int s, t1 = 0, t2;
		for(int i = 0; i < n; ++i){
			std::cin >> s >> t2;
			miles += (t2 - t1) * s;
			t1 = t2;
		}
		std::cout << miles << " miles" << std::endl;
	}
	return 0;
}