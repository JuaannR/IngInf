//Busqueda en una tabla generada aleatoriamente

#include <iostream>
#include <time.h>	//se necesita para poder generar numeros de forma aleatoria
using namespace std;

const	int NUMERO_PLANTAS       = 7;
const	int NUMERO_HABITACIONES  = 20;
const	int MAX_CAMAS_LIBRES     = 3;


typedef	int TipoTablaHospital [NUMERO_PLANTAS][NUMERO_HABITACIONES];  // Tipo Hospital plantas: filas; habitaciones: columnas

	// Sem�ntica:
	// Si 't' es una variable de tipo 'TipoTablaHospital', el valor de 't[i,j]' 
	// representa el n�mero de camas libres en la habitaci�nn�mero 'j+1' de la planta 'i+1'.
	// Recordad que empezamos en el �ndice '0'
	// Para hacer el programa ejecutable de forma directa, generamos una tabla
	// con valores aleatorios entre  0 y MAX_CAMAS_LIBRES:

void GenerarTabla (TipoTablaHospital &t) //t es un par�metro de salida de TipoTablaHospital
{

//L�xico local a GenerarTabla
	int	i ;
	int j ;
//Algorimto
	// Debemos poner '<' o 'NUMERO_PLANTAS-1' pues empezamos en el '0'
	for (i=0; i < NUMERO_PLANTAS; i=i+1) {		
			for (j=0; j < NUMERO_HABITACIONES; j=j+1) {
				t[i][j] =  rand() % 4;
			}					//Generar tabla de forma aleatoria. Al poner modulo 4, se generar�n n�meros entre 0-4.
		}
	}

void MostrarTabla (TipoTablaHospital t)  // para mostrar la tabla, t no se modifica, es un par�metro de tipo dato
{
//L�xico local a MostrarTabla
	int i ;
	int j ;
//Algoritmo
	for (i=0; i < NUMERO_PLANTAS; i=i+1) {
		for (j=0; j < NUMERO_HABITACIONES; j=j+1) {
			cout<< t[i][j]<< " ";
		}
	cout<<endl;		//cuando se acaba un fila, hace un salto de l�nea para comenzar la siguiente
	}
}

int main() {
//L�xico global
	TipoTablaHospital t ; //Variable de tipo TipoTablaHospital
	int i ;					// �ndice para recorrer filas
	int j ;					// �ndice para reorrer columnas
	
	// 'srand' inicializa el generador de n�meros aleatorios
	// para que en cada ejecuci�n genere una secuencia distinta de valores. 
	srand(time(NULL));
	GenerarTabla (t);
	MostrarTabla (t);

	// Haremos una b�squeda en orden habitual: por filas ascendentes y dentro de cada fila por
	// columnas ascendentes. Utilizaremos el tercer modelo, que, como ya
	// sabemos, es el m�s adecuado para b�squedas en tablas:
	
	// Comenzar:
	i = 0;
	j = 0;
	// MIENTRAS NO ESULTIMO Y  NO PROPIEDAD(EA)
	// !Cuidado! aqu� no ponemos poner '< NUMERO_PLANTAS o < NUMERO_HABITACIONES' no se entraria en la iteraci�n
	
	while (!((i == NUMERO_PLANTAS-1) && (j == NUMERO_HABITACIONES-1)) &&		//Mientras no se haya acabado la tabla
		!(t[i][j] == MAX_CAMAS_LIBRES) )										// Y no encuentre un 3
		{
		// Avanzar
			if (j < NUMERO_HABITACIONES -1 ){
				j = j + 1;}
				else
				{	j = 0;					//Cambiar de fila
					i = i + 1;
				}
		}
	// SI PROPIEDAD(EA) ...		
	if (t[i][j] == MAX_CAMAS_LIBRES ){cout<< "La habitacion "<< j<< " de la planta "<< i<< " esta disponible.";}		//Si he encontrado un 3, muestro la habitaci�n de la planta disponible
		else
		{cout <<"Ninguna habitacion esta disponible.";}																	//Si no he encontrado un 3, no hay habitaciones disponibles
	
}

