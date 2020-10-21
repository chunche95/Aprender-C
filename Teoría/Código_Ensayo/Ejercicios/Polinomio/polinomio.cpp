#include "polinomio.h"
#include <math.h>
#include <stdio.h>

void TipoOperacion::SumarPolinomio(TipoPolinomio P, float coeficiente, int n){
    P[n]+=coeficiente;
}

float TipoOperacion::Evaluar(const TipoPolinomio P, int b){
    float resultado=0;
    for(int i=0;i<numGrados;i++){
        resultado=resultado+P[i]*pow(b,i);
    }
    return resultado;
}

void TipoOperacion::Imprimir(const TipoPolinomio P){
    if(P[0]!=0){
        printf("%2.2f",P[0]);
    }
    if(P[1]!=0){
        if(P[1]>0){
            printf("%c",'+');
        }
        printf("%2.2fX",P[1]);
    }
    for(int i=2;i<numGrados;i++){
        if(P[i]!=0){
            if(P[i]>0){
                printf("%c",'+');
            }
            printf("%2.2fX%d",P[i],i);
        }
    }
    printf("%c\n",'=');
}