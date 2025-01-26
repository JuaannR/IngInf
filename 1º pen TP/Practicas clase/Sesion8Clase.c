#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Nodo * Estructura;
struct Nodo {
    int elem;
    Estructura sig;
};


Estructura estructura_random(int n, int a, int b) {
    Estructura e = malloc(sizeof(struct Nodo));//Nodo encabezamiento
    e->sig = NULL;
    //insertar por el principio
    for (int i = 0; i<n; i++) {
        Estructura aux = malloc(sizeof(struct Nodo));
        aux->elem = a + rand()%(b-a+1);
        aux->sig = e->sig;
        e->sig = aux;
    }
    return e;
}

/*
Estructura estructura_random(int n, int a, int b) {
    Estructura e = malloc(sizeof(struct Nodo));//Nodo encabezamiento
    //insertar por el final
    Estructura aux = e;
    for (int i = 0; i<n; i++) {
        aux->sig = malloc(sizeof(struct Nodo));
        aux->sig->elem = a + rand()%(b-a+1);
        aux = aux->sig;
    }
    aux->sig = NULL;
    return e;
}
*/

void imprimir(Estructura e) {
    Estructura aux = e->sig;
    while(aux != NULL) {
        printf("%d",aux->elem);
        aux = aux->sig;
    }
    printf("\n");
}
Estructura concatenar(Estructura el, Estructura e2) {

    Estructura e = malloc(sizeof(struct Nodo));
    Estructura aux = e;
    while (el->sig != NULL) {
        aux->sig = malloc(sizeof(struct Nodo));
        aux->sig->elem = el->sig->elem;
        aux = aux->sig;
        el = el->sig;
}

     while (e2->sig != NULL) {
        aux->sig = malloc(sizeof(struct Nodo));
        aux->sig->elem = e2->sig->elem;
        aux = aux->sig;
        e2 = e2->sig;

    }
    aux->sig = NULL;
    return e;
}

int main () {

    int n, a, b;    //listas con valores entre a y b
    n = 10;
    a = 1;
    b = 10;

    srand(time(NULL));

    Estructura el = estructura_random(n,a,b);
    imprimir(el);

    int m=5;

    Estructura e2 = estructura_random(m,a,b);
    imprimir(e2);
    Estructura e3 = concatenar(el,e2);
    imprimir(e3);
return 0;
}
