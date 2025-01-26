#include <stdio.h>

float AreaTrapecio(float baseMayor, float baseMenor, float altura)
{
    float area = ((baseMayor + baseMenor)*altura)/2;
    return area;
}


int main ()
{
    float BM;
    float bm;
    float h;


    printf("Longitud base mayor: ");
    scanf("%f",&BM);
    printf("Longitud base menor: ");
    scanf("%f",&bm);
    printf("Altura: ");
    scanf("%f",&h);

    float a = AreaTrapecio (BM,bm,h);
    printf("El area del trapcecio es: %2.f",a);

    return 0;
}
