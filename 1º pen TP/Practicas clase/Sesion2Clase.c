// Programa: Velocidad de llegada al Sol

#include <stdio.h>
#include <math.h>
#include <windows.h>

#define printf __mingw_printf

//const int d = 150000000;
const double d = 149.6E6;

int main ()
{
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);   // Necesario para tildes


    double v;
    int res;

//ponemos el do para comprobar que se ha introducido un número
    do
    {

        printf("Introduce la velocidad en km/h mayor que 0: ");
        res = scanf("%lf",&v);      //lf = long float
        while(getchar() != '\n');           //complementa al do en la comprobacion de si el dato introducido es correcto
        if (res != 1 || v<=0)
            printf("Formato incorrecto. Introduce una velocidad mayor que 0\n");
    }
    while (res != 1 || v<=0);

    printf("Velocidad: %lf Km/h\n",v);
    printf("Distancia: %lf Km\n",d);

    long double horas = (long double)d/(long double)v;
    long double dias = horas/24;
    long double anyos = dias/365;
    long double minutos = horas*60;
    long double segundos = minutos*60;          //ponemos los datos en long double para que c sea capaz de calcular segundos, minutos...

    printf("Segundos: %Lg\n", segundos);     //La g indica que se toma en formato de potencia o como numero real segun convenga (la forma mas corta)
    printf("Minutos: %Lg\n", minutos);
    printf("Horas: %Lg\n", horas);
    printf("Días: %Lg\n", dias);
    printf("Años: %Lg\n", anyos);

    //En el apartado de arriba, años, dias, horas, minutos y segundos representan el mismo tiempo. años=dias=horas...
    //Ahora ponemos el tiempo juntando todos los factores. Taradamos x años, x horas, x dias...

    long double a = floorl (anyos);                 //floorl: coge la parte entera de un número real
    long double d = floorl((anyos - floorl(anyos))*365);
    long double h = floorl((dias - floorl(dias))*24);
    long double m = floorl((horas - floorl(horas))*60);
    long double s = floorl((minutos - floorl(minutos))*60);

    printf("%Lg años, %Lg dias, %Lg horas, %Lg minutos y %Lg segundos", a, d, h, m, s);

    return 0;
}



/*
dtl = 384400 km const int. Pedir al usuario v1 y v2, y calculamos el tiempo.
d1 + d2 = dtl
v1 * t + v2 *t = dtl
t(v1+v2) = dtl
t = dtl / (v1 + v2) */
