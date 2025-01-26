#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo * Arbol;
struct Nodo
{
    int elem;
    Arbol Hijo_Izquierdo;
    Arbol Hermano_Derecho;
};

// Devuelve un árbol de un sólo nodo raíz con valor
// elem e hijo izquierdo y hermano derecho a NULL
Arbol crea_arbol(int elem)
{
    Arbol a = malloc(sizeof(struct Nodo));
    a->elem = elem;
    a->Hijo_Izquierdo = NULL;
    a->Hermano_Derecho = NULL;
    return a;
}

// Imprime en pantalla los elementos del árbol a en preorden
// !!!!!ARBOL BINARIO !!!!!
void preorden(Arbol a)
{
    if (a == NULL)
        return;
    printf("%d\n", a->elem);
    preorden(a->Hijo_Izquierdo);
    preorden(a->Hermano_Derecho);
}

void inorden(Arbol a)
{
    if (a == NULL) return;
    inorden(a->Hijo_Izquierdo);
    printf("%d\n", a->elem);
    inorden(a->Hermano_Derecho);
}

void postorden(Arbol a)
{
    if (a == NULL) return;
    postorden(a->Hijo_Izquierdo);
    postorden(a->Hermano_Derecho);
    printf("%d\n", a->elem);
}


/*int multiplica_elementos(Arbol a)
{
    if (a == NULL)
        return 1; // Si el nodo es NULL, devuelve 1 para no afectar al resultado de la multiplicación
    int multiplicacion = a->elem; // Inicializa la multiplicación con el elemento actual
    multiplicacion *= multiplica_elementos(a->Hijo_Izquierdo); // Multiplica por el resultado de recorrer el subárbol izquierdo
    multiplicacion *= multiplica_elementos(a->Hermano_Derecho); // Multiplica por el resultado de recorrer el subárbol derecho
    return multiplicacion;
}
*/

/*
 suma_hojas (ArbolBinario a)
 {
    if (a==NULL)
        return 0;
    if ((a->izq==NULL) && (a->der==NULL))
        return a->elem;
    return suma_hojas(a->izq) + suma_hojas(a->der);
 }
*/

// Devuelve el producto de los elementos del árbol a,
//  y 1 si el árbol a es vacío
int multiplicacion(Arbol a)
{
    if (a==NULL)
        return 1;
    return (a->elem)*multiplicacion(a->Hijo_Izquierdo)*multiplicacion(a->Hermano_Derecho);
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
    a->Hijo_Izquierdo->Hermano_Derecho->Hermano_Derecho->Hijo_Izquierdo = crea_arbol(5);

    printf("Preorden: \n");
    preorden(a);
    printf("Inorden: \n");
    inorden(a);
    printf("Postorden: \n");
    postorden(a);

    int mul = multiplicacion(a);
    printf("Resultado de multiplicar nodos: %d",mul);

    libera(a);
    return 0;
}
