/*
https://open.kattis.com/problems/hangingout
*/

//bad

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
	int L, x;
	cin >> L >> x;
	string s;
	int p;
	int n = 0;
	int count = 0;
	string e = "enter";
	string l = "leave";
	for (int i = 0; i < x; ++i) {
		cin >> s >> p;
		if (s == e) {
			if (n + p <= L) n += p;
			else ++count;
		}
		else if (s == l) {
			n -= p;
		}
	}
	cout << count;
	return 0;
}