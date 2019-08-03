/*
 * Ejercicio de reservas de una sala.
 */

#include <stdio.h>
#include "calendario.h"

listaNombre_t nombreMeses = { " ", /* Sin nombre para la posición cero. */
                                "ENERO","FEBRERO","MARZO","ABRIL","MAYO","JUNIO","JULIO","AGOSTO","SEPTIEMBRE",
                                "OCTUBRE","NOVIEMBRE","DICIEMBRE"
                            };

/*
 * Función para escribir sobre una posición del calendario.
 */                            

bool calendario::setDia(int dia, int valor){
    if(dia < totalDias){
        /*
         * Resto 1 para igualar la fecha de reservas con respecto al Z, que se ha adaptado aumentando en 1 su valor para que domingo = 7.
         */
        mesCalendario[(dia + zeta - 1)] = valor;
        return true;

    }else{
        return false;
    }
}

/*
 * Función que devuelve que día es 1 del mes y año dados.
 * Devuelve Lunes=1, Martes=2, Miércoles=3,...,Domingo=7.
 * Congruencia de Zeller.
 */

int TAD_Calendario::DiaSemana(int anyo, int mes,int dia){
    int a,m,y,dia1;
    a=(14-mes)/12;
    y=anyo-a;
    m=mes+(12*a)-2;
    dia1=(dia+y(y/4)-(y/100)+(y/400)+(31*m)/12)%7;
    /*
     * Ajusto el día si es domingo a 0, para que devuelva 7.
     */
    if (dia1==0){
        dia1=7;
    }
    return dia1;
}

/*
 * Función que devuelve el total de días que tiene un mes.
 */
int TAD_Calendario::TotalDiasMes(int m,int a){
    int x;
    switch(m){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            x=31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            x=30;
            break;
        case 2:
            if(a%4==0 && a%100 !=0 || a%400=0){
                x=29;
            }else{
                x=28;
            }
            break;
    }

    totalDias=x;
    return x;
}

/* 
 * Procedimiento de Impresión de la cabecera.
 */

voir TAD_Calendario::ImprimirCabecera(){
    printf("\n\n%-23.10s%d\n", nombresMeses[mes], anno);
    printf("=============================\n");
    printf("LU  MA  MI  JU  VI  |  SA  DO\n");
    printf("=============================\n");
}
/*
 *  Procedimiento de impresión de los dias del calendario.
 */

void TAD_Calendario::ImprimirDiasCalendario(){
    /*
     *  Transforma los 0 en caracter '.'
     */
    char punto= '.'; 
    int contador;
    contador=1;
    ImprimirCabecera();
    if(mesCalendario[36] == 0){
        nFilas=5;
    }else{
        nFilas=6;
    }
    for(int i =1; i<=nFilas; i++){
        for(int j=1; j<=nColumnas; j++){
            if(mesCalendario[contador]==80){
                printf("TO  ");
            }else if(mesCalendario[contador]==70){
                printf("PA  ");
            }else if(mesCalendario[contador]!=0){
                printf("%2d  ",mesCalendario[contador]);
            }else{
                printf("%2c  ", punto);
            }
            contador++;
            if(j%4==0){
                if(mesCalendario[contador]==80){
                    printf("TO | ");
                }else if(mesCalendario[contador]==70){
                    printf("PA | ");
                }else if(mesCalendario[contador]!=0){
                    printf("%2d | ", mesCalendario[contador]);
                }else{
                    printf("%2c | ", punto);
                }
                contador++;
            }
        }
        printf("\n");
    }
}

/*
 * Procedimiento el formato del mes dentro del array.
 */
void TAD_Calendario::RellenarMesCalendario(int m, int y){
    /* Total de días que tiene el mes. */
    int a,dias,z;
    if (m != 0 && y != 0){
        mes=m;
        anyo=y;
    }
    a=1;
    /* Día que comienzza el mes del calendario. */
    z=DiaSemana(anyo,mes,1);
    zeta=z;
    /*Guarda el numero de dias que tiene esa fecha. */
    dias=TotalDiasMes(mes, anyo);

    for(int i=0; i<=42;i++){
        if(i<z || a>dias){
            mesCalendario[i]=0;
        }else if(i>(dias+z)){
            mesCalendario[i]=0;
        }else{
            mesCalendario[i]=a;
            a++;
        }
    }
}