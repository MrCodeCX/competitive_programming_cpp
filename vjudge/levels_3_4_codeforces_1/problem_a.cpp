#include <iostream>
#include <bitset>

using namespace std;

// Only cases where the array is filled with n ones and m zeroes matter, with n and m multiples of 3.

// Consecutive pairs 00 and 11 are relevant because, with a third element x,
// they form the lowest-cost triplets.
// Ideally, the array would contain only triples like 111000111, etc.
// Special cases: these represent all decisions that affect the new number of pairs,
// because in each case there is only one possible decision.
// 101010101010 -> (A) No pair available; a triplet generates another pair.
// 110011001100 -> (B) No odd pair available; a triplet breaks another pair besides the one it uses.
// 111000111000 -> (C) Choosing a triplet keeps the pair count unchanged, only removing the pair it uses.

// Case A can happen with 6 or more elements: new_pairs = 1, cost 2.
// Since there are more odd elements, pairs can keep being generated.
// Case B can only happen with 12 or more elements; in any case, new_pairs = pairs - 2.
// In the new array there will be an odd element, so it can always move to case A with cost 1.
// In case C the cost is minimal: cost = 1.

// Hypothesis: whenever there is a pair element, it is possible to generate pairs
// in the new array without exhausting them, with cost 1 per iteration.
// If there is no pair element, one can be created with a single initial cost of 2.

// Therefore, it is enough to know whether the array only contains odd elements,
// that is, whether it is case A.

// Needed:
// Count the number of 1s and 0s in the subarray. This can be done by mapping
// the number of 1s and 0s up to position x and subtracting.
// Count the number of odd elements, just by iteration.
// Checking the odd-elements case is simple with bit operations.
// num == (~significant num) << 1
// How can a pair be checked quickly?
// If the input gives arrays like 101010 only, it must be identified quickly.

#define N 250001

template <size_t origin_bits, size_t new_bits>
bitset<new_bits> get_sub_bitset(const std::bitset<origin_bits>& original, size_t start) {
    // origin_bits >= new_bits
}

int main() {
    size_t t; cin >> t;
    while (t--)
    {
        size_t n; size_t q; cin >> n; cin >> q;
        for (size_t i = 0; i < n; i++)
        {
        }
        
        
    }
    
    return 0;
}
