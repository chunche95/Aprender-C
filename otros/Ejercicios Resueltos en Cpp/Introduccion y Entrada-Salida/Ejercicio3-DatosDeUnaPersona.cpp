/*
 *
 * Realice un programa que lea de la entrada estándar los siguientes datos de una persona:
 *  - Edad: dato de tipo entero.
 *  - Sexo: dato de tipo caracter.
 *  - Altura(m): dato de tipo real.
 * 
 * Tras leer los datos, el programa debe mostrarlos en la salida estándar.
 * 
 */

#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
    int edad;
    char sexo[6];
    float altura;

    cout<<"Introduzca su edad: ";
    cint>>edad;
    cout<<"Introduzca su sexo: ";
    cint<<sexo;
    cout<<"Introduzca su altura(m): ";
    cint<<altura;

    cout<<"\n Edad: "<<edad<<endl;
    cout<<"\n Sexo: "<<sexo<<endl;
    cout<<"\n Altura(m):"<<altura<<endl;
    
    return 0;
}