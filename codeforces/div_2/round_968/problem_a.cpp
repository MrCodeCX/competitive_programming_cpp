#include <iostream>
using namespace std;

// Problem: Codeforces Round 968 (Div. 2), A - Turtle and Good Strings
// Link: https://codeforces.com/contest/2003/problem/A
//
// Summary:
// For each test case, a string s is given. We need determine whether it can be
// split into at least two non-empty substrings t1, t2, ..., tk such that, for
// every i < j, the first character of ti is different from the last character
// of tj.
//
// Solve:
// The first substring always starts with s[0], and the last substring always
// ends with s[n - 1]. If those characters are equal, the required condition
// cannot be satisfied. If they are different, splitting into two substrings is
// enough, so the answer is YES.
 
int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		string s; cin >> s;
		if (s[0] != s[n - 1]) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0; 
}
