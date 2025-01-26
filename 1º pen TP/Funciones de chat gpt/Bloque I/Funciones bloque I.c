#include <stdio.h>

// Funci�n para calcular la suma de elementos de un array
int sumaArray(int arr[], int n) {
    int suma = 0;
    for (int i = 0; i < n; i++) {
        suma += arr[i];
    }
    return suma;
}

// Funci�n para calcular el producto de elementos de un array
int productoArray(int arr[], int n) {
    int producto = 1;
    for (int i = 0; i < n; i++) {
        producto *= arr[i];
    }
    return producto;
}

// Funci�n para calcular el promedio de elementos de un array
float promedioArray(int arr[], int n) {
    int suma = sumaArray(arr, n);
    return (float)suma / n;
}

// Funci�n para ordenar un array en orden ascendente
void ordenarArrayAscendente(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Funci�n para buscar un elemento en un array
int buscarElemento(int arr[], int n, int elemento) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == elemento) {
            return i;
        }
    }
    return -1;
}

// Funci�n para eliminar elementos repetidos en un array
void eliminarRepetidos(int arr[], int *n) {
    int index = 0;
    for (int i = 0; i < *n; i++) {
        int j;
        for (j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                break;
            }
        }
        if (j == i) {
            arr[index++] = arr[i];
        }
    }
    *n = index;
}

// Funci�n para invertir un array
void invertirArray(int arr[], int n) {
    int inicio = 0, fin = n - 1;
    while (inicio < fin) {
        int temp = arr[inicio];
        arr[inicio] = arr[fin];
        arr[fin] = temp;
        inicio++;
        fin--;
    }
}

// Funci�n para rotar un array a la izquierda
void rotarArrayIzquierda(int arr[], int n, int veces) {
    veces %= n;
    for (int i = 0; i < veces; i++) {
        int temp = arr[0];
        for (int j = 0; j < n - 1; j++) {
            arr[j] = arr[j + 1];
        }
        arr[n - 1] = temp;
    }
}

// Funci�n para fusionar dos arrays ordenados
void fusionarArraysOrdenados(int arr1[], int m, int arr2[], int n, int result[]) {
    int i = 0, j = 0, k = 0;
    while (i < m && j < n) {
        if (arr1[i] <= arr2[j]) {
            result[k++] = arr1[i++];
        } else {
            result[k++] = arr2[j++];
        }
    }
    while (i < m) {
        result[k++] = arr1[i++];
    }
    while (j < n) {
        result[k++] = arr2[j++];
    }
}

// Funci�n para verificar si un array es un pal�ndromo
int esPalindromo(int arr[], int n) {
    int inicio = 0;
    int fin = n - 1;
    while (inicio < fin) {
        if (arr[inicio] != arr[fin]) {
            return 0; // No es pal�ndromo
        }
        inicio++;
        fin--;
    }
    return 1; // Es pal�ndromo
}

int main() {
    // Ejemplos de uso de las funciones
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Suma: %d\n", sumaArray(arr, n));
    printf("Producto: %d\n", productoArray(arr, n));
    printf("Promedio: %.2f\n", promedioArray(arr, n));

    printf("Array original:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    ordenarArrayAscendente(arr, n);
    printf("Array ordenado en orden ascendente:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int elemento = 3;
    printf("El elemento %d se encuentra en el �ndice: %d\n", elemento, buscarElemento(arr, n, elemento));

    int arr2[] = {1, 2, 3, 3, 4, 5, 5};
    int m = sizeof(arr2) / sizeof(arr2[0]);
    eliminarRepetidos(arr2, &m);
    printf("Array sin elementos repetidos:\n");
    for (int i = 0; i < m; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    invertirArray(arr, n);
    printf("Array invertido:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    rotarArrayIzquierda(arr, n, 2);
    printf("Array rotado a la izquierda:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int arr3[] = {2, 4, 6, 8};
    int result[n + m];
    fusionarArraysOrdenados(arr, n, arr3, m, result);
    printf("Arrays fusionados y ordenados:\n");
    for (int i = 0; i < n + m; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    int arr4[] = {1, 2, 3, 2, 1};
    int o = sizeof(arr4) / sizeof(arr4[0]);
    printf("El array es pal�ndromo: %d\n", esPalindromo(arr4, o));

    return 0;
}
