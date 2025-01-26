#include <iostream>
#include <string>
using namespace std;

	const int NTitulaciones = 8;				/* constante con el número de máximo filas */
	const int NAnyos = 10; 					/* constante con el número de máximo columnas */
	const int PRIMERA_TITULACION = 0;
	const int ULTIMA_TITULACION  = 7;

	const int PRIMER_ANYO        = 0;
	const int ULTIMO_ANYO        = 9;
	
	typedef int TablaEgresados[NTitulaciones][NAnyos];



void Mostrar_Tabla(TablaEgresados t, int nf, int nc){
	int i, j;
	
	for (i = 0; i < nf; i=i+1) {		
		for (j = 0; j < nc; j=j+1) {						
			cout << t[i][j] << " ";
		}
		cout << endl;		
	}	
}
bool TitulacionCumple (TablaEgresados t, int titulacion) {

	int anyo;     							// indice años
	anyo = PRIMER_ANYO +1;

	while ((anyo != ULTIMO_ANYO) && (t[titulacion ][anyo] > t[titulacion][anyo-1])) {	
		anyo = anyo+1;
	}
	
	return  ( t[titulacion][anyo] > t[titulacion][anyo-1]);
}

int TitulacionCreciente (TablaEgresados t ) {
	int titulacion;

	titulacion = PRIMERA_TITULACION;
	while ((titulacion != ULTIMA_TITULACION) && !TitulacionCumple (t, titulacion)){
	
		titulacion = titulacion +1; 
	}
		
	if (TitulacionCumple (t, titulacion) )
				{ return (titulacion);}
	else
		{return (PRIMERA_TITULACION-1);
		}
}
int main() {	

 TablaEgresados t = {
	{12, 20, 16, 18, 21, 22, 18, 11, 12, 15},
	{14, 13, 9, 8, 20, 92, 13, 10, 21, 17},
	{15, 20, 26, 28, 21, 23, 28, 31, 26, 25},
	{22, 25, 36, 38, 41, 49, 58, 61, 62, 75},
	{13, 83, 26, 88, 23, 32, 81, 51, 42, 83},
	{11, 02, 16, 48, 31, 95, 58, 41, 33, 22},
	{14, 24, 46, 14, 41, 24, 48, 51, 15, 55},
	{15, 50, 66, 78, 11, 92, 8, 13, 22, 25},
	};
	
	int suma_titulacion;				//Suma los egresados de cada titulación
	int nt, na;							// número de titulaciones y de años 
	int titulacion,anyo; 				// índices para titulaciones  y años
	int max,indicemax;
	
	nt=8;
	na=10;
	Mostrar_Tabla(t,nt,na);
	//El número de alumnos que terminan una tirulación es >=0, podemos inicializar a -1
	// En general con valores positivos y negativos, habría que calcular el maxímo de la primera titulación.
	max=-1;
    indicemax=-1;  
	for (titulacion = 0; titulacion < nt; titulacion=titulacion+1) {
			suma_titulacion=0;
			for (anyo = 0; anyo < na; anyo=anyo+1) {	
				suma_titulacion= suma_titulacion + t[titulacion][anyo];
		 } 
		 if (max < suma_titulacion){
									 max=suma_titulacion;
									 indicemax=titulacion;
								}
		}
	

     // calcular el maximo de sumafila
	cout<<"La titulacion que mas alumnos han terminado es "<< indicemax <<" con " << max << endl; 	
 	cout<<"La primera titulacion creciente es la: " << TitulacionCreciente (t);
	     	
}

