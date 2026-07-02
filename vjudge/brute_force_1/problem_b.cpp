#include <iostream>
#include <bitset>

using namespace std;

#define N 1000
#define BIT_MASK_N 1000002

// Generar Criba de Eratostenes (Tabla de Primos)

bitset<BIT_MASK_N> bit_mask;

void setup_bit_mask() {
    bit_mask.set(); // setear todos los bits a bit_value 1
    bit_mask[0] = false; bit_mask[1] = false; // setear 0, 1 a bit_value 0
    // Generar criba
    bool continue_flag = true;
    for (size_t i = 2; i <= BIT_MASK_N && continue_flag; i++)
    {
        if(bit_mask[i]) {
            for (size_t j = i*2; j <= BIT_MASK_N; j+=i)
            {
                bit_mask[j] = false;
            }
            if(i*i > BIT_MASK_N) continue_flag = false;
        }
    }
    
}

int main() {
    setup_bit_mask();
    int n; cin >> n;
    // Verificar cada caso si es primo
    for (size_t i = 1; i <= N; i++)
    {
        if(!bit_mask[n*i + 1]) {
            cout << i << endl;
            break;
        }
    }
    
    return 0;
}