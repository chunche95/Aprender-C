#include <stdio.h>
#include <stdlib.h> /* Para usar cls -> Limpiar pantalla */
#include <conio.h> /* Uso de getch() */

#include "TAD_MenuPrincipal.h"

int main(){
    T_MenuPrincipal Menu;
    /* 
     * Llamamos al procedimiento que inicializa los valores del plan de entrenamiento. 
     * De esta forma sabremos cuando hemos introducido valores y cuando no.
     */
    Menu.InicializarValores();
    do{
    /*
     * Nos muestra el menú principal y limita la opcion introducida a valores entre 1 y 5. 
     */
    Menu.ElegirOpcion();
    /*
     * Contiene un switch que llama a otras funciones segun la opcion seleccionada.
     */
    Menu.RealizarAccion();
    /*
     * Damos la opción al usuario de decir si quiere realizar otra acción.
     */
    Menu.Repetir();
    
    }while((Menu.respuesta=='S') && (Menu.opcion!=5));

    system("cls");
    printf("Ha elegido salir del programa. \n");
    /*
     * Esta función permite al ejecutable .exe el tiempo suficiente como para ver el mensaje de despedida.
     */
    getch()
}