#include <iostream>

using namespace std;

// Para cada caso el analisis de x es exclusivamente por bit, ya que el cambio de un bit no afecta al siguiente
// Para minimizar la suma se requiere minimizar cada bit
// xxxx1 yyyy1 zzzzx -> x = 1
// xxxx1 yyyy0 zzzzx -> x = 1 o 0
// xxxx0 yyyy0 zzzzx -> x = 0

// Tomando el segundo caso como 0, se tiene x = (a & b)


int main() {
    size_t t; cin >> t;
    while(t--) {
        size_t a, b; cin >> a; cin >> b;
        size_t x = (a & b);
        size_t sum = (a ^ x) + (b ^ x);
      
        // SHOW
        cout << sum << endl;
    }
    return 0;
}