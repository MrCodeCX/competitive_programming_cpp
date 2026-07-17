#include <iostream>

using namespace std;

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
