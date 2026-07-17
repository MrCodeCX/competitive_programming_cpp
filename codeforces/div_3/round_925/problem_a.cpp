#include <iostream>
using namespace std;

// Problem: Codeforces Round 925 (Div. 3), A - Recovering a Small String
// Link: https://codeforces.com/contest/1931/problem/A
//
// Summary:
// For each test case, an integer n is given. It represents the sum of the
// positions of three lowercase letters, where 'a' is 1 and 'z' is 26. The task
// is to print the lexicographically smallest three-letter string with that sum.
//
// Solve:
// To minimize the string lexicographically, keep the earliest letters as small
// as possible and place as much value as possible on the right. This solution
// fills the answer from the last position to the first, taking up to 26 each
// time while leaving the remaining positions with at least 1.
 
int main(void) {
	int array_n[100] = { 0 };
	char array_string[3];
	int t;  cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> array_n[i];
	}
	for (int i = 0; i < t; i++)
	{
		for (int j = 2; j > -1; j--)
		{
			int n_aux = (array_n[i] - j);
			if (n_aux > 26) n_aux = 26;
			array_string[j] = (char)(n_aux + 96);
			array_n[i] -= n_aux;
		}
		cout << array_string[0] << array_string[1] << array_string[2] << endl;
	}
	return 0;
}
