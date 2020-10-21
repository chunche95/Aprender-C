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
            if(strlen(GuardarDatos[i])>1000){
                system("cls");
                printf("Warning! Ha superado los 1000 caracteres. \n");
            }
        /* Volvemos a pedir datos si nos pasamos de los 1000 caracteres. */            
        }while(strlen(GuardarDatos[i])>1000);

        /* 
         * Si los datos introducidos son iguales a "D" 
         * Guardamos en la variable TipoCD una "D" y además sustituiremos esa 'D' por el texto 
         *                                'Día de descanso'.
         * Sino lo guardamos en TipoCD guardamos una 'C'.
         */
        if(strcmp(GuardarDatos[i],descanso)==0){
            TipoCD[i]=D;
            strcpy(GuardarDatos[i], "Día de descanso");
        }else{
            TipoCD[i]=C;
        }
    }
    /* Como hemos almacenado un plan de entrenamiento PlanGuardado pasa a True */
    PlanGuardado=true;
    printf("Todos los datos se han almacenado correctamente. \n");
}

void T_Actividades::ListarPlan(){
 for(int j=0; j<10; j++){
     printf("Entrenamiento del día %2d \n", j+1);
     printf("%s \n \n ",guardarDatos[j]);
 }   
}