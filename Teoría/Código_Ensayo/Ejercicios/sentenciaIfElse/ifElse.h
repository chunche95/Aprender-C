/*
 * Secuencia de acciones if else.
 */

#include <stdio.h>

int main(){
    int edad;
    printf("Hola, introduzca su edad: \n");
    scanf("%d", &edad);
    if (edad<18){
        printf("El acceso no está permitido para menores de 18. Tiene %d años. \n");
    }else{
        printf("Registro permitido. \n");
    }
    return 0;
}