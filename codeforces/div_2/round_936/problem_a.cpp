#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Problem: Codeforces Round 936 (Div. 2), A - Median of an Array
// Link: https://codeforces.com/contest/1946/problem/A
//
// Summary:
// For each test case, an array of n integers is given. For this problem, the
// median is the element at index (n - 1) / 2 after sorting the array in
// non-decreasing order.
// In one operation, any single element can be increased by 1. The goal is to
// find the minimum number of operations needed to make the array median
// strictly larger than its initial value.
//
// Solve:
// Use nth_element to place the median in the same position it would have after
// sorting. To increase the median, every value equal to it from the median
// position to the right must be increased at least once. The answer is how many
// of those median values appear in the array.

int main() {
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		vector<int> array_n(n);
		for (int i = 0; i < n; i++)
		{
			cin >> array_n[i];
		}

		int middle = (n - 1) / 2;
		nth_element(array_n.begin(), array_n.begin() + middle, array_n.end());

		int median = array_n[middle];
		int sol = 0;
		for (int i = middle; i < n; i++)
		{
			if (array_n[i] == median) sol++;
		}

		cout << sol << endl;
	}
	return 0;
}
