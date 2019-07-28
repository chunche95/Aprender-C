#include <stdio.h>
#include <stdlib.h>

int main(int arg, char *argv[]){
    int a,b,resultado;
    printf("\ Ingrese el primer número: ");
    scanf("%d",&a);
    while (a==0)
    {
        /* Comprobación de que el número sea mayor de cero. */
        printf("\n Ingrese un número mayor que 0."); 
        scanf("%d", &a);
    }
    printf("\n Ingrese el segundo número: ");
    scanf("%d", &b);
    while(b==0){
        /* Comprobación de que el número sea mayor de cero. */
        printf("\n Ingrese un número mayor que 0."); 
        scanf("%d", &b);
    }
    
    /* Resultado de la operación. */
    resultado=a-b;

    printf("________________________________\n");
    printf("\n El resultado es: %d", resultado);
    if(resultado>=0){
        printf("\n Resultado positivo. \n");
    }else{
        printf("\n Resultado negativo. \n");
    }
    printf("________________________________\n");
    return 0;
}