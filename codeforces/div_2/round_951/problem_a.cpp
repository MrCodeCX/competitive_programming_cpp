#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Problem: Codeforces Round 951 (Div. 2), A - Guess the Maximum
// Link: https://codeforces.com/contest/1979/problem/A
//
// Summary:
// For each test case, an array is given. We need choose an integer k such that
// every subarray with length at least 2 has a maximum value greater than k. The
// goal is to find the maximum possible k.
//
// Solve:
// Any subarray with length at least 2 contains at least one adjacent pair.
// Therefore, the limiting case is the adjacent pair with the smallest maximum.
// If min_pair_max is the minimum value among max(a[i], a[i + 1]), then k must
// be strictly smaller than that value. So the answer is min_pair_max - 1.
 
int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> array_n(n);
		for (int i = 0; i < n; i++)
		{
			cin >> array_n[i];
		}
		int min_pair_max = max(array_n[0], array_n[1]);
		for (int i = 1; i < (n-1); i++)
		{
			int pair_max = max(array_n[i], array_n[i + 1]);
			if (pair_max < min_pair_max) min_pair_max = pair_max;
		}
		cout << (min_pair_max - 1) << endl;
	}
	return 0;
}
