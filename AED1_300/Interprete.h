#ifndef INTERPRETE_H
#define INTERPRETE_H
#include<string>
#include<iostream>
#include "DicPaginas.h"

using namespace std;

class Interprete
{
private:
    DicPaginas dic;
    void INSERTAR();
    void BUSCA_URL();
    void BUSCA_PAL();
    void AND();
    void OR();
    void AUTOCOMPLETAR();
    string normalizar(string cadena);
public:
    void Interpretar(char comando);
};


#endif
