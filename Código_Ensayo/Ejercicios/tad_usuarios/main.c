#include <stdio.h>
#include <stdlib.h>
#include "Serie.h"
#include "Usuario.h"

#define TAMSERIE 20
#define TAMUSUARIO 100

int main(){
    eSerie listaDeSerie[TAMSERIE];
    eUsuario listaDeUsuarios[TAMUSUARIO];

    inicializarSerieEstado(listaDeSeries, TAMSERIE);
    inicializarSeriesHardCode(listaDeSeries);
    inicializarUsuariosEstado(listaDeUsuarios,TAMUSUARIO);
    inicializarUsuariosHardCode(listaDeUsuarios);

    int opcion;

    do{
        system("cls");
        printf("\n ");
    }
}