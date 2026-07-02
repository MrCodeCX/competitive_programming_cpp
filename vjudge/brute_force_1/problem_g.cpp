#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Si se ordena el array el problema queda resuelto
// Debido al rango de sus numeros se puede aplicar 
// radix_sort con complejidad O(n)
// algorithm sort con complejidad O(n*ln(n))

// Una vez ordenado el array para k > 0, 
// basta saber que el numero k-esimo sea menor que el que le sigue, entonces ese mismo numero cumple
// n_array[0] ... <= n_array[k-1], entonces si n_array[k] > n_array[k-1]
// n_array[0] ... n_array[k-1] <= n_array[k-1]

int main() {
    size_t n; size_t k; cin >> n; cin >> k;
    vector<size_t> n_array(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> n_array[i];
    }
    sort(n_array.begin(), n_array.end());
    int solve = -1;
    if(k == 0 && n_array[0] > 1) solve = 1;
    else if (k == n || n_array[k] > n_array[k-1]) solve = n_array[k-1];
    
    cout << solve << endl;

    return 0;
}