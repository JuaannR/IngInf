#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

#define MAX_NODOS 200
#define	INFINITO 1000000


int numeroCiudades; //num ciudades caso actual
vector<string> ciudades;    //nombres ciudades
int C[MAX_NODOS][MAX_NODOS];    //matriz con distancias directas entre ciudades
int D[MAX_NODOS][MAX_NODOS];    //Matriz que usa algoritmo de Floyd para calcular las distancias mínimas entre todas las parejas de nodos
int A;  // A y B ciudades conectadas
int B;
int L;  // Distancia entre ciudades
int excentricidadCentro;    //Excentricidad ciudad central


void leeGrafo (void) {

	memset(C, 0, sizeof(C));    //Inicializa matriz con 0
	ciudades.clear();           // Limpia vector -> vacio

	cin >> numeroCiudades;  //lee ciudades en caso actual
	ciudades = vector<string>(numeroCiudades);  //redimensiona vector con tamaño necesario
	string ciudad;
	getline(cin, ciudad, '\n');

    // Bucle for, para leer todas las ciudades incluidas en el grafo y almacenarlas en ciudades
	for (int i = 0; i < numeroCiudades; i++) {
		getline(cin, ciudad, '\n');
		ciudades[i] = ciudad;
	}

    // Inizialización de la matriz
	for (int i = 0; i < numeroCiudades; i++){
		for (int j = 0; j< numeroCiudades; j++){
			C[i][j] = INFINITO;
        }
    }

    //Lee dos ciudades y distancia
cin >> A >> B >> L;
while (!(A == 0 && B == 0 && L == 0)) {
        //Se actualizan ambas direcciones -> no dirigido
    C[A][B] = L;
    C[B][A] = L;
    cin >> A >> B >> L;
}

}


void AlgoritmoFloyd() {

	memset (D, 0, sizeof(D));

    //Copia las distancias directas de la matriz C a la D
	for (int i = 0; i < numeroCiudades; i++) {
		for (int j = 0; j < numeroCiudades; j++) {
			D[i][j] = C[i][j];
		}
		// Dos nodos iguales la distancia es 0
		D[i][i] = 0;
	}

    //Aplicacion algoritmo calculando distancias más cortas entre ciudades
	for (int k = 0; k < numeroCiudades; k++) {
		for (int i = 0; i < numeroCiudades; i++) {
            for (int j = 0; j < numeroCiudades; j++) {
                if (D[i][j] > D[i][k] + D[k][j]) {
                    D[i][j] = D[i][k] + D[k][j];
                }
            }
        }
   	}
}

int Centro(){

	int capital;
	int longitudMax;
	int excentricidades [numeroCiudades];

	// Recorremos todas las ciudades para calcular excentridad
   	for (int i = 0; i < numeroCiudades; i++) {
		longitudMax = 0;
		for (int j = 0; j < numeroCiudades; j++) {
			if (D[i][j] >= longitudMax)
			longitudMax = D[i][j];
		}
		// Guardo excentridad de cada ciudad
		excentricidades[i] = longitudMax;
	}


	capital = 0;
    excentricidadCentro = INFINITO;
	string c;
	//Recorremos todas las ciudades para calcular la de menor excentridad
	for (int i = 0; i < numeroCiudades; i++) {
            //Si excentridad es menor a la que tengo, actualizo
        if (excentricidades[i] < excentricidadCentro) {
			excentricidadCentro = excentricidades[i];
			c = ciudades[i];
			capital = i;
		}
		//Si execentridades iguales, elegimos por nombre lexicográfico menor
		else if (excentricidades[i] == excentricidadCentro) {
			if (ciudades[i] < c) {
				excentricidadCentro = excentricidades[i];
				c = ciudades[i];
				capital = i;
			}
		}
	}
	return capital;
}


int main() {

	int ncasos;
	cin >> ncasos;

	for (int i = 0; i < ncasos; i++) {
		leeGrafo();
		AlgoritmoFloyd();
		cout << ciudades[Centro()] << endl;
	    cout << excentricidadCentro << endl;
	}
}
