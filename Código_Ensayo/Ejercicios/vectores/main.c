#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int vector[5]; /* ={1,5,54,0,998}; */
    /* Variable de almacenamiento del vector */
    int i;

    for (int i=0;i<5;i++){
        printf("Escriba un número: ");
        scanf("%d", &vector[i]);
    }
    for(i=0;i<5;i++){
        if(vector[i]==998){
            printf("\n Posición de memoria del vector con el número 998 es: %d \n",i);
        }
    }
    return 0;
}