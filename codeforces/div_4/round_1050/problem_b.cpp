#include <iostream>

using namespace std;

// Cualquier movimiento se puede reducir en segmenos de 3x3 partiendo desde la central
// Para llegar a las casillas aristas se necesita 1
// Para llegar a las esquinas sea que pases arista - esquina
// o que pases en diagonal por el vertice hasta la esquina, se necesita 2

// Entonces se deduce que para llegar a cada segmento habra la cantidad de cruces de distancia euclidea (respecto a segmentos)
// Ademas de que la ruta de ir primero todo derecha y luego todo arriba es una ruta valida

// La cantidad de segmentos en x es (m+1), iniciamos en el primer segmento, queremos llegar al (m+1)
// Nos topamos con m cruces
// Analisis similar para llegar desde la esquina inferior derecha a la esquina superior derecha, n cruces
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