#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int Suma(int array[], int n) {
    int sumatotal = 0;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            sumatotal = sumatotal + array[i];
        } else {
            sumatotal = sumatotal - array[i];
        }
    }

    return sumatotal;
}

int main () {

int n;
printf("Introduce el numero de elementos del array: ");
scanf("%d",&n);

int array[n];

for (int i = 0; i<n; i++) {
    printf("Escribe un entero: ");
    scanf("%d",&array[i]);
}

int sumafinal = Suma(array,n);

printf("La suma es: %d", sumafinal);

return 0;
}


