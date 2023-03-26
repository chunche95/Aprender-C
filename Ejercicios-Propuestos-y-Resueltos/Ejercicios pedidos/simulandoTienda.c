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
    char op, fp, fg, vv, vr, ov, bp, bg, ch;
    float litros= 0, coste = 0;
    int cantidad = 0;

    do  {
        printf("Que deseas comprar? \n fp - Frutas pequennas \n fg - Frutas grandes \n vv - Verduras verdes \n vr - Verduras rojas. \n ov - Otras Verduras ");
        printf("\n bp - Bebidas pequennas \n bg - Bebidas grandes \n ch - chuches. \n s - Salir de la fruteria Chufruve. ");

        switch( op ){
            case 'fp':
                printf("¿Cuantas frutas pequennas llevas?");
                float coste = aPagar(cantidad, op);
                printf("€ %.2f", coste);
                break;
            case 'fg':
                printf("¿Cuantas frutas pequennas llevas?");
                float coste = aPagar(cantidad, op);
                printf("€ %.2f", coste);
                break;
            case 'vv':
                printf("¿Cuantas frutas pequennas llevas?");
                float coste = aPagar(cantidad, op);
                printf("€ %.2f", coste);
                break;
            case 'vr':
                printf("¿Cuantas frutas pequennas llevas?");
                float coste = aPagar(cantidad, op);
                printf("€ %.2f", coste);
                break;
            case 'ov':
                printf("¿Cuantas frutas pequennas llevas?");
                float coste = aPagar(cantidad, op);
                printf("€ %.2f", coste);
                break;
            case 'bp':
                printf("¿Cuantas frutas pequennas llevas?");
                float coste = aPagar(litros, op);
                printf("€ %.2f", coste);
                break;
            case 'bg':
                printf("¿Cuantas frutas pequennas llevas?");
                float coste = aPagar(litros, op);
                printf("€ %.2f", coste);
                break;
            case 'ch':
                printf("¿Cuantas frutas pequennas llevas?");
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
    if  ( op == 'fp' ) {
        return( cantidad * precioFrutasPequennas);
    } else if ( op == 'fg' ) {
        return ( cantidad * precioFrutasGrandes);
    } else if ( op == 'vv' ) {
        return ( cantidad * precioVerdurasVerdes);
    } else if ( op == 'vr' ) {
        return ( cantidad * precioVerdurasRojas);
    } else if ( op == 'ov' ) {
        return ( cantidad * precioOtrasVerduras);
    } else if ( op == 'bp' ) {
        return ( cantidad * bebidaPequennas);
    } else if ( op == 'bg' ) {
        return ( cantidad * bebidasGrandes);
    } else if ( op == 'ch' ) {
        return ( cantidad * chuches);
    }
}