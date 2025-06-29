

#include <stdio.h>
#include <string.h>
#include "tarea.h"


void hacerMenu();
/*void menuCrearTarea();
void menuPrincipal();
void menuEditarTarea();
void buscarTarea();
void listarTareas();*/

/*void inicializarTarea(Tarea* t, const char* titulo, const char* descripcion, int dificultad) {
    strcpy(t->titulo, titulo);
    strcpy(t->descripcion, descripcion);
    t->estado = 0; // Por ejemplo, 0 = pendiente
    t->dificultad = dificultad;
    t->fecha_creacion = time(NULL);
}*/

/*void mostrarTarea(Tarea* t) {
    char fecha[80];
    strftime(fecha, sizeof(fecha), "%d/%m/%Y %H:%M:%S", localtime(&t->fecha_creacion));

    printf("\n--- TAREA ---\n");
    printf("Título: %s\n", t->titulo);
    printf("Descripción: %s\n", t->descripcion);
    printf("Estado: %d\n", t->estado);
    printf("Dificultad: %d\n", t->dificultad);
    printf("Fecha de creación: %s\n", fecha);
}*/

void hacerMenu(const char* titulo, const char* opciones[], int cantidad){
    printf("\n\n---%s---\n\n", titulo);
    for (int i = 0; i < cantidad; i++){
        if (i!=(cantidad-1)){
            printf("[%i] %s\n", i+1, opciones[i]);
        } else {
        printf("[0] %s\n", opciones[i]);}
    }
}
char* horaActu(){
        static char hora[80];
        time_t horaActual = time(NULL);
        struct tm* infoTiempo = localtime(&horaActual);

        strftime(hora, sizeof(hora), "%d/%m/%Y %H:%M:%S", infoTiempo);

        printf("La hora actual es: %s\n", hora);
        return hora;
   }

   //Menú principal
const char* menuPrincipal[] = {
    "Crear nuevas tareas",
    "Buscar una tarea especifica",
    "Ver todas mis tareas",
    "Salir"
};
//Menú crearTarea
const char* menuCrearTarea[] = {
    "Ingresa el Título: ",
    "Ingresar la descripcion: ",
    "Ingrese el estado ((P)endiente / (E)n proceso / (T)erminada / (C)ancelada): ",
    "Ingrese la dificultad ([1] / [2] / [3]/):",
     "ingrese el Vencimiento (dd//mm/aaaa): "
};
int cantOpcMenuCrearTarea = sizeof(menuCrearTarea) / sizeof(menuCrearTarea[0]);


