/*
https://projecteuler.net/problem=11
Solution: 70600674
*/

//not teh best way to do this problem

#include <iostream>
#include <fstream>
#include <vector>

const int ROW_SIZE = 20;
const int COL_SIZE = 20;

int max_lr(std::vector<int> grid, int n){
	int max = 0;
	for(int i = 0; i < ROW_SIZE; ++i){
		for(int j = 0; j < COL_SIZE - n; ++j){
			int temp = 1;
			for(int k = 0; k < n; ++k)
				temp *= grid[i * COL_SIZE + j + k];

			if(temp > max) max = temp;
		}
	}
	return max;
}

int max_ud(std::vector<int> grid, int n){
	int max = 0;
	for(int i = 0; i < COL_SIZE; ++i){
		for(int j = 0; j < ROW_SIZE - n; ++j){
			int temp = 1;
			for(int k = 0; k < n; ++k)
				temp *= grid[(j + k) * COL_SIZE + i];

			if(temp > max) max = temp;
		}
	}
	return max;
}

int max_d1(std::vector<int> grid, int n){
	int max = 0;
	for(int i = 0; i < COL_SIZE - n; ++i){
		for(int j = 0; j < ROW_SIZE - n; ++j){
			int temp = 1;
			for(int k = 0; k < n; ++k)
				temp *= grid[(j + k) * COL_SIZE + i - k];

			if(temp > max) max = temp;
		}
	}
	return max;
}

int max_d2(std::vector<int> grid, int n){
	int max = 0;
	for(int i = 0; i < COL_SIZE - n; ++i){
		for(int j = n; j < ROW_SIZE; ++j){
			int temp = 1;
			for(int k = 0; k < n; ++k)
				temp *= grid[(j - k) * COL_SIZE + i + k];

			if(temp > max) max = temp;
		}
	}
	return max;
}

int main() {
	//opens file f
	std::string file_name = "20x20_grid.txt";
	std::ifstream f {file_name};
	if(!f) std::cout << "error";

	std::vector<int> grid;
	for(int i; f >> i;) grid.push_back(i);

	int n = 4;
	int lr = max_lr(grid, n);
	int ud = max_ud(grid, n);
	int d1 = max_d1(grid, n);
	int d2 = max_d2(grid, n);

	std::cout << lr << ' ' << ud << ' ' << d1 << ' ' << d2;

	return 0;
}