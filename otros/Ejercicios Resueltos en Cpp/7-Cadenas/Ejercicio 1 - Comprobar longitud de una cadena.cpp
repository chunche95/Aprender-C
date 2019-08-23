/*
 * Hacer un programa que pida al usuario una cadena de caracteres, luego verificar la longitud 
 * de la cadena, y si ésta supera los 10 caracteres, mostrarla en pantalla, en caso contrario no
 * hacerlo. 
 */

#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string.h>

using namespace std;

int main(){
    char frase[50];

    cout<<"Escriba una frase: ";
    /* Guardamos la cadena de caracteres*/
    cin.getline(frase,50,'\n');

    if(strlen(frase>10){
        cout<<frase;
    }else{
        cout<<"La cadena escrita no tiene mas de 10 caracteres"
    }

    getch();
    return 0;
}