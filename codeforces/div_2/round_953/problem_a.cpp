#include <iostream>
using namespace std;
 
int main() {
	int t; cin >> t;
	while (t--) {
		// The last element will always go into one pile and win there, so secure the other one.
		int n; cin >> n;
		int max = 0;
		for (int i = 0; i < (n-1); i++)
		{
			int a; cin >> a;
			if (a > max) {
				max = a;
			}
		}
		int a; cin >> a;
		max += a;
		cout << max << endl;
	}
	return 0;
}
