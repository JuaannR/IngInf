#include "TablaHash.h"
#include <functional>
#define BASE_FNV 16777619
#define MAX_ELEM 2 //con relacion a tam
#define TAM 10007 //tamaño inicial

TablaHash::TablaHash() {
    nElem = 0;
    tam = TAM;
    tabla = new std::list<Pagina>[tam];
}

TablaHash::~TablaHash() {
    delete[] tabla;
}


unsigned int TablaHash::funcion(const std::string& url) {
    //usamos FNV-1
    size_t pos = url.find("://");
    pos = (pos == std::string::npos) ? 0 : pos + 3;
    // Si contiene :// empezamos en pos +3, sino lo contiene, desde 0. para ignorar prefijos como https:// que aportaran poco valor

    unsigned int hash = 2166136261;

    while (pos < url.length()) {
        hash *= BASE_FNV;
        hash ^= static_cast<unsigned int>(url[pos]);
	pos++;
    }
    return hash % tam;
}


Pagina* TablaHash::inserta(Pagina nueva) {
    int indice = funcion(nueva.getURL()); // Calculamos el �ndice
    std::list<Pagina>::iterator it = tabla[indice].begin();
    while ((it!=tabla[indice].end()) && (it->getURL() < nueva.getURL())) it++;
    if ((it == tabla[indice].end()) || (it->getURL() != nueva.getURL()))
    {
        //si no existe ninguna página con esa URL la insertamos en la lista
        it = tabla[indice].insert(it, nueva);
        nElem++;
        if (nElem > MAX_ELEM * tam) 
        {
            reestructurar();
        }
    }
    else
    {
         // Ya existe, actualizamos sus valores
        it->actualizar(nueva);
    }
    return &(*it);
}

Pagina* TablaHash::consulta(string url) {
    Pagina * pagina = nullptr;
    int indice = funcion(url); // Calculamos el �ndice

    std::list<Pagina>::iterator it = tabla[indice].begin();
    while ((it!=tabla[indice].end()) && (it->getURL() < url)) it++;
    if ((it != tabla[indice].end()) && (it->getURL() == url))
        pagina = &(*it);

    return pagina; // Retorna nullptr si no se encuentra el objeto
}


int TablaHash::getNumElem() {
    return nElem;
}

void TablaHash::reestructurar() {
    const int tam_anterior = tam;
    tam *= 2;               // Duplicamos el tamaño de la tabla
    list<Pagina>* nuevaTabla = new list<Pagina>[tam]; // Creamos la nueva tabla más grande

    //pasamos los elementos a la nueva lista
    for (int i = 0; i < tam_anterior; i++) {
        for (auto& pagina : tabla[i]) {
            int indice = funcion(pagina.getURL());
            //insertamos ordenado sabiendo que no hay que sobreescribir paginas (no teniamos repetidas), ni reestructurar, ni modificar n elem
            std::list<Pagina>::iterator it = nuevaTabla[indice].begin();
            while ((it!=nuevaTabla[indice].end()) && (it->getURL() < pagina.getURL())) it++;
            nuevaTabla[indice].insert(it, pagina);
        }
    }
    delete[] tabla;
    tabla = nuevaTabla;
}
