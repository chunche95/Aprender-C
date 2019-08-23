/*
 * Pedir al usuario una cadena de caracteres, almacenarla en un vector/arreglo y copia todo su contenido
 * hacia otro vector de caracteres.
 * 
 */ 

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h>

using namespace std;

int main(){
    char frase[20], copia[20];

    cout<<"Escriba la frase a copiar: "; 
    cin.getline(frase,20,'\n');

    strcpy(copia,frase);

    cout<<"Frase copiada: "<<copia<<endl;

    getch();
    return 0;
}