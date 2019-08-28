/*
https://open.kattis.com/problems/knapsack
*/

#include <iostream>
#include <vector>

// works, but
// Kattis: memory limit exceeded

// optimize the item vector in knapsack
// there is no need to store the values and weights everytime in the dp array
// change the item and knapsack structure

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
    knapsack K[N + 1][C + 1];

    // everything is offset by 1
        // as the index of the nth element is n - 1
    for(int n = 0; n <= N; ++n){
        for(int c = 0; c <= C; ++c){
            if(n <= 0 || c <= 0)
                K[n][c] = knapsack {k}; // k is default
            else if(k.items[n - 1].weight > c)
                K[n][c] = K[n - 1][c];
            else{
                knapsack take {K[n - 1][c - k.items[n - 1].weight]};
                take.value += k.items[n - 1].value;
                take.items[n - 1].choose = true;

                knapsack not_take {K[n - 1][c]};

                K[n][c] = (take.value > not_take.value)? take : not_take; 
            }
            //std::cout << K[n][c].value << ' ';
        }
        //std::cout << std::endl;
    }

    return K[N][C];
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