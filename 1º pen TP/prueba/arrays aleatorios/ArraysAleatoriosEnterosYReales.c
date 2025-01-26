#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Genera un array de enteros aleatorios entre [a,b]
void imprimir_array_enteros(int * v, int n)
{
    int a=0;
    int b=10;
    for (int i=0; i<n; i++)
    {
        v[i] = a + rand() % (b - a + 1);
        printf("%d ",v[i]);
    }
    printf("\n");
}

//Genera un array de reales aleatorios entre [a,b]
void imprimir_array_reales(double * v, int n)
{
    double a = 0;
    double b = 10;
    for (int i=0; i<n; i++)
    {
        v[i] = a+((b-a)*rand() ) / RAND_MAX;
        printf("%.2f ",v[i]);
    }
    printf("\n");
}

//lee por teclado un array de enteros
void imprimir_array_enteros_teclado(int * v, int n)
{
    for (int i=0; i<n; i++)
        printf("%d ",v[i]);
    printf("\n");
}

//lee por teclado un array de reales
void imprimir_array_reales_teclado(double * v, int n)
{
    for (int i=0; i<n; i++)
        printf("%lf ",v[i]);
    printf("\n");
}


int main ()
{
    srand(time(NULL));
    //tamaño arrays
    int n;
    printf("Introduce el tamano del array: ");
    scanf("%d",&n);

    //Array de enteros aleatorio
    int *array_enteros = malloc(sizeof(int)*n);
    printf("El array 1 es: \n");
    imprimir_array_enteros(array_enteros,n);

    //Array de reales aleatorio
    double * array_reales = malloc(sizeof(double)*n);
    printf("El array 2 es: \n");
    imprimir_array_reales(array_reales,n);


    int * array_enteros_teclado = malloc(sizeof(int)*n);
    //Asignar valores desde taclado al array 1
    for(int i = 0; i<n; i++)
    {
        printf("Introduce digito %d para el array de enteros: ",i+1);
        scanf("%d", &array_enteros_teclado[i]);
    }
    imprimir_array_enteros_teclado(array_enteros_teclado,n);

    double * array_reales_teclado = malloc(sizeof(double)*n);
        for(int i = 0; i<n; i++)
    {
        printf("Introduce digito %d para el array de reales: ",i+1);
        scanf("%lf", &array_reales_teclado[i]);
    }

    imprimir_array_reales_teclado(array_reales_teclado,n);

    free(array_enteros);
    free(array_reales);
    free(array_enteros_teclado);
    free(array_reales_teclado);

        return 0;
}
