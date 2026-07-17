#include <iostream>
using namespace std;

// Problem: Codeforces Round 952 (Div. 4), B - Maximum Multiple Sum
// Link: https://codeforces.com/contest/1985/problem/B
//
// Summary:
// For a given n, choose x from 2 to n. For that x, sum all positive multiples of
// x that are at most n. Print the x that gives the maximum sum.
//
// Solve:
// Try every possible x. If k = n / x, then the multiples are x, 2x, ..., kx, and
// their sum is x * k * (k + 1) / 2. Keep the x with the largest value.
 
int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int x; int val_max = 0;
		for (int i = 2; i <= n; i++)
		{
			int k = (int)(n / i);
			int val = (k * (k + 1) / 2) * i;
			if (val > val_max) {
				x = i;
				val_max = val;
			}
 		}
		cout << x << endl;
	}
	return 0;
}
