/*
https://open.kattis.com/problems/onechicken
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int a, b, dif;
	cin >> a >> b;
	dif = b - a;
	if(dif == -1)cout << "Dr. Chaz needs " << -dif << " more piece of chicken!";
	else if (dif < 0) cout << "Dr. Chaz needs " << -dif << " more pieces of chicken!";
	else if(dif == 1)cout << "Dr. Chaz will have " << dif << " piece of chicken left over!";
	else cout << "Dr. Chaz will have " << dif << " pieces of chicken left over!";
	return 0;
}