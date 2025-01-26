#include "Sesion7.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define TAM_B1 100000
#define TAM_B2 1807

int main ()
{
    //comprar boleto
    int numero;
    printf("Dame un numero entre 0 y %d: ",TAM_B1-1);
    scanf("%d",&numero);

    //construir los bombos
    srand(time(NULL));
    Bombo b1;
    Bombo b2;
    if ((b1 = BomboCrea(TAM_B1))==NULL)
    {
        fprintf(stderr,BomboMensajeError(b1,error));
        return EXIT_FAILURE;
    }

    if ((b2 = BomboCrea(TAM_B2))==NULL)
    {
        fprintf(stderr,BomboMensajeError(b1,error));
        BomboLibera(b1);
        return EXIT_FAILURE;
    }

    for (int i=0; i<TAM_B1; i++)
        BomboInserta(b1,i);
    BomboInserta(b2,4000000);
    BomboInserta(b2,1230000);
    BomboInserta(b2,500000);
    BomboInserta(b2,200000);
    BomboInserta(b2,200000);
    for(int i=0; i<8; i++)
        BomboInserta(b2,60000);
    for(int i=0; i<1794; i++)
        BomboInserta(b2,1000);

    //Sorteo
    typedef struct{
    int numero;
    int premio;
    }numero_premio;

    numero_premio sorteo[TAM_B2];

    for (int i=0; i<TAM_B2;i++) {
        if ((sorteo[i].numero = BomboExtrae(b1)) == -1)
    {
        fprintf(stderr,BomboMensajeError(b1,error));
        BomboLibera(b1);
        BomboLibera(b2);
        return EXIT_FAILURE;

    }

        if ((sorteo[i].numero = BomboExtrae(b2)) == -1)
    {
        fprintf(stderr,BomboMensajeError(b2,error));
        BomboLibera(b1);
        BomboLibera(b2);
        return EXIT_FAILURE;

    }
    }
    FILE * fichero = fopen("premios.txt","w");
    for (int i=0; i<TAM_B2;i++)
    fprintf(fichero,"Numero: %d, Premio: %d.\n",sorteo[i].numero,sorteo[i].premio);
    BomboLibera(b1);
    BomboLibera(b2);


    //Comprobar mi boleto
    int i=0;
    while(i<TAM_B2 && numero != sorteo[i].numero)
        i++;
    if(i<TAM_B2)
       printf("Numero premiado: %d",sorteo[i].premio);
    else
    printf("Numero no premiado");
return EXIT_SUCCESS;
}
