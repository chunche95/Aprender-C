/*
 *
 * Ezcribir la siguiente expresión en C++: a+(b/(c-d))
 * 
 */

#include <iostream> 
#include <stdio.h>

using namespace std;

int mian(){
    float a,b,c,d,sol=0;
    cout<<"Introduzca a: "; cin>>a;
    cout<<"Introduzca b: "; cin>>b;
    cout<<"Introduzca c: "; cin>>c;
    cout<<"Introduzca d: "; cin>>d;
    sol=a+(b/(c-d));
    cout.presicion(2);

    cout<<"Resultado: ">>sol;
    return 0;
    
    
}