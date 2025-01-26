#include <stdio.h>
#include <stdlib.h>

int main ()
{
int tamano;

printf("Introduce el tamanyo de array: ");
scanf("%d",&tamano);

int array[tamano];

for(int i = 0; i<tamano; i++) {
    printf("Introduce el valor %d del array: ",i+1);
    scanf("%d",&array[i]);
}

for(int i = 0; i<tamano; i++) {
    printf("array[%d] = %d\n",i,array[i]);
}
    return 0;
}

