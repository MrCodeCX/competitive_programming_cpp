#include <iostream>
using namespace std;

// Problem: Codeforces Round 944 (Div. 4), B - Different String
// Link: https://codeforces.com/contest/1971/problem/B
//
// Summary:
// Given a string, rearrange its characters to produce a different string. If no
// different rearrangement exists, print NO.
//
// Solve:
// If every character is equal, no rearrangement can change the string. Otherwise,
// find two adjacent different characters and swap them; this guarantees the new
// string differs from the original.
 
int main() {
	int t; cin >> t;
	while (t--)
	{
		string cadena; cin >> cadena;
		bool value = false; size_t pot_change;
		for (size_t i = 1; i < cadena.length(); i++)
		{
			if (cadena[i - 1] != cadena[i]) {
				value = true; pot_change = i;
				break;
			}
		}
		if (value) {
			cout << "YES" << endl;
			char cambio = cadena[pot_change];
			cadena[pot_change] = cadena[pot_change-1];
			cadena[pot_change - 1] = cambio;
			cout << cadena << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	return 0;
}
