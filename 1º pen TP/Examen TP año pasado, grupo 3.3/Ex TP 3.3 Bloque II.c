#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo * Estructura;
struct Nodo
{
    int elem;
    Estructura sig;
};

// requerimientos: n ≥ 1
// Devuelve una estructura enlazada con n elementos de la
// sucesión q*r^0 , q*r^1 , q*r^2...
Estructura progresion_geometrica(int n, int q, int r)
{
    Estructura e = malloc(sizeof(struct Nodo));
    if (n==1)
    {
        Estructura aux = malloc(sizeof(struct Nodo));
        e->sig = aux;
        aux -> elem = q;
        aux ->sig = NULL;
        return e;
    } else
    {
        Estructura aux = malloc(sizeof(struct Nodo));
        e->sig = aux;
        aux->elem = q;
        for(int i = 0; i<n; i++)
        {
         Estructura nuevo = malloc(sizeof(struct Nodo));
         aux->sig = nuevo;
         nuevo->elem = r*(aux->elem);
         aux = aux->sig;
        }
        aux->sig = NULL;
        return e;
    }
}

void imprimir_estructura(Estructura e)
{
    if (e==NULL)
        printf("La estructura esta vacia");
    else if (aux->sig==NULL)
        {
            Estructura aux = e->sig;
            printf("%d",aux->elem);
        }
    else {
            Estructura aux = e->sig;
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
    int q=5;
    int r=3;
    printf("Introduce el numero de elementos de la estructura: ");
    scanf("%d",&n);

    Estructura serie = progresion_geometrica(n,q,r);
    imprimir_estructura(serie);

    libera(serie);

    return 0;
}
