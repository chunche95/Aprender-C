/*
 *
 * La calficación de un estudiante, es el promedio de tres notas:
 *  - Nota practicas: 30%
 *  - Nota teórica: 60%
 *  - Nota clase: 10%
 * Escriba el programa que lea las notas y calcule la media final.
 *
 */

#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
    float np, nt, nc;
    int nf;

    cout<<"Introduzca la nota de PRACTICAS: "; cin>>np*0.6;
    cout<<"Introduzca la nota de TEORIA: "; cin>>nt*0.3;
    cout<<"Introduzca la nota de CLASE: "; cin>>nc*0.1;
    
    nf=(np+nt+nc)/3;

    cout<<"La nota final es: "<<nf;

    return 0;

}