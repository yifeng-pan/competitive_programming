/*
https://open.kattis.com/problems/knapsack
*/

#include <iostream>
#include <vector>
#include <algorithm>

//Wrong answer

struct item{
	int value;
	int weight;
	bool choose; // to select the item or not, default: false
};

struct knapsack{
	int value; // value based on which items are chosen, default: 0
	int capacity;
	std::vector<item> items;
};

// input assumes k is in default state
// dp algorithm
knapsack maximize(knapsack k){
	int N = k.items.size();
	int C = k.capacity;

	// row is from 0 elements to n elements hence n + 1, not n
	// col simular reason
	int K[N + 1][C + 1];

	bool decision[N + 1][C + 1]; // to take or not to take

	// everything is offset by 1
		// as the index of the nth element is n - 1
	for(int n = 0; n <= N; ++n){
		for(int c = 0; c <= C; ++c){
			if(n <= 0 || c <= 0){
				K[n][c] = 0; // k is default
				decision[n][c] = false;
			}else if(k.items[n - 1].weight > c){
				K[n][c] = K[n - 1][c];
				decision[n][c] = false;
			}else{
				int take {K[n - 1][c - k.items[n - 1].weight]};
				take += k.items[n - 1].value;

				int not_take {K[n - 1][c]};

				if(take > not_take){
					K[n][c] = take; 
					decision[n][c] = true;
				}else{
					K[n][c] = not_take; 
					decision[n][c] = false;
				}
			}
			//std::cout << K[n][c] << '(' << decision[n][c] << ')' << ' ';
		}
		//std::cout << std::endl;
	}

	std::vector<bool> choices;
	int c = C;
	for(int n = N; n >= 1; --n){
		if(decision[n][c]){
			choices.push_back(true);
			c -= k.items[n - 1].weight;
		}else{
			choices.push_back(false);
		}
	}
	std::reverse(choices.begin(), choices.end());

	k.value = K[N][C];
	for(int n = 0; n < N; ++n)
		k.items[n].choose = choices[n];

	return k;
}

// how many elements were selected to make up the value
int choices(knapsack k){
	int sum = 0;
	for(item i : k.items)
		if(i.choose)
			++sum;
	return sum;
}

int main(){
	int c, n;
	while(std::cin >> c >> n){
		knapsack k {0, c}; // default value = 0, capacity = c
		for(int i = 0; i < n; ++i){
			int v, w;
			std::cin >> v >> w;
			k.items.push_back(item {v, w, false});
		}

		k = maximize(k);

		//std::cout << "Max value: " << k.value << std::endl;

		std::cout << choices(k) << std::endl; 

		for(int i = 0; i < k.items.size(); ++i)
			if(k.items[i].choose)
				std::cout << i << ' ';
		std::cout << std::endl;
	}

	return 0;
}