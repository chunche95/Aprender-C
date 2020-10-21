/*
 *
 * Escriba la siguiente expresión en C++: (a+b)/(c+d)
 *
 */

#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
    float a,b,c,d, resultado=0;

    cout<<"Introduzca a: "; cin>>a;
    cout<<"Introduzca b: "; cin>>b;
    cout<<"Introduzca c: "; cin>>c;
    cout<<"Introduzca d: "; cin>>d;
    
    resultado=(a+b)/(c+d);

    /* Resultado, con 2 decimales */
    cout.presicion(2);
    cout<<"El resultado es:"<<resultado;

    return 0;
}