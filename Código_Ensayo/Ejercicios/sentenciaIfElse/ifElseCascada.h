#include <stdio.h>
int main(){
    int edad;
    float tarifa;
    int precioEntrada= 10;
    printf("Introduzca edad: ");
    scanf("%d", &edad);
    if(edad<6){
        tarifa = 0.0;
    }else if(edad<18){
        tarifa = 0.5;
    }else if(edad<65){
        tarifa = 0.1;
    }else{
        tarifa = 0.05;
    }

    printf("El precio de la entrada es: %2f", tarifa*precioEntrada);
    return 0;
}