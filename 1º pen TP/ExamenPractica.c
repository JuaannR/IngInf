#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <windows.h>
//FUNCIONES BLOQUE I
void imprimir(int * v, int n)
{
    printf("\n Array: \n");
    for(int i=0;i<n;i++)
        printf("v[%d] = %d\n",i+1,v[i]);
}

int * concatenar(int * v1, int * v2, int n, int m)
{
    int *v3 = malloc((n+n)*sizeof(int));
    for(int i=0; i<n; i++)
        v3[i]=v1[i];

    for(int i=0; i<m; i++)
        v3[n+i]=v2[i];
    return v3;
}
//FUNCIONES BLOQUE II
typedef int Elemento;
typedef struct Nodo * Estructura;
struct Nodo
{
    Elemento elem;
    Estructura sig;
};

Estructura progresion_geometrica(int n, int q, int r)
{
    Estructura l = malloc(sizeof(struct Nodo));
    Estructura aux = l;
    for(int i=0; i<n; i++)
    {
        aux->sig = malloc(sizeof(struct Nodo));
        aux = aux->sig;
        aux->elem=q*pow(r,i);
    }
    aux->sig=NULL;
    return l;
}
void imprime(Estructura l)
{
    l = l->sig;
    while (l != NULL)
    {
        printf("%d\n", l->elem);
        l = l->sig;
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
//FUNCIONES BLOQUE III
struct NodoGen
{
    int elem;
    struct NodoGen * hijoIzquierdo, * hermanoDerecho;
};

typedef struct NodoGen * ArbolGeneral;

ArbolGeneral crea_arbol(int elem)
{
    ArbolGeneral nuevo = malloc(sizeof(struct Nodo));
    nuevo->elem = elem;
    nuevo->hijoIzquierdo = NULL;
    nuevo->hermanoDerecho = NULL;
return nuevo;
}

void postorden_gen1(ArbolGeneral a)
{

    if (a == NULL) return;
    ArbolGeneral aux= a->hijoIzquierdo;
    while(aux!= NULL)
    {
        postorden_gen1(aux);
        aux= aux->hermanoDerecho;
    }
    printf("%d ", a->elem);
}
void liberar(ArbolGeneral a)
{
    if (a == NULL) return;
    liberar(a->hijoIzquierdo);
    liberar(a->hermanoDerecho);
    free(a);
}

int nodos_internos(ArbolGeneral a) {
    if (a == NULL) return 0;
    if (a->hijoIzquierdo == NULL) return 0;
    return 1 + nodos_internos(a->hijoIzquierdo) + nodos_internos(a->hermanoDerecho);
}

int main(){
//MAIN BLOQUE  I
    int n, m;

    // Pide al usuario que ingrese el tamaño de los arrays
    printf("Ingrese el tamaño del primer array: ");
    scanf("%d", &n);
    printf("Ingrese el tamaño del segundo array: ");
    scanf("%d", &m);

    // Asigna memoria dinámica para los arrays
    int *v1 = malloc(n * sizeof(int));
    int *v2 = malloc(m * sizeof(int));


    // Lee los elementos del primer array desde el teclado
    printf("Ingrese los elementos del primer array:\n");
    for (int i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &v1[i]);
    }


    // Leer los elementos del segundo array desde el teclado
    printf("Ingrese los elementos del segundo array:\n");
    for (int i = 0; i < m; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &v2[i]);
    }
    int *v3 = concatenar(v1,v2,n,m);
    int l = m+n;
    imprimir(v1,n);
    imprimir(v2,m);
    imprimir(v3,l);
    // Liberar la memoria asignada a los arrays
    free(v1);
    free(v2);
    free(v3);

//MAIN BLOQUE II
    int o = 5;
    int q = 5;
    int r = 3;
    printf("La progresion geometrica seria:\n");
    Estructura e=progresion_geometrica(o,q,r);
    imprime(e);
    printf("\n");
    libera(e);

//MAIN BLOQUE III
    ArbolGeneral agen = crea_arbol(1);
    agen->hijoIzquierdo=crea_arbol(2);
    agen->hijoIzquierdo->hijoIzquierdo=crea_arbol(5);
    agen->hijoIzquierdo->hermanoDerecho=crea_arbol(3);
    agen->hijoIzquierdo->hermanoDerecho->hermanoDerecho=crea_arbol(4);

    printf("Postorden v1 (con bucle): ");
    postorden_gen1(agen);
    printf("\n");

    printf("Nodos internos: %d\n", nodos_internos(agen));

    liberar(agen);
    return 0;
}
