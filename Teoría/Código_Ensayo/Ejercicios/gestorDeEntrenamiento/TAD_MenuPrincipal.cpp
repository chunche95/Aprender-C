#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "TAD_MenuPrincipal.h"

/* Funciones del struct T_MenuPrincipal. */
/*
 * Procedimientos principales del TAD.
 */
void T_MenuPrincipal::InicializarValores(){
    PlanDeActividades.InicializarPlan();
    PlanDeActividades.PlanGuardado=false;
    Fecha.FechaGuardada=false;
}

void T_MenuPrincipal::ElegirOpcion(){
    system("cls");
    printf("    SELECIONE UNA OPCION. \n");
    printf(" 1. Introducir plan de entrenamiento. \n");
    printf(" 2. Listar plan de entrenamiento. \n");
    printf(" 3. Introducir decha de inicio de plan. \n");
    printf(" 4. Mostrar plan en el calendario. \n");
    printf(" 5. Salir del programa. \n");
    do{
        printf("\n --> ");
        fflush(stdin);
        scanf("%d",&opcion);
        if((opcion<1) || (opcion>5)){
            printf("Error: Opción seleccionada NO válida. \n");
        }
    }while ((opcion<1)||(opcion>5));
}

void T_MenuPrincipal::RealizarAccion(){
    switch(opcion){
        case 1:
            system("cls");
            fflush(stdin);
            PlanDeActividades.IntroducirPlan();
            break;
        case 2:
            system("cls");
            PlanDeActividades.ListarPlan();
            break;
        case 3:
            system("cls");
            Fecha.InicioPlan();
            break;
        case 4:
            system("cls");
            Fecha.MostrarPlan(PlanDeActividades.TipoCD,PlanDeActividades.PlanGuardado);
            break;
        case 5:
            break;
    }
}

void T_MenuPrincipal::Repetir(){
    fflush(stdin);
    if(opcion!=5){
        do{
            printf("\n Volver al Menú Principal: (S/N) ");
            scanf("%c",&respuesta);
            /* Evitamos el key sensitive, asi las MAYUSCULAS o minusculas no afectaran a la respuesta. */
            respuesta=toupper(respuesta);
        }while (respuesta!='S' && respuesta!='N'); /* Solo acepta S/N. */
    }
}