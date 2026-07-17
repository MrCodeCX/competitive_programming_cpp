#include <iostream>

using namespace std;

#define A 1234567
#define B 123456
#define C 1234

// Problem: Codeforces Round 357 (Div. 2), B - Economy Game
// Link: https://codeforces.com/contest/681/problem/B
//
// Summary:
// Given n, determine whether it can be represented as a non-negative sum of
// 1234567, 123456, and 1234.
//
// Solve:
// With many coefficients, it is better to iterate a DP array over every possible formation in O(n).
// With few coefficients, it is better to iterate over them and check the remainder against the last one in O(A*B).

int main() {
    size_t n; cin >> n;
    bool flag = false;
    for (size_t i = 0; i <= n && !flag; i+=A)
    {
        for (size_t j = 0; j <= (n-i) && !flag; j+=B)
        {
            if((n-i-j)%C == 0) flag = true;
        }
    }
    if(flag) cout << "YES" << endl;
    else cout << "NO" << endl;
    
    return 0;
}
