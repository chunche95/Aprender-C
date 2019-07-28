#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getInt(char mensaje[]){
    int numero;
    printf("%s",mensaje);
    printf("%d", &numero);
    return numero;
}
float getFloat(char mensaje[]){
    float numero;
    printf("%s", mensaje);
    printf("%f", &numero);
    return numero;
}
char getChar(char mensaje[]){
    char letra;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%c", &letra);
    return letra;
}

/*
 * \brief genera un numero aleatorio.
 * \param desde - número aleatorio mínimo.
 * \param hasta - número aleatorio máximo.
 * \param iniciar - analiza si es el primer número solicitado.
 * \return - retorna un número aleatorio.
 */

char getAleatorio (int desde, int hasta, int iniciar){
    if(iniciar){
        srand(time(NULL));
        return desde + (rand() % (hasta + 1 - desde ));
    }
}