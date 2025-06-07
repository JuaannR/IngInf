/* Compilar con: gcc -Wall -g -std=c11 -oprogexamen progexamen.c mips-runtime.c keyio.c */

#include <stdbool.h>
#include "mips-runtime.h"

#define MAX_NOMBRE_PRODUCTO 15
struct ArticuloRep {
  int unidades;
  int precio;
  char nombre[MAX_NOMBRE_PRODUCTO];
};
typedef struct ArticuloRep Articulo;

#define MAX_ARTICULOS 20
Articulo articulos[MAX_ARTICULOS] = {
  {2, 20, "Peras"},
  {3, 10, "Plátanos"},
  {10, 20, "Manzanas"},
  {6, 30, "Ciruelas"},
  {20, 20, "Piñas"},
  {0, 30, "Aguacates"},
  {5, 40, "Arándanos"},
};

int numarticulos = 7;

struct FacturaRep {
  int numarticulos;
  int importe_total;
};
typedef struct FacturaRep Factura;

#define MAX_FACTURAS 100
Factura facturas[MAX_FACTURAS] = {
  { 3, 65 },
  { 2, 30 },
  { 4, 155 }, 
  { 2, 45 },
  { 1, 60 },
};

int numfacturas = 5;


void listar_articulos(Articulo *arts, int numarts) {
  for (int i = 0; i < numarts; ++i) {
    print_string("  Artículo: ");
    print_string(arts[i].nombre);
    print_string(". Unidades: ");
    print_integer(arts[i].unidades);
    print_string(". Precio unitario: ");
    print_integer(arts[i].precio);
    print_character('\n');
  }
}

void intercambiar_articulos(int a, int b) {
  Articulo tmp = articulos[a];
  articulos[a] = articulos[b];
  articulos[b] = tmp;
}

/* EJERCICIO 1 */
void listar_facturas(void) {
  for (int i = 0; i < numfacturas; ++i) {
    print_string("Factura nº: ");
    print_integer(i+1);
    print_string(". Número de artículos: ");
    print_integer(facturas[i].numarticulos);
    print_string(". Importe total: ");
    print_integer(facturas[i].importe_total);
    print_character('\n');
  }
}

/* EJERCICIO 2 */
void ordenar_articulos_por_valor_total(void) {
  for (int i = 0; i < numarticulos; ++i) {
    int m = i;
    for (int j = i + 1; j < numarticulos; ++j) {
      int valor_j = articulos[j].unidades * articulos[j].precio;
      int valor_m = articulos[m].unidades * articulos[m].precio;
      if (valor_j > valor_m) {
        m = j;
      }
    }
    if (m != i) {
      intercambiar_articulos(m, i);
    }
  }
}

/* EJERCICIO 3 */
void actualiza_precio(Articulo* articulos, int num_articulos, int porcentaje, int cantidad_maxima) {
  /* POR HACER */
}

int main(int argc, char* argv[]) {
  clear_screen();
  while (true) {
    print_string("\n\nExamen de ETC de ensamblador\n\n"
                 " 1. Listado de facturas actuales\n"
                 " 2. Ordenar artículos por valor total\n"
                 " 3. Actualiza precio de artículos\n"
                 " 0. Salir\n\n"
                 "Elige una opción: ");
    char opc = read_character();
    print_string("\n\n");
    if (opc == '1') {
      listar_facturas();
    } else if (opc == '2') {
      print_string("Listado de artículos sin ordenar:\n");
      listar_articulos(articulos, numarticulos);
      ordenar_articulos_por_valor_total();
      print_string("\nListado de artículos ordenados por valor total, de mayor a menor:\n");
      listar_articulos(articulos, numarticulos);
    } else if (opc == '3') {
      Articulo arts[] = {
       {2, 20, "Peras"},
       {3, 10, "Plátanos"},
       {10, 20, "Manzanas"},
       {6, 30, "Ciruelas"},
       {20, 20, "Piñas"},
       {0, 30, "Aguacates"},
       {5, 40, "Arándanos"},
      };
      int num_arts = sizeof(arts) / sizeof(arts[0]);
      print_string("Artículos antes del ajuste de precio:\n");
      listar_articulos(arts, num_arts);
      actualiza_precio(arts, num_arts, 20, 5);
      print_string("\nArtículos después del ajuste de precio (incremento del 20% cuando haya 5 o menos):\n");
      listar_articulos(arts, num_arts);
    } else if (opc == '0') {
      print_string("¡Adiós!\n");
      mips_exit(0);
    } else {
      print_string("Opción incorrecta. Pulse cualquier tecla para seguir.\n");
      read_character();
    }
  }
}
