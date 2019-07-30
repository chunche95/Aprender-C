#include <stdio.h>

int main(){
    int numero, factorial=1;

    printf("Introduzca un número para calcular el factorial: \n");
    scanf("%d", &numero);

    for(int indice = 2; indice <= numero; indice++){
        factorial *= indice;
    }

    printf("El factorial de %d vale %d \n", numero, factorial);
    printf("Ojo! al salir del bucle la variable número vale %d", numero);

    /*
     * Cuánto vale la variable indice al salir del bucle?
     * printf("Al salir del bucle la variable indice vale %d", indice);
     */
    return 0;
}