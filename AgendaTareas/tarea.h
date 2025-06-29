
#ifndef TAREA_H
#define TAREA_H

#include <time.h>

// Estructura para representar una tarea
typedef struct {
    char titulo[100];
    char descripcion[250];
    int estado;
    int dificultad;
    time_t fecha_creacion;
    time_t ultimaEdicion;
    time_t vencimiento;
} Tarea;


// Declaración de funciones
void mostrarTarea(Tarea* t);
void inicializarTarea(Tarea* t, const char* titulo, const char* descripcion, int dificultad);
void hacerMenu(const char* titulo, const char* opciones[], int cantidad);
char* horaActu();

#endif
