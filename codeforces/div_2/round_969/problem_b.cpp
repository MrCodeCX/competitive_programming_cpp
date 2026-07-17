#include <iostream>
#include <string>
using namespace std;

// Problem: Codeforces Round 969 (Div. 2), B - Index and Maximum Value
// Link: https://codeforces.com/contest/2007/problem/B
//
// Summary:
// Given an array and m operations, each operation either adds 1 or subtracts 1
// from every value inside a range [l, r]. After each operation, output the
// current maximum value of the array.
//
// Solve:
// Only the current maximum matters. If the maximum value is inside [l, r], the
// operation changes it by +1 or -1. If it is outside [l, r], the maximum does
// not change. If another value ever reaches or exceeds the old maximum after an
// operation, it must first pass through the same affected ranges, so tracking
// only the maximum is enough.
 
 
int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n; int m; cin >> m;
		int mayor = 0;
		for (int i = 0; i < n; i++)
		{
			int a; cin >> a;
			if (a > mayor) mayor = a;
		}
		string solve;
		for (int i = 0; i < m; i++)
		{
			char c; cin >> c; int l; cin >> l; int r; cin >> r;
			if (l <= mayor && mayor <= r) {
				if (c == '+') mayor++;
				else mayor--;
			}
			solve += to_string(mayor) + " ";
		}
		cout << solve << endl;
	}
	return 0;
}
