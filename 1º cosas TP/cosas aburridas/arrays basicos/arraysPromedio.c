#include <stdio.h>
#include <stdlib.h>

int main ()
{
int tamano;
float suma = 0;
float promedio;

printf("Introduce el tamanyo de array: ");
scanf("%d",&tamano);

int array[tamano];

for(int i = 0; i<tamano; i++) {
    printf("Introduce el valor %d del array: ",i+1);
    scanf("%d",&array[i]);
    suma = suma + array[i];
}

for(int i = 0; i<tamano; i++) {
    printf("array[%d] = %d\n",i,array[i]);
}
    promedio = suma/tamano;
    printf("El promedio es %2.f: ",promedio);
    return 0;
}

