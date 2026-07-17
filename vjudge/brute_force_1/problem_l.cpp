#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

#define LL long long

int main() {
    // Triangles have a formation rule for their sides:
    // (a-b) < c < (a+b) (3 permutations)
    
    // If isosceles triangles of 2^k are formed, the other number can be any smaller one.
    // Therefore, start forming isosceles triangles for each k (2 -> n).
    
    // Are there only isosceles triangles? Yes.
    // No triangle can be formed with 3 different sides, a < b < c.
    // b = 2^k, c >= 2^(k+1), (c-b) >= 2^(k+1)-2^k = 2^k
    // But (c-b) < a -> 2^k < a, and since a < b -> a < 2^k.
    // Such an a does not exist, so triangles with 3 different sides do not exist.
    
    // Ya que a < (b+c), a < 2^k + 2^k = 2^(k+1)
    // Every triangle is isosceles, with the different side less than or equal to the equal sides.

    // Strategy -> Exhaust the isosceles triangles.

    size_t n; cin >> n;
    LL solve = 0;
    LL res; cin >> res;
    // For case 1, it cannot form isosceles triangles, only equilateral ones.
    solve += res/3;
    res = res%3;
    // For any other case.
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
