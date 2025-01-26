#include "DicPaginas.h"

DicPaginas::DicPaginas() {}

DicPaginas::~DicPaginas() {}

Pagina* DicPaginas::insertar(Pagina nueva) {
    // Insertamos la p�gina en la tabla de dispersi�n
    return tabla.inserta(nueva);
}

Pagina* DicPaginas::consultar(std::string url) {
    // Buscamos la p�gina en la tabla de dispersi�n
    return tabla.consulta(url);
}

int DicPaginas::getNumElem() {
    // Devolvemos el tama�o de la tabla
    return tabla.getNumElem();
}

void DicPaginas::insertar (string palabra, Pagina *pag) { 
    arbol.insertar(palabra, pag); 
}

list<Pagina*> DicPaginas::buscar (string palabra) { 
    return arbol.buscar(palabra);
}
