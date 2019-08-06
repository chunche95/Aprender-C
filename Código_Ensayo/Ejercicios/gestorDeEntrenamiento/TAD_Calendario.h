#pragma once

#include "TAD_Actividades.h" //necesitamos un tipo definido T_CarreraDescanso.

typedef struct T_FechaPlan{
  /*
   *  VARIABLES
   */
  int DiaIntroducido;
  int MesIntroducido;
  int AnnoIntroducido;
  int DiasMes;      //En DiasMes se guardaran el número de días que tiene el mes introducido.
  int DiaSemana;    //En DiaSemana se guardara en que dia de la semana comienza el mes/año introducido. (1=Lunes - 7=Domingo);
  int ContadorMes;  //Variable auxiliar que nos indicara si debemos dibujar el calendario 1 o el 2.
  int DiaDibujado;  //Contador que nos dira cuantas "D" o "C" hemos dibujado en total en el calendario 1 y saber cuantas restan en el 2.
  T_CarreraDescanso Es_CoD; //Variable que copiara lo introducido en TAD_Actividades.h TipoCD para facilitarnos su dibujo en el calendario.
  /*
   *  INICIO PLAN Y DIBUJAR EL CALENDARIO
   */
  bool FechaGuardada; //true=si se ha introducido una fecha - false=si no se ha introducido ninguna fecha.
  bool FechaCorrecta(); //funcion que calcula si la fecha introducida es igual o mayor a la actual dada por el sistema.
  void InicioPlan(); //Procedimiento que pide la fecha de inicio del plan y comprueba si es correcta mediante FechaCorrecta().
  void MostrarPlan(T_CarreraDescanso AlmacenarCD,bool PlanGuardado); //Procedimiento que muestra 1 o 2 calendarios segun corresponda.
                  //Recibimos de T_MenuPrincipal.cpp PlanDeActividades.TipoCD y PlanDeActividades.PlanGuardado.
 /*
  *  FUNCIONES NECESARIAS PARA DIBUJAR EL CALENDARIO
  */
  bool Bisiesto();          //Funcion que calcula si el año introducido es bisiesto.
  int DiasTieneMes();       //Funcion que calcula cuantos dias tiene el mes que se tiene que mostrar.
  int CalcularDiaSemana();  //Funcion que calcula en que dia de la semana comienza un mes.
  void DibujarCalendario(); //Procedimiento que dibuja el calendario. Cambia segun sea el calendario 1 o el 2.
};

