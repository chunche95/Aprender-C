/*
 *
 * Escribir un programa que dé la entrada estándar el precio de un produ to y muestre 
 * en la salida estándar el precio del producto al aplicarse el IVA.
 * 
 */

#include <iostream>
#include <stdio.h>

using namespace std;

int main(){

    float precio, precioFinal, IVA;

    cout<<"Introduzca el precio del producto: ";
    cin>>precio; 

    IVA=precio*0.21;
    precioFinal = precio + IVA;

    cout<<"\n Precio del producto (IVA incluido): "<<precioFinal;

    return 0;
}