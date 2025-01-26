#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo * Arbol;
struct Nodo
{
    int elem;
    Arbol Hijo_Izquierdo;
    Arbol Hermano_Derecho;
};

Arbol crea_arbol(int elem)
{
    Arbol a = malloc(sizeof(struct Nodo));
    a->elem = elem;
    a->Hijo_Izquierdo = NULL;
    a->Hermano_Derecho = NULL;
    return a;
}

// !!! arbol general !!!
void inorden(Arbol a)
{
    if (a == NULL) return;
    inorden(a->Hijo_Izquierdo);
    printf("%d\n", a->elem);
    Arbol aux = a->Hijo_Izquierdo;
    while (aux != NULL)
    {
        aux = aux->Hermano_Derecho;
        inorden(aux);
    }
}

void libera(Arbol a)
{
    if (a == NULL)
        return;
    libera(a->Hijo_Izquierdo);
    libera(a->Hermano_Derecho);
    free(a);
}


int suma_internos(Arbol a)
{
    if (a==NULL)
        return 0;
    if(a->Hijo_Izquierdo == NULL) {
        return a->elem+suma_internos(a->Hijo_Izquierdo)+suma_internos(a->Hijo_Izquierdo->Hermano_Derecho);
    } else {
    return 0;
    }
}


int main ()
{
    Arbol a = crea_arbol(1);
    a->Hijo_Izquierdo = crea_arbol(2);
    a->Hijo_Izquierdo->Hermano_Derecho = crea_arbol(3);
    a->Hijo_Izquierdo->Hermano_Derecho->Hermano_Derecho = crea_arbol(4);
    a->Hijo_Izquierdo->Hijo_Izquierdo = crea_arbol(5);

    printf("Inorden: \n");
    inorden(a);

    int sumadeinternos = suma_internos(a);
    printf("La suma de los nodos internos es: %d",sumadeinternos);
    return 0;
}


















