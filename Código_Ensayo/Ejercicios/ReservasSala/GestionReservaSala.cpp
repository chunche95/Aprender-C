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
        /* Mes 1 es octubre */
        mesesTotales[mmi]=grAuxMes;
        mesesTotales[mmi+1]=grAuxMes;
        mesesTotales[mmi+1].RellenarMesCalendario((mmi+1),ddi);
        mesesTotales[mmi+2]=grAuxMes;
        mesesTotales[mmi+2].RellenarMesCalendario((mmi+2),ddi);
        mesesTotales[1]=grAuxMes;
        mesesTotales[1].RellenarMesCalendario(1,a);
    }else if(mmi==11){
        /* Mes 1 es noviembre */
        mesesTotales[mmi]=grAuxMes;
        mesesTotales[mmi+1].RellenarMesCalendario(mmi,ddi);
        mesesTotales[mmi+2]=grAuxMes;
        mesesTotales[mmi+2].RellenarMesCalendario((mmi+1),ddi);
        mesesTotales[1]=grAuxMes;
        mesesTotales[1].RellenarMesCalendario(1,a);
        mesesTotales[2]=grAuxMes;
        mesesTotales[2].RellenarMesCalendario(2,a);
    }else if(mmi==12){
        /* Mes 1 es diciembre */
        mesesTotales[mmi]=grAuxMes;
        mesesTotales[1]=grAuxMes;
        mesesTotales[1].RellenarMesCalendario(1,a);
        mesesTotales[2]=grAuxMes;
        mesesTotales[2].RellenarMesCalendario(2,a);
        mesesTotales[3]=grAuxMes;
        mesesTotales[3].RellenarMesCalendario(3,a);
    }
    iniciarAuxReserva();
    /*
     * Inicializo la lista de contadores. 
     */
    for (int i=0; i<=maxContMeses;i++){
        contadores[i]=0;
    }
}

/*
 * Funcion que comprueba que una reserva nueva no solapa otra reserva anterior. True = No solapa.
 */
bool TAD_Gestor_Reservas::noSolapa(int dd, int mm, int hc, int dur, int contador){
    for(int i=0;i<=contador;i++){
        if((reservasMT[mm][i].dia==dd) && (reservasMT[mm][i].hc<hc) && ((reservasMT[mm][i].hc+reservasMT[mm][i].duracion)>hc){
            /* Solapa por delante de una reserva previa. */
            return false;
        }else if((reservasMT[mm][i].dia == dd) &&(reservasMT[mm][i].hc>hc) && ((hc+dur)>reservasMT[mm][i])){
            /* Que solape por detrás de una reserva previa. */
            return false;
        }else if((reservasMT[mm][i].dia==dd) && (reservasMT[mm][i].hc == hc)){
            /* Comprueba que no coincida con otra reserva. */
            return false;
        }
    }
    return true;
}

/*
 * Función para comprobar si un día es reservable (libre).
 */
bool TAD_Gestor_Reservas::esReservable(int dd,int mm,int aa, int hc, int dur){
    /*
     * Comprueba que coincide rango calendarios.
     */
    int ds;
    ds = grAuxMes.DiaSemana(aa,mm,dd);
    if((mm<1)||(mm>4)){
        /* Esté dentro de los meses */
        return false;
    }else if((ds==6 || ds==7)){
        /* Comprobar que no es fin de semana */
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),199);
        printf("\n El día seleccionado es un fin de semana: %d ", ds);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
        return false;
    }
    /* Establece ds de nuevo a 0 para posteriores usos. */
    ds=0;
    /* 
     * Comprobar que no se ha alcanzado el límite de reservas al mes. 
     */
    if(contadores[mm]==20){
        printf("\n No se ha podido almacenar, límite de reservas mensuales alcanzado: %d \n", contadores[mm]);
        return false;
    }
    /* Comprobar que la reserva no solapa con una HC de otra reserva. */
    da=noSolapa(dd,mm,hc,dur,contadores[mm]);
    if(!ds){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),199);
        printf("\n Una de las horas solicitadas está ocupada. \n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
        return false;
    }
    return true;
}

/* 
 * Función para crear una reserva y almacenarla.
 */

bool TAD_Gestor_Reservas::crearReserva(no,mbre_t nomb, const int dd, const int mm, const int aa, const int hc, const int dur){
    bool comprobacion;
    comprobacion = esReservable(dd,mm,aa,hc,dur);
    iniciarAuxReserva();
    if(!comprobacion){
        SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),199);
        printf("\n Imposible de reservar! \n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
        return false;
    }

    /*
     * Crear reserva 
     */
    strcpy(auxReserva.nombrecompleto, nomb);
    auxReserva.dia=dd;
    auxReserva.mes=mm;
    auxReserva.anyo=aa;
    auxReserva.hc=hc;
    auxReserva.duracion=dur;

    /*
     * Según el mes almacena la reserva en una de las 4 RMes.
     */

    guardarReserva(mm, auxReserva);
    /* Actualiza valor del contador. */
    cambiarValorDiaMes(dd,mm,1);
    return true;
}

/*
 *  Función para buscar una reserva concreta, devuelve el indice dónde está en el array o 999 si no se encuentra.
 */

int TAD_Gestor_Reservas::buscarReserva(int dd, int mm, int aa, int hc){
    int indice2;
    indice2=999;
    for(int i=0; i<=contadores[mm]; i++){
        if((reservasMT[mm][i].dia == dd) && (reservasMT[mm][i].mes == mm) && (reservasMT[mm][i].anyo==aa) && (reservasMT[mm][i].hc==hc)){
            indice2=i;
        }
    }
    return indice2;
}

/*
 * Función para comparar fechas de dos reservas.
 * TRUE si reserva1 es mayor que reserva2.
 */

bool TAD_Gestor_Reservas::compararReservas(const TipoReserva reserva1, const TipoReserva reserva2){
    if((reserva1.dia != reserva2.dia)){
        return (reserva1.dia > reserva2.dia);
    }else{
        return (reserva1.hc > reserva2.hc);
    }
}

/* 
 * Función para borrar una reserva, devuelve TRUE si ha tenido éxito.
 */

bool TAD_Gestor_Reservas::borrarReserva(nombre_t nomb, int dd, int mm, int aa, int hc){
    int indice;
    bool vacio;

    /* Limpiamos el auxiliar de reserva */
    iniciarAuxReserva();
    /* Busca la reserva y almacena el indice si se encuentra */
    indice=buscarReserva(dd,mm,aa,hc);

    if(indice == 999){
        /* Si devuelve el código de no encontrada, mensaje correspondiente. */
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),199);
        printf("\n Reserva no encontrada. \n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
        return false;
    }else if((strcmp(reservasMT[mm][indice].nombrecompleto, nomb)==0)){
        for(int i=indice; i<=(contadores[mm]);i++){
            reservasMT[mm][i] = reservasMT[mm][i+1];
        }
        /* Reestablecer el número de día correspondiente en el calendario. */
        vacio = cambiarValorDiaMes(dd,mm,0);
        /* Asegura que no quedarán datos de la reserva reescribiéndola. */
        reservasMT[mm][contadores[mm]]=auxReserva;
    }

    /*
     * Buscamos que no hay mas reservas para ese día comprobando todas las horas.
     */
    indice = horasOcupadas(dd,mm);
    if(indice == 0){
        SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),144);
        printf("\n Calendario actualizado, actualmente no hay reservas para la decha %d/%d/%d", dd,mm,aa);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
    }
    return true;
}

/*
 * Funcion para almacenar ordenadamente las reservas en un array que corresponda al mes correspondiente.
 */

void TAD_Gestor_Reservas::guardarReserva(int mm, TipoReserva reserv){
    int izquierda,centro,derecha;
    izquierda=0;
    reservasMT[mm][contadores[mm]]=reserv;
}

/*
 * Procedimiento para mostrar las RR representantes de las reservas o los espacios en blanco que correspondan.
 */

void TAD_Gestor_Reservas::dibujarR(int dd, int mm, int contador){
    int relativo;
    relativo=8;
    SetControlTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),105);

    for (int j=0;j<contador;j++){
        if(reservasMT[mm][j].dia==dd){
            for (int k=0; k<(reservasMT[mm][k].hc-relativo); k++){
                printf("  ");
            }
            for(int h=(reservasMT[mm][j].hc); h<(reservasMT[mm][j].diracion); h++){
                printf("RR");
                relativo=(reservasMT[mm][j].hc+reservasMT[mm][j].duracion);
            }
        }
    }

    /*
     * Rellena los espacios hasta llegar al final de la barra.
     */
    for(int l=relativo; l<21;l++){
        printf("  ");
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
    /* Cierra la barra gráfica de las horas.  */
    printf("I\n");
}

/*
 * función para mostrar las reservas de un día, se pasa por referencia el día que se desea ver y el array con las reservas del mes y su contador.
 */

void TAD_Gestor_Reservas::verReservasDia(int dd, int mm, int contador){
    dibujar(dd,mm,contadores[mm]);
    /*
     * Imprimir barra inferior de cierre de reservas - grafica
     */
    printf("\n I-------------I------------------------I\n");

    dor (int i=0; i<contador;i++){
        if((reservasMT[mm][i].dia==dd)){
            if((reservasMT[mm][i].hc<10) && (reservasMT[mm][i].hc+reservasMT[mm][i].hcduracion<10)){
                printf("\n 0%d a %d reservada por %s", reservasMT[mm][i].hc, (reservasMT[mm][i].hc+reservasMT[mm][i].duracion), reservasMT[mm][i].nombrecompleto);
            }else if((reservasMT[mm][i].hc<10) && ((reservasMT[mm][i].hc+reservasMT[mm][i].duracion)>10)){
                printf("\n 0%d a %d reservada por: %s", reservasMT[mm][i].hc , (reservasMT[mm][i].hc + reservasMT[mm][i].duracion), reservasMT[mm][i].nombrecompleto);
            }else{
                printf("\n %d a %d reservada por %s", reservasMT[mm][i].hc , (reservasMT[mm][i].hc + reservasMT[mm][i].duracion), reservasMT[mm][i].nombrecompleto);
            }
        }
    }
}

/*
 * Función que devuelve la ocupación de un día concreto. Devuelve el número de horas ocupadas.
 */

int TAD_Gestor_Reservas::horasOcupadas(int dd,int mm){
    int hOcupadas=0;

    /* Suma la duración de las reservas. */
    for (int i=0; i<contadores[mm]; i++){
        if(reservasMT[mm][k].dia==dd){
            hOcupadas = hOcupadas+ reservasMT[mm][i].duracion;
        }
        return hOcupadas;
    }
}

/*
 * Función para marcar el calendario con  TO,PA, devolver día.
 */

bool TAD_Gestor_Reservas::cambiarValorDiaMes(int dd, int mm, int valor){
    /* Registrar número de horas ocupadas */
    int HO;
    /* Establecer el código del día que corresponda en funciñon de las horas ocupadas.  */
    switch(valor){
        case 1:
            contadores[mm]++;
            HO=horasOcupadas(dd,mm);
            if(HO<13){
                /* Poner 'PA' si el contador no ha llegado a las H. Máx. */
                mesesTotales[mm].setDia(dd,70);
            }else{
                /* 'TO' Para otros casos */
                mesesTotales[mm].setDia(dd,80);
            }
            break;
        case 0:
            contadores[mm]--;
            HO=horasOcuapdas(dd,mm);
            if( HO >= 1){
                mesesTotales[mm].setDia(dd,70);
            }else{
                mesesTotales[mm].setDia(dd,dd);
            }
            break;
        default:
            printf("\n No se ha podido marcar en el calendario. \n");
            return false;
    }

    printf("\n Horas ocupadas para el día %d: %d", dd, horasOcupadas(dd,mm));
    return true;
}

/*
 * Procedimiento mostrar el calendario de un mes válido.
 */

void TAD_Gestor_Reservas::mostrarReservasMes(int mm,int aa){
    mesesTotales[mm].ImprimirDiasCalendario();
}

/*
 * Procedimiento intermediario para mostrar reservas de un día.
 */

void TAD_Gestor_Reservas::mostrarReservasDia(int dd, int mm, int aaaa){
    verReservasDia(dd,mm,contadores[mm]);
}