#include <stdio.h>
#include <string.h>
#include "calendario.h"
int annoMenor = 2000;


bool TipoCalendario::EsCorrecta (int dia, int mes, int anno) {
  bool correcto = true;
  if ((anno < annoMenor) || (dia <= 0) || (mes <= 0)) {
    correcto = false;
  } else {
    switch (mes) {
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
      if (EsBisiesto( anno )) {
        correcto = (dia <= 29);
      } else {
        correcto = (dia <= 28);
      }
      break;
    default:
      correcto = false;
    }
  }
  if (correcto) {
    return true;
  } else {
    printf( "\nIntroduzca una fecha correcta\n" );
    return false;
  }
}

bool TipoCalendario::EsBisiesto (int anno) {
  if (anno % 4 != 0) {
    return false;
  } else if ((anno % 100 == 0) && (anno % 400 != 0)) {
    return false;
  } else {
    return true;
  };
}

int TipoCalendario::DiasDelMes (TipoNombreMes mes, int anno) {
  int dias;
  switch (mes) {
  case ENERO:
  case MARZO:
  case MAYO:
  case JULIO:
  case AGOSTO:
  case OCTUBRE:
  case DICIEMBRE:
    dias = 31;
    break;
  case ABRIL:
  case JUNIO:
  case SEPTIEMBRE:
  case NOVIEMBRE:
    dias = 30;
    break;
  case FEBRERO:
    if (EsBisiesto (anno)) {
      dias = 29;
    } else {
      dias = 28;
    }
    break;
  }
  return dias;
}


TipoDiaSemana TipoCalendario::DiaSemana (int mes, int anno) {
  int a, y ,m;
  int aux;
  TipoDiaSemana dia;

  a = (14 - mes) / 12;
  y = anno - a;
  m = mes + 12 * a - 2;

  aux = (1 + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;

  {
    if (aux == 0) {
      aux = 6;
    } else {
      aux--;
    }
  }
  dia = TipoDiaSemana (aux);
  return dia;
}

TipoNumSemanasDelMes TipoCalendario::CalcularNumSemanas (int dias, int primero) {
  TipoNumSemanasDelMes semanas;
  int cociente, modulo;

  cociente = (dias + primero) / 7;
  modulo = (dias + primero) % 7;

  if (modulo == 0) {
    semanas.semanas = cociente;
  } else {
    semanas.semanas = cociente + 1;
  }
  semanas.resto = (semanas.semanas * 7 - (dias + primero) );    /* dias que faltan para completar la última semana */
  return semanas;
}

TipoNombreMes_str TipoCalendario::NombreDelMes( TipoNombreMes mes ) {
  TipoNombreMes_str cadena;
  switch (mes) {
  case ENERO:
    strcpy (cadena.nombre, "ENERO");
    break;
  case FEBRERO:
    strcpy (cadena.nombre, "FEBRERO");
    break;
  case MARZO:
    strcpy (cadena.nombre, "MARZO");
    break;
  case ABRIL:
    strcpy (cadena.nombre, "ABRIL");
    break;
  case MAYO:
    strcpy (cadena.nombre, "MAYO");
    break;
  case JUNIO:
    strcpy (cadena.nombre, "JUNIO");
    break;
  case JULIO:
    strcpy (cadena.nombre, "JULIO");
    break;
  case AGOSTO:
    strcpy (cadena.nombre, "AGOSTO");
    break;
  case SEPTIEMBRE:
    strcpy (cadena.nombre, "SEPTIEMBRE");
    break;
  case OCTUBRE:
    strcpy (cadena.nombre, "OCTUBRE");
    break;
  case NOVIEMBRE:
    strcpy (cadena.nombre, "NOVIEMBRE");
    break;
  case DICIEMBRE:
    strcpy (cadena.nombre, "DICIEMBRE");
    break;
  }
  return cadena;
}

void TipoCalendario::ImprimirLineaSimbolos (int longitud, TipoSimbolo_str simbolo) {
  TipoFila_str fila = "";
  for (int i = 1; i <= longitud; i++) {
    strcat (fila,simbolo);
  }
  printf( "%s", fila );
}

void TipoCalendario::ImprimirSeparador (int &columna, int &fila, int semanas) {
  if ( columna == 7 ) {
    if ( fila < semanas) {       /* La última fila no lleva salto de línea */
      printf( "\n" );
    };
    columna = 1;
    fila++;
  } else if ( columna == 5 ) {
    printf( " | " );
    columna++;
  } else {
    printf( "  " );
    columna++;
  };
}


void TipoCalendario::ImprimirCalendario (int unidad, int mes, int anno, TipoVectorVenta vectorVenta) {

  TipoNombreMes nombreTipoMes;
  TipoDiaSemana primerDia;
  TipoNombreMes_str nombreMes;
  TipoNumSemanasDelMes numSemanas;
  int dias;
  int numEspacios;
  int fila,columna;
  bool hayVenta = false;
  int ind = 0;
  {
    dias = 0;
    numEspacios = 0;
    columna = 1;
    fila = 1;
  }
  nombreTipoMes = TipoNombreMes(mes-1);
  primerDia = DiaSemana( mes,anno );
  nombreMes = NombreDelMes( nombreTipoMes );
  dias = DiasDelMes( nombreTipoMes,anno);
  numEspacios = longitudFila - strlen( nombreMes.nombre ) - 4;
  numSemanas = CalcularNumSemanas( dias, int(primerDia) );
  {
     {
      printf ("\n");
      printf ("%s", nombreMes.nombre);
      ImprimirLineaSimbolos (numEspacios, " ");
      printf ("%4d", anno );
      printf ("\n");
      ImprimirLineaSimbolos (longitudFila, "=");
      printf ("\n");
      printf ("LU  MA  MI  JU  VI | SA  DO\n");
      ImprimirLineaSimbolos (longitudFila, "=");
      printf ("\n");
    }
    while (fila <= numSemanas.semanas) {
      if ( fila == 1 ) {
        for (int i=1; i <= primerDia; i++) {
          printf( " ." );
          ImprimirSeparador (columna,fila,numSemanas.semanas);
        }
      }
      for ( int i = 1; i <= dias; i++ ) {
        for (int j = 0; j < maxVenta; j++) {
          if ((vectorVenta[j].unidad == unidad)
              && (vectorVenta[j].fecha.dia == i)
              && (vectorVenta[j].fecha.anno == anno)) {
            ind = j;
            hayVenta = true;
          }
        }
        if (hayVenta) {
          printf( " X" );
        } else {
          printf( "%2d", i );
        }
        hayVenta = false;
        ImprimirSeparador (columna,fila,numSemanas.semanas);
      }
      if (fila == numSemanas.semanas) {
        for ( int i = 1; i <= numSemanas.resto; i++ ) {
          printf (" .");
          ImprimirSeparador (columna, fila, numSemanas.semanas );
        }
      }
    }
  }
}