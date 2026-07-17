#include <iostream>
#include <vector>
using namespace std;
 
vector<int> counting_sort(vector<int>& vect, int max) {
	// iniciando desde el 0 hasta max (inclusivo)
	vector<int> vect_counting((max + 1), 0); int n = vect.size();
	vector<int> vect_return(n);
	for (int i = 0; i < n; i++)
	{
		vect_counting[vect[i]]++;
	}
	for (int i = 0; i < max; i++)
	{
		vect_counting[i + 1] += vect_counting[i];
	}
	for (int i = 0; i < n; i++)
	{
		vect_counting[vect[i]]--;
		vect_return[vect_counting[vect[i]]] = vect[i];
	}
	return vect_return;
}
 
int find_max(vector<int>& vect) {
	int max = vect[0];
	int n = vect.size();
	for (int i = 1; i < n; i++)
	{
		if (vect[i] > max) max = vect[i];
	}
	return max;
}
 
void show(vector<int> vect) {
	int n = vect.size();
	for (int i = 0; i < n; i++)
	{
		cout << vect[i] << " ";
	}
	cout << endl;
}
 
int main() {
	int t; cin >> t;
	while (t--) {
		// Greedy problem: remove the pair with higher/lower value among 3 2, 2 3, 2 2.
		// There is no difference because the operation only ends up removing the 2.
		// Similar reasoning for turtle and piggy:
		// turtle -> removes minimums by selecting a pair containing the minimum.
		// piggy -> removes maximums by selecting a pair containing the maximum.
		// If the array is sorted from low to high, removals become:
		// minimum, maximum, minimum, maximum, and so on.
		// In the end only the median remains. If the size is even, it is the right-middle element.
		// Algoritmo de ordenamiento, radix sort
		int n; cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		int a_max = find_max(a);
		vector<int> a_sort = counting_sort(a, a_max);
		int pot = (a_sort.size() / 2);
		cout << a_sort[pot] << endl;
	}
	return 0;
}
