// Programa: Adivina un n�mero
#include <stdlib.h>     //Librer�a necesaria para escribir "EXIT_SUCCES"
#include <stdio.h>
#include <time.h>          //Necesario para generar n�meros aleatorios
#include <windows.h>        //Librer�a para tomar caracteres del espa�ol en windows, tildes
int main ()
{
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);

    printf("Hola \n");
    printf("�C�mo te llamas? ");
    char nombre[20];            //Declaraci�n de la variable, array de 20 valores de caracteres
    scanf("%s",nombre);          //Par�metro en cadena de caracteres (string), que se llama "nombre"
    printf("Encantado de conocerte %s. \n",nombre);

    printf("Estoy pensando en un n�mero del 1 al 10 \n");
    printf("A ver si lo averiguas... \n");
    srand(time(NULL));
    int miNumero = 1+rand() %10;
    int numero;
    int nIntentos = 0;

    do{
        printf ("El n�mero es: ");
        int resultado;
        do {
        resultado = scanf ("%d",&numero);       //%d es un entero

        while(getchar() != '\n');
        if (resultado != 1)
            printf ("Formato incorrecto. Introduce un n�mero:");
        }
        while (resultado != 1);
        if (miNumero<numero)
            printf ("El n�mero es menor \n");
        else if (miNumero>numero)
            printf ("El n�mero es mayor \n");
        nIntentos++;
    } while(numero != miNumero);

    printf("Has tardado %d intentos", nIntentos);

           //Declaramos una variable llamada miNumero, que generara un n�mero aleatorio entre 1-10
    return EXIT_SUCCESS;    // es lo mismo que return 0;
}

   /* srand(time(NULL)); //devuelve una semilla que coge de la hora,
    devuelve un entero que depende de la hora, diferente cada vez
    rand()  */
