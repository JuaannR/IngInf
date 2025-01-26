#include "Arbol.h"

//Inicializa nodo con palabra clave y referencia a una página
Nodo::Nodo(std::string palabra, Pagina* pag): palabra(palabra) {
    izq = NULL;
    der = NULL;
    h = 0;
    referencias.push_back(pag);
}

Nodo::~Nodo() {
    delete izq;
    delete der;
}

void Nodo::addRef(Pagina* pag) {
    std::list<Pagina*>::iterator it = referencias.begin();
    //ordena por relevancia. SI relevancias iguales, ordena por URL
    while ((it!=referencias.end()) &&
     (((*it)->getRelev() > pag->getRelev() ||
      ((*it)->getRelev() == pag->getRelev()) &&
       ((*it)->getURL() < pag->getURL())))) it++;
    if ((it == referencias.end()) || (*it != pag))
    {
        //si no existe la página la insertamos en la lista de referencias
        referencias.insert(it, pag);
    }
}

Arbol::Arbol() {
    raiz = NULL;
}

Arbol::~Arbol() {
    delete raiz;
}

int Arbol::altura(Nodo* nodo) {
    if (nodo == NULL) {
        return -1;  // Si es nulo -> altura -1
    }
    return nodo->h;  // Devuelve la altura;
}

//RSI - Rotacion simple a la izquierda
void Arbol::rsi(Nodo*& nodo) {
    Nodo* temp = nodo->izq; // temp -> B
    nodo->izq = temp->der; // A adopta al hijo derecho de B como hijo izq
    temp->der = nodo; // B adopta como hijo derecho a A
    nodo->h = 1 + std::max(altura(nodo->izq), altura(nodo->der)); //actualizamos la altura
    temp->h = 1 + std::max(altura(temp->izq), altura(temp->der));
    nodo = temp; //A=B
}

//RSD - Rotacion simple a la derecha
void Arbol::rsd(Nodo*& nodo) {
    Nodo* temp = nodo->der;
    nodo->der = temp->izq;
    temp->izq = nodo;
    nodo->h = 1 + std::max(altura(nodo->izq), altura(nodo->der)); //actualizamos la altura
    temp->h = 1 + std::max(altura(temp->izq), altura(temp->der));
    nodo = temp;
}

void Arbol::balanceoIzq(Nodo*& nodo, std::string palabra) { //balancea tras insertar por la izquierda
    if ((altura(nodo->izq) - altura(nodo->der)) > 1) {
        if (palabra < nodo->izq->palabra) {  //RSI, caso II
            rsi(nodo);
        } else { //RDI, caso ID
            rsd(nodo->izq);
            rsi(nodo);
        }
    } else {
        nodo->h = 1 + std::max(altura(nodo->izq),altura(nodo->der));
    }
}

void Arbol::balanceoDer(Nodo*& nodo, std::string palabra) { //balancea tras insertar por la derecha
    if ((altura(nodo->der) - altura(nodo->izq)) > 1) {
        if (palabra > nodo->der->palabra) {  //RSD, caso DD
            rsd(nodo);
        } else { //RDD, caso DI
            rsi(nodo->der);
            rsd(nodo);
        }
    } else {
        nodo->h = 1 + std::max(altura(nodo->izq),altura(nodo->der));
    }
}

bool Arbol::insertar(Nodo*& nodo, std::string palabra, Pagina* pag) {
    bool nodoAnadido = false; //pequeña optimizacion: ahora solo balanceamos cuando se añada un nodo
    if (nodo == NULL) {
        nodo = new Nodo(palabra, pag);
        nodoAnadido = true;
    } else if (palabra == nodo->palabra) { //si se encuentra la palabra añadimos la pagina a sus referencias
        nodo->addRef(pag);
    } else if (palabra < nodo->palabra) { //si se ha insertado a la izquierda
        if (insertar(nodo->izq, palabra, pag)) balanceoIzq(nodo, palabra);
    } else if (palabra > nodo->palabra) { //si se ha insertado a la derecha
        if (insertar(nodo->der, palabra, pag)) balanceoDer(nodo, palabra);
    }
    return nodoAnadido;
}

void Arbol::insertar(std::string palabra, Pagina* pag) {
    insertar(raiz, palabra, pag);
}

std::list<Pagina*> Arbol::buscar(std::string palabra) {
    std::list<Pagina*> resultado;
    Nodo* nodo = raiz;
    while (nodo && (nodo->palabra != palabra)) { //mientras que el nodo no sea nulo y el nodo no sea el buscado
        if (palabra < nodo->palabra) nodo = nodo->izq;
        else nodo = nodo->der;
    }
    if (nodo) resultado = nodo->referencias; // si se encuentra la palabra se devuelven sus referencias
    return resultado;
}
