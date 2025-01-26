#include <stdlib.h>  // exit
#include <string.h>  // memset
#include <iostream>  //  cin y cout
#include <queue>    // cola queue
#include <list>     // lista adyacencia
using namespace std;

#define MAX_NODOS 20000

int numnodos;            // Numero nodos grafo
list<int> L[MAX_NODOS]; // Listas de adyacencia
bool visitado[MAX_NODOS];     // Marcas visitado
queue<int> cola; // Cola recorrido Pablito


void leeGrafo (void) {
    // Comprobar numnodos dentro de rango
  cin >> numnodos;
  if (numnodos<0 || numnodos>MAX_NODOS) {
    cerr << "Numero de nodos (" << numnodos << ") no valido\n";
    exit(0);
  }

  // Inicialización listas de adyacencia
  for (int i = 0; i < numnodos; i++) {
    L[i].clear();
  }


  char c1;
  int aux=0;
    for (int i= 0; i<numnodos; i++) {
        cin >> aux;
        int aux2=0; //Contador noods adyacentes para el nodo actual
        L[i].push_back(aux-1); // Agrregamos nodo -1 a su lista
        c1 = cin.get();  // lee siguiente caracter
        aux2++;     // nodos adyacentes ++
        //Ampliar lista adyacencia con nodos veicnos para el nodo actual aux
        while(c1==' '&& aux2<=10){
            cin >> aux;
            L[i].push_back(aux-1);
            c1 = cin.get();
            aux2++;
        }
    }

}

// buscar camino desde el nodo 'a' al nodo de salida
bool buscar(int a){
    visitado[a]=true;   //marcamos nodo actual 'a' como visitado
    cola.push(a);       //añadimos 'a' al recorrido de pablito
    if(a==numnodos-1){
        return true;    //Si el nodo inicial es final, hay salida
    }

    // Recorremos nodos adyacentes a nodo actual a
    for (list<int>::iterator it=L[a].begin(); it != L[a].end(); ++it){
        if(!visitado[*it]){     // Si el nodo adyacente no ha sido visitado...
            if(buscar(*it)){    // llamada recurisva a buscar() para explorar nodo adyacente
                return true;  //hay camino a la salida
            }
            cola.push(a);   //si no se encuentra el camino, se añade el nodo "a" a la cola
        }
    }
    return false;  // no hay camino a la salida
}

void listar(){
    cout<<cola.size()<<endl;    // tam cola
    while(!cola.empty()){       // mientras cola no vacia
        cout<<cola.front()+1<<endl; // imprime 1º elemento cola
        cola.pop();                 // se elimina
    }
}

void vaciarCola(){
    while(!cola.empty()){
        cola.pop();
    }
}


int main (void) {
  int numcasos;
  cin >> numcasos;
  for (int i= 0; i<numcasos; i++) {
    cout << "Caso " << i+1 << endl;
    memset(visitado, 0, sizeof(visitado));  //Reinicio array
    leeGrafo();
    if(!buscar(0)){              // buscar(0) -> trata de buscar camino desde el nodo inicial Nodo 1 índice 0 hasta el nodo de salida nodo N indice N-1
        cout<<"INFINITO"<<endl;         // no salida -> infinito y se vacía la cola
        vaciarCola();
    }else{
        listar();                       // si lo hay, se lista
    }
  }
}
