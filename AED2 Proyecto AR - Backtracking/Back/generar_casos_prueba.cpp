#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void generarCaso(int nw, int nt) {
    // Generar capacidades aleatorias entre 0 y 15 para los trabajadores
    vector<int> capacidades(nw);
    for (int i = 0; i < nw; i++) {
        capacidades[i] = rand() % 16; // Random entre 0 y 15
    }

    // Generar matriz de beneficios aleatoria entre 1 y 20
    vector<vector<int>> beneficios(nw, vector<int>(nt));
    for (int i = 0; i < nw; i++) {
        for (int j = 0; j < nt; j++) {
            beneficios[i][j] = rand() % 21; // Random entre 1 y 20
        }
    }

    // Imprimir el caso
    cout << nw << " " << nt << endl;
    for (int i = 0; i < nw; i++) {
        for (int j = 0; j < nt; j++) {
            cout << beneficios[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < nw; i++) {
        cout << capacidades[i] << " ";
    }
    cout << endl;
}

int main() {
    srand(time(0)); // Semilla aleatoria para rand()

    // Casos de prueba con distintos tamaños para nw = nt
    vector<int> tamanos = {5, 10};
    cout << tamanos.size() << endl;
    for (int t : tamanos) {
        generarCaso(t, t); // nw = nt
    }

    return 0;
}
