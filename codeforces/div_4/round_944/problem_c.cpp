#include <iostream>
using namespace std;

// Problem: Codeforces Round 944 (Div. 4), C - Clock and Strings
// Link: https://codeforces.com/contest/1971/problem/C
//
// Summary:
// Four numbers a, b, c, and d are positions on a clock. Determine whether the
// chords between a-b and c-d intersect.
//
// Solve:
// Put a and b in increasing order. The chords intersect exactly when one of c
// and d lies strictly inside the interval (a, b), and the other lies outside it.
 
int main() {
	int t; cin >> t;
	while (t--)
	{
		int a; cin >> a; int b; cin >> b;
		int c; cin >> c; int d; cin >> d;
		if (a > b) {
			int aux = b; b = a; a = aux;
		}
		bool range_c = (c < b) && (c > a);
		bool range_d = (d < b) && (d > a);
		if (range_c == range_d) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	return 0;
}
