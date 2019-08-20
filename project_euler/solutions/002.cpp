/*
https://projecteuler.net/problem=2
Solution: 4613732
*/

#include <iostream>
using namespace std;

int sum_even_fib(int max){
    int a = 1, b = 2;
    int sum = 0;
    for(; b < max; b += a, a = b - a)
        if(b % 2 == 0) 
            sum += b;
    return sum;
}

int main() {
    int max = 4 * 1000 * 1000;
    cout << sum_even_fib(max);
	return 0;
}