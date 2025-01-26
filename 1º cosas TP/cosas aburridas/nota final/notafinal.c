#include <stdio.h>

int main () {
float notaTeoria;
float notaPrac;
float Nota;

printf("Introduzca su nota de teoria: ");
scanf("%f", &notaTeoria);

printf("Introduzca su nota de practicas: ");
scanf("%f", &notaPrac);

Nota = 0.6 * notaPrac + 0.4 * notaTeoria;

printf("Su nota en la asignatura es: %.2f", Nota);

return 0;
}
