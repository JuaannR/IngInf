#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* copia(char* s)
{
   int n = 0;
   while(n != 0)
   {
       n++;
   }
   char * c = malloc(n*sizeof(char));

   for(int i = 0; i<n; i++)
   {
       c[i] = s[i];
   }
   return c;
}

int cuenta (char * s, char c)
{
    int n = 0;

    for(int i=0; s[i] != 0; i++)
    {
        if(s[i] == c)
        {
            n++;
        }
    }
    return n;
}

void identidad(int n, int a[n][n])
{


for (int i = 0; i<n; i++)
    for (int j = 0; j<n; j++)
        if (i==j)
        {
            a[i][j] = 1;
        }
        else {
            a[i][j] = 0;


}
}

int * sucesion_suma(int n)
 {
     int  *nueva_sucesion = malloc(n*sizeof(int));
     nueva_sucesion[0] = 0;
        for(int i = 0; n<i; i++)
        {
            nueva_sucesion[i] = nueva_sucesion[i-1] + i;
        }
return nueva_sucesion;
 }




int main() {


    return 0;
}


