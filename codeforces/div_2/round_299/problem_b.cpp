#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Problem: Codeforces Round 299 (Div. 2), B - Tavas and SaDDas
// Link: https://codeforces.com/contest/535/problem/B
//
// Summary:
// Given a lucky number made only of digits 4 and 7, find its 1-based position
// in the increasing sequence of all lucky numbers.
//
// Solve:

// Through permutations, all lucky numbers with k digits can be formed.
// Therefore, position(n) = count of lucky numbers with fewer digits + position within the k-digit group, where k = get_cypher(n).

// If we analyze the k-digit lucky numbers in order:
// 444 447 474 477 744 747 774 777, they strongly resemble the binary system:
// 000 001 010 011 100 101 110 111. Their binary representation matches their
// position among the k-digit lucky numbers + 1.

// The sum of positions up to x digits is SUM 2^i (i: 1 -> (get_cypher(n) - 1)) = 1U << get_cypher(n) - 2.

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

    cout << position << endl;
    
    return 0;
}
