#include <iostream>
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
// Sort the array and locate the current median. To make the median increase,
// every occurrence equal to the median from the median position to the right
// must be increased at least once; otherwise, one of those equal values would
// still occupy the median position after sorting. Therefore, the answer is the
// size of that equal-value block. This implementation sorts with radix sort and
// then counts that block.
 
using ll = long long;
const int N = 100050;
int n;
// DATA
int array_ordenado[N] = { 0 };
int array_pseudo_ordenado[N] = { 0 };
int array_digits[N] = { 0 };
// SOLVES
int array_sol[10050] = { 0 };
int find_grade() {
	int max = array_ordenado[0];
	for (int i = 1; i < n; i++)
	{
		if (array_ordenado[i] > max) max = array_ordenado[i];
	}
	int count = 0;
	while (max) {
		max /= 10;
		count++;
	}
	return count;
}
void radix_sort(int grade) {
	// For digits 0, 1, ..., 9.
	int grade_aux = 0;
	ll pow_1 = 1; ll pow_2 = 10;
	while (grade_aux < grade)
	{
		int array_counter[10] = { 0 };
		for (int i = 0; i < n; i++)
		{
			int digit = ((array_ordenado[i] % pow_2) / pow_1);
			array_digits[i] = digit;
			array_counter[digit]++;
		}
		for (int i = 1; i < 10; i++) { array_counter[i] += array_counter[i - 1]; }
		for (int i = (n - 1); i > -1; i--)
		{
			array_counter[array_digits[i]]--;
			array_pseudo_ordenado[array_counter[array_digits[i]]] = array_ordenado[i];
		}
		for (int i = 0; i < n; i++) { array_ordenado[i] = array_pseudo_ordenado[i]; }
		pow_1 = pow_2; pow_2 *= 10;
		grade_aux++;
	}
}
void solve(int j) {
	int middle = (n - 1) / 2;
	int media = array_ordenado[middle];
	if (array_ordenado[middle + 1] != media) {
		array_sol[j] = 1;
	}
	else {
		int counter = 1;
		for (int i = (middle + 1); i < n; i++)
		{
			if (array_ordenado[i] == media) counter++;
			else break;
		}
		array_sol[j] = counter;
	}
}
void show_array() {
	for (int i = 0; i < n; i++)
	{
		cout << array_ordenado[i] << " ";
	}
	cout << endl;
}
 
int main() {
	int t; cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		for (int j = 0; j < n; j++) { cin >> array_ordenado[j]; }
		if (n == 1) array_sol[i] = 1;
		else if (n == 2) {
			if (array_ordenado[1] == array_ordenado[0]) array_sol[i] = 2;
			else array_sol[i] = 1;
		}
		else {
			radix_sort(find_grade());
			solve(i);
		}
	}
	for (int i = 0; i < t; i++)
	{
		cout << array_sol[i] << endl;
	}
	return 0;
}
