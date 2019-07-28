#include "Serie.h"
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

/*
 * Nota: Funsionamiento. -- Pauchino.
 * 
 * 
 * int idSerie, cantidadTemporadas, estado;
 * char nombre[50], genero[20];
 */

void inicializarSerieEstado(eSerie series[], int cant){
    int i;
    for(i=0;i<cant;i++){
        serie[i].estado=0;
    }
}

void inicializarSerieHardCode(eSerie series[]){
    int id[5]={100,101,102,103,104};
    char nombre[][50]={"TBBT", "TWD", "GOT", "BB", "LCDP"};
    char genero[][20]={"Comedia", "Terror", "Suspense", "Policiaca", "Ficción"};
    int cantidad[5]={10,9,7,5,2};
    
    int i;
    for(i=0;i<5;i++){
        series[i].idSerie=id[i];
        series[i].cantidadTemporadas=cantidad[i];
        series[i].estado=1;
        strcpy(series[i].nombre, nombre[i]);
        strcpy(series[i].genero, genero[i]);
    }
}

void AltaSeries(eSerie series[], int cant){
    int i;
    cant=15;
    printf("Alta series. \n");
    for(i=0;i<cant;i++){
        printf("ID: \n");
        scanf("%d",&series[i].idSerie);
        printf("\n Nombre: ");
        fflush(stdin);
        gets(series[i].nombre);
        printf("\n Cantidad de temporadas: ");
        scanf("%d", &series[i].cantidadTemporadas);
        printf("Género: ");
        fflush(stdin);
        gets(series[i].genero);
    }
}

void BajaSeries(eSerie series[], int cant)
{
    int i,j,k; cant=5;
    char nombre[20];
    mostrarListaSeries(series,5);
    printf("\nBAJA SERIES\n");
    printf("Nombre de la serie: ");
    fflush(stdin);
    gets(nombre);
    for(i=0;i<cant;i++)
    {
      if(strcmp(series[i].nombre,nombre)==0)
      {
        for(j=i+1;j<cant-1;j++)
        {
          for(k=j+1;k<cant;k++)
          {
             strcpy(series[j].nombre,series[k].nombre);
             series[j].cantidadTemporadas=series[k].cantidadTemporadas;
             series[j].idSerie=series[k].idSerie;
             break;
          }
          cant--;
        }
      }
    }

        for(i=0; i<cant; i++)
        {
            fflush(stdin);
            printf("%2d  %-6s  %-9s  %5d\n", series[i].idSerie, series[i].nombre, series[i].genero, series[i].cantidadTemporadas);
        }
    }
    if(strcmp(series[i].nombre,nombre)!=0)
    {
     printf("\nUps, no se encontro");
    }
}

void ModificacionSeries(eSerie series[])
{
    int i;
    char nombre[20];
    mostrarListaSeries(series, 5);
    printf("\nID: ");
    scanf("%d",&series[i].idSerie);
    if(strcmp(series[i].nombre,nombre)==0)
    {
       printf("Nombre: ");
       fflush(stdin);
       gets(nombre);
       strcpy(series[i].nombre,nombre);
    }
}


void mostrarListaSeries(eSerie series[], int cant)
{
    int i;
    cant = 5;
    printf("\nLista de series:\n");
    printf("ID   Nombre  Genero    Temporadas\n");
    printf("--   ------  ------    ----------\n\n");
    for(i=0; i<cant; i++)
    {
        fflush(stdin);
        printf("%2d  %-6s  %-9s  %5d\n", series[i].idSerie, series[i].nombre, series[i].genero, series[i].cantidadTemporadas);
    }

}

void ListaSeriePorUsuario(eUsuario usuarios[], int cant1, eSerie series[][], int cant2)
{
    int i;
    cant1 = 15;
    cant2 = 5;
    printf("\nUsuario   Serie:\n\n");
    for(i=0; i<15; i++)
    {
        if(usuarios[i].idSerie == series[i].idSerie)
        {
        }
    }
}