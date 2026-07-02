#include <iostream>
#include <vector>

using namespace std;
#define N 101

int main() {
    size_t n, k;
    cin >> n; cin>>k;
    vector<size_t> array_indices(N,0);
    size_t counting_indices = 0;
    for (size_t i = 0; i < n; i++)
    {
        size_t num; cin >> num;
        if(array_indices[num] == 0 && counting_indices < k) {
            array_indices[num] = i+1;
            counting_indices++;
        }
    }

    if(counting_indices >= k) {
        cout << "YES" << endl;
        for (size_t i = 0; i < N; i++)
        {
            if(array_indices[i] != 0) cout << array_indices[i] << " ";
        }
        cout << endl;
    }
    else cout << "NO" << endl;

    return 0;
}