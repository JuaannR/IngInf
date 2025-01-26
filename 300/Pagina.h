#include <iostream>

#ifndef _PAGINA
#define _PAGINA

class Pagina
{
private:
    int relevancia;
    std::string url, titulo;
public:
    void leer();
    void escribir();
    std::string getURL();
    int getRelev();
    void actualizar(Pagina actualizada);
};

#endif
