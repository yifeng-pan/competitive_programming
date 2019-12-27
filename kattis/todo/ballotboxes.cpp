/*
https://open.kattis.com/problems/ballotboxes
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

// Time limit exceeded
// Use different sorting algor?

struct City{
	int pop;
	int box = 1;
	int ppb; // pop per box
	City(int);
	void add(int); // Adds n boxes to the city
};

City::City(int n){
	pop = n;
	ppb = pop;
	return;
}

void City::add(int n){
	box += n;
	ppb = ceil((double) pop / box);
	return;
}

void swap(std::vector<City>& cities, int a, int b){
	iter_swap(cities.begin() + a, cities.begin() + b);
}

int partition(std::vector<City>& cities, int low, int high){
	int p = cities[high].ppb;
	int i = low;
	for(int j = low; j < high; ++j){
		if(cities[j].ppb > p){
			swap(cities, i, j);
			++i;
		}
	}
	swap(cities, i, high);
	return i;
}

// quick sort in reverse order
void r_qsort(std::vector<City>& cities, int low, int high){
	if(low < high){
		int p = partition(cities, low, high);
		r_qsort(cities, low, p - 1);
		r_qsort(cities, p + 1, high);
	}
	return; 
}

// custom insertion sort in reverse order
// Assumes only the first element is out of place
void cr_isort(std::vector<City>& cities){
	for(int i = 0; i < cities.size() - 1; ++i){
		if(cities[i].ppb >= cities[i+1].ppb)
			return;
		else
			swap(cities, i, i + 1);
		
	}
}

int t_case(const int N, int B) {
	if(N == 1){
		int p;
		std::cin >> p;
		return ceil((double) p / B);
	}

	std::vector<City> cities;
	for(int i = 0; i < N; ++i){
		int p;
		std::cin >> p;
		cities.push_back(City(p));
	}
	r_qsort(cities, 0, cities.size() - 1);
	B -= N;
	while(B > 0){
		int n = floor((double) cities[0].pop / cities[1].ppb) - cities[0].box;
		if(n > B) n = B;
		if(n < 1) n = 1;
		cities[0].add(n);
		B -= n;
		cr_isort(cities);
	}
	return cities[0].ppb;
}

int main()
{
	int N, B;
	while (std::cin >> N >> B && N != -1 && B != -1) {
		std::cout << t_case(N, B) << '\n';
	}
	return 0;
}