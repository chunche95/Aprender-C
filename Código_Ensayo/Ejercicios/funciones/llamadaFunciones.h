/*
 * Uso de funciones axiliares para realizar tareas. La llamada a dichas funciones se hace desde la función principal main.
 */

#include <stdio.h>

int DuplicarValor(int num){
    return num;
}

int main(){
    int numero=20;
    printf("El valor de número es %d al inicio. \n", numero);
    numero=DuplicarValor(20);
    printf("El valor de número es %d después de llamar a funcion DuplicarValor", numero);
    return 0;
}