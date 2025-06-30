#include<stdio.h>
#include<conio.h>
#include<time.h>
#include <stdlib.h>
#include "tarea.h"


void menuCrearTarea();
void hacerMenu();
/*void menuCrearTarea();
void menuPrincipal();
void menuEditarTarea();
void buscarTarea();
void listarTareas();*/



//Función que elabora un menú con opciones. Recibe Título, array de Opciones e int de cantidad
/*void hacerMenu(const char* titulo, const char* opciones[], int cantidad){
    printf("\n\n---%s---\n\n", titulo);
    for (int i = 0; i < cantidad; i++){
        if (i!=(cantidad-1)){
            printf("[%i] %s\n", i+1, opciones[i]);
        } else {
        printf("[0] %s\n", opciones[i]);}
    }
}*/
//Función que devuelve un char con la hora en formato legible.
/*char* horaActu(){
        static char hora[80];
        time_t horaActual = time(NULL);
        struct tm* infoTiempo = localtime(&horaActual);

        strftime(hora, sizeof(hora), "%d/%m/%Y %H:%M:%S", infoTiempo);

        printf("La hora actual es: %s\n", hora);
        return hora;
   }*/

int main() {


int opcion=1;

const char* menuPrincipal[] = {
    "Crear nuevas tareas",
    "Buscar una tarea especifica",
    "Ver todas mis tareas",
    "Salir"
};

int cantOpcMenuPrincipal = sizeof(menuPrincipal) / sizeof(menuPrincipal[0]);

printf("\nBienvenidx a tu gestor de TAREAS\n\n");





//Inicia el menú principal
while(opcion!=0){

    hacerMenu("Menu Principal", menuPrincipal, cantOpcMenuPrincipal);

    printf("Seleccione una opcion: ");
    scanf("%i", &opcion);
    system("cls");


        switch (opcion){
        case 1:
            menuCrearTarea();





                break;

        case 2:

                break;


    }
    system("cls");
    opcion = -1;
}
    return 0;


}
