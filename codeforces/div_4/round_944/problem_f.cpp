#include <iostream>
#include <cmath>
 
using namespace std;

// Problem: Codeforces Round 944 (Div. 4), F - Circle Perimeter
// Link: https://codeforces.com/contest/1971/problem/F
//
// Summary:
// Given r, count integer points whose distance from the origin is at least r and
// strictly less than r + 1.
//
// Solve:
// Count points in one quadrant and multiply by 4. For each positive x, compute
// the vertical range between the circle of radius r and the circle of radius
// r + 1. The number of integer y values in that range is the difference between
// the ceilings of both boundaries.
int tope(double c) {
	if ((int)c == c) return c;
	else return c + 1;
	return 0;
}
int main() {
	int t; cin >> t;
	while (t--)
	{
		int r; cin >> r;
		int sum = 0;
		for (int i = 1; i <= r; i++)
		{
			double y_1 = sqrt(pow(r, 2) - pow(i, 2));
			double y_2 = sqrt(pow((r + 1), 2) - pow(i, 2));
			sum += tope(y_2) - tope(y_1);
		}
		sum = sum * 4;
		cout << sum << endl;
	}
	return 0;
}
