#include <iostream>

using namespace std;

// Problem: Codeforces Round 1050 (Div. 4), B - Lasers
// Link: https://codeforces.com/contest/2148/problem/B
//
// Summary:
// Given vertical and horizontal laser lines, determine the minimum number of
// laser lines that must be crossed to reach the target.
//
// Solve:
// Any movement can be reduced to 3x3 segments starting from the center.
// Reaching edge cells requires 1 step.
// To reach corners, the path goes through edge -> corner.
// Or if the path goes diagonally through the vertex to the corner, it takes 2.

// Therefore, reaching each segment requires the number of Euclidean-distance crossings between segments.
// Also, the route that goes fully right first and then fully up is valid.

// The number of segments on x is (m + 1). Starting from the first segment and
// reaching the (m + 1)-th segment crosses m lines.
// Similar analysis for going from the lower-right corner to the upper-right corner: n crossings.
// solve = n + m

int main() {
    size_t t; cin >> t;
    while (t--)
    {
        size_t n; size_t m; cin >> n; cin >> m;
        size_t x; size_t y; cin >> x; cin >> y;
        for (size_t i = 0; i < n; i++)
        {
            size_t a; cin >> a;
        }
        for (size_t i = 0; i < m; i++)
        {
            size_t b; cin >> b;
        }
        size_t solve = n + m;
        cout << solve << endl;
    }
    
    return 0;
}
