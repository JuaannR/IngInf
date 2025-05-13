#include <iostream>
#include <vector>
#include <algorithm>
#include <sys/time.h>

using namespace std;

//max beneficio hasta ahora
int maxBeneficioGlobal = 0;


void leerEntrada(int& nw, int& nt, vector<vector<int>>& tabla_beneficios, vector<int>& array_capacidades) {
    // Leer la tabla de beneficios
    for (int i = 0; i < nw; i++) {
        for (int j = 0; j < nt; j++) {
            cin >> tabla_beneficios[i][j];
        }
    }

    // Leer capacidades de cada trabajador
    for (int i = 0; i < nw; i++) {
        cin >> array_capacidades[i];
    }
}

// calcular beneficio máx por tarea. Se utiliza para podas
vector<int> calcularBeneficioMaxPorTrabajo(int nw, int nt, const vector<vector<int>>& tabla_beneficios) {
    vector<int> max_por_trabajo(nt, 0); //vector de tamaño num_trabajos, inicializado a 0

        //recorremos tabla por columnas para obtener el max_beneficio posible para cada trabajo
    for (int j = 0; j < nt; j++) {
        for (int i = 0; i < nw; i++) {
            max_por_trabajo[j] = max(max_por_trabajo[j], tabla_beneficios[i][j]);
        }
    }

    return max_por_trabajo;
}

// Función principal de backtracking con poda
void backtracking(
    int tareaActual,                                // Índice de la tarea que estamos asignando ahora
    int beneficioActual,                            // Beneficio acumulado hasta ahora
    int nw, int nt,                                 // Número de trabajadores y tareas
    const vector<vector<int>>& tabla_beneficios,    // Tabla de beneficios
    vector<int>& capacidades_restantes,             // Vector que indica cuántas tareas puede hacer aún cada trabajador
    const vector<int>& max_por_trabajo              // Beneficio máximo por tarea, para estimar y podar
) {
   bool continuar = true;

    // Caso base: si ya hemos asignado todas las tareas
    if (tareaActual == nt) {
        // Actualizamos beneficio si mejora el actual
        if (beneficioActual > maxBeneficioGlobal) {
            maxBeneficioGlobal = beneficioActual;
        }
        continuar = false; // No hay más tareas que asignar
    }

    // Aplicamos poda por cota superior
    if (continuar) {
        int beneficioPosible = beneficioActual;
        for (int i = tareaActual; i < nt; i++) {
            beneficioPosible += max_por_trabajo[i];
        }

        // Si la cota superior no supera el máximo, no continuamos
        if (beneficioPosible <= maxBeneficioGlobal) {
            continuar = false;
        }
    }

    // Intentamos asignar tarea actual a cada trabajador válido
    if (continuar) {
        for (int trabajador = 0; trabajador < nw; trabajador++) {
            int b = tabla_beneficios[trabajador][tareaActual];

            if (b > 0 && capacidades_restantes[trabajador] > 0) {
                capacidades_restantes[trabajador]--;

                backtracking(tareaActual + 1, beneficioActual + b, nw, nt, tabla_beneficios, capacidades_restantes, max_por_trabajo);

                capacidades_restantes[trabajador]++;
            }
        }
    }
}

// Función que inicia el proceso de búsqueda para un solo caso
int resolverCaso(int nw, int nt, const vector<vector<int>>& tabla_beneficios, const vector<int>& capacidades) {
    maxBeneficioGlobal = 0; // Reiniciamos el beneficio global para este caso

    // Inicializamos las capacidades disponibles
    vector<int> capacidades_restantes = capacidades;

    // Calculamos una heurística para podar
    vector<int> max_por_trabajo = calcularBeneficioMaxPorTrabajo(nw, nt, tabla_beneficios);

    // Llamamos al algoritmo de backtracking desde la primera tarea
    backtracking(0, 0, nw, nt, tabla_beneficios, capacidades_restantes, max_por_trabajo);

    // Retornamos el mejor beneficio encontrado
    return maxBeneficioGlobal;
}


int main() {
    int T; // Número de casos de prueba
    cin >> T;

    for (int caso = 0; caso < T; caso++) {
        int nw, nt; // número de trabajadores y de trabajos
        cin >> nw >> nt;

        vector<vector<int>> tabla_beneficios(nw, vector<int>(nt));
        vector<int> array_capacidades(nw);

        // Lectura de entrada
        leerEntrada(nw, nt, tabla_beneficios, array_capacidades);


        // Resolver caso y mostrar resultado
        int resultado = resolverCaso(nw, nt, tabla_beneficios, array_capacidades);
        cout << resultado << endl;
    }



    return 0;
}
