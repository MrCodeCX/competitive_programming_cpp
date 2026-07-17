#include <iostream>

using namespace std;

// Problem: Codeforces Round 1050 (Div. 4), A - Sublime Sequence
// Link: https://codeforces.com/contest/2148/problem/A
//
// Summary:
// Given x and n, evaluate the alternating sequence formed with n terms of x and
// -x.
//
// Solve:
// If n is even, the sum cancels out; if n is odd, it equals x.

int main() {
    size_t t; cin >> t;
    while (t--)
    {
        size_t x; size_t n; cin >> x; cin >> n;
        size_t solve = x * (n%2);
        cout << solve << endl;
    }
    
    return 0;
}
