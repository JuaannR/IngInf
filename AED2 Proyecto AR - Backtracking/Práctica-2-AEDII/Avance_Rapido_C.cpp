#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <math.h>
using namespace std;

// Carga la matriz de distancias
vector<vector<int>> leerMatrizDistancias(int n) {
    vector<vector<int>> distancias(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> distancias[i][j];
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

            //cout << "fffff";
    return peorElemento;
}

// Algoritmo voraz principal para seleccionar el subconjunto
bool algoritmoVoraz(const vector<vector<int>>& distancias, int m, vector<int>& seleccionados) {
    int n = distancias.size();

    if(m > static_cast<int>(round(sqrt((n * (n + 1)) / 2.0)))) { // Si m supera a a la raiz de ((n * (n + 1)) / 2) es más rentable en tiempo de ejecución empezar cogiendo todos y sacar los que no se cogen
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

int main() {
    int T;
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
    }

    return 0;
}