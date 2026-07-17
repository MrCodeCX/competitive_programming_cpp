#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

#define LL long long

// Problem: Codeforces Global Round 2, E - Pavel and Triangles
// Link: https://codeforces.com/contest/1119/problem/E
//
// Summary:
// Given counts of sticks with lengths 2^0, 2^1, ..., 2^(n-1), form as many
// triangles as possible.
//
// Solve:
// Triangle sides must satisfy (a - b) < c < (a + b). Since all stick lengths
// are powers of two, no triangle can use three different side lengths: if
// a < b < c, then b = 2^k and c >= 2^(k + 1), so c - b >= 2^k, but a < 2^k.
// Therefore every valid triangle is isosceles or equilateral. The strategy is
// to exhaust triangles with two equal sides at the current length and one
// remaining smaller side, then form equilateral triangles from leftover sticks.

int main() {
    size_t n; cin >> n;
    LL solve = 0;
    LL res; cin >> res;
    solve += res/3;
    res = res%3;
    for (size_t i = 1; i < n; i++)
    {
        LL num; cin >> num;
        LL amount_2 = min(num/2, res);
        LL new_num = num - amount_2*2;
        LL amount_3 = new_num / 3;
        new_num = new_num - amount_3 * 3;

        res = res + new_num - amount_2;
        solve = solve + amount_2 + amount_3;
    }
    cout << solve << endl;

    return 0;
}
