#include <iostream>

using namespace std;

// Para un determinado numero x, su posicion seria (x / n) * (n-1) + x % n = k
// Siempre x % n != 0
//      (x / n) + (x % n / (n-1)) = k / (n-1)
// if k % (n-1) == 0 -> (x % n / (n-1)) = 1
//      x = (k/(n-1))*n - 1
// else (x % n / (n-1)) = 0
//      x = (k/(n-1))*n + k % (n-1)


int main() {
    size_t t; cin >> t;
    while (t--)
    {
        size_t n; size_t k; cin >> n; cin >> k;
        size_t x = 0;
        if(k%(n-1) == 0) x = (k/(n-1))*n - 1;
        else x = (k/(n-1))*n + k % (n-1);
        cout << x << endl;
    }
    
    return 0;
}