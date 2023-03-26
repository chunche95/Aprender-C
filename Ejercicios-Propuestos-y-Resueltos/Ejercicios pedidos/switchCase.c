#include <stdio.h>


int main() {
    char dia;
    printf(" Seleccione un dia de la semana:");
    printf("L - Lunes M- Martes X - Miercoles J - Jueves V - Viernes S- Sabado D - Domingo");
    printf("\n");
    scanf("%c", &dia);


    switch (dia)
    {
    case  'L':
        printf("Lunes");
        break;
    
    case  'M':
        printf("Martes");
        break;
    
    case  'X':
        printf("Miercoles");
        break;
    
    case  'J':
        printf("Jueves");
        break;
    case  'V':
        printf("Viernes");
        break;
    case  'S':
        printf("Sabado");
        break;
    
    case  'D':
        printf("Domingo");
        break;
    default:
        printf("Opción no valida.");
        break;
    }
}