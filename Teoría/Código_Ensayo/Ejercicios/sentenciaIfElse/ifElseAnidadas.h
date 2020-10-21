/*
 * Uso de secuencias de acciones if else anidadas.
 */

#include <stdio.h>

int main(){
    int edad;
    float tarifa;
    int precioEntrada = 10;
    printf("Introduzca edad: \n");
    scanf("%d", &edad);
    if (edad<6){
        tarifa=0.0;
    }else{
        if(edad<18){
            tarifa=0.5;
        }else{
            if(edad<65){
                tarifa=0.3;
            }else{
                tarifa=0.05;
            }
        }
    }
    printf("Según su edad, el precio de su entrada es de %2f", tarifa*precioEntrada);
    return 0;
}