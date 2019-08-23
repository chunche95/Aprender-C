/*
 *
 * Escribir la siguiente expresión en C++. (a+(b/c))/(d+(e/f))
 * 
 */

#include <iostream>
#include <stdio.h>

int main(){
    float a,b,c,d,e,f,resultado=0;

    cout<<"Introduzca a: "; cin>>a;
    cout<<"Introduzca b: "; cin>>b;
    cout<<"Introduzca c: "; cin>>c;
    cout<<"Introduzca d: "; cin>>d;
    cout<<"Introduzca e: "; cin>>e;
    cout<<"Introduzca f: "; cin>>f;
    
    resultado=(a+(b/c))/(d+(e/f));

    count.presicion(2);

    count<<"El resultado es: "<<resultado;

    return 0;
}