#include <stdio.h>

float areatriangulo(float base, float altura)
{
    float area = (base * altura) / 2;
    return area;
}

int main ()
{
float b, h;

printf ("Base triangulo: ");
scanf ("%f",&b);
printf ("Altura triangulo: ");
scanf ("%f",&h);

float area = areatriangulo(b,h);

    printf("El area del triangulo es: %2.f", area);
    return 0;
}
