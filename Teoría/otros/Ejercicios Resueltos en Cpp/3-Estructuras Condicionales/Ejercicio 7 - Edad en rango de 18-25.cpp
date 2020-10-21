/* 
 Escriba un programa que solicite una edad (un entero) e indique en la 
 salida est�ndar si la edad introducida est� en el rango [18-25].
*/

#include<iostream>

using namespace std;

int main(){
	int edad;
	
	cout<<"Digite su edad: "; 
	cin>>edad;
	
	if((edad>=18)&&(edad<=25)){
		cout<<"Su edad esta en el rango de [18-25]";
	}
	else{
		cout<<"Su edad esta fuera de rango";
	}
	
	
	return 0;
}
