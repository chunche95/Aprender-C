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
    do  {        
        float litros = 0, coste,  cantidad = 0 ;
        printf("\n OK!");
        system("sleep 1");
        //system("cls");
        printf("Que deseas comprar:  \n f - Frutas pequennas \n g - Frutas grandes \n v - Verduras verdes \n r - Verduras rojas. \n o - Otras Verduras ");
        printf("\n p - Bebidas pequennas \n b - Bebidas grandes \n c - chuches. \n s - Salir de la fruteria Chevere. ");
        printf("\n");
        scanf("%s", &op);
        switch( op ){
            case 'f':
                printf("-Cuantas frutas pequennas llevas: ");
                scanf("%f", &cantidad);
                coste =  cantidad * precioFrutasPequennas;
                printf("$ %.2f", coste);
                break;
            case 'g':
                printf("-Cuantas frutas grandes llevas: ");
                scanf("%f", &cantidad);
                coste = ( cantidad * precioFrutasGrandes);
                printf("$ %.2f", coste);
                break;
            case 'v':
                printf("-Cuantas verduras verdes llevas: ");
                scanf("%f", &cantidad);
                coste = ( cantidad * precioVerdurasVerdes);
                printf("$ %.2f", coste);
                break;
            case 'r':
                printf("-Cuantas verduras rojas llevas: ");
                scanf("%f", &cantidad);
                coste = cantidad * precioVerdurasRojas;
                printf("$ %.2f", coste);
                break;
            case 'o':
                printf("-Cuantas verduras de otro tipo llevas: ");
                scanf("%f", &cantidad);
                coste = ( cantidad * precioOtrasVerduras);
                printf("$ %.2f", coste);
                break;
            case 'p':
                printf("-Cuantos litros llevas: ");
                scanf("%f", &cantidad);
                coste = ( cantidad * bebidaPequennas);
                printf("$ %.2f", coste);
                break;
            case 'b':
                printf("-Cuantos litros llevas: ");
                scanf("%f", &cantidad);
                coste = ( cantidad * bebidasGrandes);
                printf("$ %.2f", coste);
                break;
            case 'c':
                printf("-Cuantas chuches llevas: ");
                scanf("%f", &cantidad);
                coste =  cantidad * chuches;
                printf("$ %.2f", coste);
                break;
            case 's':
                printf("\n++++++++++++++++++++++++++++++++++++++\n");
                printf("+ \t Factura de la tienda");     
                printf("\n++++++++++++++++++++++++++++++++++++++\n");
                printf("+ Coste total ($) %.2f\n", coste);
                printf("+ Gracias por su compra y vuelva pronto! + \n");
                printf("\n++++++++++++++++++++++++++++++++++++++\n");
                printf("--------- PULSA ENTER PARA SALIR ---------");
                break;
            default:
                printf("Opcion no valida...");
        } 
        coste += coste;        
    } while( op != 's');
    getch();    
}