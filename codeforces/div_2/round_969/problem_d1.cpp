#include <iostream>
#include <vector>
using namespace std;
 
// KNOWN ISSUE:
// This attempt is known to fail on test 24.
// The MEX-based reasoning below captures the intended approach, but the implementation has an unresolved edge-case bug.

/*
* PREVIOUS ANALYSIS
// Structure that summarizes a sequence with its mex value.
// If the sequence has no gap of size 1, complete = -1 (it cannot be completed).
// The sequence will then only give its mex value, or mex + 1 if x = mex.
// If the sequence has a gap of size 1, complete = gap value.
// If x has the gap value, the sequence gives its mex value.
// If x does not have the gap value, the sequence gives the gap value.
 
Reference structure; no longer needed later.
struct Data {
	int mex = 0;
	int complete = -1;
};
 
// One-gap sequences are self-completable, and mex(x, sequence) will be:
// If x is the gap -> gives its mex.
// If x is not the gap -> gives the gap and then gives its mex.
 
// A sequence without a gap (or with gap > 1) will be:
// if x is the mex -> gives mex + 1.
// if x is not the mex -> gives mex and then gives mex + 1.
 
 
// Analyze all sequences and compare the one with the largest mex.
// In all cases, the initial value of x does not matter because after a sub-operation
// it will always take the gap value and then mex for completable sequences,
// or mex and then mex + 1 for complete sequences.
 
// All of this is summarized in a vector that stores each sequence's mex,
// independent of the initial x. For complete sequences it is mex + 1;
// for completable sequences it is the mex after completing the first gap.
*/
 
// Both cases are actually the same:
// get the mex, add it, and then get the next mex.
// Faster method: count up to (lsize+1), which is the maximum mex reachable.
// If x > mexMax, it stays as x.
 
int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n; long long m; cin >> m;
		int mexMax = 0;
		for (int i = 0; i < n; i++)
		{
			int l; cin >> l;
			int lMax = l + 5;
			vector<int> vect_counting(lMax, 0);
			for (int j = 0; j < l; j++)
			{
				int a; cin >> a;
				if (a < lMax) vect_counting[a]++;
			}
			bool value_hueco = true;
			int mex = 0;
			for (mex = 0; mex < lMax; mex++)
			{
				if (vect_counting[mex] == 0) {
					if (value_hueco) {
						vect_counting[mex] = 1;
						value_hueco = false;
					}
					else {
						// Found the second gap, so it stops here.
						break;
					}
				}
			}
			if (mex > mexMax) mexMax = mex;
		}
		if (m > mexMax) {
			long long value = (((m * (m + 1)) + (mexMax * (mexMax + 1))) / 2);
			cout << value << endl;
		}
		else {
			long long value = mexMax * (m + 1);
			cout << value << endl;
		}
	}
 
	return 0;
}
