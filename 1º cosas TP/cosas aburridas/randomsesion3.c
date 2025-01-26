#include <stdio.h>
#include <math.h>

int a = 1;
int b = 2;
int aux;


int main ()
{
    printf("a = %d\n", a);
    printf("b = %d\n", b);

    aux = a;
    a = b;
    b = aux;

    printf("a = %d\n", a);
    printf("b = %d\n", b);

    return 0;
}
