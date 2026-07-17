#include <iostream>
using namespace std;

// Problem: Codeforces Round 969 (Div. 2), A - Dora's Set
// Link: https://codeforces.com/contest/2007/problem/A
//
// Summary:
// For each test case, given l and r, choose as many disjoint triples as possible
// from the integers in [l, r]. Each triple must contain three numbers that are
// pairwise coprime.
//
// Solve:
// Every three consecutive numbers in the form odd, even, odd are pairwise
// coprime. If a common divisor k greater than 1 divided two of those numbers,
// their difference would also have to be divisible by k. Consecutive values
// differ by 1, and the two odd values differ by 2, so no such k exists. The
// solution counts how many odd numbers are in [l, r]; each valid triple uses
// two odd numbers, so the answer is odd_count / 2.
 
 
int main() {
	int t; cin >> t;
	while (t--) {
		int l; cin >> l; int r; cin >> r;
		if (r % 2 == 0) r--;
		if (l % 2 == 0) l++;
		int impares = 1 + ((r - l) / 2);
		cout << (int)(impares / 2) << endl;
	}
	return 0;
}
