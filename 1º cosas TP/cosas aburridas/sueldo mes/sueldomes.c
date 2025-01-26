#include <stdio.h>

int main () {

int horas;
int extra;
float bote;
const int EH = 8;
const float EHE = 7.25;
float sueldo;

printf("Introduzca las horas trabajadas este mes: ");
scanf("%d",&horas);

printf("Introduzca las horas extra trabajadas este mes: ");
scanf("%d", &extra);

printf("Introduzca el dinero que gana del bote: ");
scanf("%f", &bote);

sueldo = horas * EH + extra * EHE + bote;

printf("Su sueldo de este mes sera de %.2f euros", sueldo);

return 0;
}
