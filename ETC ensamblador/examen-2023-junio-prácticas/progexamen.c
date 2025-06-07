/* Compilar con: gcc -Wall -g -oprogexamen progexamen.c mips-runtime.c keyio.c */

#include <stdbool.h>
#include "mips-runtime.h"

/* Declaración de algunas funciones varias de utilidad y tipos cuya definición aparece más adelante */

typedef struct FechaRep Fecha;
typedef struct PacienteRep Paciente;
typedef struct ConsultaMedicaRep ConsultaMedica;
typedef struct EstadisticasRep Estadisticas;

bool comparar_fechas(Fecha* a, Fecha* b); // Devuelve true si «a» es anterior a «b»
void intercambiar_pacientes(int a, int b);
Paciente* buscar_paciente_por_id(int id_buscado);
void mostrar_fecha(Fecha* f);
bool paciente_ya_visto(Estadisticas* estadisticas, int paciente_id);

/* Tipos de datos y variables para ejercicios 1, 2 y 3 */

#define MAX_PACIENTES   20
#define MAX_CONSULTAS   100
#define MAX_LEN_NOMBRE  35
#define MAX_LEN_INFORME 150

struct FechaRep {
  int ano;
  int mes;
  int dia;
};

struct PacienteRep {
  int id;
  char nombre[MAX_LEN_NOMBRE];
  Fecha nacimiento;
  int altura_cm;
  char sexo; // «H»ombre | «M»ujer
};

struct ConsultaMedicaRep {
  int paciente_id;
  Fecha fecha;
  char informe[MAX_LEN_INFORME];
};

struct EstadisticasRep {
  int num_consultas_totales;
  int num_pacientes_id_vistos;
  int pacientes_id_vistos[MAX_PACIENTES];
  int altura_media_pacientes_cm;
};

Paciente pacientes[MAX_PACIENTES] = {
  { 7, "Zorka Setare Kuhn",            { 1956,  8,  6 }, 162, 'M' },
  { 6, "Elin Konstantin Silva",        { 1967, 11,  1 }, 168, 'M' },
  { 3, "Robert Susanoo Van Bokhoven",  { 1987,  2, 16 }, 172, 'H' },
  { 8, "Astraia Agostino Saari",       { 1995,  1, 24 }, 187, 'M' },
  { 2, "Farouk Akmad Bridges",         { 1978,  3, 17 }, 180, 'H' },
};
int num_pacientes = 5;

ConsultaMedica consultas[MAX_CONSULTAS] = {
  { 6, { 2015,  4,  5 }, "Resfriado." },
  { 8, { 2015,  6, 18 }, "Bronquiolitis." },
  { 2, { 2015,  7,  3 }, "Faringitis." }, 
  { 6, { 2015,  7,  9 }, "Otitis." },
  { 7, { 2015, 10,  4 }, "Pierna izquierda rota." },
  { 3, { 2015, 11, 15 }, "Dolor de muelas." },
  { 2, { 2015,  1, 17 }, "Astigmatismo." },
  { 2, { 2015,  4, 12 }, "Conjuntivitis." },
  { 6, { 2015,  4, 16 }, "Miopía." },
  { 2, { 2015,  5, 15 }, "Lipotimia." },
  { 8, { 2016,  6, 26 }, "Rubéola." },
  { 7, { 2016,  9, 26 }, "Gripe." },
  { 7, { 2016,  9, 30 }, "Hipocondria." },
  { 3, { 2016, 10, 24 }, "Sinusitis." },
  { 3, { 2016,  1, 14 }, "Dolor de garganta." },
  { 2, { 2016,  3, 15 }, "Gota." },
  { 2, { 2016,  3, 23 }, "Lepra." },
  { 3, { 2016,  3, 26 }, "Gastroenteritis." },
  { 3, { 2016,  4, 13 }, "Bronquitis." },
  { 7, { 2016,  6,  7 }, "Pierna derecha rota." },
};
int num_consultas = 20;

/* EJERCICIO 1 */ 
void ordenar_pacientes_por_nacimiento(void) {
  int i = 0;
  while (i < num_pacientes) {
    if (i == 0 || (comparar_fechas(&pacientes[i].nacimiento,
                                   &pacientes[i - 1].nacimiento) == false)) {
      i = i + 1;
    } else {
      intercambiar_pacientes(i, i - 1);
      i = i - 1;
    }
  }
}

/* EJERCICIO 2 */
void calcular_estadisticas(int ano, Estadisticas *estadisticas) {
  for (int i = 0; i < num_consultas; ++i) {
    if (consultas[i].fecha.ano == ano) {
      estadisticas->num_consultas_totales = estadisticas->num_consultas_totales + 1;
      if (paciente_ya_visto(estadisticas,
                            consultas[i].paciente_id) == false) {
        int indice = estadisticas->num_pacientes_id_vistos;
        estadisticas->num_pacientes_id_vistos = indice + 1;
        estadisticas->pacientes_id_vistos[indice] = consultas[i].paciente_id;
        Paciente *p = buscar_paciente_por_id(consultas[i].paciente_id);
        estadisticas->altura_media_pacientes_cm = estadisticas->altura_media_pacientes_cm + p->altura_cm;
      }
    }
  }

  if (estadisticas->num_pacientes_id_vistos > 0) {
      estadisticas->altura_media_pacientes_cm = estadisticas->altura_media_pacientes_cm / estadisticas->num_pacientes_id_vistos;
  }
}

/* EJERCICIO 3 */
int mostrar_y_contar_consultas(Paciente* paciente) {
  /* POR HACER */
}

/* Funciones varias de utilidad */

int longitud_integer(int i) {
  int l = i <= 0 ? 1 : 0;
  while (i != 0) {
    l = l + 1;
    i = i / 10;
  }
  return l;
}

void repite_caracter(char c, int veces) {
  for (int i = 0; i < veces; ++i) {
    print_character(c);
  }
}

void mostrar_fecha(Fecha* f) {
  repite_caracter('0', 4 - longitud_integer(f->ano));
  print_integer(f->ano);
  print_character('-');
  repite_caracter('0', 2 - longitud_integer(f->mes));
  print_integer(f->mes);
  print_character('-');
  repite_caracter('0', 2 - longitud_integer(f->dia));
  print_integer(f->dia);
}

void mostrar_paciente(Paciente* p) {
  print_string("ID: ");
  repite_caracter('0', 4 - longitud_integer(p->id));
  print_integer(p->id);
  print_string(", Nombre: ");
  print_string(p->nombre);
  print_string(", Fecha nacimiento: ");
  mostrar_fecha(&p->nacimiento);
  print_string(", Altura: ");
  print_integer(p->altura_cm);
  print_string("cm\n");
}

Paciente* buscar_paciente_por_id(int id_buscado) {
  for (int i = 0; i < num_pacientes; ++i) {
    if (pacientes[i].id == id_buscado) {
      return &pacientes[i];
    }
  }
  return NULL;
}

// Devuelve true si «a» es anterior a «b»
bool comparar_fechas(Fecha* a, Fecha* b) { 
  return a->ano < b->ano
    || (a->ano == b->ano && a->mes < b->mes)
    || (a->ano == b->ano && a->mes == b->mes && a->dia < b->dia);
}

void intercambiar_pacientes(int a, int b) {
  Paciente q;
  memcpy(&q, &pacientes[a], sizeof(Paciente));
  memcpy(&pacientes[a], &pacientes[b], sizeof(Paciente));
  memcpy(&pacientes[b], &q, sizeof(Paciente));
}

bool paciente_ya_visto(Estadisticas* estadisticas, int paciente_id) {
  for (int i = 0; i < estadisticas->num_pacientes_id_vistos; ++i) {
    if (estadisticas->pacientes_id_vistos[i] == paciente_id) {
      return true;
    }
  }
  return false;
}

int main(int argc, char* argv[]) {
  clear_screen();
  while (true) {
    print_string("\n\nExamen de ETC de ensamblador\n\n"
                 " 1. Ordenar pacientes por edad\n"
                 " 2. Mostrar estadísticas anuales\n"
                 " 3. Mostrar y contar consultas por paciente\n"
                 " 0. Salir\n\n"
                 "Elige una opción: ");
    char opc = read_character();
    print_string("\n\n");
    if (opc == '1') {
      print_string("Pacientes antes de ordenarlos:\n");
      for (int i = 0; i < num_pacientes; ++i) {
        mostrar_paciente(&pacientes[i]);
      }
      ordenar_pacientes_por_nacimiento();
      print_string("\nPacientes después de ordenarlos:\n");
      for (int i = 0; i < num_pacientes; ++i) {
        mostrar_paciente(&pacientes[i]);
      }
      print_character('\n');
    } else if (opc == '2') {
      for (int ano = 2015; ano <= 2016; ++ano) {
        print_string("Estadísticas anuales de ");
        print_integer(ano);
        Estadisticas e = { 0 };
        calcular_estadisticas(ano, &e);
        print_string(":\nTotal de consultas: ");
        print_integer(e.num_consultas_totales);
        print_string("\nTotal de pacientes: ");
        print_integer(e.num_pacientes_id_vistos);
        if (e.num_pacientes_id_vistos > 0) {
          print_string(" [");
          for (int i = 0; i < e.num_pacientes_id_vistos; ++i) {
            print_character(' ');
            print_integer(e.pacientes_id_vistos[i]);
          }
          print_string("]");
        }
        print_string("\nAltura media de los pacientes: ");
        print_integer(e.altura_media_pacientes_cm);
        print_string("\n\n");
      }
    } else if (opc == '3') {
      for (int i = 0; i < num_pacientes; ++i) {
        mostrar_paciente(&pacientes[i]);
        int nconsultas = mostrar_y_contar_consultas(&pacientes[i]);
        print_string("Total de consultas para el paciente ");
        repite_caracter('0', 4 - longitud_integer(pacientes[i].id));
        print_integer(pacientes[i].id);
        print_string(": ");
        print_integer(nconsultas);
        print_string("\n\n");
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

