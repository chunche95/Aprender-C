
#include "Usuario.h"
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

void inicializarUsuariosEstado(eUsuario usuarios[], int cant)
{
     int i;

    for(i=0; i<cant; i++)
    {
        usuarios[i].estado = 0;
    }
}
void inicializarUsuariosHardCode(eUsuario usuarios[])
{


    int id[15] = {1000,1001,1002,1003,1004,1005,1006,1007,1008,1009, 1010,1011,1012,1013,1014};
    char nombre[][50]={"Juan","Maria","Pedro","Vanesa","Jose","Luisa","Laura","Marcelo","German","Victoria","Dafne","Antonela","Gisele","Dario","Pedro"};
    int serie[15] = {100,100,101,101,102,100,100,103,101,102,103,104,104,100,103};



    int i;

    for(i=0; i<15; i++)
    {
        usuarios[i].idUsuario=id[i];
        usuarios[i].idSerie=serie[i];
        usuarios[i].estado = 1;
        strcpy(usuarios[i].nombre, nombre[i]);

    }
}

void AltaUsuario(eUsuario usuarios[], int cant)
{
  int i;
  cant=15;
  printf("ALTA USUARIO\n");
  for(i=0;i<cant;i++)
  {
    printf("ID:");
    scanf("%d", &usuarios[i].idUsuario);
    printf("Nombre: ");
    gets(usuarios[i].nombre);
    printf("Serie: ");
    scanf("%d", &usuarios[i].idSerie);
  }

}

void BajaUsuario(eUsuario usuarios[], int cant)
{
    int i,j,k; cant=20;
    char nombre[20];
    printf("BAJA USUARIO\n");
    printf("Nombre del usuario: ");
    gets(nombre);
    for(i=0;i<cant;i++)
    if(strcmp(usuarios[i].nombre,nombre)==0)
    {
        for(j=i+1;j<cant-1;j++)
        {
            for(k=j+1;k<cant;k++)
            {
                strcpy(usuarios[j].nombre,usuarios[k].nombre);
                usuarios[j].idSerie=usuarios[k].idSerie;
                usuarios[j].idUsuario=usuarios[k].idUsuario;
                break;
            }
            cant--;
        }
    }
    if(strcmp(usuarios[i].nombre,nombre)!=0)
    {
        printf("Ups! No se encontro el usuario!");
    }
}


void ModificacionUsuario(eUsuario usuarios[])
{
    int i;
    char nombre[20];
    mostrarListaUsuarios(usuarios, 15);
    printf("Nombre del usuario: ");
    fflush(stdin);
    gets(nombre);
    if(strcmp(usuarios[i].nombre,nombre)==0)
    {
        printf("Nombre: ");
        fflush(stdin);
        gets(nombre);
        strcpy(usuarios[i].nombre,nombre);
    }
}


void mostrarListaUsuarios(eUsuario usuarios[], int cant)
{
    int i;
    cant = 15;
    printf("\nLista de usuarios:\n");
    printf("Usuario  Nombre      Serie\n");
    for(i=0; i<cant; i++)
    {
        fflush(stdin);
        printf("%-8d %-10s %4d \n", usuarios[i].idUsuario, usuarios[i].nombre, usuarios[i].idSerie);
    }

}



void ListaUsuarioPorSerie(eUsuario usuarios[], int cant1, eSeries series[], int cant2)
{
    
}