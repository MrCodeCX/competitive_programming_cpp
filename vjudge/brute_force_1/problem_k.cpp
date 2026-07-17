#include <iostream>

using namespace std;

// First, by Euler-style intuition, symmetric pairs can be formed:
// 1 ... n
// n ... 1
// Pairs are (1, n), (2, (n-1)), etc.
// When the same number of pairs can be formed for both groups, |SUM(A) - SUM(B)| = 0; this happens when n is a multiple of 4.
// When n is not a multiple of 4, res = n%4 and new_n = n-res.
// The first "res" numbers can be separated from the following "new_n" numbers; with new_n, groups A and B can be formed with x = 0.
// Then the remaining res numbers must be added to groups A and B.
// res = 1 -> add 1 to any group; x = 1
// res = 2 -> add 1,2; add 1 to one group and 2 to the other; x = 1
// res = 3 -> add 1,2,3; add 1 and 2 to one group and 3 to the other; x = 0

int main() {
    size_t n; cin >> n;
    size_t res = n%4;
    if(res == 0 || res == 3) cout << 0 << endl;
    else cout << 1 << endl;

    return 0;
}
