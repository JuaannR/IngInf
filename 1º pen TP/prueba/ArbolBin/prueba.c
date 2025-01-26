#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura del nodo del árbol
typedef struct Nodo
{
    int elem; // Cambia "Elemento" por el tipo de dato que desees almacenar
    struct Nodo *hijoIzquierdo;
    struct Nodo *hijoDerecho;
} Nodo;

// Definición del tipo de dato para un árbol binario
typedef struct Nodo *ArbolBinario;

// Función para crear un árbol de un solo nodo raíz con un valor dado
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

// Función para imprimir el árbol en preorden
void imprimirPreorden(ArbolBinario raiz)
{
    if (raiz != NULL)
    {
        printf("%d ", raiz->elem);
        imprimirPreorden(raiz->hijoIzquierdo);
        imprimirPreorden(raiz->hijoDerecho);
    }
}

// Función para imprimir el árbol en inorden
void imprimirInorden(ArbolBinario raiz)
{
    if (raiz != NULL)
    {
        imprimirInorden(raiz->hijoIzquierdo);
        printf("%d ", raiz->elem);
        imprimirInorden(raiz->hijoDerecho);
    }
}

// Función para liberar la memoria ocupada por el árbol
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
    // Crear un árbol con nodo raíz 1
    ArbolBinario arbol = crea_arbol(1);

    // Crear nodos para el árbol
    arbol->hijoIzquierdo = crea_arbol(2);
    arbol->hijoIzquierdo->hijoIzquierdo = crea_arbol(5);
    arbol->hijoDerecho = crea_arbol(4);
    arbol->hijoIzquierdo->hijoDerecho = crea_arbol(3);

    // Imprimir el árbol en preorden
    printf("Arbol en preorden: ");
    imprimirPreorden(arbol);
    printf("\n");

    // Imprimir el árbol en inorden
    printf("Arbol en inorden: ");
    imprimirInorden(arbol);
    printf("\n");

    // Liberar la memoria ocupada por el árbol
    liberarArbol(arbol);

    return 0;
}

