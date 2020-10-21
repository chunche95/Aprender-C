#include <stdio.h>

int main(){
    for(int indiceExterior = 1; indiceExterior < 5 ; indiceExterior++){
        for(int indiceInterior = 1; indiceInterior < 5; indiceInterior++){
            printf("(%d,%d)",indiceExterior,indiceInterior);
        }
        printf("\n");
    }
    return 0;
}