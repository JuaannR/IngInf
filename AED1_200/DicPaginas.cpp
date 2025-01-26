#include "DicPaginas.h"

DicPaginas::DicPaginas() {}

void DicPaginas::insertar(Pagina nueva) {
    // Insertamos la p�gina en la tabla de dispersi�n
    tabla.inserta(nueva);
}

Pagina* DicPaginas::consultar(std::string url) {
    // Buscamos la p�gina en la tabla de dispersi�n
    return tabla.consulta(url);
}

int DicPaginas::getNumElem() {
    // Devolvemos el tama�o de la tabla
    return tabla.getNumElem();
}