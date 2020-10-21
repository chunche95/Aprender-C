#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * \brief Solicita un numero al usuario y devuelve el resultado.
 * \param mensaje Es el mensaje a mostrar.
 * \return El número ingresado por el usuario.
 * 
 */

float getFloat(char mensaje[]){
    float auxiliar;
    printf("%s", mensaje);
    scanf("%f", &auxiliar);
    return auxiliar;
}

int getInt(char mensaje[]){
    int auxiliar; printf("%s", mensaje);
    printf("%s", mensaje);
    scanf("%d", &auxiliar);
    return auxiliar;
}

char getChar(char mensaje[]){
    char auxiliar;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%c", &auxiliar);
    return auxiliar;
}

/*
 * \brief Genera un numero aleatorio.
 * \param desde Número aleatorio mínimo.
 * \param hasta Número aleatorio máximo.
 * \param iniciar Indica si se trata del primer número solicitado 1 indica que sí.
 * \return retorna el número aleatorio generado.
 * 
 */
char getNumeroAleatorio(int desde,int hasta,int iniciar){
    if(iniciar){
        srand(time(NULL));
    }
    return desde + (rand() % (hasta +1 - desde));
}

/*
 * \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es numérico y 0 si no lo es.
 * 
 */
int esNumerico(char str[]){
    int i=0;
    while(str[i] != '\0'){
        if(str[i]<'0' || str[i]>'9'){
            return 0;
        }
        i++;
    }
    return 1;
}

/*
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a se analizada
 * \return 1 si contien solo ' ' y letras y 0 so no es así.
 * 
 */
int esSoloLetras(char str[]){
    int i=0;
    while(str[i] != '\0'){
        if((str[i] !=' ') && (str[i]<'a' || str[i]>'z') && (str[i]<'A' || str[i]>'Z')){
            return 0;
        }
        i++;
    }
    return 1;
}

/*
 * \brief Verifica si el valor recibido contiene solo letras y números.
 * \param str Array con la cadena a ser analizada.
 * \return 1 Si contiene solo espacio o letras y números, o 0 si no es así.
 * 
 */
int esAlfaNumerico(char str[]){
    int i=0;
    while(str[i] != '\0'){
        if((str[i] != ' ') && (str[i]<'a' || str[i]>'z') && (str[i]<'A' || str[i]>'Z')){
            return 0;
        }
        i++;
    }
    return 1;
}

/*
 * \brief Verifica si el valor recibido contiene solo números, + y -.
 * \param str Array con la cadena a ser analizada.
 * \return 1 Si contiene solo números, espacios y un guión.
 * 
 */
int esTelefono(char str[]){
    int i=0;
    int contadorGuiones=0;
    while(str[i] != '\0'){
        if((str[i] !=' ') && (str[i]!='-') && (str[i]<'0' || str[i]>'9')){
            return 0;
        }
        if(str[i]=='-'){
            contadorGuiones++;
        }
        i++;
    }
    if(contadorGuiones==1){
        return 1;
    }
    return 0;
}