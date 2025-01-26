#include <stdio.h>
#include <math.h>

const int d = 150000000;

int main ()
{
    float v;
    int res;

    printf("Introduce un velocidad en km/h: ");
    scanf("%f",&v);

   printf("La distancia a recorrer es de %d km y la velocidad es de %.2f km/h \n", d,v);

   double seg;
   double min;
   double hora;
   double dia;
   double anyo;

   hora = d/v;
   min = hora*60;
   seg = hora*3600;
   dia = hora/24;
   anyo = dia/365;

    printf("Para recorrer dicha distancia, tardariamos: %.2lf horas. \n",hora);
    printf("Que son: %.2lf  segundos. \n",seg);
    printf("Que son: %.2lf  minutos. \n",min);
    printf("Que son: %.2lf  dias. \n",dia);
    printf("Que son: %.2lf  anyos. \n",anyo);

    printf("Lo que equivale a: \n");
    int a;
    int d;
    int h;
    int m;
    int s;

    a = floor(anyo);
    d = floor((anyo - floor(anyo))*365);
    h = floor((dia - floor(dia))*24);
    m = floor((hora - floor(hora))*60);
    s = floor((min - floor(min))*60);

    printf("Taradariamos: %d anyos, %d dias, %d horas, %d minutos y %d segundos.",a,d,h,m,s);



    return 0;
}

