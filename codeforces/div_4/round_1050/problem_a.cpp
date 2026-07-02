#include <iostream>

using namespace std;

// Si n es par la suma se anula, si n es impar vale x

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