#include <iostream>
using namespace std;
int main () {
	int dia;
	int mes;
	int ano;
	cout << "Introduzca el dia: ";
	cin >> dia;
	cout << "Introduza el mes: ";
	cin >> mes;
	cout << "Introduzca el año: ";
	cin >> ano;
	switch (mes) {
		case 2:
		if (dia<28) {
			dia++;
		} else {
			dia=1;
			mes++; }
			break;
		
		case 4:
		case 6:
		case 9: 
		case 11:
		if (dia<30) {
			dia++;
			} else {
				dia=1;
				mes++; }
				break;
		case 1:
		case 3: 
		case 5:
		case 7:
		case 8:
		case 10:
		if (dia<31) {
			dia=dia+1;
		} else {
			dia=1;
			mes++; }
			break;
			
		case 12:
		if (dia<31) {
			dia++;
		} else { 
			dia=1;
			mes=1;
			ano++; }
			break;
		default: {
		cout << "Desconocido"; }
		
	}	
	cout << "La fecha del día siguiente es: " << dia << " " << mes << " " << ano << endl;
	
}
		
	
