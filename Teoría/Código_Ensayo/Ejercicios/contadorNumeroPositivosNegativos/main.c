#include <stdio.h>
#include <stdlib.h>

int main(){
    int num, contPositivos=0, contNegativos=0;

    for(int i=0; i<10; i++){
        scanf("%d", &num);
        if(num>0){
            contPositivos++;
        }else {
            contNegativos++;
        }
        system("cls");
    }
    printf("Resultados encontrados. \n");
    printf("La cantidad de número positivos es: %d \n La cantidad de números negativos es: %d", contPositivos, contNegativos);
    return 0;
}