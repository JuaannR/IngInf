#include <stdio.h>

/* float PrecioRebajado(int n, float precio[],float rebaja[], float final[])
{
    printf("Introduce el numero de objetos a valorar: ");
    scanf("%d",&n);

    for (int i  = 0; i < n; i++)
    {


    }
}
*/
int main ()
{
    int n;

    printf("Introduce el numero de objetos a tratar: ");
    scanf("%d",&n);

    float precio[n];
    float rebaja[n];
    float final[n];

        for (int i=0; i<n; i++)
        {
        printf("Introduce el precio del objeto %d: ", i+1);
        scanf("%f",&precio[i]);
        printf("Precio objeto %d: %2.f euros. \n",i+1,precio[i]);
        printf("Introduce la rebaja del producto %d en porcentaje: ", i+1);
        scanf("%f", &rebaja[i]);
        printf("Rebaja objeto %d: %2.f por ciento. \n",i+1,rebaja[i]);
        final[i] = precio[i] - (precio[i] * (rebaja[i]/100));
        printf("El nuevo valor del producto %d es: %2.f euros \n",i+1, final[i]);
        }

    return 0;
}

