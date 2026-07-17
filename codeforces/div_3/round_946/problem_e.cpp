#include <iostream>
#include <vector>
using namespace std;
 
#define ll long long
const ll NP = 1000000000000;

// Problem: Codeforces Round 946 (Div. 3), E - Money Buys Happiness
// Link: https://codeforces.com/contest/1974/problem/E
//
// Summary:
// Over m months, each month offers one item with cost c[i] and happiness h[i].
// You earn x money per month over time, and an item can only be bought if the
// money available before that month is enough. The goal is to maximize total
// happiness.
//
// Solve:
// Use dynamic programming by happiness. dp[h] stores the minimum total money
// needed to reach happiness h after processing some months. For each month,
// either skip the item or buy it if the new total cost does not exceed the money
// available by that month. The largest happiness with finite cost is the answer.
 
int main() {
	int t; cin >> t;
	while (t--) {
		int m; cin >> m; ll x; cin >> x;
		vector<ll> c; vector <ll> h;
		c.resize(m); h.resize(m);
		ll h_max = 0;
		for (int i = 0; i < m; i++)
		{
			cin >> c[i]; cin >> h[i];
			h_max += h[i];
		}
		vector<ll> dp = vector<ll>((h_max + 1), NP);
		dp[0] = 0;
		for (int i = 0; i < m; i++)
		{
			vector<ll> ndp = dp;
			for (int j = 0; j <= h_max; j++)
			{
				if (dp[j] == NP) continue;
				ll new_h = j + h[i];
				ll new_cost = dp[j] + c[i];
				if (new_cost <= (i * x) && new_cost < dp[new_h]) ndp[new_h] = new_cost;
			}
			dp = ndp;
		}
		for (int i = (dp.size()-1); i >= 0; i--)
		{
			if(dp[i] != NP ) { 
				cout << i << endl;
				break;
			}
		}
	}
	return 0;
}
