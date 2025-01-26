#include <stdio.h>
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
        if (a==v[i])
            return 1;
    return 0;
}

int busca_array2(int v[], int n, int a)
{
    int encontrado = 0;
    int i=0;
    while(i<n && !encontrado)
    {
        if (a==v[i]) encontrado = 1;
        i++;
    }
    return encontrado;
}
int busca_array3(int v[], int n, int a)
{
    int i=0;
    while(i<n && a!=v[i])
        i++;
    return (i<n);
}

// Definir un procedimiento que tenga, como par�metros formales, una matriz v
// de dos dimensiones de n�meros enteros, el n�mero de filas y el n�mero de columnas.
void imprimir_matriz(int filas, int columnas, int v[filas][columnas])
//void imprimir_matriz(int columnas, int v[][columnas], int filas)
//void imprimir_matriz(int filas, int columnas, int v[][columnas])
{
    for (int i=0; i<filas; i++)
    {
        for (int j=0; j<columnas; j++)
            printf("%d ",v[i][j]);
        printf("\n");
    }
    printf("\n");
}

int busca_matriz(int filas, int columnas, int v[][columnas], int a)
{
    for (int i=0; i<filas; i++)
        for (int j=0; j<columnas; j++)
            if (v[i][j]==a)
                return 1;
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
    printf("Introduce tama�o del array (mayor o igual que 0): ");
    int n;
    scanf("%d",&n);

    // Declarar un array v de enteros de tama�o n.
    int v[n];
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
    printf("Introduce un n�mero a buscar en el array: ");
    int a;
    scanf("%d",&a);

    // Desde la funci�n main() invocar la funci�n e imprimir en pantalla
    // si el elemento buscado existe o no en el array v.
    if (busca_array(v,n,a))
        printf("El elemento %d pertenece al array.\n",a);
    else
        printf("El elemento %d no pertenece al array.\n",a);

    // Repetir todo el proceso anterior para una matriz filas x columnas, con filas>=0 y columnas>=0.
    printf("Introduce n�mero de filas (mayor o igual que 0): ");
    int filas;
    scanf("%d",&filas);

    printf("Introduce n�mero de columnas (mayor o igual que 0): ");
    int columnas;
    scanf("%d",&columnas);

    int matriz[filas][columnas];
    for (int i=0; i<filas; i++)
        for (int j=0; j<columnas; j++)
        {
            printf("Introduce elemento (%d,%d): ",i,j);
            scanf("%d",&matriz[i][j]);
        }

    // Imprimir los elementos de la matriz.
    // Invocar el procedimiento desde la funci�n main().
    printf("Los elementos de la matriz son:\n");
    imprimir_matriz(filas,columnas,matriz);

    printf("Introduce un n�mero a buscar en la matriz: ");
    scanf("%d",&a);

    if (busca_matriz(filas,columnas,matriz,a))
        printf("El elemento %d pertenece a la matriz.\n",a);
    else
        printf("El elemento %d no pertenece a la matriz.\n",a);

    // Declarar una cadena de caracteres s1.
    char s1[STRING_SIZE];
    // Leer la cadena de caracteres s1 desde teclado.
    printf("Introduce una cadena de caracteres: ");
    scanf("%s",s1);

    // Comprobar si otra cadena s2, tambi�n le�da desde teclado, es igual a s1.
    char s2[STRING_SIZE];
    printf("Introduce otra cadena de caracteres: ");
    scanf("%s",s2);

    // Desde la funci�n main() invocar la funci�n e imprimir en pantalla si la cadena s2 es igual o no a la cadena s1.
    if (iguales(s1,s2))
        printf("La cadena %s es igual a la cadena %s.\n",s2,s1);
    else
        printf("La cadena %s no es igual a la cadena %s.\n",s2,s1);
    return 0;
}
