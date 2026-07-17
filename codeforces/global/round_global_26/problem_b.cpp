#include <iostream>
#include <string>
using namespace std;
 
int array_a[55] = { 0 };
int main() {
	int t; cin >> t;
	while (t--) {
		// For large numbers xxx + yyy, each digit sum always carries 1 to the next digit:
		// 1000 + ((x + y + 1)%10) * 100 + ((x + y + 1)%10) * 10 + ((x + y)%10).
		// The first digit must be formable with (x1 + y1)%10; this is not possible for 9.
		// The second digit must be formable with ((x2 + y2 + 1)%10), which works for all digits
		// except 0, because (5 + 5 + 1) % 10 is 1; only the last digit can be 0.
		// Every digit can be formed with ((x2 + y2 + 1)%10) for large numbers
		// because (x1 + y1)%10 can form every digit except 8.
		// The carry (x + y + 1) // 10 is always 1, so each digit follows this formation rule.
		// Both large numbers must have the same number of digits; if one is 9xx and the other 0yy, it may fail.
		// For 1001 it does not hold.
		// Is a non-zero second digit necessary? 5555 5555
		// The minimum large number that works has the form 111111s0.
		long long x; cin >> x;
		string s = to_string(x);
		long long cota = 0;
		long long p = 1;
		for (int i = 1; i < s.size(); i++)
		{
			p *= 10;
			cota += p;
		}
		
		if (s[0] == '1' && s[s.size() - 1] != '9' && x >= cota) {
			bool value_find = true;
			for (int i = 1; i < (s.size() - 1); i++)
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
