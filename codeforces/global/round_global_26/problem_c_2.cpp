#include <algorithm>
#include <cstdlib>
#include <iostream>
using namespace std;

// Problem: Codeforces Global Round 26, C2 - Magnitude (Hard Version)
// Link: https://codeforces.com/contest/1984/problem/C2
//
// Summary:
// Process the array from left to right. At each step, add the current value to
// the current result, then choose whether to keep it as is or replace it with
// its absolute value. Count how many ways produce the maximum final value,
// modulo 998244353.
//
// Solve:
// Track the best positive state and the best negative state after each prefix,
// together with the number of ways to reach each one. Each new value can be
// applied to both states. If applying absolute value produces the same best
// value from both sides, add their counts, avoiding double-counting when both
// previous states were actually the same value.
 
long long array_a[200005];
long long vect_positive[200005];
long long vect_negative[200005];
bool posi(long long num) {
	if (num >= 0) return true;
	return false;
}
 
int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> array_a[i];
		}
		vect_positive[0] = abs(array_a[0]);
		vect_negative[0] = array_a[0];
		long long counter_positive = 1;
		long long counter_negative = 1;
		if (posi(array_a[0])) {
			counter_positive *= 2;
			counter_negative *= 2;
		}
		for (int i = 1; i < n; i++){
			long long counter_positive_aux = counter_positive;
			long long counter_negative_aux = counter_negative;
			long long p_p = array_a[i] + vect_positive[i - 1];
			long long p_n = array_a[i] + vect_negative[i - 1];
			vect_positive[i] = max(abs(p_p), abs(p_n));
			if (abs(p_p) > abs(p_n)) {
				if (posi(p_p)) counter_positive = (counter_positive_aux * 2);
				else counter_positive = counter_positive_aux;
			}
			else if (abs(p_n) > abs(p_p)) {
				if (posi(p_n)) counter_positive = (counter_negative_aux * 2);
				else counter_positive = counter_negative_aux;
			}
			else if (abs(p_n) == abs(p_p)) {
				long long sum = 0;
				if (posi(p_p)) sum += (counter_positive_aux * 2);
				else sum += counter_positive_aux;
				if (posi(p_n)) sum += (counter_negative_aux * 2);
				else sum += counter_negative_aux;
				counter_positive = sum;
				if (vect_positive[i - 1] == vect_negative[i - 1]) counter_positive = counter_positive / 2;
			}
			long long n_p = array_a[i] + vect_positive[i - 1];
			long long n_n = array_a[i] + vect_negative[i - 1];
			vect_negative[i] = min(n_p, n_n);
			if (n_p < n_n) {
				if (posi(n_p)) counter_negative = (counter_positive_aux * 2);
				else counter_negative = counter_positive_aux;
			}
			else if (n_n < n_p) {
				if (posi(n_n)) counter_negative = (counter_negative_aux * 2);
				else counter_negative = counter_negative_aux;
			}
			else if (n_p == n_n) {
				long long sum = 0;
				if (posi(n_p)) sum += (counter_positive_aux * 2);
				else sum += counter_positive_aux;
				if (posi(n_n)) sum += (counter_negative_aux * 2);
				else sum += counter_negative_aux;
				counter_negative = sum;
				if (vect_positive[i - 1] == vect_negative[i - 1]) counter_negative = counter_negative / 2;
			}
			if (counter_positive >= 998244353) counter_positive = counter_positive % 998244353;
			if (counter_negative >= 998244353) counter_negative = counter_negative % 998244353;
		}
		cout << counter_positive << endl;
	}
	return 0;
}
