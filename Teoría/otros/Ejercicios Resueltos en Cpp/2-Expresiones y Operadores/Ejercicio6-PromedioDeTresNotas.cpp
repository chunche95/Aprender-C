/*
 *
 * Escriba el programa que lea las tres notas de un alumno y calcule la nota media final.
 * 
 */

#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
    float n1,n2,n3;
    int nf;

    cout<<"Introduzca nota: ";cin>>n1;
    cout<<"Introduzca nota: ";cin>>n2;
    cout<<"Introduzca nota: ";cin>>n3;
    
    nf=(n1+n2+n3)/3;
    cout<<"La nota media final es: "<<nf;

    return 0;
}