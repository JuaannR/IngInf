#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

int escribir_fichero(char *nombre)
{
    //Declarar el fichero
    FILE * f;
    //Abrir fichero para escritura
    f = fopen(nombre,"w");
    if (f==NULL)
        return -1;
    do
    {
        char c = getc(stdin);
        if(!feof(stdin))
            putc(c,f);
    }while(!feof(stdin));
    fclose(f);
    return 0;
}

int caracteres_fichero(char * nombre)
{
    //Declarar el fichero
    FILE * f;
    //Abrir fichero para lectura
    f = fopen(nombre,"r");
    if (f==NULL)
        return -1;
    int cont=0;
    do
    {
        char c = getc(f);
        if(!feof(f) && c!='\n')
            cont++;
    }while(!feof(f));
    fclose(f);
    return cont;
}

int palabras_fichero(char * nombre)
{
    //Declarar el fichero
    FILE * f;
    //Abrir fichero para lectura
    f = fopen(nombre,"r");
    if (f==NULL)
        return -1;
    int cont=0;
    do
    {
        char palabra[100];
        fscanf(f,"%s",palabra);
        if(!feof(f))
            cont++;
    }while(!feof(f));
    fclose(f);
    return cont;
}

int main ()
{
    char nombre[]="texto.txt";
    printf("Introduce texto (RETURN CTRL+Z RETURN para terminar):\n ");
    if (escribir_fichero(nombre)!=0)
    {
        //Tratamiento de errores
        fprintf(stderr, "El fichero no se puede abrir para escritura %s\n",nombre);
        fprintf(stderr, "Error numero %d\n",errno);
        fprintf(stderr, "%s: %s\n",nombre,strerror(errno));
    }

    system("pause");

    int n_car = caracteres_fichero(nombre);
    if (n_car != 1)
        printf("El numero de caracteres es %d. \n", n_car);
    else
    { //tratamiento de errores
        fprintf(stderr, "El fichero no se puede abrir para escritura %s\n",nombre);
        fprintf(stderr, "Error numero %d\n",errno);
        fprintf(stderr, "%s: %s\n",nombre,strerror(errno));
    }

    int n_pal = palabras_fichero(nombre);
    if (n_pal != 1)
        printf("El numero de palabras es %d. \n", n_pal);
    else
    { //tratamiento de errores
        fprintf(stderr, "El fichero no se puede abrir para escritura %s\n",nombre);
        fprintf(stderr, "Error numero %d\n",errno);
        fprintf(stderr, "%s: %s\n",nombre,strerror(errno));
    }

    return 0;
}
