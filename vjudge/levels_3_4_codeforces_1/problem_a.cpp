#include <iostream>
#include <bitset>

using namespace std;

// Solo nos interesa analizar los casos en los que el array este lleno de n 1s, m 0s, n y m multiplos de 3

// Resulta que nos interesan los pares consecutivos 00, 11, pues con ellos y un tercer elemento x se forman los tripletes de menor coste
// Lo ideal seria tener puros triples 111000111 etc
// Casos Especiales, Estos casos representan todas las desiciones posibles que afecten a la nueva cantidad de pares pues 
// en cada uno solo existe una desicion posible
// 101010101010 -> (A) Sin par disponible, un triplete genera otro par
// 110011001100 -> (B) Sin dispar disponible, un triplete rompe otro par (ademas del que utiliza)
// 111000111000 -> (C) Elegir Triplete, un triplete mantiene la cantidad de pares (solo quita el que utiliza)

// El caso A puede darse con 6 elementos a mas, new_pares = 1, coste 2
// dado que hay mas elementos dispares, se podran seguir generando pares
// El caso B solo puede darse con 12 elementos a mas, en cualquier caso, new_pares = pares - 2
// En el nuevo array existira un elemento dispar, siempre puede pasar al caso A con coste 1
// En el caso C el coste es minimo, coste = 1

// Hipotesis: Siempre que exista un elemento par, sera posible generar pares en el nuevo array sin agotarse, coste 1 de cada iteracion
// Si no existe elemento par es posible hacer existir uno por un unico costo inicial, coste 2

// Entonces solo necesitamos saber para el array si solo existen elementos dispares, es decir, verificar si es el caso A

// Se necesita 
// Contar cantidad de 1s y 0s en el subarray, esto se puede hacer mapiando la cantidad de 1s y 0s hasta la posicion x y restando
// Contar cantidad de elementos dispares, iteracion nomas
// Verificar  el caso de elementos dispares es sencillo con operaciones de bits
// num == (~num significativo) << 1 
// Como verificas rapidamente si hay un par?
// En el caso de que te den puros array de tipo 101010, debes poder identificarlo rapido

#define N 250001

template <size_t origin_bits, size_t new_bits>
bitset<new_bits> get_sub_bitset(const std::bitset<origin_bits>& original, size_t start) {
    // origin_bits >= new_bits
}

int main() {
    size_t t; cin >> t;
    while (t--)
    {
        size_t n; size_t q; cin >> n; cin >> q;
        for (size_t i = 0; i < n; i++)
        {
        }
        
        
    }
    
    return 0;
}