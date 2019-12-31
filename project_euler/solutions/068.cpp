/*
https://projecteuler.net/problem=68
Solution: 6531031914842725
*/

// https://en.wikipedia.org/wiki/Steinhaus%E2%80%93Johnson%E2%80%93Trotter_algorithm#Even's_speedup

// Not optimized, all results are duplicated SIZE/2 times, among other things

#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

// Even number >= 6
const int SIZE = 10;

std::vector<int> int_perm(){
	std::vector<int> perm;
	for(int i = 0; i < SIZE; ++i)
		perm.push_back(i + 1);
	return perm;
}

std::vector<int> int_dir(){
	std::vector<int> dir;
	dir.push_back(0);
	for(int i = 1; i < SIZE; ++i)
		dir.push_back(-1);
	return dir;
}

// If all elements are zero
bool all_zero(std::vector<int> dir){
	for(int i = 0; i < SIZE; ++i){
		if(dir[i] != 0)
			return false;
	}
	return true;
}

// Part of the SJT algorithm
int max_non_zero(std::vector<int> perm, std::vector<int> dir){
	int max = -1;
	int index = -1;
	for(int i = 0; i < SIZE; ++i){
		if(max < perm[i] && dir[i] != 0){
			max = perm[i];
			index = i;
		}
	}
	return index;
}

// Returns the next permutation, starting from 2nd
// The SJT algorithm
std::vector<int> next(){
	static std::vector<int> perm = int_perm();
	static std::vector<int> dir = int_dir();

	if(all_zero(dir)){
		perm = int_perm();
		dir = int_dir();
		return perm;	
	}

	int a = max_non_zero(perm, dir); // source
	int b = a + dir[a]; // target
	iter_swap(perm.begin() + a, perm.begin() + b);
	iter_swap(dir.begin() + a, dir.begin() + b);

	if(b == 0 || b == SIZE - 1)
		dir[b] = 0;
	if(perm[b] < perm[b + dir[b]])
		dir[b] = 0;
	
	for(int i = 0; i < SIZE; ++i)
		if(dir[i] == 0 && perm[i] > perm[b])
			dir[i] = (i < b)? 1 : -1;

	return perm;
}

// A very slow way to calculate factorials
// For testing the next() function
// int factorial(){
// 	std::vector<int> first = int_perm();
// 	std::vector<int> perm = first;

// 	int counter = 0;
// 	do{
// 		++counter;
// 		perm = next();
// 	} while (first != perm);

// 	return counter;
// }

void print(const std::vector<int>& vec){
	for(int i = 0; i < vec.size(); ++i){
		if(i == 0)
			std::cout << '<';
		std::cout << vec[i];
		std::cout << ((i != (vec.size() - 1))? ", " : ">");
	}
	std::cout << '\n';
	return;
}

// If that permutation forms a magic ring, returns the sum, -1 if not
int magic_ring(const std::vector<int>& perm){
	std::vector<int> first;
	std::vector<int> second;
	for(int i = 0; i < SIZE / 2; ++i){
		first.push_back(perm[i]);
		second.push_back(perm[i + SIZE / 2]);
	}
	second.push_back(perm[SIZE / 2]);

	int target = first[0] + second[0] + second[1];
	for(int i = 1; i < SIZE / 2; ++i)
		if(target != first[i] + second[i] + second[i + 1])
			return -1;

	return target;
}

// botch function to concat the perm to project euler format string
std::string to_string(std::vector<int> perm){
	std::stringstream ss;

	// from the magic_ring function 
	// bad
	std::vector<int> first;
	std::vector<int> second;
	for(int i = 0; i < SIZE / 2; ++i){
		first.push_back(perm[i]);
		second.push_back(perm[i + SIZE / 2]);
	}
	for(int i = 0; i < SIZE / 2; ++i){
		first.push_back(perm[i]);
		second.push_back(perm[i + SIZE / 2]);
	}

	int offset = std::min_element(first.begin(), first.end()) - first.begin();

	for(int i = 0; i < SIZE / 2; ++i){
		ss << first[i + offset] << second[i + offset] << second[i + offset + 1];
	}

	return ss.str();
}

int main() {
	std::vector<int> first = int_perm();
	std::vector<int> perm = first;

	std::vector<std::string> solutions;

	do{
		int total = magic_ring(perm);
		if(total != -1){
			std::cout << "Total: " << total << ", Solution: " << to_string(perm) << '\n';
			solutions.push_back(to_string(perm));
		}
		perm = next();
	} while (first != perm);

	sort(solutions.begin(), solutions.end());
	for(int i = 0; i < solutions.size(); ++i){
		std::cout << solutions[i] << '\n';
	}


	// std::cout << factorial();

	// for(int i = 0; i < 10; ++i){
	// 	print(perm);
	// 	perm = next();
	// }


	return 0;
}