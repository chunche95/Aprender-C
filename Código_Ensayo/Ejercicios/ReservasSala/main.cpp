#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <locate.h>
#include <Windows.h>

#include "calendario.h"
#include "GestionReservaSala.h"

/*
 * definición de tipos, variables y constantes.
 */
char tecla;
bool flag;
const int maxNombre=21;
int auxDia, auxMes, auxAnyo, auxHora, auxDuracion;
typdef char nombre_t[maxNombre];

nombre_t auxNombre;
TAD_Gestor_Reservas gestor;

/*
 * Función de lectura de horas y duracion 
 * Devuelve TRUE = correcta; FALSE= incorrecta.
 */
bool LeerTiempo(int d){
    auxHora=0;
    auxDuracion=0;
    flag=false;

    if(dd==1){
        printf("    Hora de incio (De 8:00 a 22:00h).");
        scanf("%d", &auxHora);
        if(auxHora<8 || auxHora>20){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 199);
            printf("\n HORA INCORRECTA! Es de 8:00-22:00h \n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
            fflush(stdin);
            return false;
        }
    }else{
        printf("    Hora de inicio: ");
        scanf("%d", &auxHora);
        if(auxHora<8 || auxHora>20){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),199);
            printf("\n HORA INCORRECTA! Es de 8:00-22:00h \n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
            fflush(stdin);
            return false;
        }
    }
    if(dd==1){
        printf("    Duración (Horas completas): ");
        scanf("%d", &auxDuracion);
        if(auxDuracion < 1 || auxDuracion > 12 || (auxHora + auxDuracion) > 21){
            SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),199);
            printf("\n Duración incorrecta. Es entre 1-12 h en horario de 8:00 a 20:00 h \n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
            return false;
        }
    }
    fflush(stdin);
    return true;
}

/*
 *  Función de lectura del nombre.
 * Devuelve true=correcto; false=incorrecto.
 */

bool LeerNombre(){
    int lg=0;
    char caracter = ' ';
    char Fin='\n';
    flag=false;
    fflush(stdin); 

    for(int i=0; i<maxNombre; i++){
        auxNombre[i]= '\0';
    }

    /*
     * Lee la cadeba del nombre completo.
     */
    do{
        scanf("%c",&caracter);
        if((isalpha(caracter)) || (isspace(caracter)) || (caracter==char(164)) ||(caracter==char(165))){
            if (caracter !='\n'){
                auxNombre[lg]=caracter;
                lg++;
            }
        }else{
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),199);
            printf("\n Nombre introducido INVÁLIDO. \n");
            SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7);
            fflush(stdin);
            return false;
        }
        if (lg>=maxNombre){
            SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),199);
            printf("\n")
        }
    }
}