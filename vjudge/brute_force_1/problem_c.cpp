#include <iostream>

using namespace std;

#define A 1234567
#define B 123456
#define C 1234

// Para varios coeficientes es mejor iterar un array (dp) de cada formacion posible O(n)
// Para pocos coeficientes es mejor iterar sobre ellos y verificar el residuo respecto al ultimo O(A*B)

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