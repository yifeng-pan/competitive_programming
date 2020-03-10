// Compute $a^n (mod m)$, where $a$ in an integer, and $n,m$ are naturals.

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

void print(std::vector<long long int> v){
    std::cout << '<';
    for(int i = 0; i < v.size() - 1; ++i)
        std::cout << v[i] << ", ";
    std::cout << v[v.size() - 1] << '>' << '\n';
}

int main() {
    long long int a, n, m;
    // std::cin >> a >> n >> m;
    a = 137; n = 177013; m = 100003;
    int np = n;

    std::vector<long long int> bs;
    while(np > 0){
        bs.push_back(np % 2);
        np /= 2;
    }
    std::reverse(bs.begin(), bs.end());
    print(bs);

    std::vector<long long int> rs {a % m};
    for(int i = 0; i < bs.size() - 1; ++i){
        long long int r_next = rs[i] * rs[i] * (bs[i + 1]? a : 1);
        if(r_next < 0) throw std::overflow_error("Overflow in rs.");
        r_next %= m;
        rs.push_back(r_next);
    }
    print(rs);

    std:: cout << a << "^" << n << " (mod " << m << ") = " << rs[rs.size() - 1];

	return 0;
}