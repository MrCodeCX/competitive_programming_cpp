#include <iostream>

using namespace std;

// Problem: Codeforces Round 676 (Div. 2), A - XORwice
// Link: https://codeforces.com/contest/1421/problem/A
//
// Summary:
// Given a and b, choose x to minimize (a xor x) + (b xor x).
//
// Solve:
// For each case, x can be analyzed bit by bit because changing one bit does not affect the next one.
// To minimize the sum, each bit must be minimized independently.
// xxxx1 yyyy1 zzzzx -> x = 1
// xxxx1 yyyy0 zzzzx -> x = 1 or 0
// xxxx0 yyyy0 zzzzx -> x = 0

// Taking the second case as 0 gives x = (a & b).


int main() {
    size_t t; cin >> t;
    while(t--) {
        size_t a, b; cin >> a; cin >> b;
        size_t x = (a & b);
        size_t sum = (a ^ x) + (b ^ x);
      
        cout << sum << endl;
    }
    return 0;
}
