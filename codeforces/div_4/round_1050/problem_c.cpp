#include <iostream>

using namespace std;

// Problem: Codeforces Round 1050 (Div. 4), C - Pacer
// Link: https://codeforces.com/contest/2148/problem/C
//
// Summary:
// A runner has time checkpoints with required positions. Between checkpoints,
// the runner can move or wait. Maximize the number of seconds spent moving while
// still being at each required position at the required time.
//
// Solve:
// In general this is a greedy problem, because the history is fully described by the pot state.
// Therefore, it is necessary to find the maximum score between requirements a(k) and a(k+1).
// This score is the time needed to reach the requirement: 1 if pots differ, 0 if they are equal.
// Add the loops that can be generated: (time between requirements - time needed to reach it) / cycle time.
// The cycle time is 2.

size_t get_score(size_t time, size_t last_time, size_t pot, size_t last_pot) {
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
