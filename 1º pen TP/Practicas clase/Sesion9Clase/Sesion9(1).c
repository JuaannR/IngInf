#include "Cola.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5

int main () {
    int especialidad;
    char especialidades[N][17]= {"Medicina general","Pediatria","Reumatologia","Medicina Interna","Enfermeria"};
    Cola * consultorio = malloc(sizeof(Cola)*N);
    for (int i=0; i<N; i++)
        consultorio[i] = crea();
        int pacientes = 0;
        Elemento paciente;
        //encolar a cada paciente en la cola de sus especialidades
    do {
        printf("Dime la especialidad (entre 1 y %d) : ",N);
        scanf("%d",&especialidad);
        if (especialidad != 0) {
            printf("Dime tu nombre: ");
            scanf("%s",paciente.nombre);
            printf("Dime tu DNI: ");
            scanf("%s",paciente.DNI);
            inserta(consultorio[especialidad],paciente);
            pacientes++;
        }
    }while (especialidad !=0);

    //proceso de dar paso al paciente siguiente
    srand(time(NULL));


    //a + rand()%(b-a+1)
    /*
    while(pacientes>0)
        int cola_rand <- //cola aleatoria entre 0 y N-1
    while(vacia(cola_rand))
        cola_rand <- (cola_rand+1)%N
    recuperar paciente
    Imprimir en pantalla nombre, DNI y especialidad
    Suprimir paciente de su cola
    pacientes--
    Liberar todas las colas
    Liberar el consultorio
    */





    return 0;
}
