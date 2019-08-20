/*
https://open.kattis.com/problems/collatz
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//Generates the next number of the Collatz sequence
unsigned long long next(unsigned long long n) {
	return (n % 2 == 0) ? n / 2 : n * 3 + 1;
}

//Generates the Collatz sequence from n to 1. Store in S.
//Modifies S.
void gen_seq(vector<unsigned long long>& S, unsigned long long n) {
	S.push_back(n);
	while (n != 1) {
		n = next(n);
		S.push_back(n);
	}
}

//Looks for b in vector A. Returns the index if found, -1 otherwise.
int search(const vector<unsigned long long>& A, unsigned long long b) {
	for (int i = 0; i < A.size(); ++i)
		if (A[i] == b)
			return i;
	return -1;
}

//Returns true if target(convergence point) is found. Ending the Binary search.
bool target_found(const vector<unsigned long long>& A, const vector<unsigned long long>& B, int ia, int ib) {
	if (A[ia] == B[ib])
		if (ia == 0 || ib == 0 || A[ia - 1] != B[ib - 1]) return true;
	return false;
}

//Binary search for finding b found in A.
//Modifies ia and ib
void bsearch(const vector<unsigned long long>& A, const vector<unsigned long long>& B, int& ia, int& ib) {
	int l = 0, r = B.size() - 1;
	while (l <= r) {
		ib = floor((l + r) / 2);
		ia = search(A, B[ib]);
		if (ia == -1)
			l = ib + 1;
		else if (!target_found(A, B, ia, ib))
			r = ib - 1;
		else return;
	}
}

//Runs one case of the test, prints "a needs sa steps, b needs sb steps, they meet at c".
void t_case(int a, int b) {
	vector<unsigned long long> A, B;
	gen_seq(A, a);
	gen_seq(B, b);

	int ia = 0, ib = 0;
	bsearch(A, B, ia, ib);

	cout << a << " needs " << ia << " steps, " << b << " needs " << ib << " steps, they meet at " << B[ib] << '\n';
}

int main()
{
	int a, b;
	while (cin >> a >> b && a != 0 && b != 0)
		t_case(a, b);
	return 0;
}