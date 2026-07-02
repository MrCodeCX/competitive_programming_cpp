#include <iostream>

using namespace std;

// En general es un problema voraz, dado que la historia queda completamente descrita por el estado pot
// Entonces es necesario hayar el maximo puntaje entre requerimientos a(k) a(k+1)
// Este puntaje es lo que le tarda en llegar al requerimiento (si pots son distintos le tarda 1, si pots son iguales le tarda 0)
// Sumado con los bucles que se pueden generar, que seria el (tiempo entre requerimientos) - (lo que le tarda en llegar) / (lo que tarda un ciclo)
// Lo que tarda un ciclo es 2

size_t get_score(size_t time, size_t last_time, size_t pot, size_t last_pot) {
    // Calculate posible steps
    size_t steps = time - last_time;
    ssize_t res = (pot==last_pot ? 0 : 1);
    size_t cycles = (steps-res)/2;
    size_t score = res + cycles * 2;
    return score;
}

int main() {
    size_t t; cin >> t;
    while (t--)
    {
        size_t n; size_t m; cin >> n; cin >> m;
        size_t last_time = 0;
        size_t last_pot = 0;
        size_t counter = 0;
        for (size_t i = 0; i < n; i++)
        {
            size_t time; cin >> time;
            size_t pot; cin >> pot;
            
            counter += get_score(time, last_time, pot, last_pot);
            
            last_pot = pot;
            last_time = time;
        }
        counter += (m-last_time);
        cout << counter << endl;   
    }
    
    return 0;
}