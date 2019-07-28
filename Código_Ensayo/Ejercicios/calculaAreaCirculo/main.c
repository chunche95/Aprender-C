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
int getRadio(int num){
    int cuadrado;
    printf("Ingrese un número: ");
    scanf("%d", &num);
    cuadrado=(num*num);
    return cuadrado;
}
int getArea(int num){
    float area;
    area=3.14*getRadio(num);
    printf("\n El área es: %2f", area);
    return area;
}
