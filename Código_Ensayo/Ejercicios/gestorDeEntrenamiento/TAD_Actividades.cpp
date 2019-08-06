#include <stdio.h>
#include <stdlib.h>
#include <string.h> /* Para usar strlen */
#include <ctype.h> /* Para usar tuopper */

#include "TAD_Actividades.h"

/*
 *  Funciones del struct T_Actividades
 */

/* Funcion y procedimientos principales del TAD */
/*
 * Este procedimiento se hace pensando en el caso de que queramos mostrar los datos del plan son haberlos 
 * introducido previamente.
 */
void T_Actividades::InicializarPlan(){
    fir(int i=0;i<10;i++){
        strcpy(GuardarDatos[i],"No se han introducido datos");
    }
}

void T_Actividades::IntroducirPlan(){
    /* Compararemos los datos introducidos con esta variable para saber si es dia de descanso o no. */
    T_CaracteresMaximos descanso="D";

    for(int i=0;i<10;i++){
        do{
            printf("Actividad del día %2d? Nota: Los días de descanso se indican con una 'D'. \n ",i+1);
            printf("#> ");
            gets(GuardarDatos[i]);
            system("cls");
        }
    }
}