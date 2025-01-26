#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Nodo * Estructura;
struct Nodo
{
    int elem;
    Estructura sig;
};


int factorial(int n)
{
    if (n <= 1)
        return 1;
    else
        return n * factorial(n - 1);
}


Estructura serie_factorial(int n)
{
    Estructura e = malloc(sizeof(struct Nodo));
     e->elem = NULL;
    if(n==0)
    {
        e->sig=NULL;
    }
    else if(n==1)
    {
        Estructura aux = malloc(sizeof(struct Nodo));
        e->sig = aux;
        aux->elem = n;
        aux->sig = NULL;
        return e;
    }
    else
    {
        Estructura aux = malloc(sizeof(struct Nodo));
        e->sig = aux;
        aux->elem = 1;

        for (int i = 1; i<=n; i++)
        {
            Estructura nuevo = malloc(sizeof(struct Nodo));
            aux->sig = nuevo;
            nuevo->elem = factorial(i);
            aux = aux ->sig;
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
    int n;
    printf("Introduce el numero de elementos de la estructura: ");
    scanf("%d",&n);

    Estructura serie = serie_factorial(n);
    imprimir_estructura(serie);

    libera(serie);
    return 0;
}











