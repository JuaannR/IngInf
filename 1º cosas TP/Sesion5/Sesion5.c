#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define STRING_SIZE 100

// Definir un procedimiento que tenga, como par�metros formales,*
// un array v de enteros y su n�mero n de elementos.
void imprimir_array(int v[], int n)
{
    for (int i=0; i<n; i++)
        printf("%d ",v[i]);
    printf("\n");
}

// Definir una funci�n que tenga, como par�metros formales, un array v de enteros,
// su n�mero n de elementos, y el numero a buscar, y devuelva un entero
// que represente un valor booleano.
int busca_array(int v[], int n, int a)
{
    for (int i=0; i<n; i++)
        if (a==v[i]) return 1;
    return 0;
}


// Definir un procedimiento que tenga, como par�metros formales, una matriz v
// de dos dimensiones de n�meros enteros, el n�mero de filas y el n�mero de columnas.
void imprimir_matriz(int ** v, int filas, int columnas)
{
    for (int i=0; i<filas; i++)
    {
        for (int j=0; j<columnas; j++)
            printf("%d ",v[i][j]);
        printf("\n");
    }
    printf("\n");
}


int busca_matriz(int filas, int columnas, int * v[], int a)
{
    for (int i=0; i<filas; i++)
        for (int j=0; j<columnas; j++)
            if (v[i][j]==a) return 1;
    return 0;
}

int iguales(char * s1, char *s2) // Versi�n iterativa
{
    int i=0;
    while ((s1[i]!=0) && (s2[i]!=0) && (s1[i]==s2[i]))
        i++;
    return (s1[i]==s2[i]);
}


int main()
{
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    // Leer un n�mero n>=0 desde teclado.
    int n;
    printf("Introduce tama�o del array (mayor o igual que 0): ");
    scanf("%d",&n);

    // Declarar un array v de enteros de tama�o n.
    int * v = malloc(n*sizeof(int));

    // Leer n n�meros enteros desde teclado y asignarlos a los elementos del
    // array v de forma consecutiva (sin definir una funci�n para ello).
    for (int i=0; i<n; i++)
    {
        printf("Introduce elemento %d: ",i);
        scanf("%d",&v[i]);
    }

    // Imprimir los elementos del array v.
    // Invocar el procedimiento desde la funci�n main().
    printf("Los elementos del array son:\n");
    imprimir_array(v,n);

    // Compobar si otro n�mero, tambi�n le�do desde teclado, pertenece al array v.
    int a;
    printf("Introduce un n�mero a buscar en el array: ");
    scanf("%d",&a);

    // Desde la funci�n main() invocar la funci�n e imprimir en pantalla
    // si el elemento buscado existe o no en el array v.
    if (busca_array(v,n,a))
        printf("El elemento %d pertenece al array.\n",a);
    else
        printf("El elemento %d no pertenece al array.\n",a);

    // Repetir todo el proceso anterior para una matriz filas x columnas, con filas>=0 y columnas>=0.
    printf("Introduce numero de filas (mayor o igual que 0): ");
    int filas;
    scanf("%d",&filas);


    int columnas;
    printf("Introduce n�mero de columnas (mayor o igual que 0): ");
    scanf("%d",&columnas);

    // ASIGNAR MEMORIA DIN�MICA PARA UNA MATRIZ DE DOS DIMENSIONES
    // Asigna memoria para los punteros a las filas
    int ** matriz = malloc(filas*sizeof(int*));
    // Asigna memoria para los elementos de cada una de las filas
    for(int i=0; i<filas; i++)
        matriz[i] = calloc(columnas,sizeof(int));
    for (int i=0; i<filas; i++)
        for (int j=0; j<columnas; j++)
        {
            printf("Introduce elemento (%d,%d): ",i,j);
            scanf("%d",&matriz[i][j]);
        }

    // Imprimir los elementos de la matriz.
    // Invocar el procedimiento desde la funci�n main().
    printf("Los elementos de la matriz son:\n");
    imprimir_matriz(matriz,filas,columnas);

    printf("Introduce un n�mero a buscar en la matriz: ");
    scanf("%d",&a);

    if (busca_matriz(filas,columnas,matriz,a))
        printf("El elemento %d pertenece a la matriz.\n",a);
    else
        printf("El elemento %d no pertenece a la matriz.\n",a);


    // Declarar una cadena de caracteres s1.
    char * s1 = malloc(STRING_SIZE*sizeof(char));
    // Leer la cadena de caracteres s1 desde teclado.
    printf("Introduce una cadena de caracteres: ");
    scanf("%s",s1);

    // Comprobar si otra cadena s2, tambi�n le�da desde teclado, es igual a s1.
    char * s2 = malloc(STRING_SIZE*sizeof(char));;
    printf("Introduce otra cadena de caracteres: ");
    scanf("%s",s2);

    // Desde la funci�n main() invocar la funci�n e imprimir en pantalla si la cadena s2 es igual o no a la cadena s1.
    if (iguales(s1,s2))
        printf("La cadena %s es igual a la cadena %s.\n",s2,s1);
    else
        printf("La cadena %s no es igual a la cadena %s.\n",s2,s1);

    // Aumentar (o disminuir) el tama�o del array v a un nuevo tama�o le�do desde teclado,
    // usando la funci�n realloc.
    int nuevo_tam;
    printf("Introduce nuevo tama�o del array (mayor o igual que 0): ");
    scanf("%d",&nuevo_tam);
    v=realloc(v,sizeof(int)*nuevo_tam);

    // Leer desde teclado los nuevos elementos si el nuevo tama�o del array es mayor que el anterior.
    for (int i=n; i<nuevo_tam; i++)
    {
        printf("Introduce elemento %d: ",i);
        scanf("%d",&v[i]);
    }
    // Imprimir los elementos del nuevo array v.
    // Invocar el procedimiento desde la funci�n main().
    printf("Los elementos del array son:\n");
    imprimir_array(v,nuevo_tam);
    // Aumentar (o disminuir) el n�mero de filas de la matriz
    // a un nuevo tama�o le�do desde teclado usando las funciones realloc y calloc.
    int nuevo_filas;
    printf("Introduce nuevo n�mero de filas de la matriz (mayor o igual que 0): ");
    scanf("%d",&nuevo_filas);
    // Liberar filas si el nuevo tama�o es menor que el anterior
    for(int i=nuevo_filas; i<filas; i++)
        free(matriz[i]);
    matriz=realloc(matriz,sizeof(int*)*nuevo_filas);
    for(int i=filas; i<nuevo_filas; i++)
        matriz[i]=calloc(columnas,sizeof(int));
    // Leer desde teclado los nuevos elementos en su caso.
    for (int i=filas; i<nuevo_filas; i++)
        for (int j=0; j<columnas; j++)
        {
            printf("Introduce elemento (%d,%d): ",i,j);
            scanf("%d",&matriz[i][j]);
        }
    // Imprimir los elementos de la nueva matriz.
    // Invocar el procedimiento desde la funci�n main().
    printf("Los elementos de la nueva matriz son:\n");
    imprimir_matriz(matriz, nuevo_filas, columnas);

    // Aumentar (o disminuir) el n�mero de columnas de la matriz
    // a un nuevo tama�o le�do desde teclado usando la funci�n realloc.
    int nuevo_columnas;
    printf("Introduce nuevo n�mero de columnas de la matriz (mayor o igual que 0): ");
    scanf("%d",&nuevo_columnas);
    for(int i=0; i<nuevo_filas; i++)
        matriz[i]=realloc(matriz[i],sizeof(int)*nuevo_columnas);
    // Leer desde teclado los nuevos elementos en su caso.
    for (int i=0; i<nuevo_filas; i++)
        for (int j=columnas; j<nuevo_columnas; j++)
        {
            printf("Introduce elemento (%d,%d): ",i,j);
            scanf("%d",&matriz[i][j]);
        }
    // Imprimir los elementos de la nueva matriz.
    // Invocar el procedimiento desde la funci�n main().
    printf("Los elementos de la nueva matriz son:\n");
    imprimir_matriz(matriz, nuevo_filas, nuevo_columnas);
    // Liberar toda la memoria din�mica asignada.
    free(v);
    for(int i=0; i<nuevo_filas; i++)
        free(matriz[i]);
    free(matriz);
    free(s1);
    free(s2);
    return 0;
}
