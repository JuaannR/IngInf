#ifndef TABLAHASH_H
#define TABLAHASH_H
#include <string>
#include <list>
#include "Pagina.h"

using namespace std;

class TablaHash {
private:
    list<Pagina>* tabla; // Cada �ndice almacena una lista de p�ginas
    int nElem; // N�mero de elementos en la tabla
    int tam; //nº de cubetas
    void reestructurar();
    unsigned int funcion(const std::string& url); // Funci�n de dispersi�n
public:
    TablaHash();
    ~TablaHash();
    Pagina* inserta(Pagina nueva);
    Pagina* consulta(string url);
    int getNumElem();
};

#endif
