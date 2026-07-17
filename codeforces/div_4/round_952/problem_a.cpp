#include <iostream>
using namespace std;

// Problem: Codeforces Round 952 (Div. 4), A - Creating Words
// Link: https://codeforces.com/contest/1985/problem/A
//
// Summary:
// Given two three-letter words, swap their first characters and print the
// resulting words.
//
// Solve:
// Store the first character of the first word, replace it with the first
// character of the second word, then place the stored character in the second
// word.
 
int main() {
	int t; cin >> t;
	while (t--) {
		string a; cin >> a; string b; cin >> b;
		char aux = a[0];
		a[0] = b[0];
		b[0] = aux;
		cout << a << " " << b << endl;
	}
	return 0;
}
