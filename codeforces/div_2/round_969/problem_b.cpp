#include <iostream>
#include <string>
using namespace std;
 
 
int main() {
	int t; cin >> t;
	while (t--) {
		// Only the maximum matters.
		// Going forward, if another value ever exceeds the maximum, it must first become equal to it;
		// from that moment, the original maximum and the new value follow the same trajectory and values.
		// Going backward, it never stops being the maximum. If it decreases until meeting another number
		// and then decreases further, the other number also decreases, so both follow the same trajectory and values.
		int n; cin >> n; int m; cin >> m;
		int mayor = 0;
		for (int i = 0; i < n; i++)
		{
			int a; cin >> a;
			if (a > mayor) mayor = a;
		}
		string solve;
		for (int i = 0; i < m; i++)
		{
			// Operaciones
			char c; cin >> c; int l; cin >> l; int r; cin >> r;
			if (l <= mayor && mayor <= r) {
				if (c == '+') mayor++;
				else mayor--;
			}
			solve += to_string(mayor) + " ";
		}
		cout << solve << endl;
	}
	return 0;
}
