#ifndef _DICCIONARIO
#define _DICCIONARIO

#include "Pagina.h"
#include "TablaHash.h"
#include "Arbol.h"

class DicPaginas {
   private:
     TablaHash tabla; // Cambiamos la lista por una tabla hash
     Arbol arbol; //Árbol AVL
   public:
     DicPaginas();
     ~DicPaginas();
     Pagina* insertar(Pagina nueva); //insertar pagina
     Pagina* consultar(std::string url); //consultar pagina
     int getNumElem();
     void insertar (std::string palabra, Pagina *pag); //insertar palabra
     list<Pagina*> buscar (std::string palabra); //consulta paginas con palabra
};

#endif // _DICCIONARIO
