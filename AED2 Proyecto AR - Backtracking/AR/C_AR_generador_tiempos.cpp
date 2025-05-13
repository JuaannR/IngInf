#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>


#include <random>
#include <stdio.h>
#include <sys/time.h>

#define MAX_VALUE 1000

using namespace std;

// Carga la matriz de distancias
vector<vector<int>> leerMatrizDistancias(int n) {
    vector<vector<int>> distancias(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> distancias[i][j];
    return distancias;
}

// Carga la matriz de distancias mejor
vector<vector<int>> generarMejorMatrizDistancias(int n) {
    vector<vector<int>> distancias(n, vector<int>(n,0));
    return distancias;
}

// Carga la matriz de distancias promedio
vector<vector<int>> generarPromedioMatrizDistancias(int n) {
    vector<vector<int>> distancias(n, vector<int>(n));

    // Configurar generador de números aleatorios para todos los int posibles
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribucion(0, MAX_VALUE); // Valores de 0 a MAX_VALUE

    // Llenar la matriz: diagonal 0, resto aleatorios
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            distancias[i][j] = (i == j) ? 0 : distribucion(gen);
        }
    }

    return distancias;
}

// Carga la matriz de distancias peor
vector<vector<int>> generarPeorMatrizDistancias(int n) {
    vector<vector<int>> distancias(n, vector<int>(n));

    // Configurar generador de números aleatorios para todos los int posibles
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribucion(MAX_VALUE/2, MAX_VALUE); // Valores altos y parecidos

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            distancias[i][j] = (i == j) ? 0 : distribucion(gen); // Valores altos y similares para forzar comparaciones costosas;
        }
    }
    return distancias;
}

// Suma total de distancias entre los elementos seleccionados
int calcularDiversidad(const vector<vector<int>>& distancias, const vector<int>& seleccionados) {
    int suma = 0;
    for (size_t i = 0; i < seleccionados.size(); ++i)
        for (size_t j = i + 1; j < seleccionados.size(); ++j)
            suma += distancias[seleccionados[i]][seleccionados[j]] + distancias[seleccionados[j]][seleccionados[i]];
    return suma;
}

// Selecciona el candidato inicial: escogemos aquel con mayor suma de distancias ya que esta es una buena heurística
int seleccionarElementoInicial(const vector<vector<int>>& distancias) {
    int mejorIndice = -1;
    int mejorSuma = -1;
    for (size_t i = 0; i < distancias.size(); ++i) {
        int suma = 0;
        for (size_t j = 0; j < distancias.size(); ++j)
            suma += distancias[i][j];
        if (suma > mejorSuma) {
            mejorSuma = suma;
            mejorIndice = i;
        }
    }
    return mejorIndice;
}

// Selecciona el siguiente mejor candidato que más contribuye a la diversidad actual
int seleccionarMejorCandidato(const vector<vector<int>>& distancias, const vector<int>& candidatos, const vector<int>& seleccionados) {
    int mejorElemento = -1;
    int mejorContribucion = -1;
    for (int candidato : candidatos) {
        int suma = 0;
        for (int seleccionado : seleccionados)
            suma += distancias[candidato][seleccionado] + distancias[seleccionado][candidato];
        if (suma > mejorContribucion) {
            mejorContribucion = suma;
            mejorElemento = candidato;
        }
    }
    return mejorElemento;
}

// Selecciona el siguiente mejor candidato que más contribuye a la diversidad actual
int seleccionarPeor(const vector<vector<int>>& distancias, const vector<int>& seleccionados) {
    int peorElemento = -1;
    int peorContribucion = numeric_limits<int>::max();
    for (int candidato : seleccionados) {
        int suma = 0;
        for (int seleccionado : seleccionados)
            suma += distancias[candidato][seleccionado] + distancias[seleccionado][candidato];
        if (suma < peorContribucion) {
            peorContribucion = suma;
            peorElemento = candidato;
        }
    }
    return peorElemento;
}

// Algoritmo voraz principal para seleccionar el subconjunto
bool algoritmoVoraz(const vector<vector<int>>& distancias, int m, vector<int>& seleccionados) {
    int n = distancias.size();

    if(m > static_cast<int>(round(sqrt((n * (n + 1)) / 2.0)))) { // Si m supera a la raiz de ((n * (n + 1)) / 2) es más rentable en tiempo de ejecución empezar cogiendo todos y sacar los que no se cogen
        // Seleccionar todos los elementos
        seleccionados.resize(n);
        for (int i = 0; i < n; ++i) seleccionados[i] = i;
        // Desseleccionar hasta tener m elementos
        while (seleccionados.size() > static_cast<size_t>(m)) {
            int siguiente = seleccionarPeor(distancias, seleccionados);
            seleccionados.erase(remove(seleccionados.begin(), seleccionados.end(), siguiente), seleccionados.end());
        }
    } else if (m == 0){
    } else { // Si m  no supera a la raiz de ((n * (n + 1)) / 2) es más rentable en tiempo de ejecución empezar desde 0 e ir añadiendo el mejor candidato
        // Generar el conjunto inicial de candidatos
        vector<int> candidatos(n);
        for (int i = 0; i < n; ++i) candidatos[i] = i;

        // Selección del primer elemento inicial
        int inicial = seleccionarElementoInicial(distancias);
        seleccionados.push_back(inicial);
        candidatos.erase(remove(candidatos.begin(), candidatos.end(), inicial), candidatos.end());

        // Seleccionar hasta tener m elementos
        while (seleccionados.size() < static_cast<size_t>(m) && !candidatos.empty()) {
            int siguiente = seleccionarMejorCandidato(distancias, candidatos, seleccionados);
            if (siguiente == -1) return false;
            seleccionados.push_back(siguiente);
            candidatos.erase(remove(candidatos.begin(), candidatos.end(), siguiente), candidatos.end());
        }
    }


    return seleccionados.size() == static_cast<size_t>(m);
}

// Imprime la salida según el formato requerido
void imprimirResultado(const vector<int>& seleccionados, int diversidad, int n) {
    cout << diversidad << endl;
    vector<int> binario(n, 0);
    for (int idx : seleccionados)
        binario[idx] = 1;
    for (int i = 0; i < n; ++i)
        cout << binario[i] << (i < n - 1 ? " " : "\n");
}

// Para probar tiempos
double probar(const vector<vector<int>>& distancias, int m) {
        vector<int> seleccionados;

        struct timeval ti, tf;
        gettimeofday(&ti, NULL);

        bool exito = algoritmoVoraz(distancias, m, seleccionados);

        gettimeofday(&tf, NULL); // Instante final
        double tiempo = ((tf.tv_sec - ti.tv_sec)*1000 + (tf.tv_usec - ti.tv_usec)/1000.0);

        /*if (!exito) {
            cout << "No se puede encontrar solución" << endl;
        } else {
            int diversidad = calcularDiversidad(distancias, seleccionados);
            // imprimirResultado(seleccionados, diversidad, distancias.size());
            cout << "Tiempo: " << tiempo << "ms." << "m=" << m << endl;
        }*/
        return tiempo;
}

int main() {
    /*int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> distancias = leerMatrizDistancias(n);
        vector<int> seleccionados;

        bool exito = algoritmoVoraz(distancias, m, seleccionados);

        if (!exito) {
            cout << "No se puede encontrar solución" << endl;
        } else {
            int diversidad = calcularDiversidad(distancias, seleccionados);
            imprimirResultado(seleccionados, diversidad, n);
        }
    }*/

    // Para generador de números aleatorios
    random_device rd;
    mt19937 gen(rd());

    vector<vector<int>> distancias;
    int m;
    for(int n = 100; n<130000; n*=2) {
        cout << "n=" << n << endl;
        // Caso Mejor
        m = 0; // En el mejor caso m es 0
        distancias = generarMejorMatrizDistancias(n);
        cout << "Caso mejor: " << probar(distancias, m) << "ms" << endl;
        // Caso Promedio
        double tiempoTotal = 0;
        uniform_int_distribution<int> distribucion(0, n); // Configurar generador para generar m aleatoria entre 0 y n
        for (int i = 0; i<=10; i++) {
            distancias = generarPromedioMatrizDistancias(n);
            // generar m aleatoria entre 0 y n
            //m = distribucion(gen);
            m=i*n/10; //usar una m asi produce una media similar a generar m aleatorias con más muestras
            tiempoTotal += probar(distancias, m);
        }
        cout << "Tiempo promedio = " << tiempoTotal/10 << "ms" << endl;
        // Caso Peor
        m = static_cast<int>(round(sqrt((n * (n + 1)) / 2.0))); // En el peor caso m = raiz de ((n * (n + 1)) / 2)
        distancias = generarPromedioMatrizDistancias(n);
        cout << "Caso peor: " << probar(distancias, m) << "ms" << endl;
        cout << endl;
    }

    return 0;
}
