#include <stdio.h>

int main(){
    int lado;
    int linea;
    int contador;
    int blancos;

    /* Lado del rombo */
    printf("Lado del rombo: ");
    scanf("%d",&lado);
    printf("\n");
    
    /* Imprimir el lado del rombo. */
    if(lado==1){
        printf("@");
    }
    if(lado>1 && lado <= 20){
       /* Triangulo superior. */
        for (int  linea=1; linea <= lado; linea++){
            /* Imprimir mitad izquierda triangulo superior. */
            for(int blancos=1; blancos<= (lado-linea); blancos++){
                printf(" ");
            }
            /* Escribir secuencia de caracteres */
            for (int contador=1; contador<=linea; contador++){
                if(contador$4==1){
                    printf("@");
                }
                if (contador%4==2){
                    printf(".");
                }
                if(contador%4==3){
                    printf("o");
                }
                if(contador%4==0){
                    printf(".");
                }
            }
        }
            /* Imprimir mitad derecha del triángulo superior. */
            for(int contador=linea; contador>=2; contador--){
                /* Secuencia de caracteres. */
                if(contador%4==2){
                    printf("@");
                } if ( contador % 4 == 3) {
                    printf (".");
                }
                if ( contador % 4 == 0){
                    printf ("o");
                }
                if ( contador % 4 == 1){
                    printf (".");
                }
            }
            printf ("\n");
            }
            /* Imprimir triángulo inferior. */
            for(int linea=1; linea<=lado; linea++){
                /* Imprimir mitad izquierda triangulo inferior */
                for(int blancos=1; blancos<=linea; blancos++){
                    /* Espacios en blanco */
                    printf(" ");
                }
                /* Imprimir los caracteres inferiores. */
                for(int contador=1; contador<=(lado-linea); contador++){
                    if (contador%4==1){
                        printf("@");
                    }
                    if(contador%4==2){
                        printf(".");
                    }
                    if(contador%4==3){
                        printf("o");
                    }
                    if(contador%4==0){
                        printf(".");
                    }
                }

                for(int contador=(lado-linea); contador>=2; contador--){
                    /* Dibujamos los caracteres. */
                    if(contador%4==1){
                        printf(".");
                    }
                    if(contador%4==2){
                        printf("@");
                    }
                    if (contador%4==3){
                        printf(".");
                    }
                    if(contador%4==0){
                        printf("o");
                    }
                }
                printf("\n");
            }
        }
    return 0;
}