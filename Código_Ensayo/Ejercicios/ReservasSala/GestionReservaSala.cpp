#include<stdio.h>
#include <string.h>
#include <Windows.h>
#include "GestionReservaSala.h"
#include "calendario.h"

TipoReserva auxReserva;
RMAnno reservasMT;
contadores_t contadores;
typedef TAD_Calendario calendarios[maxContMeses];
calendarios mesesTotales;

/* Calendarios de cada mes. */
TAD_Calendario mes1;
TAD_Calendario mes2;
TAD_Calendario mes3;
TAD_Calendario mes4;
/* Auxiliar de calendario mensual. */
TAD_Calendario grAuxMes;

/*
 * Procedimiento iniciar el auxReserva y que no queden residuos.
 */

void TAD_Gestor_Reservas::iniciarAuxReserva(){
    strcpy(auxReserva.nombrecompleto, " ");
    auxReserva.dia=0;
    auxReserva.mes=0;
    auxReserva.anyo=0;
    auxReserva.hc=0;
    auxReserva.duracion=0;
}

/*
 * Procedimineto para crear los cuatro calendarios e iniciar listar, variables, etc.
 */
void TAD_Gestor_Reservas::iniciarCalendarios(int mmi, int ddi){
    /* Iniciar los meses a partir del mes actual. */
    int a;
    /* Para el caso de que el año debe incrementarse. */
    a=ddi+1;

    if(mmi<10){
        mesesTotales[mmi]=grAuxMes;
        mesesTotales[mmi].RellenarMesCalendario(mmi,ddi);
        mesesTotales[mmi+1]=grAuxMes;
        mesesTotales[mmi+1].RellenarMesCalendario((mmi+1),ddi);
        mesesTotales[mmi+2]=grAuxMes;
        mesesTotales[mmi+2].RellenarMesCalendario((mmi+2),ddi);
        mesesTotales[mmi+3]=grAuxMes;
        mesesTotales[mmi+3].RellenarMesCalendario((mmi+3),ddi);
        /* Sobreescritura para los casos en los que cambie de año, al siguiente. */
    }else if(mmi==10){
        mesesTotales[mmi]=grAuxMes;
        mesesTotales[mmi+1]=grAuxMes;
        mesesTotales[mmi+1].RellenarMesCalendario((mmi+1),ddi);
        mesesTotales[mmi+2]=grAuxMes;
        mesesTotales[mmi+2].RellenarMesCalendario((mmi+2),ddi);
        mesesTotales[1]=grAuxMes;
        mesesTotales[1].RellenarMesCalendario(1,a);
    }
}