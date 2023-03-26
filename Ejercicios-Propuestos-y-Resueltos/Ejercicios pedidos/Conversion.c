/**************Estructura de control secuencial*****************
*
*	Autor: @AngelTienda
*	Programa: Ejercicio 5 - Conversi�n de pulgadas a cent�metros
*
****************************************************************/
#include <stdio.h>
int main(){

	// Declaración de variables necesarias
	float cm;
	float aPulgada = 2.54;
	float resultado;

	// Solicitud de los datos.
	printf("Bienvenido al conversor de centimetros a pulgadas \n");
	printf("");
	printf("Introduzca nº de cm:");
	scanf("%f",&cm);

	// Realizamos los calculos
	resultado = cm/aPulgada;
	printf("%f cm son %f pulgadas", cm, resultado);
	return 0;
}
