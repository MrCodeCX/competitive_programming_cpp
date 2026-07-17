#include <iostream>
#include <cmath>
using namespace std;

// Problem: Codeforces Round 940 (Div. 2), B - A BIT of a Construction
// Link: https://codeforces.com/contest/1957/problem/B
//
// Summary:
// For each test case, construct an array of n non-negative integers whose sum is
// exactly k. Among all valid arrays, the goal is to maximize the number of
// 1 bits in the bitwise OR of all array elements. Any array that reaches that
// maximum is accepted.
//
// Solve:
// If n is 1, the only possible array is [k]. Otherwise, build sol with the same
// binary length as k, but with the MSB as 0 and every lower bit as 1. For
// example, if k is 128 (10000000 in binary), sol is 127 (01111111 in binary).
// The second number is k - sol, and the rest is filled with zeroes.

int main() {
	int t; cin >> t;
	while (t--)
	{
		int n; int k; cin >> n >> k;
		if (n == 1) cout << k << endl;
		else {
			int n_bits = log2(k);
			int sol = pow(2, n_bits) - 1;
			cout << sol << " " << (k - sol) << " ";
			for (int j = 2; j < n; j++)
			{
				cout << 0 << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
