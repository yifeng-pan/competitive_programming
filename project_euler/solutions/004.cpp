/*
https://projecteuler.net/problem=4
Solution: 906609
*/

#include <iostream>
#include <string>
using namespace std;

//Returns if a number is Palindrome.
bool palindrome(int n) {
	string ns = to_string(n);
	while (ns.length() > 1) {
		if (ns.at(0) != ns.at(ns.length() - 1)) return false;
		ns = ns.substr(1, ns.length() - 2);
	}
	return true;
}

//Returns the lagrest Palindrome number that is the product of any 2 numbers between min and max.
//Unoptimized
int check_pp(int min, int max) {
	int l = -1;
	for (int a = max; a >= min; --a)
		for (int b = max; b >= a; --b)
			if (palindrome(a * b) && a * b > l) l = a * b;
	return l;
}

int main() {
	int max = 999;
	int min = 100;
	cout << check_pp(min, max);
	return 0;
}