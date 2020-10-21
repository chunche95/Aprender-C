/*
 * Hacer una estructura llamada corredor, en la cual se tendrán los siguientes campos: 
 *  - Nombre
 *  - Edad
 *  - Sexo
 *  - Club
 * Pedir datos al usuario para un corredor, y asignarle una categoría  de competición:
 *  * Juvenil <=18 años
 *  * Señor <= 40 años
 *  * Veterano > 40 años 
 * Posteriormente imprimir todos los datos del corredor, incluida su categoría de competición.
 */

#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;

struct Corredor{
    char nombre[20];
    int edad;
    char sexo[10];
    char club[20];
}
cl;
int main(){
    char categorio[20];

    cout<<"Nombre: ";
    cin.getline(cl.nombre,20,'\n');
    cout<<"Edad: ";
    fflush(stdin);
    cout<<"Sexo: ";
    cin.getline(cl.nombre,20,'\n');
    cout<<"Club: ";
    cin.getline(cl.club,20,'\n');


    if(cl.edad <= 18){
        
    }
}