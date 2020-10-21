#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funciones.h"
#define MAXINPUT 100

int main(){
    char input[MAXINPUT];
    int length;
    printf("Escriba un texto: ");
    scanf("%s", input);
    length=strlen(input);
    if(length>0){
        if(esNumerico(input)){
            printf("Si es un número. \n");
        }
        if(esTelefono(input)){
            printf("Si es un teléfono. \n");
        }
        if(esSoloLetras(input)){
            printf("Si son solo letras. \n");
        }
        if(esAlfaNumerico(input)){
            printf("Contiene números y letras. \n");
        }
    }
}