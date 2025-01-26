#include <stdlib.h>  // Funcion exit
#include <string.h>  // Funcion memset
#include <iostream>  // Variables cin y cout
using namespace std;

#define MAX_NODOS 26

int nnodos;                   // Numero de nodos del grafo
int naristas;                 // Numero de aristas del grafo
bool G[MAX_NODOS][MAX_NODOS]; // Matriz de adyacencia
bool visitado[MAX_NODOS];     // Marcas de nodos visitados

// Procedimiento para leer un grafo de la entrada
void leeGrafo (void) {
  cin >> nnodos >> naristas; // Lee número de nodos y aristas
  if (nnodos<0 || nnodos>MAX_NODOS) {
    cerr << "Numero de nodos (" << nnodos << ") no valido\n";
    exit(0);
  }
  memset(G, 0, sizeof(G)); //Inicializa matriz de adyacencia en false
  char c1, c2;
  for (int i= 0; i<naristas; i++) {
    cin >> c1 >> c2;    //Lee arsita como dos caracteres
    G[c1-'A'][c2-'A']= true;    //Actualiza matriz en funcion de la arista
  }
}

// Procedimiento iterativo de la busqueda primero en anchura
//   inicio - primer nodo visitado en la bpa
void bpa(int inicio) {
  int cola[MAX_NODOS];  //Maneja nodos por explorar
  int frente = 0;   // Indice del nodo que será procesado
  int fin = 0;      // Indice donde se añadirá el próximo nodo

  cola[fin++] = inicio; // Añade el nodo inicial a la cola
  visitado[inicio] = true;  //Marca como visitado

  while (frente < fin) {    // Mientras haya nodos en la cola
    int v = cola[frente++]; // Sacar el nodo al frente de la cola
    cout << char(v + 'A');  // Imprimir el nodo (convertir índice a letra)

    // Añadir a la cola los adyacentes no visitados
    for (int w = 0; w < nnodos; w++) {
      if (G[v][w] && !visitado[w]) {
        cola[fin++] = w;    //añade a la cola
        visitado[w] = true; //marca como visitado
      }
    }
  }
}

// Procedimiento principal de la busqueda en anchura
void busquedaPA (void) {
  memset(visitado, 0, sizeof(visitado)); //Marca todos los nodos como no visitados
  for (int v= 0; v<nnodos; v++) //Recorre todos los nodos
    if (!visitado[v]) //Si el nodo no ha sido visitado
      bpa(v);   //Llamamos a bpa para explorar sus ramas
  cout << endl;
}


int main (void)
{
  int ncasos;
  cin >> ncasos;
  for (int i= 0; i<ncasos; i++) {
    leeGrafo();
    busquedaPA();
  }
}
