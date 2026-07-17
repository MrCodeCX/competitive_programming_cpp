#include <algorithm>
#include <cstdlib>
#include <iostream>
using namespace std;

// Problem: Codeforces Global Round 26, C1 - Magnitude (Easy Version)
// Link: https://codeforces.com/contest/1984/problem/C1
//
// Summary:
// Process the array from left to right. At each step, add the current value to
// the current result, then choose whether to keep it as is or replace it with
// its absolute value. Find the maximum final value.
//
// Solve:
// Only two reachable states matter after each position: the maximum value that
// can be made non-negative through absolute value, and the minimum raw value
// that may later become useful. Update both states from the previous positive
// and negative candidates.
 
long long array_a[200005];
long long vect_positive[200005];
long long vect_negative[200005];
 
int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> array_a[i];
		}
		vect_positive[0] = abs(array_a[0]);
		vect_negative[0] = array_a[0];
		for (int i = 1; i < n; i++)
		{
			vect_positive[i] = max(abs(array_a[i] + vect_positive[i - 1]), abs(array_a[i] + vect_negative[i - 1]));
			vect_negative[i] = min((array_a[i] + vect_positive[i - 1]), (array_a[i] + vect_negative[i - 1]));
		}
		cout << vect_positive[n - 1] << endl;
	}
	return 0;
}
