#include "Sesion7.h"
#include <stdlib.h>
#include <stdio.h>

int error;

char mensaje[100];

struct BomboRep
{
    int * bolas;
    int  n;
};


Bombo BomboCrea(int n)
{
    if (n<2)
    {
        error=1;
        return NULL;
    }
    Bombo b = malloc(sizeof(struct BomboRep));
    b->bolas = malloc(sizeof(int)*n);
    b->n = 0;
    return b;
}


void BomboInserta(Bombo b, int bola)
{
    b->bolas[b->n] = bola;
    b->n++;
}

void BomboLibera(Bombo b)
{
    free(b->bolas);
    free(b);
}


int BomboExtrae(Bombo b)
{
    if (b->n==0)
    {
        error=2;
        return -1;
    }
    int indice = rand()%(b->n);
    int bola = b->bolas[indice];
    b->bolas[indice]=b->bolas[b->n-1];
    b->n--;
    return bola;
}


int BomboVacia(Bombo b)
{
    return (b->n==0);
}


char * BomboMensajeError(Bombo b, int codigoError)
{
    switch(codigoError)
    {
    case 1:
    {
        sprintf(mensaje,"El numero de bolas iniciales debe ser mayor que 2.\n");
        return mensaje;
    }
    case 2:
    {
        sprintf(mensaje,"El bombo esta vacio.\n");
        return mensaje;
    }
    }
    return NULL;
}
