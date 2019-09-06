/*
https://open.kattis.com/problems/ballotboxes
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct City {
	vector<int> box;
	vector<double> ppb; // pop per box
	City(int);
	void sort_ppb();
};

City::City(int N) {
	int city_pop;
	for (int i = 0; i < N; ++i) {
		cin >> city_pop;
		ppb.push_back(city_pop);
		box.push_back(1);
	}
	sort(ppb.begin(), ppb.end());
}

//Assuming only the last element is out of place
void City::sort_ppb() {
	//WIP
}

void t_case(const int N, int B) {
	City city = { N };
	B -= N;
	int end = city.ppb.size() - 1;
	double& high_ppb = city.ppb[end];
	int& high_box = city.box[end];
	for (; B > 0; --B) {
		high_ppb *= high_box;
		++high_box;
		high_ppb /= high_box;
		city.sort_ppb();
	}
	cout << ceil(high_ppb) << "\n";
}

int main()
{
	int N, B;
	while (cin >> N >> B && N != -1 && B != -1) {
		t_case(N, B);
	}
	return 0;
}