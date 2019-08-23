/*
 *
 * Escribir el fragmento de programa que intercambie los valores de dos variables.
 * 
 */


#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
    int x,y,aux;
    cout<<"Introduzca el valor de x: "; cin>>x;
    cout<<"Introduzca el valor de y: "; cin>>y;

    aux=x;
    x=y;
    y=aux;

    cout<<"\n El nuevo valor de x: "<<x<<endl;
    cout<<"El valor de y es: "<<y<<endl;

    return 0;
    
}