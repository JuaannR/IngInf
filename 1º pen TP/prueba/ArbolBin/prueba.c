#include <stdio.h>
#include <stdlib.h>

// Definici�n de la estructura del nodo del �rbol
typedef struct Nodo
{
    int elem; // Cambia "Elemento" por el tipo de dato que desees almacenar
    struct Nodo *hijoIzquierdo;
    struct Nodo *hijoDerecho;
} Nodo;

// Definici�n del tipo de dato para un �rbol binario
typedef struct Nodo *ArbolBinario;

// Funci�n para crear un �rbol de un solo nodo ra�z con un valor dado
ArbolBinario crea_arbol(int e)
{
    ArbolBinario arbol = (ArbolBinario)malloc(sizeof(Nodo));
    if (arbol != NULL)
    {
        arbol->elem = e;
        arbol->hijoIzquierdo = NULL;
        arbol->hijoDerecho = NULL;
    }
    return arbol;
}

// Funci�n para imprimir el �rbol en preorden
void imprimirPreorden(ArbolBinario raiz)
{
    if (raiz != NULL)
    {
        printf("%d ", raiz->elem);
        imprimirPreorden(raiz->hijoIzquierdo);
        imprimirPreorden(raiz->hijoDerecho);
    }
}

// Funci�n para imprimir el �rbol en inorden
void imprimirInorden(ArbolBinario raiz)
{
    if (raiz != NULL)
    {
        imprimirInorden(raiz->hijoIzquierdo);
        printf("%d ", raiz->elem);
        imprimirInorden(raiz->hijoDerecho);
    }
}

// Funci�n para liberar la memoria ocupada por el �rbol
void liberarArbol(ArbolBinario raiz)
{
    if (raiz != NULL)
    {
        liberarArbol(raiz->hijoIzquierdo);
        liberarArbol(raiz->hijoDerecho);
        free(raiz);
    }
}

int main()
{
    // Crear un �rbol con nodo ra�z 1
    ArbolBinario arbol = crea_arbol(1);

    // Crear nodos para el �rbol
    arbol->hijoIzquierdo = crea_arbol(2);
    arbol->hijoIzquierdo->hijoIzquierdo = crea_arbol(5);
    arbol->hijoDerecho = crea_arbol(4);
    arbol->hijoIzquierdo->hijoDerecho = crea_arbol(3);

    // Imprimir el �rbol en preorden
    printf("Arbol en preorden: ");
    imprimirPreorden(arbol);
    printf("\n");

    // Imprimir el �rbol en inorden
    printf("Arbol en inorden: ");
    imprimirInorden(arbol);
    printf("\n");

    // Liberar la memoria ocupada por el �rbol
    liberarArbol(arbol);

    return 0;
}

