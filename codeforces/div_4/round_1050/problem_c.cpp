#include <iostream>

using namespace std;

// In general this is a greedy problem, because the history is fully described by the pot state.
// Therefore, it is necessary to find the maximum score between requirements a(k) and a(k+1).
// Este puntaje es lo que le tarda en llegar al requerimiento (si pots son distintos le tarda 1, si pots son iguales le tarda 0)
// This score is the time needed to reach the requirement: 1 if pots differ, 0 if they are equal.
// Add the loops that can be generated: (time between requirements - time needed to reach it) / cycle time.
// The cycle time is 2.

size_t get_score(size_t time, size_t last_time, size_t pot, size_t last_pot) {
    // Calculate possible steps.
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
