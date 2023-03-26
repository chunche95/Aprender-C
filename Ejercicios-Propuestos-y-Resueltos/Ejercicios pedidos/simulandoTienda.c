#include <stdio.h>
#include <conio.h>

#define precioFrutasPequennas 1.25
#define precioFrutasGrandes 2.44
#define precioVerdurasVerdes 2.01
#define precioVerdurasRojas 2.13
#define precioOtrasVerduras 2.93
#define bebidaPequennas 1.05
#define bebidasGrandes 2.25
#define chuches 0.75

int main() {
    char op, f, g, v, r, o, p, b, c;
    float litros= 0, coste = 0;
    int cantidad = 0;

    do  {
        printf("Que deseas comprar? \n fp - Frutas pequennas \n fg - Frutas grandes \n vv - Verduras verdes \n vr - Verduras rojas. \n ov - Otras Verduras ");
        printf("\n bp - Bebidas pequennas \n bg - Bebidas grandes \n ch - chuches. \n s - Salir de la fruteria Chufruve. ");

        switch( op ){
            case 'f':
                printf("¿Cuantas frutas pequennas llevas?");
                float coste = aPagar(cantidad, op);
                printf("€ %.2f", coste);
                break;
            case 'g':
                printf("¿Cuantas frutas grandes llevas?");
                float coste = aPagar(cantidad, op);
                printf("€ %.2f", coste);
                break;
            case 'v':
                printf("¿Cuantas verduras verdes llevas?");
                float coste = aPagar(cantidad, op);
                printf("€ %.2f", coste);
                break;
            case 'r':
                printf("¿Cuantas verduras rojas llevas?");
                float coste = aPagar(cantidad, op);
                printf("€ %.2f", coste);
                break;
            case 'o':
                printf("¿Cuantas verduras de otro tipo llevas?");
                float coste = aPagar(cantidad, op);
                printf("€ %.2f", coste);
                break;
            case 'p':
                printf("¿Cuantas bebidas pequennas llevas?");
                float coste = aPagar(litros, op);
                printf("€ %.2f", coste);
                break;
            case 'b':
                printf("¿Cuantas bebidas grandes llevas?");
                float coste = aPagar(litros, op);
                printf("€ %.2f", coste);
                break;
            case 'c':
                printf("¿Cuantas chuches llevas?");
                float coste = aPagar(cantidad, op);
                printf("€ %.2f", coste);
                break;
            case 's':
                printf("Coste total.");
                printf("\n");
                printf(&coste);
                printf("Factura de la tienda");                
                break;
            default:
                printf("Opcion no valida...");
        } 
        coste += coste;
    } while( op == 's');
}

float aPagar(int cantidad, char op) {
    if  ( op == 'f' ) {
        return( cantidad * precioFrutasPequennas);
    } else if ( op == 'g' ) {
        return ( cantidad * precioFrutasGrandes);
    } else if ( op == 'v' ) {
        return ( cantidad * precioVerdurasVerdes);
    } else if ( op == 'r' ) {
        return ( cantidad * precioVerdurasRojas);
    } else if ( op == 'o' ) {
        return ( cantidad * precioOtrasVerduras);
    } else if ( op == 'p' ) {
        return ( cantidad * bebidaPequennas);
    } else if ( op == 'b' ) {
        return ( cantidad * bebidasGrandes);
    } else if ( op == 'c' ) {
        return ( cantidad * chuches);
    } else {
        return 0;
    }
}