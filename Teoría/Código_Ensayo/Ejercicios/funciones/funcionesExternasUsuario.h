#include <stdio.h>
#include "funcionesAuxiliares/funcionesAuxiliares.h"
int main(){
    int numero=20;
    printf("El valor de número es: %d al inicio", numero);
    numero= DuplicarValor(20);
    printf("El valor de número es %d después de llamar a función DuplicarValor. \n", numero);
    printf("Esto es válido?"Qué valor sale por pantalla? %d, DuplicarValor(20));
    return 0;
}