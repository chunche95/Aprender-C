#include <stdio.h>
#include <stdlib.h>
#include "gestion.h"

int main () {
  char opcion = ' ';
  TipoGestion gestion;
  TipoVectorVenta vectorVenta;
  gestion.InicializarVectorVenta (vectorVenta);

  do {
    system ("cls");
    printf ("ANALIZADOR DE VENTAS\n\n");
    printf ("1. Introducir venta\n");
    printf ("2. Eliminar venta\n");
    printf ("3. Listar ventas de un mes\n");
    printf ("4. Listar productos por orden de venta\n");
    printf ("5. Salir\n");
    printf ("opcion (1, 2, 3, 4, 5)? ");
    scanf ("%c", &opcion);

    switch (opcion) {
      case '1':
        gestion.IntroducirVenta (vectorVenta);
        break;
      case '2':
        gestion.EliminarVenta (vectorVenta);
        break;
      case '3':
        gestion.ListarVenta (vectorVenta);
        break;
        case '4':
       /*******************/
        break;
      case '5':
      return 0;
        break;
    }
  } while ((opcion !=  '1') || (opcion != '2') || (opcion != '3') || (opcion != '4') || (opcion != '5'));
}