#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// If the array is sorted, the problem is solved.
// Due to the range of the numbers, these approaches are possible:
// radix_sort with O(n) complexity
// algorithm sort with O(n*ln(n)) complexity

// Once the array is sorted and k > 0,
// it is enough to know that the k-th number is smaller than the next one; then that same number works.
// n_array[0] ... <= n_array[k-1], so if n_array[k] > n_array[k-1]
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
