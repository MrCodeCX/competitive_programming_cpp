#include <iostream>
#include <string>
using namespace std;

// Problem: Codeforces Global Round 26, B - Large Addition
// Link: https://codeforces.com/contest/1984/problem/B
//
// Summary:
// Determine whether x can be written as the sum of two large positive integers,
// where a large integer has no zero digits.
//
// Solve:
// For large numbers added digit by digit, the inner digits must be produced with
// an incoming carry. That makes digit 0 impossible in the middle, while the
// first digit must be 1 and the last digit cannot be 9. The lower bound with the
// same digit count is 111...110, and every middle digit must be non-zero.
 
int array_a[55] = { 0 };
int main() {
	int t; cin >> t;
	while (t--) {
		long long x; cin >> x;
		string s = to_string(x);
		long long cota = 0;
		long long p = 1;
		for (size_t i = 1; i < s.size(); i++)
		{
			p *= 10;
			cota += p;
		}
		
		if (s[0] == '1' && s[s.size() - 1] != '9' && x >= cota) {
			bool value_find = true;
			for (size_t i = 1; i < (s.size() - 1); i++)
			{
				if (s[i] == '0') {
					value_find = false;
					break;
				}
			}
			if (value_find) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
		else cout << "NO" << endl;
	}
	return 0;
}
