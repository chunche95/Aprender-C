#include <stdio.h>
#include <stdlib.h>

int main(){
    int numero, contador=0, max=0, min=0, aux=0;
    float promedio=0;

    for (int i=0; i<5; i++){
        printf("%d", &numero);
        contador+=numero;
        aux++;

        if(aux==1){
            /* Asignación de comparación */
            max=numero;
            min=numero;
        }
        if (numero > max){
            max = numero;
        }
        if (numero < min){
            min = numero;
        }

        promedio = contador/5;
    }

    printf("El promedio es: %f", promedio);
    printf("\n El número máximo es: %d \n El número mínimo es: %d ", max,min);

    return 0;
}