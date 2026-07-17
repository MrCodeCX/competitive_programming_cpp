#include <iostream>
using namespace std;
 
int n; long long c;
long long array_a[200005];
long long array_a_f[200005];
long long array_mayorDerecho[200005];
long long max_(long long a, long long b) {
	if (a > b) return a;
	return b;
}
void start() {
	for (int i = 0; i < n; i++)
	{
		cin >> array_a[i];
		array_a_f[i] = array_a[i];
	}
	// Array Mayor Derecho
	array_mayorDerecho[n - 1] = 0;
	for (int i = (n - 2); i >= 0; i--)
	{
		array_mayorDerecho[i] = max_(array_a[i+1], array_mayorDerecho[i + 1]);
	}
	// Array en Forma Acumulada   
	for (int i = 1; i < n; i++)
	{
		array_a_f[i] += array_a_f[i - 1];
	}
}
 
int main() {
	// Ways for a candidate to win:
	// If it is not the one with the most votes, remove all candidates before it so undecided votes are added to it.
	// If it is still not the largest after that, remove the maximum on the right and it will become the largest.
	int t; cin >> t;
	while (t--) {
		cin >> n; cin >> c;
		start();
		bool value_first = true;
		long long max_1 = array_mayorDerecho[0];
		long long max_2 = array_a[0] + c;
		for (int i = 0; i < n; i++)
		{
			if (max_1 > max_2) {
				if (array_a[i] >= max_1 && value_first) {
					cout << 0 << " ";
					value_first = false;
				}
				else {
					// Eliminar Izquierda y Tomar Acumulado + c;
					long long val = (array_a_f[i] + c);
					if (val >= array_mayorDerecho[i]) cout << i << " ";
					else cout << i + 1 << " ";
				}
			}
			else {
				// Eliminar Izquierda y Tomar Acumulado + c;
				long long val = (array_a_f[i] + c);
				if (val >= array_mayorDerecho[i]) cout << i << " ";
				else cout << i + 1 << " ";
			}
		}
		cout << endl;
	}
	return 0;
}
