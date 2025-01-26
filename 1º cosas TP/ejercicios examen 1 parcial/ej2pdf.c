#include <stdio.h>

float PrecioRebajado(int n, float precio[],float rebaja[], float final[])
{
    printf("Introduce el numero de objetos a valorar: ");
    scanf("%d",&n);

    for (int i  = 0; i < n; i++)
    {
        printf("Introduce el precio del objeto %d", i+1);
        scanf("%f",&precio[i]);
        printf("Precio objeto %d: %f euros. \n",i+1,precio[i]);
    }

    for (int i = 0; i < n; i++)
    {
        printf("Introduce la rebaja del producto %d en porcentaje: ", i+1);
        scanf("%f", rebaja[i]);
        printf("Rebaja objeto %d: %f %",i+1,rebaja[i]);
    }


}


int main ()
{


    return 0;
}


/*
double * PrecioRebajado(double * v1, double * v2, int n)
{
double * v3 = malloc(n*sizeof(double));
for(int i=0; i<n; i++)
v3[i] = v1[i]-v1[i]*v2[i]/100;
return v3;
}
*/


