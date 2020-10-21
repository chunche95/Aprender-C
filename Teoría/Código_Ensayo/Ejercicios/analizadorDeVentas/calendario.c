/*
 * Práctica de creación de calendario en C.
 */

#include <stdio.h>
#include <string.h>
#include "calendario.h"

int anyoMenor = 2000;

bool TipoCalendario::EsCorrecta (int dia, int mes, int anyo){
    bool correcto = true;
    if ((anyo < anyoMenor) || (dia <= 0) || (mes <= 0)){
        correcto = false;
    }else{
        switch (mes){
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                correcto = (dia <= 31);
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                correcto = (dia <= 30);
                break;
            case 2:
                if (EsBisiesto(anyo)){
                    correcto = (dia <= 29);
                }else{
                    correcto = (dia <= 28);
                }
                break;
            default:
                correcto=false;
        }
    }
    if (correcto){
        return true;
    }else{
        printf("\n Introduzca una fecha correcta. \n");
        return false;
    }
}

bool TipoCalendario::EsBisiesto (int anyo){
    if (anyo % 4 != 0 ){
        return false;
    } else if ((anyo % 100 == 0 ) && ( anyo % 400 != 0)){
        return false;
    } else {
        return true;
    };
}

int TipoCalendario::DiaDelMes (TipoNombreMes mes, int anyo){
    int dias;
    switch (mes){
        case enero:
        case marzo:
        case mayo:
        case julio:
        case agosto:
        case octubre:
        case diciembre:
            dias = 31;
            break;
        case abril:
        case junio:
        case septiembre:
        case noviembre:
            dias = 30;
            break;
        case febrero:
            if (EsBisiesto (anyo)){
                dias=29;
            }else{
                dias=28;
            }
            break;
    }
    return dias;
}

TipoDiaSemana TipoCalendario::DiaSemana(int mes, int anyo){
    int a,m,y;
    int aux;
    TipoDiaSemana dia;

    a=(14-mes)/12;
    y=anyo-a;
    m=mes+12*a-2;

    aux=(1+y+y/4-y/100+y/400+(31*m)/12)%7;
    if (aux == 0){
        aux=6;
    }else{
        aux--;
    }

    dia = TipoDiaSemana(aux);
    return dia;
}

TipoNumSemanasDelMes TipoCalendario::CalcularNumSemanas (int dias, int primero){
    TipoNumSemanaDelMes semanas;
    int cociente, modulo;

    cociente = (dias + primero) / 7;
    modulo = (dias + primero) % 7;

    if (modulo == 0){
       semanas.semanas = cociente; 
    }else{
        semanas.semanas = cociente + 1;
    }
    /* Días que faltan para completar la última semana. */
        semanas.resto = (semanas.semanas * 7 - (dias + primero));
        return semanas;
}

TipoNombresMes_str TipoCalendario::NombreDelMes (TipoNombreMes mes){
    TipoNombreMes_str cadena;
    switch (mes){
        case enero:
            strcpy (cadena.nombre, "Enero");
            break;
        case febrero:
            strcpy (cadena.nombre, "Febrero");
            break;
        case marzo:
            strcpy (cadena.nombre, "Marzo");
            break;
        case abril:
            strcpy (cadena.nombre, "Abril");
            break;
        case mayo:
            strcpy (cadena.nombre, "Mayo");
            break;
        case junio:
            strcpy (cadena.nombre, "Junio");
            break;
        case julio:
            strcpy (cadena.nombre, "Julio");
            break;
        case agosto:
            strcpy (cadena.nombre, "Agosto");
            break;
        case septiembre:
            strcpy (cadena.nombre, "Septiembre");
            break;
        case octubre:
            strcpy (cadena.nombre, "Octubre");
            break;
        case noviembre:
            strcpy (cadena.nombre, "Noviembre");
            break;
        case diciembre:
            strcpy (cadena.nombre, "Diciembre");
            break;
    }
    return cadena;
}

void TipoCalendario::ImprimirLineaSimbolos (int longitud, TipoSimbolo_str simbolo){
    TipoFila_str fila = "";
    for (int i=1; i <= longitud; i++){
        strcat(fila, simbolo);
    }
    printf("%s", fila);
}

void TipoCalendario::ImprimirSeparador (int &columna, int &fila, int semanas){
    if (columna == 7){
        if (fila < semanas){
            printf("\n");
        };
        columna = 1;
        fila++;
    }else if  (columna == 5){
        printf(" | ");
        columna++;
    }else{
        printf(" ");
        columna++;
    };
}

void TipoCalendario::ImprimirCalendario (int unidad, int mes, int anyo, TipoVectorVenta vectorVenta){
    TipoNombreMes nombreTipoMes;
    TipoDiaSemana primerDia;
    TipoNombreMes_str nombreMes;
    TipoNumSemanaDelMes numSemanas;

    int dias;
    int numEspacios;
    int fila, columna;

    bool hayVenta = false;
    int ind = 0;
    {
        dias = 0;
        numEspacios = 0;
        columna = 1;
        fila = 1;
    }

    nombreTipoMes = TipoNombreMes(mes-1);
    primerDia = DiaSemana(mes,anyo);
    nombreMes = NombreDelMes(nombreTipoMes);
    dias = DiasDelMes(nombreTipoMes, anyo);
    numEspacios = longitudFila - strlen(nombreMes.nombre) - 4;
    numSemanas = CalcularNumSemanas(dias, int(primerDia));
    {
        {
            printf(" \n ");
            printf("%s", nombreMes.nombre);
            ImprimirLinesasSimbolos(numEspacios, " ");
            printf("%4d", anyo);
            printf("\n");
            printf(" LU MA MI JU VI | SA DO \n");
            ImprimirLineaSimbolos(longitudFila, '=');
            printf("\n");
        }
        while(fila <=  numSemanas.semanas){
            if (fila == 1){
                for (i=1; i <= primerDia; i++ ){
                    printf(".");
                    ImprimirSeparador (columna, fila, numSemanas.semanas);
                }
            }
            for (int i= 1; i <= dias; i++){
                for (int j=0; j < maxVenta; j++){
                    if((vectorVenta[j].unidad == unidad) && (vectorVenta[j].fecha.dia == i) && (vectorVenta[j].fecha.anyo == anyo)){
                        ind = j;
                        hayVenta = true;
                    }
                }

                if (hayVenta){
                    printf(" X ");
                }else{
                    printf("%2d", i);
                }

                hayVenta = false;
                ImprimirSeparador (columna,fila,numSemanas.semanas);
            }
            if (fila == numSemanas.semanas){
                for (int i=1; i <= numSemanas.resto; i++){
                    printf(" . ");
                    ImprimirSeparador(columna, fila, numSemanas.semanas);
                }
            }
        }
    }
}