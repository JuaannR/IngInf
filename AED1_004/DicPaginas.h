#ifndef _DICCIONARIO
#define _DICCIONARIO

#include <list>
#include <iostream>
#include "Pagina.h"

class DicPaginas {
   private:
     std::list<Pagina> lista;
     int NumElem;
   public:
     DicPaginas ();
     void insertar (Pagina nueva);
     Pagina* consultar (std::string url);
     int getNumElem ();
};

#endif // _DICCIONARIO
