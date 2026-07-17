#include <iostream>
using namespace std;

// Problem: Codeforces Global Round 26, A - Strange Splitting
// Link: https://codeforces.com/contest/1984/problem/A
//
// Summary:
// Given an array, color each element red or blue so that both colors are used
// and the difference between the maximum and minimum red values is different
// from the difference between the maximum and minimum blue values. If this is
// impossible, print NO.
//
// Solve:
// If every value is equal, both color groups will have range 0, so it is
// impossible. Otherwise, with at least one different value, color one suitable
// position red and the rest blue; this makes one group's range different from
// the other's.
 
int array_a[55] = { 0 };
int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> array_a[i];
		}
		int counter_1 = 1;
		int counter_2 = 0;
		int ref = array_a[0];
		int pot = -1;
		for (int i = 1; i < n; i++)
		{
			if (array_a[i] != ref) counter_2++;
			else counter_1++;
			if (counter_2 >= 2) {
				pot = i;
				break;
			}
			else if (counter_2 == 1 && counter_1 >= 2) {
				pot = 0;
				break;
			}
		}
		if (pot != -1) {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++)
			{
				if (i == pot) cout << "R";
				else cout << "B";
			}
			cout << endl;
		}
		else cout << "NO" << endl;
	}
	return 0;
}
