#include <iostream>
#include <vector>

using namespace std;
#define LL long long

// Problem: Codeforces Round 332 (Div. 2), D - Spongebob and Squares
// Link: https://codeforces.com/contest/599/problem/D
//
// Summary:
// Given x, find all grid dimensions n by m such that the total number of square
// subrectangles in the grid is exactly x.
//
// Solve:
// Squares range from size 1 to min_side and extend across max_side.

// It is only necessary to analyze combinations with n < m, so total = analysis * 2.

// Horizontal square density: 1 + max_side - side = 1 + c_2 - side
// Vertical square density: 1 + min_side - side = 1 + c_1 - side

// side 1 -> min_side
// Squares = SUM (1 + c_1 - side) * (1 + c_2 - side)
// Squares = SUM ((1+c_1)*(1+c_2) - (2+c_1+c_2)*side + side*side)
// Squares = (1+c_1)*(1+c_2)*c_1 - (2+c_1+c_2)*c_1*(1+c_1)/2 + c_1*(1+c_1)*(2*c_1+1)/6
// Squares = c_1*(1+c_1)*(1+3*c_2 -c_1)/6

// Get c_2 as a function of c_1 and squares.
// c_2 = (c_1 + (squares*6)/(c_1*(c_1+1)) - 1) / 3
// min_c_1 = 1
// It is not necessary to determine the maximum; it is enough to know it will be found in O(n^(1/3)).
// Iterate while c_1 < c_2 (c_1 = n, c_2 = m for n <= m).

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
    bool state_case = n_array[counting_cases-1] == m_array[counting_cases-1];
    size_t real_cases = counting_cases*2;
    size_t second_iter = counting_cases;
    if(state_case) {
        real_cases--;
        second_iter--;
    }
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
