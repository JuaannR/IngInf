
#include "DicPaginas.h"
#include "Pagina.h"
#include <list>
#include <iostream>

DicPaginas::DicPaginas ()
{
    NumElem = 0 ;
}

void DicPaginas::insertar (Pagina nueva)
{
    std::list<Pagina>::iterator it = lista.begin();
    while ((it!=lista.end()) && (it->getURL() < nueva.getURL())) it++;
    if ((it == lista.end()) || (it->getURL() != nueva.getURL()))
    {
        lista.insert(it, nueva);
        NumElem++;
    }
    else
    {
         *it = nueva;
    }
}

Pagina* DicPaginas::consultar (std::string url)
{
    Pagina * pagina = NULL;

    std::list<Pagina>::iterator it = lista.begin();
    while ((it!=lista.end()) && (it->getURL() < url)) it++;
    if ((it != lista.end()) && (it->getURL() == url))
        pagina = &(*it);

    return pagina; // Retorna nullptr si no se encuentra el objeto
}

int DicPaginas::getNumElem ()
{
    return NumElem;
}
