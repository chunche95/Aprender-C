/*
 *
 * Ejecute el programa del ejercicio anterior con entrada de datos erróneas y observe los resultados.
 * Por ejemplo:
 *  Introduzca un dato de tipo caracter cuando se espera un dato de tipo entero.
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