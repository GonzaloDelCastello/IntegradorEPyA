

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include "tarea.h"


void hacerMenu();
void menuCrearTarea();
/*void menuPrincipal();
void menuEditarTarea();
void buscarTarea();
void listarTareas();*/

Tarea listaTareas[100];
int cantTareas = 0;

const char* opcionesMenuCrearTarea[] = {
    "Ingresa el Titulo: ",
    "Ingresar la descripcion: ",
    "Ingrese el estado: ",
    "Ingrese la dificultad:",
    "Ingrese el Vencimiento: ",
    "Guardar la tarea y volver al menu principal.",
    "Volver al menu anterior, sin guardar."
};
int cantOpcMenuCrearTarea = sizeof(opcionesMenuCrearTarea) / sizeof(opcionesMenuCrearTarea[0]);

const char* opcionesEstado[] = {
    "Pendiente",
    "En curso",
    "Terminada",
    "Cancelada",
    "Volver al menu anterior."
};
int cantOpcEstado = sizeof(opcionesEstado) / sizeof(opcionesEstado[0]);

const char* opcionesDificultad[] = {
    "Facil",
    "Medio",
    "Dificil",
    "Volver al menu anterior."
};
int cantOpcDificultad = sizeof(opcionesDificultad) / sizeof(opcionesDificultad[0]);



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
        static char hora[60];
        time_t horaActual = time(NULL);
        struct tm* infoTiempo = localtime(&horaActual);

        strftime(hora, sizeof(hora), "%d/%m/%Y %H:%M:%S", infoTiempo);

        //printf("La hora actual es: %s\n", hora);
        return hora;
   }

void menuCrearTarea(){
    char titulo[100];
    char descripcion[200];
    int estado = 1;
    char fechaVencimiento[30];
    int dificultad = 1;
    int opcion = -1;
    while(opcion!=0){
        hacerMenu("Crear Tarea", opcionesMenuCrearTarea, cantOpcMenuCrearTarea);
        printf("Seleccione una opcion: ");
        scanf("%i", &opcion);
        system("cls");
            switch (opcion){
                case 1: //Agregar titulo (obligatorio)
                    printf("Ingrese el titulo de la tarea: ");
                    scanf("%s", titulo);
                    printf("El titulo con el nombre: %s, ha sido guadado\n", titulo);
                    printf("Titulo guradado, presione una tecla para continuar.");
                    getch();
                    system("cls");
                    break;
                case 2: //Agregar descripcion
                    printf("Ingrese la descripcion: ");
                    scanf("%s", descripcion);
                    printf("La descripcion: %s, ha sido guardada. \n  \n", descripcion);
                    printf("Descripcion guardada, presione una tecla continuar.");
                    getch();
                    system("cls");
                    break;
                case 3: //Cargar estado
                    printf("Ingrese el estado de la tarea: ");
                    hacerMenu("Ingrese el estado de la tarea: ", opcionesEstado, cantOpcEstado);
                    scanf("%i", &estado);
                    if(estado == 0){
                        printf("Presiona una tecla para continuar.");
                        getch();
                        system("cls");
                        break;
                    } else {
                    if (estado < 1 || estado > 4) {
                        printf("Estado inválido. \n");
                        estado = 1;
                        break;
                        } else{
                            printf("Estado guardado, presione una tecla para continuar.");
                            getch();
                            system("cls");
                            break;
                        }
                    }
                case 4: //Cargar dificultad
                    printf("Ingrese la dificultad:");
                    hacerMenu("Ingrese la dificultad de la tarea: ", opcionesDificultad, cantOpcDificultad);
                    scanf("%i", &dificultad);
                    if(dificultad==0){
                        printf("Presiona una tecla para continuar.");
                        getch();
                        system("cls");
                        break;
                    } else {
                        printf("La dificultad: %i, ha sido guardado. \n  \n", dificultad);
                        printf("Dificultad guardada, presione una tecla para continuar.");
                        getch();
                        system("cls");
                        break;
                    }
                case 5:
                    printf("Ingrese la fecha de vencimiento (dd/mm/aaaa): ");
                    scanf("%s", fechaVencimiento);
                    printf("La fecha: %s, ha sido guardada. \n  \n", fechaVencimiento);
                    printf("Fecha guardada, presione una tecla para continuar.");
                    getch();
                    system("cls");
                    break;
                case 6:
                    //control para inicializar tarea
                    if(strlen(titulo) == 0){
                        printf("No se puede guardar una tarea sin titulo.");
                        getch();
                        system("cls");
                        break;
                    } else {
                        Tarea tarea1 = inicializarTarea(titulo, descripcion, dificultad, estado, fechaVencimiento);


                    //Tarea tarea1 = inicializarTarea();
                    printf("La tarea %s ha sido creada.\n Desc: %s,\n dificultad %i,\n estado %i,\n fecha de creacion %s.\n", tarea1.titulo, tarea1.descripcion, tarea1.dificultad, tarea1.estado, tarea1.fechaCreacion);
                    if (cantTareas<100){
                        listaTareas[cantTareas] = tarea1;
                        cantTareas++;
                        opcion = 0;
                    } else {
                        printf("No se pueden agregar más tareas.");
                    }
                    printf("Fecha guardada, presione una tecla para continuar.");
                    getch();
                    system("cls");
                    break;
                    }

                case 0:
                    return;
                    break;
                    default:
                        printf("Opcion invalida.\n");
                        getch();
                        system("cls");
                        break;
                    }
                }
   }

Tarea inicializarTarea(const char* titulo, const char* descripcion, int dificultad, int estado, char* FechaVencimiento){
    Tarea t;
    strcpy(t.titulo, titulo);
    strcpy(t.descripcion, descripcion);
    t.dificultad = dificultad;
    t.estado = estado;
    strcpy(t.fechaCreacion, horaActu());
    strcpy(t.ultimaEdicion, horaActu());
    strcpy(t.vencimiento, FechaVencimiento);


    return t;
}

void listarTareas(){
    if(cantTareas == 0){
        printf("No hay tareas para mostrar.\n");
        getch();
        return;
    }

    printf("====== LISTADO DE TAREAS ======\n\n");

    for (int i = 0; i < cantTareas; i++) {
        printf("Tarea %i:\n", i + 1);
        printf("  Titulo        : %s\n", listaTareas[i].titulo);
        printf("  Descripcion   : %s\n", listaTareas[i].descripcion);
        printf("  Estado        : %s\n", opcionesEstado[listaTareas[i].estado - 1]);
        printf("  Dificultad    : %d\n", listaTareas[i].dificultad);
        printf("  Fecha creacion: %s\n", listaTareas[i].fechaCreacion);
        printf("  Ult. edicion  : %s\n", listaTareas[i].ultimaEdicion);
        printf("  Vencimiento   : %s\n", listaTareas[i].vencimiento);
        printf("-------------------------------\n");
    }

    printf("Presione una tecla para continuar...");
    getch();
}


