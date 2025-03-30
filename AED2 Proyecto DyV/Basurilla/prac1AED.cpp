#include <iostream>
#include <string>
using namespace std;

// La función devuelve un par de enteros (posición inicial, máximo de apariciones consecutivas)
pair<int, int> encontrar_mejor_subcadena(const string& A, int m, char C) {
    int n = A.size();
    int indice_subcadena = 0;        //indice mejor subcadena
    int max_chars_seguidos = 0;   // max caracteres seguidos en la subcadena

    for (int i = 0; i <= n - m; ++i) { // Recorremos todas las subcadenas de tamaño m
        string subcadena = A.substr(i, m);

        int max_actual = 0; //guarda el maximo contador encontrado
        int contador = 0;   //contador en cada subcadena

        for (char ch : subcadena) {
            if (ch == C) {
                contador++;
                if (contador > max_actual) {
                    max_actual = contador;
                }
            } else {
                contador = 0;
            }
        }

        if (max_actual > max_chars_seguidos) {
            max_chars_seguidos = min(max_actual, m);
            indice_subcadena= i;
        }
    }

    return {indice_subcadena, max_chars_seguidos};
}

int main() {
    string A = "ccabccc";
    int m = 5;
    char C = 'a';

    pair<int, int> resultado = encontrar_mejor_subcadena(A, m, C);
    cout << "Posicion de inicio: " << resultado.first +1  << endl;
    cout << "Numero de apariciones consecutivas: " << resultado.second << endl;

    return 0;
}
