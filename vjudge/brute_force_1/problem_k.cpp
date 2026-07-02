#include <iostream>

using namespace std;

// Primero se demuestra por intuicion de Euler que se pueden formar pares simetricos
// 1 ... n
// n ... 1
// Los pares (1, n), (2, (n-1)), etc,
// Cuando se puedan formar igual cantidad de pares para ambos entonces |SUM(A) - SUM(B)| = 0, esto pasa cuando n es multiplo de 4
// Cuando n no es multiplo de 4, res = n%4, entonces, siendo new_n = n-res
// Se pueden separar los primeros "res" numeros de los siguientes "new_n" numeros, con los new_n se pueden formar los grupos A B de x = 0
// Es necesario entonces agregar los otros res numeros a los grupos A B
// res = 1 -> agregar 1, lo agregamos a cualquier grupo; y x = 1
// res = 2 -> agregar 1,2, agregamos 1 a un grupo y 2 al otro; y x = 1
// res = 3 -> agregar 1,2,3, agregamos 1 y 2 a un grupo y 3 al otro; y x = 0

int main() {
    size_t n; cin >> n;
    size_t res = n%4;
    if(res == 0 || res == 3) cout << 0 << endl;
    else cout << 1 << endl;

    return 0;
}