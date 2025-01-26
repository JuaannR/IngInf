#include<iostream>
using namespace std;
const int nf=11;
const int nc=31;
//definimos el tipo como float ya que los valores de lluvia no tienen porque ser exactos
typedef float LluviaMurcia[nf][nc];

void DiaMasLluvia(LluviaMurcia lluvia,int &dia,int &ano){
	int i=0,j=0,lluviamax=0;
	//recorremos toda la tabla
	for(i=0;i<nf;i++){
		for(j=0;j<nc;j++){
			//unicamente modificamos el valor del dia y el año si el valor actual es mayor que el valor de lluviamax
			if(lluvia[i][j]>lluviamax){
				lluviamax=lluvia[i][j];
				dia=j;
				ano=i;
			}
		}
	}
}

bool nollovio(LluviaMurcia lluvia, int i){
	bool nollovio=true;
	//recorremos las filas de ese año
	for(int j=0;j<nc;j++){
		//si el valor de lluvia de la posicion (i,j) es mayor que 0 ese año si llovio
		if(lluvia[i][j]>0){
			nollovio=false;	
		}
	}
	return nollovio;
}
int AynoLluvioso(LluviaMurcia lluvia){
	int sumaAno;
	int sumaAnoMax;
	int anoMax;
	
	anoMax = 0;
	sumaAnoMax = 0;
	//Filas son los años
	for (int i=0; i < nf; i++) {
		sumaAno = 0;
		//Sumamos todas las cantidades de lluvia de los dias de ese año
		for (int j=0; j < nc; j++) {
			sumaAno = sumaAno + lluvia[i][j];
		}
		//comparamos, si la suma de ese año mayor a la del año maximo entonces ese año es el mayor
		if (sumaAno > sumaAnoMax) {
			sumaAnoMax = sumaAno;
			anoMax = i;
		}
	}
	return anoMax;
}
int main (){
	//definimos los valores de nuestra tabla(valores aleatorios), 11 filas para contar 10 años (2013-2023), 31 columnas para contar los 31 dias de enero
	LluviaMurcia lluvia={0,10,30,1,32,43,1,10,123,14,3,5,63,2,3,46,78,74,21,3,2,5,3,5,5,23,4,5,5,5,0,//2023
	0,0,0,1,2,3,1,0,3,4,3,5,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,//2022
	0,0,0,1,2,3,1,0,3,4,3,5,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,//2021
	0,0,0,1,2,3,1,0,3,4,3,5,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,//2020
	0,0,0,1,2,3,1,0,3,4,3,5,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,//2019
	0,0,0,1,2,3,1,0,3,4,3,5,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,//2018
	0,0,0,1,2,3,1,0,3,4,3,5,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,//2017
	0,0,0,1,2,3,1,0,3,4,3,5,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,//2016
	0,0,0,1,2,3,1,0,3,4,3,5,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,//2015
	0,0,0,1,2,3,1,0,3,4,3,5,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,//2014
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};//2013
	//inicializamos las variables que vamos a usar
	int dia=0, ano=0,ano1=0;
	
	//Muestra en pantalla la tabla
	cout << "El contenido de la tabla es el siguiente:\n";
	for(int i = 0; i < nf; i++){
		for(int j = 0; j < nc;j++){
			cout << lluvia[i][j]<<" ";
			}
		cout << endl;
	}
	//teniendo en cuenta que estamos en enero de 2023
	DiaMasLluvia(lluvia,dia,ano);
	cout<<"El dia que mas llovio fue el "<<dia+1<<"/"<<ano+2013<<endl;
	
	cout<<"El año que mas llovio fue "<<AynoLluvioso(lluvia)+2013<<endl;
	
	cout<<"Dime un año para comprobar si llovio(2013-2023) "<<endl; cin>>ano1;
	
	//comprobaciones para saber si el año otorgado por el usuario esta en el rango dicho
	if((ano1>2023)||(ano1<2013)){
		cout<<"El año indicado no es valido";
	}else{
		//esta en el rango dicho por lo tanto situamos el valor del año dado en rango 0-11 para poder trabajar con la tabla
		ano1=2023-ano1;
		if(nollovio(lluvia,ano1)==true){
			//llamamos a la funcion no llovio y si su valor es true entonces ese año no ha llovido de lo contrario ese año ha llovio
			cout<<"El año indicado no llovio"<<endl;
		} else{
			cout<<"El año indicado SI llovio "<<endl;
		}
	}
	
	return 0;
}
