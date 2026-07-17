#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

// Problem: Codeforces Round 951 (Div. 2), C - Earning on Bets
// Link: https://codeforces.com/contest/1979/problem/C
//
// Summary:
// For each test case, there are n possible betting outcomes. If outcome i wins,
// every coin placed on it is multiplied by k[i]. We need choose a positive
// number of coins for each outcome so that, no matter which outcome wins, the
// payout is strictly greater than the total number of coins placed. If no valid
// distribution exists, print -1.
//
// Solve:
// Let total be the sum of all placed coins. For every outcome i, we need
// coins[i] * k[i] > total. A useful construction is to take the LCM of all k[i]
// and set coins[i] = LCM / k[i]. Then every possible payout is exactly LCM.
// This works only if the total number of placed coins is smaller than LCM,
// which is equivalent to sum(LCM / k[i]) < LCM.

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> array_k(n);
		for (int i = 0; i < n; i++)
		{
			cin >> array_k[i];
		}

		long long lcm_value = 1;
		for (int value : array_k)
		{
			lcm_value = lcm(lcm_value, (long long)value);
		}

		vector<int> array_coins(n);
		long long total = 0;
		for (int i = 0; i < n; i++)
		{
			array_coins[i] = (int)(lcm_value / array_k[i]);
			total += array_coins[i];
		}

		if (total >= lcm_value) cout << -1 << endl;
		else {
			for (int coin : array_coins)
			{
				cout << coin << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
