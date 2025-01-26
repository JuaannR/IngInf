#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ABB.h"
#define STRING_SIZE 1000

int main ()
{
    ABB a = ABBCrea();    //creamos �rbol vac�o
    int n;
    printf("Introduce numero de elementos del arbol a: ");
    scanf("%d",&n);         //Leemos n�mero de nodos
    int dato;

    for (int i = 0; i<n; i++)
    {
        printf("Introduce elemento: ");
        scanf("%d",&dato);
        ABBInserta(&a,dato);         //Inserta los datos en el arbol binario
    }
    char s[STRING_SIZE]="";
    printf("Arbol a: %s\n",ABBToString(s,a));

    //segundo arbol binario

    ABB b = ABBCrea();    //creamos �rbol vac�o
    int m;
    printf("Introduce numero de elementos del arbol a: ");
    scanf("%d",&m);         //Leemos n�mero de nodos

    for (int i = 0; i<m; i++)
    {
        printf("Introduce elemento: ");
        scanf("%d",&dato);
        ABBInserta(&b,dato);         //Inserta los datos en el arbol binario
    }
    strcpy(s,"");
    printf("Arbol b: %s\n",ABBToString(s,b));

    //union

    ABB c = ABBUnion(a,b);
    strcpy(s,"");
    printf("Union de a y b: %s\n",ABBToString(s,c));

    ABBLibera(c);
    //interseccion
    c = ABBInterseccion(a,b);
    strcpy(s,"");
    printf("Interseccion de a y b: %s\n",ABBToString(s,c));

    return 0;
}

