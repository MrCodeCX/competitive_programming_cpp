#include <iostream>
#include <bitset>

using namespace std;

#define N 1000
#define BIT_MASK_N 1000002

// Generate the Sieve of Eratosthenes (prime table).

bitset<BIT_MASK_N> bit_mask;

void setup_bit_mask() {
    bit_mask.set(); // Set all bits to 1.
    bit_mask[0] = false; bit_mask[1] = false; // Set 0 and 1 to 0.
    // Generate the sieve.
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
    // Check each case until finding a composite value.
    for (size_t i = 1; i <= N; i++)
    {
        if(!bit_mask[n*i + 1]) {
            cout << i << endl;
            break;
        }
    }
    
    return 0;
}
