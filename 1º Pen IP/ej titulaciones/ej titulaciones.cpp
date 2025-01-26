#include <iostream>
using namespace std;
	
	const int NFilas = 8;						/* constante con el número de titulaciones */
	const int NColumnas = 10; 					/* constante con el número de años */
	typedef int Matriz[NFilas][NColumnas];


void Mostrar_Tabla(Matriz t, int nf, int nc){
	int i, j;
	
	for (i = 0; i < nf; i=i+1) {		
		for (j = 0; j < nc; j=j+1) {						
			cout << t[i][j] << " ";
		}
		cout << endl;		
	}	
}
int main() {	

 Matriz t = {
	{12, 20, 16, 18, 21, 22, 18, 11, 12, 15},
	{14, 13, 9, 8, 20, 92, 13, 10, 21, 17},
	{15, 20, 26, 28, 21, 23, 28, 31, 26, 25},
	{22, 25, 36, 38, 41, 49, 58, 61, 62, 75},
	{13, 83, 26, 88, 23, 32, 81, 51, 42, 83},
	{11, 02, 16, 48, 31, 95, 58, 41, 33, 22},		//Inicializar tabla manualmente
	{14, 24, 46, 14, 41, 24, 48, 51, 15, 55},
	{15, 50, 66, 78, 11, 92, 8, 13, 22, 25},
	};

	int sumafila[NFilas];
	int nf, nc, i, j;
	int max,indicemax;
	
	nf=8;
	nc=10;
	
	Mostrar_Tabla(t,nf,nc);
	//Esquema de recorrido de una tabla bidimensional
	
	for (i = 0; i < nf; i=i+1) {
			sumafila[i]=0;
			for (j = 0; j < nc; j=j+1) {	
				sumafila[i]= sumafila[i] + t[i][j];		//Va sumando celda a celda cada fila
		 } 
		 cout<<endl;  
		}
	

     // Esquema de recorrido tabla unidimensional, calcular el maximo de sumafila
     max=sumafila[0];
     indicemax=0;
    
	for (i = 1; i < nf; i=i+1){
		
			if (max < sumafila[i]){
									 max=sumafila[i];
									 indicemax=i;
								}
	}
	cout<<"La titulacion que mas alumnos han terminado es la "<< indicemax <<" con " << max;      	
}






