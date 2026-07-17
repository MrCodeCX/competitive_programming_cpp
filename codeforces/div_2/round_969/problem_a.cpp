#include <iostream>
using namespace std;
 
 
int main() {
	int t; cin >> t;
	while (t--) {
		// todos los consecutivos de a 3 son pesi entre si, siempre cuando sea impar par impar
		// Notice that if there is a k (!= 1) such that a // k, b // k, c // k, and a < b < c,
		// then a + k <= b. But if they are consecutive, b = a + 1, so this is impossible.
		// Also a + k <= c, but c = a + 2 when consecutive. If k is not 2, it is impossible;
		// k is not 2 because there are two odd numbers and only one even number.
		int l; cin >> l; int r; cin >> r;
		// Answer: number of operations = number of odd values divided by 2.
		if (r % 2 == 0) r--;
		if (l % 2 == 0) l++;
		// 2 3 4 5 6 7 8 9 10 se transforma a
		// 3 4 5 6 7 8 9, from this form odd values can be derived as 1 + ((r - l) / 2).
		int impares = 1 + ((r - l) / 2);
		cout << (int)(impares / 2) << endl;
	}
	return 0;
}
