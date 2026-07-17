#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Problem: Codeforces Round 953 (Div. 2), D - Elections
// Link: https://codeforces.com/contest/1978/problem/D
//
// Summary:
// There are n election candidates and c undecided votes. Candidate 0 receives
// all undecided votes among the remaining candidates. For each candidate i, find
// the minimum number of other candidates that must be removed so that candidate
// i becomes a winner.
//
// Solve:
// If every candidate before i is removed, candidate i becomes the first
// remaining candidate and receives all undecided votes plus the votes of those
// removed candidates. That value is prefix_sum[i] + c. If it is at least the
// maximum vote count on the right, removing the i previous candidates is enough.
// Otherwise, one more removal is needed for the strongest candidate on the
// right. The only exception is a candidate that already wins without removing
// anyone, whose answer is 0.

int main() {
	int t; cin >> t;
	while (t--) {
		int n; long long c;
		cin >> n >> c;

		vector<int> array_n(n);
		for (int i = 0; i < n; i++)
		{
			cin >> array_n[i];
		}

		vector<long long> array_prefix(n);
		array_prefix[0] = array_n[0];
		for (int i = 1; i < n; i++)
		{
			array_prefix[i] = array_prefix[i - 1] + array_n[i];
		}

		vector<int> array_right_max(n);
		array_right_max[n - 1] = 0;
		for (int i = n - 2; i >= 0; i--)
		{
			array_right_max[i] = max(array_n[i + 1], array_right_max[i + 1]);
		}

		long long initial_max = max(array_n[0] + c, (long long)array_right_max[0]);
		bool found_initial_winner = false;

		for (int i = 0; i < n; i++)
		{
			int sol;
			if (!found_initial_winner && array_n[i] + (i == 0 ? c : 0) >= initial_max) {
				sol = 0;
				found_initial_winner = true;
			}
			else if (array_prefix[i] + c >= array_right_max[i]) sol = i;
			else sol = i + 1;

			cout << sol << " ";
		}
		cout << endl;
	}
	return 0;
}
