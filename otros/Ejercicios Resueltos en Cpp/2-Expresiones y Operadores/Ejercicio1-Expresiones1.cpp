/*
 *
 * Escribe la siguiente expresión como expresión en C++. (a/b)+1
 * 
 */

#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
    float a,b,resultado=0;

    cout<<"Introduzca el valor de a: ";
    cin>>a;
    cout<<"Introduzca el valor de b: ";
    cin>>b;

    resultado= (a/b)+1;

    /* Recorta los números después de la coma decimal a 2. */
    cout.precision(2);

    return 0;
}