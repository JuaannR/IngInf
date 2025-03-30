#include <iostream>
#include <vector>
#include <algorithm>

#include <stdio.h>
#include <chrono>

using namespace std;

// Estructura para almacenar la soluci�n de un subproblema
struct Solucion {
    int posicion;    // �ndice de inicio de la subcadena
    int apariciones; // N�mero m�ximo de apariciones consecutivas de C
};

//Imprime resultado subrayando en color la subcadena
void imprimir(Solucion resultado, const string& A, char c, int m) {
    cout << "La subcadena comienza en el caracter " << resultado.posicion + 1 << " contando desde 1" << endl;
    cout << "Numero maximo de apariciones consecutivas de '" << c << "': " << resultado.apariciones << endl;
    for (size_t i = 0; i < A.size(); ++i) {
        if (i == static_cast<size_t>(resultado.posicion)) cout << "\033[4;96m";
        cout << A[i];
        if (i == static_cast<size_t>(resultado.posicion + m -1)) cout << "\033[0m";
    }
    cout << "\033[0m" << endl;
}

//Imprime soluci�n normal por si el equipo en el que se ejecuta no soporta el subrayado
void imprime_sin_remarcar(Solucion resultado, const string& A, char c, int m) {
    cout << A << endl;
    cout << "La subcadena comienza en el caracter " << resultado.posicion + 1 << " contando desde 1" << endl;
    cout << "Numero maximo de apariciones consecutivas de '" << c << "': " << resultado.apariciones << endl;

}

// Funci�n para calcular la mejor subcadena de tama�o m de manera directa
Solucion solucionDirecta(const string& A, int inicio, int fin, int m, char c) {
    int mejorPosicion = inicio;
    int maxApariciones = 0;
    int apariciones = 0;
    while (maxApariciones < m && inicio <= fin) {
        if (A[inicio] == c) {
                ++apariciones;
                if(apariciones > maxApariciones) {
                    maxApariciones = apariciones;
                    // Encontramos la posicion de inicio de una cadena de tama�o m
                    // (o menor si la cadena tiene tama�o menor) que contiene a la subsecuencia m�s larga�del�caracter�c
                    mejorPosicion = max(min(inicio - apariciones + 1, fin-m+1),0);
                }
            } else {
                apariciones = 0;
            }
        inicio++;
    }

    return {mejorPosicion, maxApariciones};
}

// Funci�n que combina las soluciones de los subproblemas contando C consecutivos en la frontera
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

    // Contamos caracteres C en la parte izquierda desde la mitad hacia atr�s
    for (int i = medio; i >= inicio && A[i] == C && izquierdaMax < m; --i) {
        izquierdaMax++;
    }

    // Contamos caracteres C en la parte derecha desde la mitad hacia adelante
    for (int i = medio + 1; i <= fin && A[i] == C && (izquierdaMax+derechaMax) < m; ++i) {
        derechaMax++;
    }

    int fronteraApariciones = izquierdaMax + derechaMax;

    // Comprobar si la mejor soluci�n est� en la frontera
    if (fronteraApariciones > mejorApariciones) {
        mejorApariciones = fronteraApariciones;
        mejorPosicion = medio - izquierdaMax + 1;
    }
    return {mejorPosicion, mejorApariciones};
}

// Funci�n recursiva para aplicar Divide y Vencer�s
Solucion encontrarSubcadena(const string& A, int inicio, int fin, int m, char C) {

    Solucion resultado;

    //Si la subcadena es mas peque�a que m aplicamos el caso directo
    if ((fin - inicio + 1)/2 < m) {
        return solucionDirecta(A, inicio, fin, m, C);
    }

    // Si no, hacemos una nueva divisi�n
    int medio = (inicio + fin) / 2;
    Solucion izquierda = encontrarSubcadena(A, inicio, medio, m, C);
    if (izquierda.apariciones == m) {
        resultado = izquierda;
    } else {
        Solucion derecha = encontrarSubcadena(A, medio + 1, fin, m, C);
        if (derecha.apariciones == m) {
            resultado = derecha;
        } else {
            resultado = combinar(izquierda, derecha, A, inicio, medio, fin, C, m);
        }
    }

    return resultado;
}

int main() {
    //string A = "ccccccccccccccccccccccccccccccccccc";
    //string A = "hhhhcchhhh";
    string A = "hhccaaccchh";
    int m = 3;
    char c = 'a';

    chrono::time_point<chrono::high_resolution_clock> inicio = chrono::high_resolution_clock::now();

    Solucion resultado = encontrarSubcadena(A, 0, A.size() - 1, m, c);

    chrono::time_point<chrono::high_resolution_clock> fin = chrono::high_resolution_clock::now();
    auto tiempo = chrono::duration_cast<chrono::nanoseconds>(fin - inicio);

    cout << "Tiempo: " << tiempo.count() << " nanosegundos" << endl;

    imprime_sin_remarcar(resultado, A, c, m);
}
