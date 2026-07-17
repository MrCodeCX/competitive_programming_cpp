#include <iostream>
using namespace std;

// Problem: Codeforces Round 946 (Div. 3), A - Phone Desktop
// Link: https://codeforces.com/contest/1974/problem/A
//
// Summary:
// Each phone screen is a 5 by 3 grid. A 1x1 icon uses one cell, and a 2x2 icon
// uses four cells. For each test case, given x small icons and y large icons,
// find the minimum number of screens needed to place all icons.
//
// Solve:
// Each screen can fit at most two 2x2 icons, so first reserve ceil(y / 2)
// screens for the large icons. Those screens may still have free 1x1 cells.
// After placing as many small icons as possible there, any remaining small icons
// need extra screens, each with 15 cells.

int main() {
	int t; cin >> t;
	while (t--) {
		int x; cin >> x; int y; cin >> y;
		int screen = (y + 1) / 2;
		int res_1 = (screen * 15) - y * 4;
		int res_2 = x - res_1;
		if (res_2 > 0) {
			screen += (res_2 + 14) / 15;
		}
		cout << screen << endl;
	}
	return 0;
}
