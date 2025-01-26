#include <stdio.h>
#include <stdlib.h>

//Función que imprime en pantalla los valores de un array
void imprimir_array(int * v, int n)
{
    for (int i=0; i<n; i++)
        printf("%d ",v[i]);
    printf("\n");
}

int * concatenar_array(int * v1, int * v2, int n, int m)
{
    int * v3 = malloc(sizeof(int)*(n+m));
    for (int i = 0; i<n; i++)
    {
        v3[i] = v1[i];
    }
    for (int i = 0; i<m; i++)
    {
        v3[n+i] = v2[i];
    }
    return v3;
}

int main ()
{
    //Tamaño array 1
    int n;
    printf("Introduce el tamano del primer array: ");
    scanf("%d",&n);
    //Crear array 1 con asignación dinámica de memoria
    int * v1 = malloc(sizeof(int)*n);
    //Asignar valores desde taclado al array 1
    for(int i = 0; i<n; i++)
    {
        printf("Introduce numero entero: ");
        scanf("%d", &v1[i]);
    }

    //Tamaño array 2
    int m;
    printf("Introduce el tamano del segundo array: ");
    scanf("%d",&m);
    //Crear array 2 con asignación dinámica de memoria
    int * v2 = malloc(sizeof(int)*m);
    //Asignar valores desde teclado al array 2
    for(int i = 0; i<m; i++)
    {
        printf("Introduce numero entero: ");
        scanf("%d", &v2[i]);
    }

    //Mostrar los valores del array en pantalla con la función imprimir_array
    printf("Los elementos del primer array son:\n");
    imprimir_array(v1,n);

    printf("Los elementos del segundo array son:\n");
    imprimir_array(v2,m);

    //Crear un tercer array que será la concatenación de los array 1 y 2
    int * v3 = concatenar_array(v1,v2,n,m);

    //Imprimir tercer array
    printf("Los elementos del tercer array son:\n");
    imprimir_array(v3,n+m);

    //Liberamos los 3 arrays
    free(v1);
    free(v2);
    free(v3);
    return 0;
}
