/*
https://open.kattis.com/problems/cd
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int N, M;
	while(std::cin >> N >> M && N != 0 && M != 0){
		std::vector<int> n, m;
		for(int i = 0; i < N; ++i){
			int x;
			std::cin >> x;
			n.push_back(x);
		}
		for(int i = 0; i < M; ++i){
			int x;
			std::cin >> x;
			m.push_back(x);
		}

		sort(n.begin(), n.end());
		sort(m.begin(), m.end());

		int in = 0, im = 0, count = 0;
		while(in < n.size() && im < m.size()){
			if(n[in] == m[im]){
				++count;
				++in;
				++im;
			}else if(n[in] < m[im]){
				++in;
			}else{
				++im;
			}
		}

		std::cout << count << '\n';
	}

	return 0;
}