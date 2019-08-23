/*
 * Crear una cadena que tenga la siguiente frase "Hola que tal", luego crear otra
 * cadena para preguntarle al usuario su nombre, por ultimo añadir el nombre al final de 
 * la primera cadena y mostrar el mensaje completo "Hola que tal (NombreDelUsuario)".
 */

#include<iostream>
#include<conio.h>
#include<string.h>

using namespace std;

int main(){
	char cadena1[] = "Hola que tal ";
	char cadena2[20];
	
	cout<<"Escriba su nombre: ";
	cin.getline(cadena2,20,'\n');
	
	strcat(cadena1,cadena2);
	
	cout<<"Frase: "<<cadena1<<endl;	
	
	
	getch();
	return 0;
}
