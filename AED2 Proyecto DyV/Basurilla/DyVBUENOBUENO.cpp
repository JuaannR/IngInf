#include <iostream>
#include <vector>
#include <algorithm>

#include <fstream>

#include <stdio.h>
#include <sys/time.h>

#define TAM_MIN 99 //tamaño minimo de la cadena generada
#define TAM_MAX 1050000 //tamaño máximo de la cadena generada
#define N_MUESTRAS 1000 //número de muestras para cada caso

//constantes para las mediciones de tiempo
#define M_PRUEBAS   100
#define C_PRUEBAS   'c'

#define S_CSV ';'// carácter usado como separador en el csv

using namespace std;

// Estructura para almacenar la solución de un subproblema
struct Solucion {
    int posicion;    // Índice de inicio de la subcadena
    int apariciones; // Número máximo de apariciones consecutivas de C
};

//Imprime resultado subrayando en color la subcadena
void imprimir(Solucion resultado, const string& A, char c, int m) {
    cout << "Caso de prueba: A = \"" << A << "\", c = '" << c << "', m = " << m << endl;
    cout << "La subcadena comienza en el caracter " << resultado.posicion + 1 << " contando desde 1" << endl;
    cout << "Numero maximo de apariciones consecutivas de '" << c << "': " << resultado.apariciones << endl;
    for (size_t i = 0; i < A.size(); ++i) {
        if (i == static_cast<size_t>(resultado.posicion)) cout << "\033[4;96m";
        cout << A[i];
        if (i == static_cast<size_t>(resultado.posicion + m -1)) cout << "\033[0m";
    }
    cout << "\033[0m" << endl << endl;
}

//Imprime solución normal por si el equipo en el que se ejecuta no soporta el subrayado
void imprime_sin_remarcar(Solucion resultado, const string& A, char c, int m) {
    cout << "Caso de prueba: A = \"" << A << "\", c = '" << c << "', m = " << m << endl;
    cout << "La subcadena comienza en el caracter " << resultado.posicion + 1 << " contando desde 1" << endl;
    cout << "Numero maximo de apariciones consecutivas de '" << c << "': " << resultado.apariciones << endl << endl;

}

// Función para calcular la mejor subcadena de tamaño m de manera directa
Solucion solucionDirecta(const string& A, int inicio, int fin, int m, char c) {
    int mejorPosicion = inicio, maxApariciones = 0;
    int apariciones = 0;
    while (maxApariciones < m && inicio <= fin) {
        if (A[inicio] == c) {
            ++apariciones;
            if(apariciones > maxApariciones) {
                maxApariciones = apariciones;
                mejorPosicion = max(min(inicio - apariciones + 1, fin-m+1),0); // Encontramos la posicion de inicio de una cadena de tamaño m (o menor si la cadena tiene tamaño menor) que contiene a la subsecuencia más larga del caracter c
            }
        } else {
            apariciones = 0;
        }
        inicio++;
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
    for (int i = medio; i >= inicio && A[i] == C && izquierdaMax < m; --i) {
        izquierdaMax++;
    }

    // Contamos caracteres C en la parte derecha desde la mitad hacia adelante
    for (int i = medio + 1; i <= fin && A[i] == C && (izquierdaMax+derechaMax) < m; ++i) {
        derechaMax++;
    }

    int fronteraApariciones = izquierdaMax + derechaMax;

    // Comprobar si la mejor solución está en la frontera
    if (fronteraApariciones > mejorApariciones) {
        mejorApariciones = fronteraApariciones;
        mejorPosicion = medio - izquierdaMax + 1;
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

// Genera una cadena aleatoria de tamaño n con caracteres en [a, b]
string generarCadenaAleatoria(int n, char a, char b) {
    string cadena;
    for (int i = 0; i < n; ++i) {
        cadena += a + rand() % (b - a + 1);
    }
    return cadena;
}

// Encontrar caracter diferente a C
char getCaracterDistinto(char C) {
    char a = 'a';
    if (C == a) {
        a++;
    }
    return a;
}

// Genera una cadena con el carácter C repetido en la mejor posicion
string generarCadenaFavorable(int n, int m, char C) {
    char caracterDiferente = getCaracterDistinto(C);
    string cadena(n, caracterDiferente);
    return cadena;
}

// Genera una cadena con el carácter C en subsequencias de tamaño m-1
string generarCadenaDesfavorable(int n, int m, char C) {
    string cadena(n, C);
    return cadena;
}

// Funcion para calcular el tiempo promedio de un caso usando n muestras y verificar que el resultado sea correcto.
// Para veficar el resultado usamos la solucion sin divide y vencerás como oráculo
// Siempre se usan m y C constantes para simplificar el análisis, aunque m puede influir en el tiempo de ejecucion
double medirTiempo(const string& A) {
    struct timeval ti, tf;
    double tiempo_promedio;
    Solucion resultadoDyV;
    gettimeofday(&ti, NULL);
    for (int i = 0; i < N_MUESTRAS; i++) {
        resultadoDyV = encontrarSubcadena(A, 0, A.size() - 1, M_PRUEBAS, C_PRUEBAS);
    }
    gettimeofday(&tf, NULL); // Instante final

    Solucion resultadoEsperado = solucionDirecta(A, 0, A.size() - 1, M_PRUEBAS, C_PRUEBAS); // usamos como oráculo la funcion simple
    if ((resultadoDyV.posicion != resultadoEsperado.posicion) || (resultadoDyV.apariciones != resultadoEsperado.apariciones)) { //verificamos
        cout << "Error: El resultado del siguiente caso de estudio es incorrecto." << endl;
        cout << "Solución obtenida:" << endl;
        imprimir(resultadoDyV, A, C_PRUEBAS, M_PRUEBAS);
        cout << "Solución esperada:" << endl;
        imprimir(resultadoEsperado, A, C_PRUEBAS, M_PRUEBAS);
        tiempo_promedio = -1.0;
    } else {
        tiempo_promedio = ((tf.tv_sec - ti.tv_sec)*1000 + (tf.tv_usec - ti.tv_usec)/1000.0)/static_cast<double>(N_MUESTRAS);
    }

    return tiempo_promedio;
}

// Funcion para generar un csv con las medias de las muestras de tiempo para cada caso
void generarCSV(const std::string& nombreArchivo) {
    // Crear y abrir el archivo
    ofstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        cerr << "Error al crear el archivo csv" << endl;
        return;
    }

    // Escribir encabezados
    archivo << "TamanoCadena" << S_CSV << "T promedio mejor caso(ms)" << S_CSV << "T promedio caso promedio(ms)" << S_CSV << "T promedio peor caso(ms)" << endl;

    // Escribir datos
    double t_mejor;
    double t_promedio;
    double t_peor;
    for (int i = TAM_MIN; i<TAM_MAX; i*=2) {
        t_mejor = medirTiempo(generarCadenaFavorable(i, M_PRUEBAS, C_PRUEBAS));
        t_promedio = medirTiempo(generarCadenaAleatoria(i,'a','b'));
        t_peor = medirTiempo(generarCadenaDesfavorable(i, M_PRUEBAS, C_PRUEBAS));
        archivo << i << S_CSV << t_mejor << S_CSV << t_promedio << S_CSV << t_peor << endl;

        if (t_mejor < 0 || t_promedio < 0 || t_peor < 0) {   //asegurar que los resultados son correctos
            cerr << "Se han detectado inconsistencias en las muestras de los tiempos" << endl;
            archivo.close();
            return;
        }
    }

    archivo.close();
    cout << "Archivo CSV generado correctamente: " << nombreArchivo << endl;
}

int main() {

    char c = 'c';
    int m;
    string A;
    // Pruebas manuales
    // testing unitario de caja negra con clases de equivalencia
    // clase de equivalencia 1 : m > longitud de cadena
    m = 100; A = "hcc";
    Solucion resultado1 = encontrarSubcadena(A, 0, A.size() - 1, m, c);
    imprimir(resultado1, A, c, m);
    // clase de equivalencia 2 : m << longitud de cadena
    m = 3; A = "ckcckkccckkkccccckcckkccckkkcccc";
    Solucion resultado2 = encontrarSubcadena(A, 0, A.size() - 1, m, c);
    imprimir(resultado2, A, c, m);
    // clase de equivalencia 3 : m = longitud cadena y C no aparece
    m = 6; A = "ultima";
    Solucion resultado3 = encontrarSubcadena(A, 0, A.size() - 1, m, c);
    imprimir(resultado3, A, c, m);

    // finalmente verificamos los resultados de casos aleatorios a la vez que medimos sus tiempos
    generarCSV("analisisExperimental.csv");
}
