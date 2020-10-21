/*
 *Uso de los procedimientos printf() y scanf(). Sirve además para aplicar operadores matemáticos y conversiones.
 */(

#include <stdio.h>

int main(){
    int hor, min, seg;
    printf("Qué cantidad de segundos quieres convertir? ");
    scanf("%d", &seg);
    hor = seg / 3600;
    seg = seg % 3600;
    min = seg / 60;
    seg = seg % 60;
    printf(" Equivalen a %2d horas %2d segundos \n ", hor, min,seg);
    return 0;
}