#include <iostream>

using namespace std;

#define N 3

// Problem: Codeforces Round 511 (Div. 2), A - Little C Loves 3 I
// Link: https://codeforces.com/contest/1047/problem/A
//
// Summary:
// Given n, split it into three positive integers whose sum is n and none of
// them is divisible by 3.
//
// Solve:
// Aim for one maximum number, keep the rest minimal, and distribute the remainder across all of them.
// new_n = (n / 3) * 3
// res = n % 3
// a = new_n; b = 0; c = 0

// Notice that new_n will always be greater than or equal to 3.
// Distribute the remainder among the 3 numbers so none of them is a multiple of 3.

// The real question is how to distribute the remainder.
// Example when distributing 0:
// -2 1 1
// Example when distributing 1:
// -1 1 1
// Example when distributing 2:
// -1 2 1

int main() {
    size_t n; cin >> n;
    size_t new_n = (n / 3) * 3;
    size_t res = n % 3;
    size_t a = new_n, b = 0, c = 0;
    switch (res)
    {
    case 0:
        a -= 2; b++; c++;
        break;
    case 1:
        a -= 1; b++; c++;
        break;
    case 2:
        a -= 1; b+=2; c++;
        break;
    default:
        break;
    }
    cout << a << " " << b << " " << c << endl;

    return 0;
}
