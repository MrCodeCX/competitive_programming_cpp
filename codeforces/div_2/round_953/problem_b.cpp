#include <iostream>
using namespace std;

// Problem: Codeforces Round 953 (Div. 2), B - New Bakery
// Link: https://codeforces.com/contest/1978/problem/B
//
// Summary:
// Bob sells n buns. Normally each bun costs a coins, but he may choose k buns
// for a promotion, where the first promoted bun costs b, the next b - 1, and so
// on. The remaining buns are sold at the normal price a. The goal is to maximize
// the total profit.
//
// Solve:
// Start from selling every bun at the normal price a. A promoted bun is useful
// only while its promoted price is greater than a, so the number (k) of useful
// promoted buns is min(n, b - a). Add the extra profit from those promoted buns:
// (b - a) + (b - a - 1) + ... (b - a - (b - a - 1)) = k * (b - a) - k * (k - 1) / 2
 
int main() {
	int t; cin >> t;
	while (t--) {
		int n; int a; int b;
		cin >> n >> a >> b;

		int k = min(n, max(0, b - a));
		long long sol = 1LL * n * a + 1LL * k * (b - a) - 1LL * k * (k - 1) / 2;
		cout << sol << endl;
	}
	return 0;
}
