#include <stdio.h>
#include <stdlib.h>

/* 
 * Escribir un programa que realice las siguientes acciones:
 * 1- Limpie la pantalla.
 * 2- Asigne a dos variables num1 y num2 valores distintos de cero.
 * 3- Efectue el producto de dichas variables.
 * 4- Muestre el resultado por pantalla.
 * Obtenga el cuadrado del numero 1 y lo muestre por pantalla. 
 */

int main(int argc, char *argv[]){
    int a, b, producto, cuadrado;
    system("cls");
    do {
        /* Numero 1. */
        printf("\n Introduzca el primer número: ");
        scanf("%d",&a);
        printf("El número introducido es: %d \n", a );
        if (a==0){
            printf("\n Ingrede un número distinto a 0 \n");
            scanf("%d",&a);
        }
    } while (a==0);
    do
    {
        /* Número 2. */
        printf("\n Ingrese 2\247 número: ");
        scanf("%d",&b);
        printf("El número ingresado es: %d \n", b);
        if(b==0){
            printf("\n Ingrese un número distinto a 0.\n");
            scanf("%d",&b);
        }
    } while (b==0);
        producto=a*b;
        cuadrado=a*a;
        printf("\n El valor 1\247: %d \n El valor 2\247: %d \n El producto es: %d \n El cuadrado de 1\247 es: %d \n",a,b,producto,a,cuadrado);
        printf("\n \n \n \n");
        return 0;
}