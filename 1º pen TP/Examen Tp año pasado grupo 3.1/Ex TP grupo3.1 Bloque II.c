#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Nodo * Estructura;
struct Nodo
{
    int elem;
    Estructura sig;
};

//Devuelve una estructura enlazada con n>=0 valores enteros aleatorios
//en un intervalo [a,b], y el elemento actual es mayor que el anterior

Estructura crear_estructura(int n, int a, int b)
{
    Estructura e = malloc(sizeof(struct Nodo));
    if (n==0)
    {
        e->sig=NULL;
        return e;
    }
    else if (n==1)
    {
        Estructura aux = malloc(sizeof(struct Nodo));
        e->sig = aux;
        aux->elem = a + rand() % (b-a+1);
        aux->sig = NULL;
        return e;
    }
    else
    {
        Estructura aux = malloc(sizeof(struct Nodo));
        e->sig = aux;
        aux->elem = a + rand() % (b-a+1);
        for (int i = 0; i<n; i++)
        {
        Estructura nuevo = malloc(sizeof(struct Nodo));
        aux->sig = nuevo;
        a = aux->elem;
        nuevo->elem = a + rand() % (b-a+1);
        aux=aux->sig;
        }
        aux->sig=NULL;
        return e;
    }
}



void imprimir_estructura(Estructura e)
{
    Estructura aux = e->sig;
    if (e==NULL)
        printf("La estructura esta vacia");
    else if (aux->sig==NULL)
        {
            printf("%d",aux->elem);
        }
    else
    {
        while(aux->sig != NULL)
        {
            printf("%d", aux->elem);
            printf("\n");
            aux = aux->sig;
        }
    }
}

void libera(Estructura l)
{
    while (l!=NULL)
    {
        Estructura p = l;
        l = l->sig;
        free(p);
    }
}

int main ()
{
    int a = 1;
    int b = 100;
    int n;
    printf("Introduce el numero de datos: ");
    scanf("%d",&n);
    srand(time(NULL));

    Estructura serie = crear_estructura(n,a,b);
    imprimir_estructura(serie);
    libera(serie);
    return 0;
}
