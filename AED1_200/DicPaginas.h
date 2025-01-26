#ifndef _DICCIONARIO
#define _DICCIONARIO

#include "Pagina.h"
#include "TablaHash.h"

class DicPaginas {
   private:
     TablaHash tabla; // Cambiamos la lista por una tabla hash
   public:
     DicPaginas();
     void insertar(Pagina nueva);
     Pagina* consultar(std::string url);
     int getNumElem();
};

#endif // _DICCIONARIO
