
#ifndef TAREA_H
#define TAREA_H

#include <time.h>

// Estructura para representar una tarea
typedef struct {
    char titulo[100];
    char descripcion[250];
    int estado;
    int dificultad;
    char fechaCreacion[30];
    char ultimaEdicion[30];
    char vencimiento[30];
} Tarea;


// Declaración de funciones
void mostrarTarea(Tarea* t);
//void inicializarTarea(Tarea* t, const char* titulo, const char* descripcion, int dificultad);
Tarea inicializarTarea(const char* titulo, const char* descripcion, int dificultad, int estado, char vencimiento[30]);
void hacerMenu(const char* titulo, const char* opciones[], int cantidad);
char* horaActu();
void listarTareas();

#endif
