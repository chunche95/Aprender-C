#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "gestion.h"
#include "calendario.h"

int ind = 0;
TipoCalendario calendario;

void TipoGestion::ListarVenta (TipoVectorVenta vectorVenta) {
  int unidad, mes, anno, nombre;
  system ("cls");
  try {
  printf ("Unidad? ");
  fflush (stdin);
  scanf ("%d", &unidad);
  printf ("ID producto? ");
  fflush (stdin);
  scanf ("%d", &nombre);
  printf ("Mes (1..12)? ");
  fflush (stdin);
  scanf ("%2d", &mes);
  printf ("Anno (1600..3000)? ");
  fflush (stdin);
  scanf ("%4d", &anno);
  if ((mes < 1) || (mes > 12)
      || (anno < 1600) || (anno > 3000)) {
        throw 1;
      }
  }
  catch (int error) {
    printf ("-ERROR!!!-");
    if (error == 1) {
      printf ("Introduzca valores correctos\n");
      system ("pause");
    }
  }
  calendario.ImprimirCalendario (unidad, mes, anno, vectorVenta);
  printf ("\n\n");
  OrdenarVectorVenta (vectorVenta);
  for (int i = 0; i <= maxVenta; i++) {
    if ((vectorVenta[i].fecha.mes == mes)
        && (vectorVenta[i].fecha.anno == anno)
        && (vectorVenta[i].unidad == unidad)) {
      printf ("%d: %s\n", vectorVenta[i].fecha.dia, vectorVenta[i].unidad);
    }
  }
  system ("pause");
}

void TipoGestion::IntroducirVenta (TipoVectorVenta vectorVenta) {
  TipoVenta Venta;
  InicializarVenta (Venta);
  if (VentaCompletas ()) {
    system ("cls");
    try {
      printf ("Unidades? ");
      fflush (stdin);
      scanf ("%d", &Venta.unidad);
      printf ("Mes (1..12)? ");
      fflush (stdin);
      scanf ("%2d", &Venta.fecha.mes);
      printf ("Anno (1600..3000)? ");
      fflush (stdin);
      scanf ("%4d", &Venta.fecha.anno);
      printf ("Dia (1..31)? ");
      fflush (stdin);
      scanf ("%2d", &Venta.fecha.dia);
      if ((Venta.fecha.dia < 1) || (Venta.fecha.dia > 31)
          || (Venta.fecha.mes < 1) || (Venta.fecha.mes > 12)
          || (Venta.fecha.anno < 1600) || (Venta.fecha.anno > 3000)) {
        throw 0;
      }
      printf ("Identificador del producto? ");
      fflush (stdin);
      scanf ("%[^\n]s", &Venta.nombre);

    }
    catch (int error) {
      printf ("-ERROR!!!-");
      if (error == 0) {
        printf ("Introduzca valores correctos\n");
        system ("pause");
      }
    }
  }
  vectorVenta[ind] = Venta;
  ind++;
}


void TipoGestion::EliminarVenta (TipoVectorVenta vectorVenta) {
  int unidad, mes, anno, dia, nombre;
  printf ("Unidad? ");
  fflush (stdin);
  scanf ("%d", &unidad);
  printf ("ID producto? ");
  fflush (stdin);
  scanf ("%d", &nombre);
  printf ("Mes (1..12)? ");
  fflush (stdin);
  scanf ("%2d", &mes);
  printf ("Anno (1600..3000)? ");
  fflush (stdin);
  scanf ("%4d", &anno);
  printf ("Dia (1..31)? ");
  fflush (stdin);
  scanf ("%2d", &dia);


  system ("pause");
}


bool TipoGestion::VentaCompletas () {
  if (ind < maxVenta) {
    return true;
  } else {
    return false;
  }
}


void TipoGestion::OrdenarVectorVenta (TipoVectorVenta vectorVenta) {
  TipoVenta VentaAux;
  for (int i = 0; i <= maxVenta; i++) {
    if (vectorVenta[i].fecha.dia > vectorVenta[i + 1].fecha.dia) {
      VentaAux = vectorVenta[i];
      vectorVenta[i] = vectorVenta[i + 1];
      vectorVenta[i +1] = VentaAux;
    }
  }
}


void TipoGestion::InicializarVenta (TipoVenta &Venta) {
  strcpy(Venta.nombre, "" );
  Venta.fecha.dia = 0;
  Venta.fecha.mes = 0;
  Venta.fecha.anno = 0;
  Venta.unidad = unidad0;
}


void TipoGestion::InicializarVectorVenta(TipoVectorVenta vectorVenta) {
  TipoVenta Venta;
  InicializarVenta (Venta);
  for (int i = 0; i < maxVenta; i++) {
    vectorVenta[i] = Venta;
  }
}