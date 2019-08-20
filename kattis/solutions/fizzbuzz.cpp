/*
https://open.kattis.com/problems/fizzbuzz
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int X, Y, N;
	cin >> X >> Y >> N;
	int n;
	string s;
	for (int i = 0; i < N; ++i) {
		n = i + 1;
		s = "";
		if (n % X == 0) s.append("Fizz");
		if (n % Y == 0) s.append("Buzz");
		if (s == "") cout << n;
		else cout << s;
		cout << '\n';
	}

	return 0;
}