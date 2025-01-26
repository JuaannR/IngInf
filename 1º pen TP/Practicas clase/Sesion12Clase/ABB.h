#ifndef ABB_H_INCLUDED
#define ABB_H_INCLUDED

typedef struct ABBRep * ABB;
typedef int Elemento;

// Devuelve un nuevo �rbol binario de b�squeda vac�o.
ABB ABBCrea();

// Libera la memoria asignada al �rbol binario de b�squeda a.
void ABBLibera(ABB a);

// Devuelve 1 (true) si el elemento e pertenece al �rbol binario de
// b�squeda a, y 0 false) en caso contrario.
int ABBPertenece(ABB a, Elemento e);

// Inserta el elemento e en el �rbol binario de b�squeda a.
void ABBInserta(ABB * a, Elemento e);

// Suprime el elemento e del �rbol binario de b�squeda a.
void ABBSuprime(ABB * a, Elemento e);

// Devuelve un �rbol binario de b�squeda que es la uni�n de los
// �rboles binarios de b�squeda a y b.
ABB ABBUnion(ABB a, ABB b);

// Devuelve un �rbol binario de b�squeda que es la intersecci�n de
// los �rboles binarios de b�squeda a y b.
ABB ABBInterseccion(ABB a, ABB b);

// Devuelve un �rbol binario de b�squeda que es la diferencia de los
// �rboles binarios de b�squeda a y b.
ABB ABBDiferencia(ABB a, ABB b);

// A�ade a la cadena apuntada por s los elementos del �rbol binario a
// en orden creciente y devuelve la direcci�n de la cadena.
char * ABBToString(char * s, ABB a);

#endif // ABB_H_INCLUDED
