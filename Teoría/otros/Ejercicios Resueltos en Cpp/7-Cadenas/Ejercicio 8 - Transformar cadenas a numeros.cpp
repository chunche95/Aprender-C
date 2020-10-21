#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

int main(){
    char cad1[10], cad2[10];
    int valorEntero;
    float valorFlotante;

    cout<<"Escribir un numero entero: ";
    cin.getline(cad1,10,'\n');
    cout<<"Escribir un numero flotante: ";
    cin.getline(cad2,10,'\n');

    valorEntero=atoi(cad1);
    valorFlotante=atof(cad2);

    cout<<"\n La suma es: "<<valorEntero+valorFlotante;

    getch();
    return 0;
}