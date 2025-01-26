#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Genera números aleatorios reales
void imprimir_array(double * v, int n)
{
    double a = -10;
    double b = 10;
    for (int i=0; i<n; i++)
    {
        v[i] = a+((b-a)*rand() ) / RAND_MAX;
        printf("%.2f ",v[i]);
    }
    printf("\n");
}

// requerimientos: n ≥ 1
// Devuelve el mínimo de los elementos de v
double minimo(double * v, int n)
{
    double min = 11.0;
    for(int i = 0; i<n; i++)
    {
        if(min>v[i])
        {
            min = v[i];
        }

    }
    return min;
}

// requerimientos: 𝑛𝑛 ≥ 1
// Devuelve el máximo de los elementos de v
double maximo(double * v, int n)
{
    double max = -11.0;
    for (int i = 0; i<n; i++)
    {
        if (max < v[i])
        {
            max = v[i];
        }
    }
    return max;
}

void invertirArray(double arr[], int n) {
    int inicio = 0, fin = n - 1;
    printf("Array invertido:\n");
    while (inicio < fin) {
        double temp = arr[inicio];
        arr[inicio] = arr[fin];
        arr[fin] = temp;
        inicio++;
        fin--;
    }
    // Imprimir el array invertido
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}


int main ()
{
    int n;
    printf("Introduce el tamano del array: ");
    scanf("%d",&n);

    double * v = malloc(sizeof(double)*n);

    srand(time(NULL));
    for (int i = 0; i<n; i++)
    {
        v[i] = rand() %21-10;
    }

    printf("Los elementos del array son: ");
    imprimir_array(v,n);

    double min = minimo(v,n);
    printf("El elemento minimo del array es: %.2f\n",min);

    double max = maximo(v,n);
    printf("El elemento maximo del array es: %.2f\n",max);

    invertirArray(v,n);
    free(v);


    return 0;
}
