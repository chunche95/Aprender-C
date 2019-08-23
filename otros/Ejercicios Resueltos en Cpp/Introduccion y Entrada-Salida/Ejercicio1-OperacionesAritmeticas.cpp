/*
 *
 * Escriba un programa que lea de la entrada estándar dos números y muestre 
 * en la salida estándar su suma, resta, multiplicación y división.
 * 
 */ 

#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
    int n1,n2, suma=0, resta=0, multiplicacion=0, division=0;
    
    cout<<"Escriba un número: "; cin>>n1;
    cout<<"Escriba un número: "; cin>>n2;
    
    suma = n1+n2;
    resta = n1-n2;
    multiplicacion = n1*n2;
    division = n1/n2;

    cout<<"\n La suma es: "<<suma<<endl;
    cout<<"\n La resta es: "<<resta<<endl;
    cout<<"\n La multiplicacion es: "<<multiplicacion<<endl;
    cout<<"\n La division es: "<<division<<endl;

    return 0;
}