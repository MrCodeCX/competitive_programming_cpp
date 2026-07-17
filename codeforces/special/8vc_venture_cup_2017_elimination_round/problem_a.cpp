#include <iostream>
#include <bitset>

using namespace std;

#define N 1000
#define BIT_MASK_N 1000002

// Problem: 8VC Venture Cup 2017 - Elimination Round, A - PolandBall and Hypothesis
// Link: https://codeforces.com/contest/755/problem/A
//
// Summary:
// Given n, find a positive integer m such that n * m + 1 is composite.
//
// Solve:
// Precompute primality with the Sieve of Eratosthenes, then check m from 1
// upward until n * m + 1 is not prime.

bitset<BIT_MASK_N> bit_mask;

void setup_bit_mask() {
    bit_mask.set(); // Set all bits to 1.
    bit_mask[0] = false; bit_mask[1] = false; // Set 0 and 1 to 0.
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
    for (size_t i = 1; i <= N; i++)
    {
        if(!bit_mask[n*i + 1]) {
            cout << i << endl;
            break;
        }
    }
    
    return 0;
}
