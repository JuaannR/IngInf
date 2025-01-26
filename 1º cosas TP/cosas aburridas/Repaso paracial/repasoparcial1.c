#include <stdio.h>
#include <math.h>

int Suma(int array[], int n) {
    int sumatotal=0;
    for(int i=0;i<n;i++) {
        sumatotal = sumatotal + pow(array[i],2);
    }
    return sumatotal;
}
int main () {

    int n;
    printf("Escribe el numero de elementos del array: ");
    scanf("%d",&n);

    int array[n];
    for(int i=0;i<n;i++) {
        printf("Escribe un entero: ");
        scanf("%d",&array[i]);
    }

    int sumafinal = Suma(array,n);
    printf("La suma de los cuadrados es: %d",sumafinal);

return 0;
}
