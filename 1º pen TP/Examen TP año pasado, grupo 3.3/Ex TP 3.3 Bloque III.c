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

void postorden(Arbol a)
{
    if (a == NULL) return;
    postorden(a->Hijo_Izquierdo);
    postorden(a->Hermano_Derecho);
    printf("%d\n", a->elem);
}

// Devuelve el número de nodos internos del árbol a
int nodos_internos(Arbol a)
{
    if (a==NULL || a->Hijo_Izquierdo==NULL)
        return 0;
    int cont = 1;
    Arbol aux = a->Hijo_Izquierdo;
    while(aux != NULL)
    {
        cont += nodos_internos(aux);
        aux = aux->Hermano_Derecho;
    }
    return cont;
}

// Libera la memoria del árbol a
void libera(Arbol a)
{
    if (a == NULL)
        return;
    libera(a->Hijo_Izquierdo);
    libera(a->Hermano_Derecho);
    free(a);
}

int main ()
{
    Arbol a = crea_arbol(1);
    a->Hijo_Izquierdo = crea_arbol(2);
    a->Hijo_Izquierdo->Hermano_Derecho = crea_arbol(3);
    a->Hijo_Izquierdo->Hermano_Derecho->Hermano_Derecho = crea_arbol(4);
    a->Hijo_Izquierdo->Hijo_Izquierdo = crea_arbol(5);

    printf("Postorden: \n");
    postorden(a);

    int ninternos = nodos_internos(a);
    printf("Hay %d nodos internos",ninternos);

    libera(a);
    return 0;
}
