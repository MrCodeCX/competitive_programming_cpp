#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Problem: Codeforces Round 968 (Div. 2), B - Turtle and Piggy Are Playing a Game 2
// Link: https://codeforces.com/contest/2003/problem/B
//
// Summary:
// Turtle and Piggy play on an array. On Turtle's turns, one element is replaced
// by the minimum of two chosen elements. On Piggy's turns, one element is
// replaced by the maximum of two chosen elements. Both play optimally, and the
// goal is to determine the final remaining value.
//
// Solve:
// Turtle can remove the current minimum by choosing a pair that contains it,
// because the minimum remains and the other value disappears. Piggy can remove
// the current maximum in the symmetric way by choosing a pair that contains it.
// If the array is sorted, the removals become minimum, maximum, minimum,
// maximum, and so on. Therefore, the final value is the middle value of the
// sorted array; for even n, it is the right-middle element.

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> array_n(n);
		for (int i = 0; i < n; i++)
		{
			cin >> array_n[i];
		}

		sort(array_n.begin(), array_n.end());
		cout << array_n[n / 2] << endl;
	}
	return 0;
}
