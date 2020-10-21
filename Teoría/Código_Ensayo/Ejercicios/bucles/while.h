#include <stdio.h>

int main(){
    int numero, factorial = 1, datoUsuario;
    
    printf("Introduzca un número para realizar el factorial. \n ");
    scanf("%d",&datoUsuario);

    numero = datoUsuario;

    while (numero > 1){
        factorial *= numero;
        numero--; 
    }

    printf("\n El factorial de %d vale %d \n",datoUsuario, factorial);
    printf("Ojo! Al salir del bucle la variable número vale %d",  numero);

    return 0;
    
}