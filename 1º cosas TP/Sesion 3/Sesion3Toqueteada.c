#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void despejarEntrada(void)
{

    while(getchar() != '\n');
}

int leer_entero(int * n)    //Se declara como apuntador
{
    // * n se refiere al contenido de n
    int dato;
    int res = scanf("%d", &dato);
    despejarEntrada();
    if (res != 1)
        return 1;
    *n = dato;
    return 0;
}

/*
int leer_entero(int * n) {  //Se declara como apuntador
                            // * n se refiere al contenido de n

    int res = scanf("%d", n);
    despejarEntrada();
    if (res != 1)
        return 1;
    return 0;
*/

int leer_entero_mayorIgual(int * n, int a)
{
    int res = scanf("%d", n);
    despejarEntrada();
    if (res != 1)
        return 1;
    if (*n<a)
        return 2;
    return 0;
}

int leer_entero_rango(int * n, int a, int b)
{

    int res = scanf("%d", n);
    despejarEntrada();
    if (res != 1)
        return 1;
    if (*n<a)
        return 2;
    if(*n>b)
        return 3;
    return 0;
}

void pausa(void)
{
    printf("Presiona una tecla para continuar...\n");
    getchar();
}

int entero_aleatorio_rango(int a, int b)
{
    return a+rand()%(b-a+1);
}


int main ()
{
    int res;
    int n;
    printf("Introduce un entero: ");
    do
    {
        res = leer_entero(&n);
        if (res==1)
            printf("Formato incorrecto. Introduce un entero: ");
    }
    while (res != 0);

    int m;
    printf("Introduce un entero mayor o igual que %d: ", n);
    do
    {
        res = leer_entero_mayorIgual(&m,n);
        if (res==1)
            printf("Formato incorrecto. Introduce un entero: ");
        if (res==2)
            printf("Rango incorrecto. Introduce un entero mayor o igual que %d: ", n);

    }
    while (res != 0);

    int r;
    do {
    printf("Introduce un numero mayor o igual que %d y menor que %d: ", n,m);
    res = leer_entero_rango(&r,n,m);
    if (res==2 || res==3)
    {
        printf("Rango incorrecto, introduce un entero: \n");
    }
    } while (res != 0);



    return 0;
}

