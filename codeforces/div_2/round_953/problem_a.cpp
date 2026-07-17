#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Problem: Codeforces Round 953 (Div. 2), A - Alice and Books
// Link: https://codeforces.com/contest/1978/problem/A
//
// Summary:
// For each test case, an array of n book values is given. We must split the
// array into two non-empty consecutive parts and maximize the sum of the last
// value of each part.
//
// Solve:
// The last value of the second part is always a[n - 1]. To maximize the answer,
// choose the split so that the last value of the first part is the maximum value
// among a[0], a[1], ..., a[n - 2]. Therefore, the answer is a[n - 1] plus the
// maximum value before it.
 
int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> array_n(n);
		for (int i = 0; i < n; i++)
		{
			cin >> array_n[i];
		}
		int sol = array_n[n - 1] + *max_element(array_n.begin(), array_n.end() - 1);
		cout << sol << endl;
	}
	return 0;
}
