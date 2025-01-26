#ifndef _ARBOL_AVL
#define _ARBOL_AVL

#include "Pagina.h"
#include <iostream>
#include <string>
#include <list>

class Nodo {
    friend class Arbol;
    private:
        std::string palabra;
        std::list<Pagina*> referencias;  // Lista de referencias a páginas
        Nodo* izq;
        Nodo* der;
        int h; //altura

        Nodo(std::string palabra, Pagina* pag);
        ~Nodo();
        void addRef(Pagina* pag);
};

class Arbol {
    private:
        Nodo* raiz;

        int altura(Nodo* nodo);
        void rsi(Nodo*& nodo);
        void rsd(Nodo*& nodo);
        void balanceoIzq(Nodo*& nodo, std::string palabra);
        void balanceoDer(Nodo*& nodo, std::string palabra);
        bool insertar(Nodo*& nodo, std::string palabra, Pagina* pag);

    public:
        Arbol();
        ~Arbol();
        void insertar(std::string palabra, Pagina *pag);
        std::list<Pagina*> buscar(std::string palabra);
};

#endif