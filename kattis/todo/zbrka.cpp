/*
https://open.kattis.com/problems/zbrka
*/

/*
How many ways are there to
	choose one element from each row
	such that adding them up results in C
	
	0
	0 1
	0 1 2
	0 1 2 3
	0 1 2 3 4
	0 1 2 3 4 .. n
*/

// not fast enough, need better algorithm

#include <iostream>
#include <cmath>

long long int mod = pow(10, 9) + 7;

long long int dp(int N, int C){
	--N; // offset for indexing

	long long int confusions[N + 1][C + 1]; // row is upto N, col is ways to sum confusion from the first N rows
	// Both offset by one due to indexing

	for(int c = 1; c <= C; ++c) // base case for n = 0
		confusions[0][c] = 0;

	for(int n = 0; n <= N; ++n) // base case for c = 0 and c = n = 0
		confusions[n][0] = 1;

	for(int n = 1; n <= N; ++n){
		for(int c = 1; c <= C; ++c){

			long long int sum = 0;

			if(c <= n){
				int i = 0;
				while(c - i >= 0 && i <= n){
					sum += confusions[n - 1][c - i];
					sum %= mod;
					++i;
				}
			}else{
				sum = confusions[n][c - 1];
				sum -= confusions[n - 1][c - n - 1];
				sum += confusions[n - 1][c];
				sum = (sum + mod) % mod; // cpp doesn't mod negatives properly
			}

			confusions[n][c] = sum;

		}
	}

	/*
	for(int n = 0; n <= N; ++n){
		for(int c = 0; c <= C; ++c){
			std::cout << confusions[n][c] << ' ';
		}
		std::cout << '\n';
	}
	*/

	return confusions[N][C];
}

int main(){
	int N, C;
	std::cin >> N >> C;
	std::cout << dp(N, C);
	return 0;
}