    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
    #include <math.h>

/*
void imprimir_array(double * v, int n)
    {
        for (int i=0; i<n; i++)
            printf("%.2f ",v[i]);
        printf("\n");
    }
*/

void imprimir_array(double * v, int n)
{
    double a = -10;
    double b = 10;
    for (int i=0; i<n; i++)
    {
        v[i] = a+((b-a)*rand() ) / RAND_MAX;
        printf("%.2f ",v[i]);
    }
    printf("\n");
}


    // requerimientos: n ≥ 1
    // Devuelve la media aritmética de los elementos de v
    double calcula_media(double * v, int n)
    {
        double suma = 0;
        for (int i = 0; i<n; i++)
        {
            suma=suma+v[i];
        }
        double media = suma/n;
        return media;

    }

    // requerimientos: n ≥ 1
    // Devuelve la desviación típica de los elementos de v
    double dt(double * v, int n)
    {
        double suma = 0;
        double med = calcula_media(v,n);
        for(int i = 0; i<n; i++)
        {
            suma = suma + pow((v[i]-med),2);
        }
    double dest=sqrt((suma)/n);
    return dest;
    }


    int main ()
     {
        int n;
        printf("Introduce el tamano del array: ");
        scanf("%d",&n);

        double * v = malloc(sizeof(double)*n);

        srand(time(NULL));
        for(int i = 0; i<n; i++)
        {
        //Genera nº aleatorio entre 0,200 luego se le resta 100 para que se quede en el intervalo -100,100
            v[i]= rand() %201-100;
        }

        printf("Los elementos del array son:\n");
        imprimir_array(v,n);

        double m = calcula_media(v,n);
        printf("La media de los elementos del array es: %.2f\n",m);

        double s = dt(v,n);
        printf("La desviacion tipica de los elementos del array es: %.2f\n",s);

        free(v);
    }
