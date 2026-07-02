#include <iostream>

using namespace std;

#define N 3

// Apuntar a un numero maximo, el resto minimos y distribuir el residuo entre todos
// new_n = (n / 3) * 3
// res = n % 3
// a = new_n; b = 0; c = 0

// Notar que new_n siempre sera mayor o igual a 3
// Distribuir el residuo entre los 3 numeros tal que ninguno sea multiplo de 3

// La verdadera pregunta es, como distribuyes el residuo
// Ejemplo al distribuir 0
// -2 1 1
// Ejemplo al distribuir 1
// -1 1 1
// Ejemplo al distribuir 2
// -1 2 1

int main() {
    size_t n; cin >> n;
    size_t new_n = (n / 3) * 3;
    size_t res = n % 3;
    // Generar numeros
    size_t a = new_n, b = 0, c = 0;
    // Distribuir Residuo
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