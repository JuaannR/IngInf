#include <stdio.h>
#include <stdlib.h>

double * PrecioRebajado(double * v1, double * v2, int n) {
    double * v3 = malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        v3[i] = v1[i] - v1[i] * v2[i] / 100.0;
    }
    return v3;
}

int main() {
    int n;
    printf("Ingrese el número de elementos: ");
    scanf("%d", &n);

    double preciosOriginales[n];
    double porcentajesDescuento[n];

    printf("Ingrese los precios originales:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &preciosOriginales[i]);
    }

    printf("Ingrese los porcentajes de descuento:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &porcentajesDescuento[i]);
    }

    double * preciosRebajados = PrecioRebajado(preciosOriginales, porcentajesDescuento, n);

    printf("Precios rebajados:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", preciosRebajados[i]);
    }
    printf("\n");

    return 0;
}
