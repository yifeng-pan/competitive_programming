// Problem:
// An urn containing 80 red balls and 20 blue balls.
// The balls are removed one by one.
// If a red ball is taken it is discarded.
// If a blue ball is taken it is put back in the urn and the following ball taken is discarded regardless of color.

// How likely is the last ball to be red?

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

// Could be improved by using a fraction structure

double p(int r, int b){
    if(r >= 1 && b == 0) return 1;
    if(r == 0 && b >= 1) return 0;

    double n = r + b;
    double pr = r / n + b * r / n / n;
    double pb = b * b / n / n;
    return pr * p(r - 1, b) + pb * p(r, b -1);
}

double dp(int r, int b){
    double urn[r + 1][b + 1];
    
    for(int i = 1; i < r + 1; ++i)
        urn[i][0] = 1;
    
    for(int j = 1; j < b + 1; ++j)
        urn[0][j] = 0;

    for(int i = 1; i < r + 1; ++i){
        for(int j = 1; j < b + 1; ++j){
            double n = i + j;
            double pr = i / n + j * i / n / n;
            double pb = j * j / n / n;
            urn[i][j] = pr * urn[i - 1][j] + pb * urn[i][j - 1];
        }
    }

    // std::cout << "dp array: \n";
    // for(int i = 1; i < r + 1; ++i){
    //     for(int j = 1; j < b + 1; ++j) 
    //         std::cout << urn[i][j] << ' ';
    //     std::cout << '\n';
    // }

    return urn[r][b];
}

int main(){
    int r = 80;
    int b = 20;
    // double recursion = p(r,b);
    // std::cout << "Recursion output: " << recursion << '\n';
    double dynamic = dp(r,b);
    std::cout << std::setprecision(100) << "DP output: " << dynamic << '\n';
	return 0;
}