#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <locate.h>
#include <Windows.h>

#include "calendario.h"
#include "GestionReservaSala.h"

/*
 * definición de tipos, variables y constantes.
 */
char tecla;
bool flag;
const int maxNombre=21;
int auxDia, auxMes, auxAnyo, auxHora, auxDuracion;
typdef char nombre_t[maxNombre];

nombre_t auxNombre;
TAD_Gestor_Reservas gestor;

/*
 * Función de lectura de horas y duracion 
 * Devuelve TRUE = correcta; FALSE= incorrecta.
 */
bool LeerTiempo(int d){
    auxHora=0;
    auxDuracion=0;
    flag=false;

    if(dd==1){
        printf("    Hora de incio (De 8:00 a 22:00h).");
        scanf("%d", &auxHora);
        if(auxHora<8 || auxHora>20){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 199);
            printf("\n HORA INCORRECTA! Es de 8:00-22:00h \n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
            fflush(stdin);
            return false;
        }
    }else{
        printf("    Hora de inicio: ");
        scanf("%d", &auxHora);
        if(auxHora<8 || auxHora>20){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),199);
            printf("\n HORA INCORRECTA! Es de 8:00-22:00h \n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
            fflush(stdin);
            return false;
        }
    }
    if(dd==1){
        printf("    Duración (Horas completas): ");
        scanf("%d", &auxDuracion);
        if(auxDuracion < 1 || auxDuracion > 12 || (auxHora + auxDuracion) > 21){
            SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),199);
            printf("\n Duración incorrecta. Es entre 1-12 h en horario de 8:00 a 20:00 h \n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
            return false;
        }
    }
    fflush(stdin);
    return true;
}

/*
 *  Función de lectura del nombre.
 * Devuelve true=correcto; false=incorrecto.
 */

bool LeerNombre(){
    int lg=0;
    char caracter = ' ';
    char Fin='\n';
    flag=false;
    fflush(stdin); 

    for(int i=0; i<maxNombre; i++){
        auxNombre[i]= '\0';
    }

    /*
     * Lee la cadeba del nombre completo.
     */
    do{
        scanf("%c",&caracter);
        if((isalpha(caracter)) || (isspace(caracter)) || (caracter==char(164)) ||(caracter==char(165))){
            if (caracter !='\n'){
                auxNombre[lg]=caracter;
                lg++;
            }
        }else{
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),199);
            printf("\n Nombre introducido INVÁLIDO. \n");
            SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7);
            fflush(stdin);
            return false;
        }
        if (lg>=maxNombre){
            SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),199);
            printf("\n Nombre demasiado largo. \n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
            fflush(stdin);
            return flase;
        }
    }while((caracter != Fin));

    fflush(stdin);
    return true;
}

/*
 * Función de lectura de fechas con switch.
 * 1 = solicita día 
 * 0 = no solicita día
 * Devuelve TRUE=Correcta, FALSE=Incorrecta.
 */
bool LeerFecha(int dd){
    flag=false;
    auxDia=0;
    auxMes=0;
    auxAnyo=0;
    fflush(stdin);

    if(dd==1){
        /* 
         * Pregunta por el día si ha llegado activado, esto permite que se puedea reciclar para otras funciones 
         * que requeira o no el dato día.
         */
        printf(" Día: ");
        scanf("%d", &auxDia);
        if(auxDia<1 || auxDia>31){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),199);
            printf("\n Dñia incorrecto (1-31) \n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
            /* 
             * Limpio el buffer para que no sea captado por otro scanf o servicio que pueda interpretarlo de manera erronea.
             */
            fflush(stdin);
            return false;
        }
    }
    printf(" Mes: ");
    scanf("%d",auxMes);
    if(auxMes<1 || auxMes12){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),199);
        printf("\n Mes incorrecto. (1-12) \n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
        fflush(stdin);
        return false;
    }
    printf(" Año: ");
    scanf("%d", &auxAnyo);
    if(auxAnyo<2019 || auxAnyo> 2020){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),199);
        printf("\n Año incorrecto. (2019-2020 \n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
        fflush(stdin);
        return false;
    }
    return true;
}

/*
 * Funcion para crear una nueva reserva.
 */
bool NuevaReserva(){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),32);
    printf("\n Nueva reserva.");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
    printf("\n  ¿Nombre de la persona que reserva? (Máx: 20 carácteres) ");
    flag=LeerNombre();
    if(flag == false){
        return false;
    }
    flag=LeerFecha(1);
    if(flag == false){
        return false;
    }
    flag = LeerTiempo(0);
    if(flag ==  false){
        return false;
    }
    flag = gestor.crearReserva(auxNombre, auxDia, auxMes, auxAnyo, auxHora, auxDuracion);
    return flag;
}

/*
 * Función para anular una reserva.
 */

bool BorrarReserva(){
    char tecla;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),32);
    printf("\n ¿Anular reserva? ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
    printf("\n ¿Persona qué hizo la reserva? ");
    flag=LeerNombre();
    if(flag == false){
        return false;
    }
    flag=LeerFecha(1);
    if(flag == false){
        return false;
    }
    flag=LeerTiempo(0);
    if(flag == false){
        return false;
    }

    printf("\n ¿Seguro de borrar la reserva? (S/N) ");
    tecla=' ';
    while(tecla != 'N'){
        scanf("%c",&tecla);
        tecla=toupper(tecla);
        if(tecla == 'S'){
            flag = gestor.borrarReserva(auxNombre, auxDia, auxMes, auxAnyo, auxHora);
            if(flag){
                printf("\n ================= ");
                printf("\n Reserva eliminada.");
                printf("\n ================= ");
                return true;
            }else{
                printf("\n No hay coincidencias en la búsqueda. \n ");
                return false;
            }
        }
    }
    return false;
}

/*
 * Función para mostrar las reservas del día.
 */

bool MostrarReservasDia(){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),32);
    printf("\n Reservas del día. \n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
    flag = LeerFecha(1);

    /* Mostrar las reservas para la fecha introducida con el formato. */
    if(flag){
        pirntf("\n  Reservas del día: %d/%d/%d \n\n", auxDia,auxMes,auxAnyo);
        printf("\nI-------------I----------------------------I");
        printf("\nI Horas:      I 08  10  12  14  16  18  20 I");
        printf("\nI-------------I----------------------------I");
        printf("\n Reservadas:  I");
        gestor.mostrarReservasDia(auxDia,auxMes,auxAnyo);
        return true;
    }
    return false;
}

/*
 * Función para crear mostrar las reservas del mes.
 */
bool MostrarReservasMes(){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),32);
    printf("\n Reservas del mes: ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
    flag=LeerFecha(0);
    if (flag){    
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),32);
        printf("\n Reservas del mes: ");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
        gestor.mostrarReservasMes(auxMes, auxAnyo);
        return true;
    }
    return false;
}

/*
 * Procedimiento obtener fecha del sistema.
 */
void ObtenerFechaSistema(int &auxMes, int &auxAnyo){
    SYSTEMTIME str_t;
    GetSystemTime(&str_t);
    auxAnyo=str_t.wYear;
    auxMes=str_t.wMonth;
}

/*
 * Programa principal.
 */
int main(){
    /* Menu principal. */
    /* Config. carácteres espalo en Windows 7,8,10, etc. */
    setlocate(LC_ALL, "Spanish");
    /* Config. Windows XP */
    SetConsoleOutputCP(1251);
    flag=false;

ObtenerFechaSistema( auxMes, auxAnno);
  gestor.iniciarCalendarios(auxMes, auxAnno);

  /*-- crea 4 reservas para comprobaciones --*/

  /*Reservas de prueba...     Nombre  día mes año HC Duración */
  flag = gestor.crearReserva("test a", 5, 1, 2019, 8, 1);  /*Relleno el día 5 hasta 11 reservas para comprobar TO/PA */
  flag = gestor.crearReserva("test b", 5, 1, 2019, 9, 1);
  flag = gestor.crearReserva("test c", 5, 1, 2019, 10, 1);
  flag = gestor.crearReserva("test d", 5, 1, 2019, 11, 1);
  flag = gestor.crearReserva("test e", 5, 1, 2019, 12, 1);
  flag = gestor.crearReserva("test f", 5, 1, 2019, 13, 1);
  flag = gestor.crearReserva("test g", 5, 1, 2019, 14, 1);
  flag = gestor.crearReserva("test h", 5, 1, 2019, 15, 1);
  flag = gestor.crearReserva("test j", 5, 1, 2019, 16, 1);
  flag = gestor.crearReserva("test k", 5, 1, 2019, 17, 1);
  flag = gestor.crearReserva("test l", 5, 1, 2019, 18, 1);
  flag = gestor.crearReserva("test m", 5, 1, 2019, 19, 1);
  flag = gestor.crearReserva("test n", 5, 1, 2019, 20, 1);
  flag = gestor.crearReserva("test v", 3, 1, 2019, 19, 1);
  flag = gestor.crearReserva("test x", 3, 1, 2019, 15, 1);
  flag = gestor.crearReserva("test z", 3, 1, 2019, 17, 1);
  flag = gestor.crearReserva("test s", 2, 1, 2019, 8, 1);
  flag = gestor.crearReserva("test w", 2, 1, 2019, 19, 1);
  flag = gestor.crearReserva("test q", 10,2, 2019, 8, 1);
  flag = gestor.crearReserva("test y", 2, 1, 2019, 17, 1);  /*Reserva número 20 */


flag=false;

do{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),32);
    printf("\n H¡gestión de reservas de sala. \n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
    printf(" (N)UEVA RESERVA. \n");
    printf(" (A)NULAR RESERVA.\n");
    printf(" RESERVAS DEL (D)ÍA \n");
    printf(" RESERVAS DEL (M)ES \n");
    printf(" (S)ALIR \n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),32);
    printf("Seleccione una opción válida (N|A|D|M|S): ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7); 

    tecla= ' ';
    do{
        scanf("%c",&tecla);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
        /* Acepta minúsculas. */
        tecla=toupper(tecla);
        switch(tecla){
            case 'N':
                flag=NuevaReserva();
                break;
            case 'A':
                flag=BorrarReserva();
                break;
            case 'D':
                flag=MostrarReservasDia();
                break;
            case 'M':
                flag=MostrarReservasMes();
                break;
        }
        if(!flag){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),199);
            printf(" La opción seleccionada es incorrecta. \n ");
            SetConsoletextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
        }
    }
    /* Bucle hasta que se oprima la tecla válida */
    while((tecla !='N')&&(tecla!='A')&&(tecla!='D')&&(tecla!='M')&&(tecla!='S'));
}while (tecla != 'S');
{
    /* code */
}


}
