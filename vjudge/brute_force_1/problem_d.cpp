#include <iostream>
#include <vector>

using namespace std;

#define N_CYPHER 32

size_t get_cypher(size_t num) {
    return 32 - __builtin_clz(num);
}

int main() {
    // No importa el orden debido a que la operacion y condicion es simetrica, pero solo se toman los pares de la forma i<j, por lo que cantidad de pares = n_i^2 / 2 en vez de n_i^2

    // Para numeros con igual cantidad de cifras, se identifican los casos
    // Caso a: 1xxxx 1yyyy, cumple la operacion
    // Caso b: 1xxxx 0yyyy, no cumple la operacion
    // Caso c: 0xxxx 0yyyy, nunca se considera pues no entra dentro de este rango de cifras
    // En el caso del numero 0, se le tomaria en cuenta cantidad de cifras 0 (aunque no lo piden)
    
    // La cantidad de pares sera igual a SUM (n_i^2)/2, siendo n_i la cantidad de numeros con i cifras

    size_t t; cin >> t;
    for (size_t iter_t = 0; iter_t < t; iter_t++)
    {
        size_t n; cin >> n;
        vector<size_t> counting_cypher_groups(N_CYPHER,0);
        for (size_t i = 0; i < n; i++)
        {
            size_t num; cin >> num;
            counting_cypher_groups[get_cypher(num)]++;
        }
        size_t solve = 0;
        for (size_t i = 0; i < N_CYPHER; i++)
        {
            solve += counting_cypher_groups[i] * (counting_cypher_groups[i]-1) / 2;
        }
        cout << solve << endl;
    }
    
    return 0;
}