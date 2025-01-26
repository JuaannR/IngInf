#include "Cola.h"
#include <stdlib.h>
struct Celda
{
Elemento elem;
struct Celda * sig;
};
typedef struct Celda * Celda;
struct ColaRep
{
Celda frente, posterior;
};

Cola crea()
{
Cola c = malloc(sizeof(struct ColaRep));
c->frente = malloc(sizeof(struct Celda));
c->frente->sig = NULL;
c->posterior = c->frente;
return c;
}
void libera(Cola c)
{
while(c->frente!=NULL)
{
Celda aux = c->frente;
c->frente = aux->sig;
free(aux);
}
free(c);
}

void inserta(Cola c, Elemento e)
{
c->posterior->sig = malloc(sizeof(struct Celda));
c->posterior = c->posterior->sig;
c->posterior->elem = e;
c->posterior->sig = NULL;
}
void suprime(Cola c)
{
Celda eliminado = c->frente;
c->frente = eliminado->sig;
free(eliminado);
}
Elemento recupera(Cola c) { return c->frente->sig->elem; }
int vacia(Cola c) { return (c->frente->sig==NULL); }
