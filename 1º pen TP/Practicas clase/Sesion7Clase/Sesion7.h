#ifndef SESION7_H_INCLUDED
#define SESION7_H_INCLUDED

extern int error;

typedef struct BomboRep * Bombo;

// Construye y devuelve un bombo vacío que puede contener un
// máximo de n bolas. Si n<2 devuelve NULL y asigna error=1.
Bombo BomboCrea(int n);

// Inserta una bola en el bombo b.
void BomboInserta(Bombo b, int bola);

// Libera el bombo b.
void BomboLibera(Bombo b);

// Extrae y devuelve una bola del bombo b.
// Si el bombo b está vacío devuelve -1 y asigna error=2.
int BomboExtrae(Bombo b);

// Devuelve 1 si el bombo b está vacío y 0 en caso contrario.
int BomboVacia(Bombo b);

// Devuelve el mensaje de error asociado a un código de error
// del bombo b.
char * BomboMensajeError(Bombo b, int codigoError);

#endif // BOMBO_H_INCLUDED
