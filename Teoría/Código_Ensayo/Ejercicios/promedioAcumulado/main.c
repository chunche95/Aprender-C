#include <stdio.h>
#include <stdlib.h>

int main(void){
    int numero[5];
    int acumulado = 0;
    float promedio = 0;
    int max=0,min=0,aux=0;

    for(int i=0;i<5;i++){
        printf("Ingrese un número: ");
        scanf("\n%d", &numero[i]);
        aux++;

        if(aux==1){
            max = numero[i];
            min = numero[i];
        }
        else if (numero[i] > max){
            max = numero[i];
        }
        else if (numero[i] < min){
            min = numero[i];
        }
    }
    printf("\n _________________________ \n ");
    printf("Números ingresados: ");
    for(int i=0;i<5;i++){
        printf("%d,", numero[i]);
        acumulado += numero[i];
    }
    promedio = (acumulado/aux);
    printf("\n ____________________________ \n ");
    printf("El promedio es: %f", promedio);
    printf("\n El máximo es: %d \n El mínimo es: %d",max,min);
}