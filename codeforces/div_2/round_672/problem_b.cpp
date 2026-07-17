#include <iostream>
#include <vector>

using namespace std;

#define N_CYPHER 32

size_t get_cypher(size_t num) {
    return 32 - __builtin_clz(num);
}

// Problem: Codeforces Round 672 (Div. 2), B - Rock and Lever
// Link: https://codeforces.com/contest/1420/problem/B
//
// Summary:
// Count pairs of indices (i, j), i < j, such that a[i] & a[j] is greater than
// or equal to a[i] xor a[j].
//
// Solve:
// Numbers satisfy the condition exactly when they have the same most significant
// bit. Count how many numbers belong to each bit-length group, then add
// count * (count - 1) / 2 for every group.
// Order does not matter because the operation and condition are symmetric. For
// numbers with the same number of bits, both have the same leading 1 bit, so the
// bitwise AND keeps that high bit while XOR cannot exceed it. Numbers from
// different bit-length groups do not satisfy the condition.

int main() {
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
