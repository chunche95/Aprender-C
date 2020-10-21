/*
 * Pedir al usuario que escriba 2 cadenas de caracteres e indicar si ambas son iguales, en caso 
 * contrario, indicar cual es la mayor.
 */

#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;

int main(){
    char p1[50], p2[50];

    cout<<"Escriba la primera palabra: ";
    cin.getline(p1,50,'\n');
    cout<<"Escriba la segunda palabra: ";
    cin.getline(p2,50,'\n');
    
    if(strcmp(p1,p2)==0){
        cout<<"Ambas cadenas son iguales.";
    }else if(strcmp(p1,p2)>0){
        cout<<p1<<" Es mayor alfabeticamente.";
    }else{
        cout<<p2<<" Es mayor alfabeticamente.";
    }

    getch();
    return 0;
}