

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



const char* opcionesMenuCrearTarea[] = {
    "Ingresa el Titulo: ",
    "Ingresar la descripcion: ",
    "Ingrese el estado ((P)endiente / (E)n proceso / (T)erminada / (C)ancelada): ",
    "Ingrese la dificultad ([1] / [2] / [3]/):",
    "Ingrese el Vencimiento (dd/mm/aaaa): ",
    "Guardar la tarea y volver al menu principal.",
    "Volver al menu anterior, sin guardar."
};
int cantOpcMenuCrearTarea = sizeof(opcionesMenuCrearTarea) / sizeof(opcionesMenuCrearTarea[0]);

const char* opcionesEstado[] = {
    "Pendiente",
    "En curso",
    "Terminada",
    "Cancelada"
};
int cantOpcEstado = sizeof(opcionesEstado) / sizeof(opcionesEstado[0]);



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

void menuCrearTarea(){
    char titulo[60];
    char descripcion[200];
    int estado;
    char fechaVencimiento[30];
    int dificultad;
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
                    printf("Titulo guradado, presione una tecla para volver al menu: crear tarea.");
                    getch();
                    system("cls");
                    break;
                case 2: //Agregar descripcion
                    printf("Ingrese la descripcion: ");
                    scanf("%s", descripcion);
                    printf("La descripcion: %s, ha sido guardada. \n  \n", descripcion);
                    printf("Descripcion guardada, presione una tecla para volver al menu: crear tarea");
                    getch();
                    system("cls");
                    break;
                case 3: //Cargar estado
                    printf("Ingrese el estado de la tarea: ");
                    hacerMenu("Ingrese el estado de la tarea: ", opcionesEstado, cantOpcEstado);
                    scanf("%i", &estado);


                    printf("Estado guardado, presione una tecla para volver al menu: crear tarea");
                    getch();
                    system("cls");
                    break;
                case 4:
                    printf("Ingrese la dificultad ([1] / [2] / [3]): ");
                    scanf("%i", &dificultad);
                    printf("El estado: %i, ha sido guardado. \n  \n", dificultad);
                    printf("Dificultad guardada, presione una tecla para volver al menu: crear tarea");
                    getch();
                    system("cls");
                    break;
                case 5:
                    printf("Ingrese la fecha de vencimiento (dd/mm/aaaa): ");
                    scanf("%s", fechaVencimiento);
                    printf("La fecha: %s, ha sido guardada. \n  \n", fechaVencimiento);
                    printf("Fecha guardada, presione una tecla para volver al menu: crear tarea");
                    getch();
                    system("cls");
                    break;
                case 6:
                    Tarea tarea1 = inicializarTarea(titulo, descripcion, dificultad, estado);
                    //control para inicializar tarea
                    //Tarea tarea1 = inicializarTarea();
                    printf("Guardar la tarea y volver al menu principal.");
                    scanf("%s", fechaVencimiento);
                    printf("La fecha: %s, ha sido guardada. \n  \n", fechaVencimiento);
                    printf("Fecha guardada, presione una tecla para volver al menu: crear tarea");
                    getch();
                    system("cls");
                    default: ;
                    }
                }
   }

Tarea inicializarTarea(const char* titulo, const char* descripcion, int dificultad, char estado){
    Tarea t;
    strcpy(t.titulo, titulo);
    strcpy(t.descripcion, descripcion);
    t.dificultad = dificultad;
    t.estado = estado;
    t.fecha_creacion = time(NULL);
    t.ultimaEdicion = t.fecha_creacion;
    t.vencimiento = t.fecha_creacion;
    return t;
}


