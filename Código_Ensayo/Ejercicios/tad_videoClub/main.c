#include <stdio.h>
#include <stdlib.h>
#include "Serie.h"
#include "Usuario.h"

#define TAMSERIE 20
#define TAMUSUARIO 100

int main(){
    eSerie listaDeSeries[TAMSERIE];
    eUsuario listaDeUsuarios[TAMUSUARIO];

    inicializarSerieEstado(listaDeSeries, TAMSERIE);
    inicializarSeriesHardCode(listaDeSeries);
    inicializarUsuariosEstado(listaDeUsuarios,TAMUSUARIO);
    inicializarUsuariosHardCode(listaDeUsuarios);

    int opcion;

    do{
        system("cls");
        printf("1. Alta. \n");
        printf("2. Baja. \n");
        printf("3. Modificación. \n");
        printf("4. Mostrar el listado de series. \n");
        printf("5. Mostrar el listado de usuarios. \n");
        printf("6. Mostrar el listado de usuarios con el nombre de la serie que ve. \n");
        printf("7. Mostrar por cada serie, el nombre de los usuarios que la ven. \n");
        printf("8. Salir. \n");
        printf("\n Opcióm elegida: \n");
        scanf("%d", &opcion);

        switch(opcion){
            case 1:
                system("cls");
                AltaSeries(listaDeSeries, TAMSERIE);
                system("pause");
                break;
            case 2:
                system("cls");
                BajaSeries(listaDeSeries, TAMSERIE);
                system("pause");
                break;
            case 3:
                system("cls");
                ModificacionSeries(listaDeSeries);
                system("pause");
                break;
            case 4:
                system("cls");
                MostrarListaSeries(listaDeSeries, TAMSERIE);
                system("pause");
                break;
            case 5:
                system("cls");
                MostrarListaUsuarios(listaDeUsuarios, TAMUSUARIO);
                system("pause");
                break;
            case 6:
                system("cls");
                ListaUsuarioPorSerie(listaDeUsuarios,TAMUSUARIO, listaDeSeries, TAMSERIE);
                system("pause");
                break;
            case 7:
                system("cls");
                ListaSeriePorUsuario(listaDeSeries,TAMSERIE, listaDeUsuarios,TAMUSUARIO);
                system("pause");
                break;
        }
    }while (opcion<8);
    /*
        1. Mostrar el listado de series.
        2. Mostrar el listado de usuarios.
        3. Mostrar el listado de usuarios con el nombre de la serie que ve.
        4. Mostrar por cada serie, el nombre de los usuarios que la ven.
     */  
    return 0;
    
}