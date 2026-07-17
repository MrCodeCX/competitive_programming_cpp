#include <iostream>

using namespace std;

// Any movement can be reduced to 3x3 segments starting from the center.
// Reaching edge cells requires 1 step.
// To reach corners, the path goes through edge -> corner.
// o que pases en diagonal por el vertice hasta la esquina, se necesita 2

// Therefore, reaching each segment requires the number of Euclidean-distance crossings between segments.
// Also, the route that goes fully right first and then fully up is valid.

// La cantidad de segmentos en x es (m+1), iniciamos en el primer segmento, queremos llegar al (m+1)
// Nos topamos con m cruces
// Similar analysis for going from the lower-right corner to the upper-right corner: n crossings.
// solve = n + m

int main() {
    size_t t; cin >> t;
    while (t--)
    {
        size_t n; size_t m; cin >> n; cin >> m;
        size_t x; size_t y; cin >> x; cin >> y;
        for (size_t i = 0; i < n; i++)
        {
            size_t a; cin >> a;
        }
        for (size_t i = 0; i < m; i++)
        {
            size_t b; cin >> b;
        }
        size_t solve = n + m;
        cout << solve << endl;
    }
    
    return 0;
}
