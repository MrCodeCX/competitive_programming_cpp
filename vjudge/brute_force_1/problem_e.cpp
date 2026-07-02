#include <iostream>
#include <vector>

using namespace std;
#define LL long long

// Los cuadrados van desde size 1 hasta min_side, y se extienden por todo max_side

// Solo es necesario analizar combinaciones de n < m, tal que total = analisis*2

// Densidad de Cuadrados Laterales 1 + max_side - side = 1 + c_2 - side
// Densidad de Cuadrados Verticales 1 + min_side - side = 1 + c_1 - side

// side 1 -> min_side
// Squares = SUM (1 + c_1 - side) * (1 + c_2 - side)
// Squares = SUM ((1+c_1)*(1+c_2) - (2+c_1+c_2)*side + side*side)
// Squares = (1+c_1)*(1+c_2)*c_1 - (2+c_1+c_2)*c_1*(1+c_1)/2 + c_1*(1+c_1)*(2*c_1+1)/6
// Squares = c_1*(1+c_1)*(1+3*c_2 -c_1)/6

// Obtenemos c_2 en funcion de c_1 y squares 
// c_2 = (c_1 + (squares*6)/(c_1*(c_1+1)) - 1) / 3
// min_c_1 = 1
// No es necesario determinar el maximo, basta saber que lo encontrare en un orden O(n^(1/3))
// Iterar mientras c_1 < c_2 (c_1 = n, c_2 = m para n <= m)

LL get_c_2(LL squares, LL c_1) {
    return (c_1 + (squares*6)/(c_1*(c_1+1)) - 1) / 3;
}

bool verify_squares(LL squares, LL c_1, LL c_2) {
    LL a = squares*6;
    LL b = c_1*(1+c_1)*(1+3*c_2 -c_1);
    return a == b;
}


int main() {
    LL squares; cin >> squares;
    bool continue_flag = true;
    vector<LL> n_array;
    vector<LL> m_array;
    size_t counting_cases = 0;

    for (LL n = 1; continue_flag; n++)
    {
        LL m = get_c_2(squares, n);
        if(n > m) continue_flag = false;
        else if(verify_squares(squares,n,m)) {
            n_array.push_back(n);
            m_array.push_back(m);
            counting_cases++;
        }
    }
    // SELECT THE CASE
    bool state_case = n_array[counting_cases-1] == m_array[counting_cases-1];
    size_t real_cases = counting_cases*2;
    size_t second_iter = counting_cases;
    if(state_case) {
        real_cases--;
        second_iter--;
    }
    // SHOW
    cout << real_cases << endl;
    for (size_t i = 0; i < counting_cases; i++)
    {
        cout << n_array[i] << " " << m_array[i] << endl;
    }
    for (size_t i = second_iter; i > 0; i--)
    {
        cout << m_array[i-1] << " " << n_array[i-1] << endl;
    }
    return 0;
}
