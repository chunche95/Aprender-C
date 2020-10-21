#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main(){
    int numeroIngresado, numeroOculto, jugar;
    char letra = 's';

    while(letra=='s'){
        /*
         * Aleatorio a la función "aleatorio" dándole los parámetros y lo gu("ar("da el número en una variable.
         */
        numeroOculto=getAleatorio(1,100,1);
        jugar=1;
        while(jugar==1){
            numeroIngresado = getInt("Ingrese un número: ");
            if (numeroIngresado < 0 ){
                jugar=0;
            }
            else if(numeroIngresado == numeroOculto){
                printf("\n Felicidades ganaste! \n");
                jugar=0;
            }
            else if(numeroIngresado < numeroOculto){
                printf("\n El número es más alto. \n");
            }
            else if(numeroIngresado > numeroOculto){
                printf("\n Te pasaste, inténtalo de nuevo. \n");
            }
        }
        letra = getChar("\n ¿Desea continuar? \n");
    }
    return 0;
}