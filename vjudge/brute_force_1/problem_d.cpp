#include <iostream>
#include <vector>

using namespace std;

#define N_CYPHER 32

size_t get_cypher(size_t num) {
    return 32 - __builtin_clz(num);
}

int main() {
    // Order does not matter because the operation and condition are symmetric.
    // Only pairs with i < j are counted, so the number of pairs is n_i^2 / 2 instead of n_i^2.

    // For numbers with the same number of bits, the cases are:
    // Case a: 1xxxx 1yyyy, satisfies the operation.
    // Case b: 1xxxx 0yyyy, does not satisfy the operation.
    // Case c: 0xxxx 0yyyy, never considered because it is outside this bit-length range.
    // For the number 0, its bit-length would be treated as 0, although the problem does not ask for it.
    
    // The number of pairs is SUM (n_i^2)/2, where n_i is the number of values with i bits.

    size_t t; cin >> t;
    for (size_t iter_t = 0; iter_t < t; iter_t++)
    {
        size_t n; cin >> n;
        vector<size_t> counting_cypher_groups(N_CYPHER,0);
        for (size_t i = 0; i < n; i++)
        {
            size_t num; cin >> num;
            counting_cypher_groups[get_cypher(num)]++;
        }
        size_t solve = 0;
        for (size_t i = 0; i < N_CYPHER; i++)
        {
            solve += counting_cypher_groups[i] * (counting_cypher_groups[i]-1) / 2;
        }
        cout << solve << endl;
    }
    
    return 0;
}
