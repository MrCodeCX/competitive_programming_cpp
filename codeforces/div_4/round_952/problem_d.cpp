#include <iostream>
using namespace std;

// Problem: Codeforces Round 952 (Div. 4), D - Manhattan Circle
// Link: https://codeforces.com/contest/1985/problem/D
//
// Summary:
// Given a grid containing a Manhattan circle drawn with '#', find the coordinates
// of the circle center.
//
// Solve:
// Scan the grid until the first '#'. That position is on the top of the vertical
// diameter. Continue downward in the same column while cells are '#'; the center
// is halfway along that vertical segment.
 
int n; int m;
char traduct(string& cadena, int x, int y) {
	return cadena[(y - 1) * m + (x - 1)];
}
 
int main() {
	int t; cin >> t;
	while (t--) {
		cin >> n; cin >> m;
		string s;
		for (int i = 0; i < n; i++)
		{
			string s_aux; cin >> s_aux;
			s = s + s_aux;
		}
		int x = -1; int y = -1;
		bool val_for = false;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				int counter = 0;
				if (traduct(s, j, i) == '#') {
					for (int i_aux = (i + 1); i_aux <= n; i_aux++)
					{
						if (traduct(s, j, i_aux) == '#') counter++;
						else break;
					}
					x = j; y = i + (counter / 2);
					val_for = true;
					break;
				}
			}
			if (val_for) break;
		}
		cout << y << " " << x << endl;
	}
	return 0;
}
