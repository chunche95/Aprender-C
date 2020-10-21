/*
 * Introducir al alumno en el uso de los procedimientos  scanf() & printf().
 */
#include <stdio.h>

int main(){
    ind edad=0;
    printf("\n Hola! Qué edad tienes? \n");
    scanf("%d", &edad);
    printf("Muy bien! Tienes %d años!", edad);
    return 0;
}