/*
 Escriba un programa que lea de la entrada estandar un caracter e indique 
 en la salida estandar si el caracter es una vocal minuscula o no.
*/

#include<iostream>

using namespace std;

int main(){
	char letra;
	
	cout<<"Digite un caracter: "; 
	cin>>letra;
	
	switch(letra){
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u': cout<<"Es una vocal minuscula"; break;
		default : cout<<"No es una vocal minuscula"; break;			
	}
		
	return 0;
}
