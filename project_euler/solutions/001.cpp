/*
https://projecteuler.net/problem=1
Solution: 233168
*/

#include <iostream>
#include <vector>
using namespace std;

int sum_multiple(vector<int> divisors, int max){
    int sum = 0;
    for(int i = 0; i < max ; ++i)
        for(int d : divisors)
            if(i % d == 0){
                sum += i;
                break;
            }
    return sum;
}

int main() {
    vector<int> divisors = {3,5};
    int max = 1000;
    cout << sum_multiple(divisors, max);
	return 0;
}