#include <stdio.h>
#include <stdlib.h>

int getInt(int num);
int getRadio(int num);
int getArea(int num);

int main(){
    int numero;
    getArea(numero);
    return 0;
}

int getInt(int num){
    printf("Ingrese un número: ");
    scanf("%d", &num);
    return num;
}
int getRadio()
