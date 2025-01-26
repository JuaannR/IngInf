#include <stdio.h>
int sumatorio(int n)
{
  if (n==1)
        return 1;
  return sumatorio(n-1)+n;
}

int suma_digitos(int n)
{
    if (n<10)
        return n;
    return suma_digitos(n/10)+n%10;
}

int longitud(char * s)
{
    if (s[0]==0)
        return 0;
    return longitud(s+1)+1;
}

void piramide(char * s)
{
    if(s[0]==0)
        return;
    piramide(s+1);
    printf("%s\n",s);
}

void piramide_invertida(char * s)
{
    if(s[0]==0)
        return;
    printf("%s\n",s);
    piramide_invertida(s+1);

}

int palindromo_aux(char * s, int i, int j)
{
    if(i>j)
        return 1;
    if (s[i]!=s[j])
        return 0;
    return palindromo_aux(s,i+1,j-1);

}

int palindromo(char * s)
{
    return palindromo_aux(s,0,longitud(s));
}

int main()
{
    int n = 224;
    printf("Sumatorio de %d: %d \n",n,sumatorio(n));
    printf("Suma de los digitos de %d: %d \n",n,suma_digitos(n));
    char s[100] = "hola que tal";
    printf("Longitud de %s: %d\n",s,longitud(s));
    piramide(s);
    piramide_invertida(s);
    return 0;

}
