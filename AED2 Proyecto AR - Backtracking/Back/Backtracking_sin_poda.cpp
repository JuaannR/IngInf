#include <iostream>
#include <vector>
#include <algorithm>
#include <sys/time.h>

using namespace std;

// Máximo beneficio encontrado hasta ahora
int maxBeneficioGlobal = 0;

void leerEntrada(int& nw, int& nt, vector<vector<int>>& tabla_beneficios, vector<int>& array_capacidades) {
    for (int i = 0; i < nw; i++) {
        for (int j = 0; j < nt; j++) {
            cin >> tabla_beneficios[i][j];
        }
    }
    for (int i = 0; i < nw; i++) {
        cin >> array_capacidades[i];
    }
}

// Versión de backtracking sin poda
void backtrackingSinPoda(
    int tareaActual,
    int beneficioActual,
    int nw, int nt,
    const vector<vector<int>>& tabla_beneficios,
    vector<int>& capacidades_restantes
) {
    // Caso base: todas las tareas asignadas
    if (tareaActual == nt) {
        if (beneficioActual > maxBeneficioGlobal) {
            maxBeneficioGlobal = beneficioActual;
        }
        return;
    }

    // Intentamos asignar la tarea actual a cada trabajador válido
    for (int trabajador = 0; trabajador < nw; trabajador++) {
        int b = tabla_beneficios[trabajador][tareaActual];

        if (b > 0 && capacidades_restantes[trabajador] > 0) {
            capacidades_restantes[trabajador]--;

            backtrackingSinPoda(tareaActual + 1, beneficioActual + b, nw, nt, tabla_beneficios, capacidades_restantes);

            capacidades_restantes[trabajador]++;
        }
    }
}

// Función que resuelve un caso sin aplicar poda
int resolverCasoSinPoda(int nw, int nt, const vector<vector<int>>& tabla_beneficios, const vector<int>& capacidades) {
    maxBeneficioGlobal = 0;
    vector<int> capacidades_restantes = capacidades;

    backtrackingSinPoda(0, 0, nw, nt, tabla_beneficios, capacidades_restantes);

    return maxBeneficioGlobal;
}

int main() {
    int T;
    cin >> T;

    for (int caso = 0; caso < T; caso++) {
        int nw, nt;
        cin >> nw >> nt;

        vector<vector<int>> tabla_beneficios(nw, vector<int>(nt));
        vector<int> array_capacidades(nw);

        leerEntrada(nw, nt, tabla_beneficios, array_capacidades);

        struct timeval ti, tf;
        gettimeofday(&ti, NULL);

        int resultado = resolverCasoSinPoda(nw, nt, tabla_beneficios, array_capacidades);
        cout << resultado << endl;

        gettimeofday(&tf, NULL);
        double tiempo = (tf.tv_sec - ti.tv_sec)*1e6 + (tf.tv_usec - ti.tv_usec);
        double tiempo2 = (tf.tv_sec - ti.tv_sec)*1000 + (tf.tv_usec - ti.tv_usec)/1000.0;
        cerr << "Tiempo: " << tiempo << " microsegundos" << endl;
        cerr << "Tiempo: " << tiempo2 << " milisegundos" << endl;
    }

    return 0;
}
