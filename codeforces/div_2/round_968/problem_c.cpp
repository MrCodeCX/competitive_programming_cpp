#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Problem: Codeforces Round 968 (Div. 2), C - Turtle and Good Pairs
// Link: https://codeforces.com/contest/2003/problem/C
//
// Summary:
// Given a lowercase string, reorder its characters to maximize the number of
// good pairs. A pair is good if both positions contain the same character, or if
// there is a valid split point between them that satisfies the pleasant-pair
// condition from the statement.
//
// Solve:
// Count how many times each character appears. Then repeatedly append one
// available occurrence of each character from 'a' to 'z'. This distributes equal
// characters across the string instead of placing all copies together, which
// maximizes the number of pairs that can become good.

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		string s; cin >> s;

		vector<int> array_counter(26, 0);
		for (char letter : s)
		{
			array_counter[letter - 'a']++;
		}

		string sol;
		while ((int)sol.size() < n)
		{
			for (int i = 0; i < 26; i++)
			{
				if (array_counter[i] > 0) {
					sol += (char)('a' + i);
					array_counter[i]--;
				}
			}
		}

		cout << sol << endl;
	}
	return 0;
}
