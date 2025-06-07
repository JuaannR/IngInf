/* Compilar con: gcc -Wall -g -std=c11 -oprogexamen progexamen.c mips-runtime.c keyio.c */

#include <stdbool.h>
#include "mips-runtime.h"

#define MAX_LONGITUD_NOMBRE 18
struct PersonaRep {
  char nombre[MAX_LONGITUD_NOMBRE];
  int edad;
  char sexo; // F = Femenino, M = Masculino
};
typedef struct PersonaRep Persona;

#define MAX_PERSONAS 100
Persona personas[MAX_PERSONAS] = {
  { "Tracey Sanders", 25, 'F' },
  { "Teresa Reed", 30, 'F' },
  { "Erin Franklin", 29, 'F' },
  { "Bruce Cruz", 65, 'M' },
  { "Cody Robinson", 47, 'M' },
  { "Christy Sandoval", 22, 'F' },
  { "Kelsey Newman", 58, 'F' },
  { "Beverly Jackson", 77, 'F' },
  { "Kristina Grimes", 27, 'F' },
  { "Ralph Wheeler", 30, 'M' },
};
int num_personas = 10;

void leer_cadena(char* destino, int max_tam) {
  read_string(destino, max_tam);
  /* Elimina el '\n' final leído */
  for (int i = 0; i < max_tam; ++i) {
    if (destino[i] == '\n') {
      destino[i] = '\0';
      break;
    }
  }
}

void intercambiar_personas(int a, int b) {
  Persona tmp = personas[a];
  personas[a] = personas[b];
  personas[b] = tmp;
}

/* EJERCICIO 2 */
void ordenar_personas_por_edad(void) {
  for (int i = 0; i < num_personas; ++i) {
    int m = i;
    for (int j = i + 1; j < num_personas; ++j) {
      if (personas[j].edad < personas[m].edad) {
        m = j;
      }
    }
    if (m != i) {
      intercambiar_personas(m, i);
    }
  }
}

/* EJERCICIO 1 */
void anadir_persona(void) {
  if (num_personas < MAX_PERSONAS) {
    print_string("Nombre: ");
    leer_cadena(&personas[num_personas].nombre[0], MAX_LONGITUD_NOMBRE);
    char s;
    do {
      print_string("Sexo (M/F): ");
      s = read_character();
      print_character('\n');
      /* Pasa a mayúsculas si es necesario */
      if (s >= 'a') {
        s = s - ('a' - 'A');
      }
    } while (s != 'M' && s != 'F');
    personas[num_personas].sexo = s;
    print_string("Edad: ");
    personas[num_personas].edad = read_integer();
    num_personas = num_personas + 1;
  } else {
    print_string("No se pueden añadir más personas a la lista.");
  }
}

long unsigned int strlen(const char* s) {
  const char* p = s;
  while (*p != '\0') {
    ++p;
  };
  return p - s;
}

void listar_personas(void) {
  for (int i = 0; i < num_personas; ++i) {
    print_string(personas[i].nombre);
    for (int j = strlen(personas[i].nombre); j < MAX_LONGITUD_NOMBRE + 2; ++j) {
      print_character(' ');
    }
    print_integer(personas[i].edad);
    print_string("  ");
    print_character(personas[i].sexo);
    print_character('\n');
  }
}

struct RectanguloRep {
  int ancho;
  int alto;
};
typedef struct RectanguloRep Rectangulo;

/* EJERCICIO 3 */
int calcula_area_y_ajusta_rectangulos(Rectangulo* array_rectangulos, int num_rectangulos) {
  /* POR HACER */
}


int main(int argc, char* argv[]) {
  clear_screen();
  while (true) {
    print_string("\n\nExamen de ETC de ensamblador\n\n"
                 " 1. Añadir persona\n"
                 " 2. Ordenar personas por edad\n"
                 " 3. Calcular el área de una lista de rectángulos y ajustarlos\n"
                 " 0. Salir\n\n"
                 "Elige una opción: ");
    char opc = read_character();
    print_string("\n\n");
    if (opc == '1') {
      anadir_persona();
      print_string("Listado de personas actual:\n");
      listar_personas();
    } else if (opc == '2') {
      print_string("Listado de personas sin ordenar:\n");
      listar_personas();
      ordenar_personas_por_edad();
      print_string("\nListado de personas ordenado por edad:\n");
      listar_personas();
    } else if (opc == '3') {
      Rectangulo rects[] = {
        { 10, 20 },
        { 30, 15 },
        { 12, 67 },
        { 21, 13 },
      };
      int num_rects = sizeof(rects) / sizeof(rects[0]);
      print_string("Rectángulos antes del ajuste:\n");
      for (int i = 0; i < num_rects; ++i) {
        print_integer(rects[i].ancho);
        print_string(" × ");
        print_integer(rects[i].alto);
        print_character('\n');
      }
      int total = calcula_area_y_ajusta_rectangulos(&rects[0], num_rects);
      print_string("\nRectángulos después del ajuste:\n");
      for (int i = 0; i < num_rects; ++i) {
        print_integer(rects[i].ancho);
        print_string(" × ");
        print_integer(rects[i].alto);
        print_character('\n');
      }
      print_string("\nÁrea total: ");
      print_integer(total);
    } else if (opc == '0') {
      print_string("¡Adiós!\n");
      mips_exit(0);
    } else {
      print_string("Opción incorrecta. Pulse cualquier tecla para seguir.\n");
      read_character();
    }
  }
}
