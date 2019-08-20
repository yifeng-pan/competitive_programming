/*
https://open.kattis.com/problems/threepowers
*/

//Bad

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<string> pow_three;

string mul(string pow, int n) {
	int x = 0;
	string rstring = "";
	for (int i = pow.length() - 1; i >= 0; --i) {
		x += n * (int)(pow.at(i) - '0');
		rstring = to_string(x % 10) + rstring;
		x /= 10;
	}
	if (x != 0) rstring = to_string(x % 10) + rstring;
	return rstring;
}

void gen_three_pow(vector<string>& S, int max) {
	string pow = "1";
	for (int i = 0; i < max; pow = mul(pow, 3), ++i){
		S.push_back(pow);
	}
}

void t_case(unsigned long long n) {
	unsigned long long on = n;
	cout << "{ ";
	long long index = 0;
	while (n > 0) {
		if (n % 2 == 1) {
			cout << pow_three[index];
			if (n > 2) cout << ", ";
		}
		n /= 2;
		++index;
	}

	if (on != 0)
		cout << ' ';
	cout << "}\n";
}

int main()
{
	gen_three_pow(pow_three, 3000);
	unsigned long long n;
	cin >> n;
	do {
		t_case(n - 1);
		cin >> n;
	} while (n != 0);
	return 0;
}