/*
https://open.kattis.com/problems/longincsubseq
*/

//https://en.wikipedia.org/wiki/Longest_increasing_subsequence

#include <iostream>
#include <vector>
#include <algorithm>

// returns the indices of the Longest Increasing Subsequence
std::vector<int> ilis(std::vector<int> seq){
	int N = seq.size();
	int M[N + 1]; // Increasing subsequence of length n // M[0] is unused
	int P[N];

	int max = 0;
	for(int i = 0; i < N; ++i){
		int low = 1;
		int high = max;
		while(low <= high){
			int mid = (low + high + 1) / 2;
			if(seq[M[mid]] < seq[i])
				low = mid + 1;
			else
				high = mid - 1;
		}

		int local_max = low;

		P[i] = M[local_max - 1];
		M[local_max] = i;

		if(local_max > max)
			max = local_max;
	}
	
	std::vector<int> subseq;
	int k = M[max];
	for(int i = 0; i < max; ++i){
		subseq.push_back(k);
		k = P[k];
	}
	std::reverse(subseq.begin(), subseq.end());

	return subseq;
}

int main(){
	int n;
	while(std::cin >> n){
		std::vector<int> seq;
		for(int i = 0; i < n; ++i){
			int s;
			std::cin >> s;
			seq.push_back(s);
		}
		std::vector<int> subseq = ilis(seq);
		std::cout << subseq.size() << '\n';
		for(int i = 0; i < subseq.size(); ++i){
			std::cout << subseq[i] << ' ';
		}
		std::cout << '\n';
	}
	return 0;
}