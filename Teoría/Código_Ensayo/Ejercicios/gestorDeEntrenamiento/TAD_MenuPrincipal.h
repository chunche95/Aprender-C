#pragma once

#include "TAD_Actividades.h" 
#include "TAD_Calendario.h"  

typedef struct T_MenuPrincipal{
  int opcion;
  char respuesta; //Variable que almacenara si deseamos realizar otra acción.
  T_Actividades PlanDeActividades; //Almacenara el plan de entrenamiento de cada dia y si es "C" o "D".
  T_FechaPlan Fecha; //Almacenara el dia introducido entre otras cosas.
  
  /*
   * FUNCIONES PARA EL MENU
   */
  void InicializarValores();  //Procedimiento que inicializa el plan introducido entre otras cosas.
  void ElegirOpcion();        //Procedimiento que pide la opcion al usuario.
  void RealizarAccion();      //Procedimiento que contiene un switch y realiza una accion u otra segun la opcion seleccionada.
  void Repetir();             //Procedimiento que nos pregunta si deseamos realizar otra accion.
};
