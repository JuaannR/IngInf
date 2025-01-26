#include <stdio.h>

int num = 10;
int *apt = &num;

int main ()
{
printf("El numero es: %d\n",num);

*apt = 30;

printf("El nuevo numero es: %d",num);

    return 0;
}
