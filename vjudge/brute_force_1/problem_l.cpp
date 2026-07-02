#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

#define LL long long

int main() {
    // Los triangulos tienen una regla de formacion para sus lados
    // (a-b) < c < (a+b) (3 permutaciones)
    
    // Si se forman triangulos iscoceles de 2^k, el otro numero puede ser cualquiera menor
    // Ergo, debes empezar a formar iscosceles para cada k (2 -> n)
    
    // Solo existen triangulos iscoceles? SIII
    // No se puede formar ningun triangulo con los 3 lados diferentes, a < b < c
    // b = 2^k, c >= 2^(k+1), (c-b) >= 2^(k+1)-2^k = 2^k
    // Pero (c-b) < a -> 2^k < a, pero como sabemos a < b -> a < 2^k
    // No existe a, entonces no existen triangulos con los 3 lados diferentes
    
    // Ya que a < (b+c), a < 2^k + 2^k = 2^(k+1)
    // Todo triangulo es iscoceles con el lado diferente menor o igual a los lados iguales

    // Estrategia -> Agotar los iscoceles

    size_t n; cin >> n;
    LL solve = 0;
    LL res; cin >> res;
    // Para el caso 1, no puede formar isosceles solo equilateros
    solve += res/3;
    res = res%3;
    // Para cualquier otro caso
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