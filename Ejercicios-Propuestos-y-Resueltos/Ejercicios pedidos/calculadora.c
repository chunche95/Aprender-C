#include <stdio.h>

int main() {
    int n1, n2, opc;
    while ( opc != 0 ) {
        printf("\v");
        printf("Num. 1: ");
        scanf("%d", &n1);
        printf("\n");
        printf("Num. 2: ");
        scanf("%d", &n2);
        printf("\n");

        printf("Seleccione una opcion:"); 
        printf("\n");
        printf("1) Suma"); 
        printf("\n");
        printf("2) Resta"); 
        printf("\n");
        printf("3) Multiplicacion"); 
        printf("\n");
        printf("4) Division"); 
        printf("\n");
        printf("5) Resto");    
        printf("\n") ;
        printf("6) Porcentaje"); 
        printf("\n");
        
        printf("0) Salir"); 
        printf("\n");
        printf("\v");
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
            printf("Resultado de %d y %d es: %d", n1,n2,n1+n2);
            break;
        case 2:
            printf("Resultado de %d y %d es: %d", n1,n2,n1-n2);
            break;
        case 3:
            printf("Resultado de %d y %d es: %d", n1,n2,n1*n2);
            break;
        case 4:
            printf("Resultado de %d y %d es: %f", n1,n2,(float)n1/n2);
            break;
        case 5:            
            printf("Resultado de %d y %d es: %f", n1,n2,n1%n2);
            break;
        case 6:
            printf("El %d por ciento de %d es: %.2f", n1,n2,(float)(n1*n2)/100);
            break;
        case 0:
            printf("Gracias por usar mi basic calculator.");
            break;
        default:
            printf("Esta opcion no la conozco");
            break;
        }
        n1 = 0; n2 = 0;
    }
    
}