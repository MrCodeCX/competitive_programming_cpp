#include <iostream>
#include <string>
#include <math.h>

using namespace std;


// A travez de las permutaciones se pueden formar todos los lucky numbers de k cifras
// Entonces la posicion de n = cantidad de luckys de cifras inferiores + posicion dentro de las cifras k = get_cypher(n)

// Si analizamos en orden los lucky number de k cifras
// 444 447 474 477 744 747 774 777 vemos que se asemeja mucho al sistema binario
// 000 001 010 011 100 101 110 111, y su representacion en binario coincide con su (posicion entre los lucky number de k cifras) + 1

// La suma de posiciones hasta x cifras es SUM 2^i (i: 1 -> (get_cypher(n) - 1)) = 1U << get_cypher(n) - 2

//if(s[i] == '4') ret_bin = ret_bin << 1 + 0;
//else ret_bin = ret_bin << 1 + 1;

size_t get_bin(size_t num) {
    string s = to_string(num);
    size_t ret_bin = 0;
    for (auto it = s.begin(); it != s.end(); ++it)
    {
        if(*it == '4') ret_bin = ret_bin << 1;
        else ret_bin = (ret_bin << 1) + 1;
    }
    return ret_bin;
}

size_t get_cypher(size_t num) {
    return 1 + log10(num);
}

int main() {
    size_t n; cin >> n;
    size_t sum_position = (1U << get_cypher(n)) - 2;
    size_t position_relative = 1 + get_bin(n);
    size_t position = sum_position + position_relative;

    // SHOW
    cout << position << endl;
    
    return 0;
}