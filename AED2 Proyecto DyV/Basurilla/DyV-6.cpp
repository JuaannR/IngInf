#include <iostream>
#include <vector>
#include <algorithm>

#include <stdio.h>
#include <sys/time.h>

using namespace std;

// Estructura para almacenar la solución de un subproblema
struct Solucion {
    int posicion;    // Índice de inicio de la subcadena
    int apariciones; // Número máximo de apariciones consecutivas de C
};

//Imprime resultado subrayando en color la subcadena
void imprimir(Solucion resultado, const string& A, char c, int m) {
    cout << "La subcadena comienza en el caracter " << resultado.posicion + 1 << " contando desde 1" << endl;
    cout << "Numero maximo de apariciones consecutivas de '" << c << "': " << resultado.apariciones << endl;
    for (int i = 0; i < A.size(); ++i) {
        if (i == resultado.posicion) cout << "\033[4;96m";
        cout << A[i];
        if (i == resultado.posicion + m - 1) cout << "\033[0m";
    }
    cout << "\033[0m";
}

//Imprime solución normal
void imp(Solucion resultado, const string& A, char c, int m) {
    cout << A << endl;
    cout << "La subcadena comienza en el caracter " << resultado.posicion + 1 << endl;
    cout << "Numero maximo de apariciones consecutivas de '" << c << "': " << resultado.apariciones << endl;

}

// Función para calcular la mejor subcadena de tamaño m de manera directa
Solucion solucionDirecta(const string& A, int inicio, int fin, int m, char c) {
    int mejorPosicion = -1, maxApariciones = -1;

    for (int i = inicio; i <= fin - m + 1; ++i) {
        int apariciones = 0, maxAparicionesLocales = 0;
        for (int j = 0; j < m; ++j) {
            if (A[i + j] == c) {
                ++apariciones;
                maxAparicionesLocales = max(maxAparicionesLocales, apariciones);
            } else {
                apariciones = 0;
            }
        }
        if (maxAparicionesLocales > maxApariciones && m <= (fin - inicio + 1)) {
            maxApariciones = maxAparicionesLocales;
            mejorPosicion = i;
        }
    }
    // Caso en el que el tamaño de la subcadena es menor que m
    if (mejorPosicion==-1) {
        int apariciones = 0;
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] == c) {
                ++apariciones;
                maxApariciones = max(maxApariciones, apariciones);
            } else {
                apariciones = 0;
            }
        }
        mejorPosicion = inicio;
    }

    return {mejorPosicion, maxApariciones};
}

// Función que combina las soluciones de los subproblemas contando C consecutivos en la frontera
Solucion combinar(const Solucion& izq, const Solucion& der, const string& A, int inicio, int medio, int fin, char C, int m) {
    int mejorPosicion = izq.posicion;
    int mejorApariciones = izq.apariciones;

    if (der.apariciones > mejorApariciones) {
        mejorApariciones = der.apariciones;
        mejorPosicion = der.posicion;
    }

    // Contar C consecutivos en la frontera
    int izquierdaMax = 0;
    int derechaMax = 0;

    // Contamos caracteres C en la parte izquierda desde la mitad hacia atrás
    for (int i = medio; i >= inicio && A[i] == C; --i) {
        izquierdaMax++;
    }

    // Contamos caracteres C en la parte derecha desde la mitad hacia adelante
    for (int i = medio + 1; i <= fin && A[i] == C; ++i) {
        derechaMax++;
    }

    int fronteraApariciones = izquierdaMax + derechaMax;

    // Comprobar si la mejor solución está en la frontera
    if (fronteraApariciones > mejorApariciones && fronteraApariciones <= m) {
        mejorApariciones = fronteraApariciones;
        mejorPosicion = medio - izquierdaMax + 1;
    } else if (m <= (fin - inicio + 1)) {
        mejorApariciones = min(mejorApariciones, m);
    }

    return {mejorPosicion, mejorApariciones};
}

// Función recursiva para aplicar Divide y Vencerás
Solucion encontrarSubcadena(const string& A, int inicio, int fin, int m, char C) {
    if ((fin - inicio + 1)/2 < m) {
        return solucionDirecta(A, inicio, fin, m, C);
    }

    int medio = (inicio + fin) / 2;
    Solucion izquierda = encontrarSubcadena(A, inicio, medio, m, C);
    Solucion derecha = encontrarSubcadena(A, medio + 1, fin, m, C);

    return combinar(izquierda, derecha, A, inicio, medio, fin, C, m);
}

int main() {
    string A = "c";
    int m = 2;
    char c = 'c';


    struct timeval ti, tf;
    double tiempo;
    gettimeofday(&ti, NULL);

    Solucion resultado = encontrarSubcadena(A, 0, A.size() - 1, m, c);

    gettimeofday(&tf, NULL); // Instante final
    tiempo = (tf.tv_sec - ti.tv_sec)*1000 + (tf.tv_usec - ti.tv_usec)/1000.0;
    printf("Has tardado: %g milisegundos\n", tiempo);

    imp(resultado, A, c, m);
}
