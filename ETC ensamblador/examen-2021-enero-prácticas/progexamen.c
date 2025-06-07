/* Compilar con: gcc -Wall -g -std=c11 -oprogexamen progexamen.c mips-runtime.c keyio.c */

#include <stdbool.h>
#include "mips-runtime.h"

#define TABLERO_MAX_SIZE 1024

struct MatrizRep { 
  unsigned int filas; 
  unsigned int columnas;
  char data[TABLERO_MAX_SIZE];
};
typedef struct MatrizRep Tablero;
typedef struct MatrizRep Pieza;

char* tablero_celda_addr(Tablero* tablero, int fila, int columna) {
  return &tablero->data[fila * tablero->columnas + columna];
}

void tablero_set_celda(Tablero* tablero, int fila, int columna, int valor) {
  char* celda = tablero_celda_addr(tablero, fila, columna);
  *celda = valor;
}

int tablero_get_celda(Tablero* tablero, int fila, int columna) {
  char* celda = tablero_celda_addr(tablero, fila, columna);
  return *celda;
}

void tablero_init(Tablero* tablero, int filas, int columnas) {
  tablero->filas = filas;
  tablero->columnas = columnas;
  for (int fila = 0; fila < tablero->filas; ++fila) {
    for (int columna = 0; columna < tablero->columnas; ++columna) {
      tablero_set_celda(tablero, fila, columna, ' ');
    }
  }
}

void tablero_copy(Tablero* destino, Tablero* origen) {
  destino->filas = origen->filas;
  destino->columnas = origen->columnas;
  for (int fila = 0; fila < origen->filas; ++fila) {
    for (int columna = 0; columna < origen->columnas; ++columna) {
      tablero_set_celda(destino, fila, columna, tablero_get_celda(origen, fila, columna));
    }
  }
}

void tablero_print(Tablero* tablero) {
  print_string("+");
  for (int columna = 0; columna < tablero->columnas; ++columna) {
    print_string("-");
  }
  print_string("+\n");
  for (int fila = 0; fila < tablero->filas; ++fila) {
    print_string("|");
    for (int columna = 0; columna < tablero->columnas; ++columna) {
      char n = tablero_get_celda(tablero, fila, columna);
      print_character(n);
    }
    print_string("|\n");
  }
  print_string("+");
  for (int columna = 0; columna < tablero->columnas; ++columna) {
    print_string("-");
  }
  print_string("+\n");
}

void tablero_colocar_pieza(Tablero* destino, int x, int y, Pieza* pieza) {
  for (int i = 0; i < pieza->filas; ++i) {
    for (int j = 0; j < pieza->columnas; ++j) {
      tablero_set_celda(destino, x + i, y + j, tablero_get_celda(pieza, i, j));
    }
  }
}

/* Piezas predefinidas */
Pieza pieza1 = { 3, 3, 
                 { ' ', '*', ' ',
                   ' ', ' ', '*',
                   '*', '*', '*', 
                 } };

/*
 * 
 */
int contar_vecinos(Tablero* tablero, int fila, int columna) {
  int n = 0;
  for (int i = -1; i <= 1; ++i) {
    for (int j = -1; j <= 1; ++j) {
      if (i != 0 || j != 0) {
        int f = (fila + i + tablero->filas) % tablero->filas;
        int c = (columna + j + tablero->columnas) % tablero->columnas;
        if (tablero_get_celda(tablero, f, c) != ' ') {
          ++n;
        }
      }
    }
  }
  return n;
}

void simular_vida(Tablero* tablero) {
  Tablero tablero_auxiliar;
  tablero_copy(&tablero_auxiliar, tablero);
  for (int i = 0; i < tablero->filas; ++i) {
    for (int j = 0; j < tablero->columnas; ++j) {
      int nvecinos = contar_vecinos(&tablero_auxiliar, i, j);
      if (nvecinos == 3) {
        tablero_set_celda(tablero, i, j, '*');
      } else if (nvecinos == 2) {
        tablero_set_celda(tablero, i, j, tablero_get_celda(&tablero_auxiliar, i, j));
      } else { // nvecinos >=4 || nvecinos < 2
        tablero_set_celda(tablero, i, j, ' ');
      }
    }
  }
}

/* Comprueba si los tableros a y b on del mismo tamaño. Si lo son,
 * devuelve true, inicializa el tablero resultado y almacena en cada
 * celda del mismo un caracter '<', '>' o '=' representando el
 * resultado de la comparación de las celdas respectivas de los
 * tableros a y b. Devuelve false en otro caso. */
bool comparar_tableros_celda_a_celda(Tablero* resultado, Tablero* a, Tablero* b) {
  /* POR HACER */
}

int clasificar_numeros(int* entrada, int n_elementos, int* pares, int* impares) {
  int n_pares = 0;
  int n_impares = 0;
  for (int i = 0; i < n_elementos; ++i) {
    if (entrada[i] % 2 == 0) {
      pares[n_pares] = entrada[i];
      ++n_pares;
    } else {
      impares[n_impares] = entrada[i];
      ++n_impares;
    }
  }
  return n_pares;
}

/* Cuenta cuántos números aparecen en la tablero que estén contenidos
 * en el intervalo [lim_inferior, lim_superior] (inclusive) */ 
void eliminar_caracteres(Tablero* tablero, char* eliminar, int n_eliminar) {
  /* POR HACER */
}

struct ItemRep {
  char nombre[100];
  int x;
  int y;
};
typedef struct ItemRep Item;

bool item_menor_que(Item* a, Item* b) {
  if (a->x == b->x) {
    return a->y < b->y;
  } else {
    return a->x < b->x;
  }
}

void ordenar_items(Item* array, int n_items) {
  int it = 0;
  while (it < n_items) {
    if (it == 0 || item_menor_que(&array[it], &array[it - 1]) == false) {
      it = it + 1;
    } else {
      Item t = array[it];
      array[it] = array[it - 1];
      array[it - 1] = t;
      it = it - 1;
    }
  }
} 

int main(int argc, char* argv[]) {
  clear_screen();
  while (true) {
    print_string("\n\nExamen de ETC de ensamblador\n\n"
                 " 1. Simular juego de la vida (prueba contar_vecinos)\n"
                 " 2. Comparar tableros\n"
                 " 3. Clasificar números\n"
                 " 4. Eliminar caracteres de tableros\n"
                 " 5. Ordenar\n"
                 " 0. Salir\n\n"
                 "Elige una opción: ");
    char opc = read_character();
    print_string("\n\n");
    if (opc == '1') {
      Tablero t;
      tablero_init(&t, 10, 30);
      tablero_colocar_pieza(&t, 2, 4, &pieza1);
      int i = 0;
      while (true) {
        clear_screen();
        print_string("Iteración ");
        print_integer(i);
        print_string(":\n");
        tablero_print(&t);
        print_string("\n Pulsa «X» para salir, o cualquier otra para pasar a la siguiente iteración. ");
        char c = read_character();
        if (c == 'x' || c == 'X') {
          break;
        }
        ++i;
        simular_vida(&t);
      }
    } else if (opc == '2') {
      Tablero t1 = { 5, 4, "11112222333344445555" };
      Tablero t2 = { 5, 4, "101312a2933a33442456" };
      Tablero t3 = { 5, 10, "aaaaaaaaaabbbbbbbbbbccccccccccddddddddddeeeeeeeeee" };
      Tablero t4 = { 5, 10, "aaazzzazaabbbbb33bxbcccxc55cccddddddzz22222zeeeeee" };
      Tablero r;
      struct { Tablero* a; Tablero* b; } tests[] = {
        { &t1, &t2 },
        { &t2, &t3 },
        { &t3, &t4 },
        { &t4, &t3 },
      };
      for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); ++i) {
        print_string("Comparando:\n");
        tablero_print(tests[i].a);
        print_string("y:\n");
        tablero_print(tests[i].b);
        if (comparar_tableros_celda_a_celda(&r, tests[i].a, tests[i].b)) {
          print_string("Resultado:\n");
          tablero_print(&r);          
        } else {
          print_string("Los tableros no son del mismo tamaño, por lo que no se pueden comparar celda a celda.\n");
        }
        print_string("\nPulse una tecla para otra prueba.\n");
        read_character();
        print_string("\n\n");
      }
    } else if (opc == '3') {
      int test[] = { 2369, 2021, 8712, 8510, 1060, 7543, 8849, 1504, 2533, 3045, 7228, 8911, 6856, 2825, 9510, 4352, 8870, 6191, 2500, 2856 };
      int test_len = sizeof(test) / sizeof(test[0]);
      print_string("Clasificando: ");
      for (int i = 0; i < test_len; ++i) {
        print_integer(test[i]);
        print_character(' ');
      }
      int pares[test_len];
      int impares[test_len];
      int n_pares = clasificar_numeros(test, test_len, pares, impares);
      print_string("\nPares: ");
      for (int i = 0; i < n_pares; ++i) {
        print_integer(pares[i]);
        print_character(' ');
      }
      print_string("\nImpares: ");
      for (int i = 0; i < (test_len - n_pares); ++i) {
        print_integer(impares[i]);
        print_character(' ');
      }
      print_character('\n');
    } else if (opc == '4') {
      Tablero t1 = { 5, 9, "aaaaaaaaabbbbbbbbbcccccccccdddddddddeeeeeeeee" };
      Tablero t2 = { 7, 8, "jfsvnrpotigdsfbkndsvfelkrgoirgfgijdsfgkndffkgjh123456789" };
      struct { Tablero* a; char *eliminar, n_eliminar; } tests[] = {
        { &t1, "abde", 4 },
        { &t2, "jgf", 3 },
      };
      for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); ++i) {
        print_string("Eliminado «");
        print_string(tests[i].eliminar);
        print_string("» de:\n");
        tablero_print(tests[i].a);
        print_string("Resultado:\n");
        eliminar_caracteres(tests[i].a, tests[i].eliminar, tests[i].n_eliminar);
        tablero_print(tests[i].a);
        print_character('\n');
      }
    } else if (opc == '5') {
      Item test[] = {
        { "abc", 3, 5 },
        { "def", 8, 2 },
        { "ghi", 3, 1 },
        { "jkl", 0, 3 },
        { "mnñ", 0, 2 },
      };
      print_string("Lista sin ordenar:\n");
      for (int i = 0; i < sizeof(test) / sizeof(test[0]); ++i) {
        print_string(test[i].nombre);
        print_character(' ');
        print_integer(test[i].x);
        print_character(' ');
        print_integer(test[i].y);
        print_character(' ');
        print_character('\n');
      }
      ordenar_items(test, sizeof(test) / sizeof(test[0]));
      print_string("\nLista ordenada:\n");
      for (int i = 0; i < sizeof(test) / sizeof(test[0]); ++i) {
        print_string(test[i].nombre);
        print_character(' ');
        print_integer(test[i].x);
        print_character(' ');
        print_integer(test[i].y);
        print_character(' ');
        print_character('\n');
      }
    } else if (opc == '0') {
      print_string("¡Adiós!\n");
      mips_exit(0);
    } else {
      print_string("Opción incorrecta. Pulse cualquier tecla para seguir.\n");
      read_character();
    }
  }
}
