#include <iostream>
using namespace std;

// Problem: Codeforces Round 952 (Div. 4), C - Good Prefixes
// Link: https://codeforces.com/contest/1985/problem/C
//
// Summary:
// Given an array, count how many prefixes are good. A prefix is good if one of
// its elements is equal to the sum of all the other elements in that prefix.
//
// Solve:
// For a prefix with total sum S, the condition is equivalent to having an
// element equal to S / 2. Therefore, only the maximum element in the prefix can
// be a candidate. Track the prefix sum and the current maximum; a prefix is good
// when 2 * current_max == prefix_sum.
 
long long array_a[200005];
int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> array_a[i];
		}
		for (int i = 1; i < n; i++)
		{
			array_a[i] += array_a[i-1];
		}
		int cant_i = 0;
		if (array_a[0] == 0) cant_i++;
		int candidato_ant = array_a[0];
		for (int i = 1; i < n; i++)
		{
			long long sum = array_a[i];
			long long candidato_new = (array_a[i] - array_a[i - 1]);
			if (2 * candidato_ant == sum) cant_i++;
			else if(2 * candidato_new == sum) cant_i++; 
			if (candidato_new > candidato_ant) candidato_ant = candidato_new;
		}
		cout << cant_i << endl;
	}
	return 0;
}
