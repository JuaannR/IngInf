#include <stdlib.h>  	// exit
#include <string.h>  	// memset
#include <iostream>  	//  cin y cout
#include <math.h>        // sqrt
using namespace std;

#define MAX_NODOS 2000
#define	INFINITO 1000000

int C[MAX_NODOS][MAX_NODOS];    //matriz de adyacencia
int X[MAX_NODOS];               // almacenamiento coordenadas colonias
int Y[MAX_NODOS];
int x, y;                       //lectura de coordenadas
bool visitado[MAX_NODOS];       // array nodos visitados

void leeGrafo(int numeroColonias) {
    // Lectura coordendas
    for (int i = 0; i < numeroColonias; i++) {
        cin >> x >> y;
        if ((x < -1000) || (x > 1000) || (y < -1000) || (y > 1000)) {
            cerr << "Coordenadas fuera del rango permitido\n";  // Fuera de rango
            exit(0);
        }
        //Si coordenadas correctas, guardamos en sus respectivos arrays
        X[i] = x;
        Y[i] = y;
    }

    // Inicializa matriz costes
    memset(C, 0, sizeof(C));
    for (int i = 0; i < numeroColonias; i++) {
        for (int j = 0; j < numeroColonias; j++) {
            if (i == j) {
                C[i][j] = 0;  // Mismo nodo distancia 0
            } else {
                //Calculo distancia
                int dx = X[i] - X[j];
                int dy = Y[i] - Y[j];
                // Se trunca pasandolo a int
                C[i][j] = C[j][i] = (int)sqrt(dx * dx + dy * dy);
            }
        }
    }
}

void AlgoritmoPrim(int numeroColonias) {
    int menorCoste[numeroColonias];
    int cableMinimo = 0;

    memset(visitado, false, sizeof(visitado));  //Inicializa todos las colonias array a false

    // Inicializa costes mínimos desde nodo inicial 0 al resto de nodos
    for (int i = 1; i < numeroColonias; i++) {
        menorCoste[i] = C[0][i];
    }

    visitado[0] = true; //nodo inical visitado

    // Busca nodo no visitado con el menor costo
    for (int i = 1; i < numeroColonias; i++) {
        int min = INFINITO;  //inicializamos con infinito para asignarle en cada iteracion el coste minimo desde el nodo actual a otro nodo no visitado
        int k = 0;  //Indice nodo con el costo mínimo

        // Encuentra nodo no visitado con menor coste
        for (int j = 1; j < numeroColonias; j++) {
            if (!visitado[j] && menorCoste[j] < min) {  //Si la colonia j no ha sido visitada...
                min = menorCoste[j];    //Actualizo costo mínimo
                k = j;      //Guardo el índice
            }
        }

        visitado[k] = true; //Marco como visitado
        cableMinimo += min; //cableMinimo = cableMinimo + min

        // Actualiza los costes mínimos desde el nodo actual al resto de nodos
        for (int h = 1; h < numeroColonias; h++) {
            if (!visitado[h] && C[k][h] < menorCoste[h]) {
                menorCoste[h] = C[k][h];    //Actualizo con costo mas bajo
            }
        }
    }
    cout << cableMinimo << endl;
}

int main() {
    int ncasos;
    cin >> ncasos;

    for (int i = 0; i < ncasos; i++) {
        int numColonias;
        cin >> numColonias;  // Lee el número de colonias
        if (numColonias <= 0 || numColonias > MAX_NODOS) {
            cerr << "Numero de nodos (" << numColonias << ") no valido\n";
            exit(0);
        }
        leeGrafo(numColonias);
        AlgoritmoPrim(numColonias);
    }

    return 0;
}
