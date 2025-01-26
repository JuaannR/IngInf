#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main ()
{
    char nombre[20];

    printf("¿Como te llamas?\n");
    scanf("%s",nombre);
    printf("Encantado de conocerte %s\n",nombre);

    printf("Estoy pensando en un número del 1 al 10\n");
    printf("A ver si lo averiguas... \n");

    srand(time(NULL));

    int Naleatorio = 1+rand() %10;
    int Nintentos = 0;
    int numero;


    do {
     printf("Adivina el numero: ");
     scanf("%d",&numero);
     Nintentos++;

     if (numero<Naleatorio){
        printf("El numero es mayor\n");
        }
        else if (numero>Naleatorio){
        printf("El numero es menor\n");
       }
       else {
        printf("Correcto, has adivinado el numero en %d intentos\n", Nintentos);
       }
    }  while(numero != Naleatorio);

return 0;
}
