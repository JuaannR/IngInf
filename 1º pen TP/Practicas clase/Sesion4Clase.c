#include <stdio.h>
#define MAX_STRING_SIZE 100

void imprimir_array(int v[], int n) {
    for (int i = 0; i < n; i++)
        printf("v[%d]=%d\n", i, v[i]);
}

int busca_array3(int v[], int n, int a) {
    int i = 0;
    while (i < n && v[i] != a)
        i++;
    return (i < n);
}

void imprimir_matriz(int columnas, int filas, int matriz[filas][columnas]) {
    for (int i = 0; i < filas; i++)
        for (int j = 0; j < columnas; j++)
            printf("matriz[%d][%d]=%d\n", i, j, matriz[i][j]);
}

int busca_matriz(int columnas, int filas, int matriz[filas][columnas], int a) {
    for (int i = 0; i < filas; i++)
        for (int j = 0; j < columnas; j++)
            if (matriz[i][j] == a)
                return 1;
    return 0;
}

int main() {
    int n;
    printf("Introduce el numero de elementos del array: ");
    scanf("%d", &n);
    int v[n];
    for (int i = 0; i < n; i++) {
        printf("Introduce el elemento v[%d]: ", i);
        scanf("%d", &v[i]);
    }
    imprimir_array(v, n);
    printf("Introduce un elemento a buscar en el array: ");
    int a;
    scanf("%d", &a);
    if (busca_array3(v, n, a))
        printf("Encontrado\n");
    else
        printf("No encontrado\n");

    int filas, columnas;
    printf("Introduce numero de filas: ");
    scanf("%d", &filas);
    printf("Introduce el numero de columnas: ");
    scanf("%d", &columnas);
    int matriz[filas][columnas];

    for (int i = 0; i < filas; i++)
        for (int j = 0; j < columnas; j++) {
            printf("Introduce el elemento matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    imprimir_matriz(columnas, filas, matriz);
    printf("Introduce un elemento a buscar en la matriz: ");
    scanf("%d", &a);

    char S1[MAX_STRING_SIZE];
    printf("Introduce cadena: ");
    scanf("%s", S1);

    return 0;
}
