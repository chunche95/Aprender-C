#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>

#include "TAD_Calendario.h"

/*
 * FUNCIONES DEL STRUCT T_FechaPlan
 * PROCEDIMIENTOS Y FUNCIONES PRINCIPALES
 */
bool T_FechaPlan::FechaCorrecta(){
int AnnoActual;
int MesActual;
int DiaActual;

   SYSTEMTIME str_t;
   GetSystemTime(&str_t);
   AnnoActual=str_t.wYear;
   MesActual=str_t.wMonth;
   DiaActual=str_t.wDay;

   if(AnnoIntroducido<AnnoActual){ //Comparamos la fecha introducida con la actual
     return false;
   }else if((MesIntroducido<MesActual) && (AnnoIntroducido==AnnoActual)){
     return false;
   }else if ((DiaIntroducido<DiaActual) && (MesIntroducido==MesActual) && (AnnoIntroducido==AnnoActual)){
     return false;
   }else{
     return true; //solo devuelve true si la fecha introducida es igual o superior a la actual.
   }
}
bool T_FechaPlan::Bisiesto() { //Función que comprueba si el año es bisiesto o no.
  if (((AnnoIntroducido%4==0)&& (AnnoIntroducido%100)!=0)||(AnnoIntroducido%400)==0) {
    return true;
  } else {
    return false;
  }
}

/*
 * Función que calcula los dias que tiene el mes del año dado.
 * Se aprovecha para mostrar por pantalla la zona superior del calendario.
 */

int T_FechaPlan::DiasTieneMes(){

  switch (MesIntroducido) {
    case 1: printf("ENERO%22d\n",AnnoIntroducido); return 31; break;
    case 2: printf("FEBRERO%20d\n",AnnoIntroducido);
            if (Bisiesto()==true) { return 29; } //si bisiesto es true, devolvera 29 dias.
            else { return 28; }                //si bisiesto es false, devolvera 28 dias.
            break;
    case 3: printf("MARZO%22d\n",AnnoIntroducido); return 31; break;
    case 4: printf("ABRIL%22d\n",AnnoIntroducido); return 30; break;
    case 5: printf("MAYO%23d\n",AnnoIntroducido); return 31; break;
    case 6: printf("JUNIO%22d\n",AnnoIntroducido); return 30; break;
    case 7: printf("JULIO%22d\n",AnnoIntroducido); return 31; break;
    case 8: printf("AGOSTO%21d\n",AnnoIntroducido); return 31; break;
    case 9: printf("SEPTIEMBRE%17d\n",AnnoIntroducido); return 30; break;
    case 10: printf("OCTUBRE%20d\n",AnnoIntroducido); return 31; break;
    case 11: printf("NOVIEMBRE%18d\n",AnnoIntroducido); return 30; break;
    case 12: printf("DICIEMBRE%18d\n",AnnoIntroducido); return 31; break;
    }
}

/*
    Calcular el Día de la semana con la que comienza el dia 1 del mes y año dado.
    Se ha utilizado el algoritmo de la congruencia de zeller, que dice:
    a = (14 - Mes) / 12
    y = Año - a
    m = Mes + 12 * a - 2

    Para el calendario Gregoriano:
    d = (día + y + y/4 - y/100 + y/400 + (31*m)/12) mod 7
*/

int T_FechaPlan::CalcularDiaSemana(){
  int a=0;
  int y=0;
  int m=0;
  int d=0;

  a = (14 - MesIntroducido) / 12;
  y = AnnoIntroducido - a;
  m = MesIntroducido + 12 * a - 2;

   d = ((1 + y + y/4 - y/100 + y/400 + (31*m)/12) % 7);

  if(d==0){ //con Zeller el Domingo toma valor 0, nos interesa que valga 7.
    d=7;
  }
  return d;
}

/*
 * Función que Dibuja el Calendario recibiendo como valores los dias que
 * tiene el mes y el Dia de la semana en que comienza el mes.
 */
void T_FechaPlan::DibujarCalendario(){
  int posicion; //utilizado para saber que dia de la semana estamos dibujando.
  int auxiliar=DiaIntroducido; //Variable que almacenara el dia en que tenemos que empezar a dibujar C o D.

    if(ContadorMes==1){ //ContadorMes nos dira si estamos dibujando el Calendario 1 o el 2.
        DiaDibujado=0;  //Contador que nos indica cuantos dias del plan llevamos dibujados en el calendario.
        posicion=1;     //Inicializamos posicion en 1 (Lunes).
      /*Dibujamos la Zona superior del calendario.*/

        printf ("LU  MA  MI  JU  VI | SA  DO\n");

      /*Dibujamos la primera parte del calendario. "Puntos" hasta el primer dia del mes o del plan.*/
        for (int i=1; i<DiaSemana; i++){
          printf (" . ");          //desde 1 hasta el primer dia de la semana escribe " . "
          if (posicion%7==5){      //Si estamos en la quinta posicion (es decir viernes)
            printf ("|");          //tenemos que poner "|"
          }
          printf (" ");            //espacio entre posiciones
          posicion=posicion+1;     //Sumamos 1 a la posicion para representar los 7 dias de la semana.
        }

      /*Dibujamos la segunda parte del calendario. Son los dias que tiene el mes*/
        for(int i=1;i<=DiasMes;i++){
          if((auxiliar==i)&&(DiaDibujado<10)){ //Si el Diaintroducido coincide con el numero del dia y llevamos menos de 10 dias dibujados (C o D)
            switch(Es_CoD[DiaDibujado]){        //Dibujamos C o D segun lo que contenga Es_CoD[contador de dias dibujados] (que va de 0 a 9).
              case 0: printf(" C"); break;
              case 1: printf(" D"); break;
            }
            DiaDibujado=DiaDibujado+1;   //Añadimos 1 al contador de dias dibujados.
            auxiliar=auxiliar+1;
          }else{                    //si no coincide el dia introducido escribimos el numero del día normal.
            printf("%2d",i);
            }
          if (posicion%7==0){      //si la posicion es 7(domingo) tenemos que saltar de linea
            printf("\n");
          }else if(posicion%7==5){ //si la posicion es 5(Viernes) tenemos que poner " | "
            printf (" | ");
          }else{
            printf("  ");          //espacio entre posiciones
          }
            posicion=posicion+1;
        }

      /* Acabados los dias del mes, colocamos "." y "|" hasta acabar el mes */
         while (posicion%7!=1){    //mientras la posicion sea distinta de 1
           if(posicion%7==0){      //si es domingo imprimira un punto y borde lateral.
            printf(" .");
           }
           else{
           printf(" . ");
           }
           if (posicion%7==5){     //si la posicion es 5(Viernes) tenemos que poner "| "
             printf ("| ");
           }else{
             printf (" ");
           }

           posicion=posicion+1;
         }
         printf ("\n"); //salto de linea final para diferenciar el dibujo del calendario de otras zonas.

  /*Dibujamos el Calendario Nº2 si lo hubiera*/

      }else{
        auxiliar=1; //Auxiliar lo inicializamos a 1 ya que tenemos que continuar dibujando C o D en el primer dia del siguiente mes.
        posicion=1; //Volvemos a inicializar posicion a 1 para que el primer dia vuelva a ser Lunes independientemente de como acabara antes.

      /*Dibujamos la Zona superior del calendario.*/
        printf ( "LU  MA  MI  JU  VI | SA  DO\n");

      /*Dibujamos la primera parte del calendario.*/
        for (int i=1; i<DiaSemana; i++){
          printf (" . ");          //desde 1 hasta el primer dia de la semana escribe " . "
          if (posicion%7==5){    //Si estamos en la quinta posicion (es decir viernes)
            printf ("|");          //tenemos que poner "|"
          }
          printf (" ");            //espacio entre posiciones
          posicion=posicion+1;
        }

      /*Dibujamos la segunda parte del calendario. Son los dias que tiene el mes.*/
        for(int i=1;i<=DiasMes;i++){
            if((auxiliar==i)&&(DiaDibujado<10)){ //Continuacion del calendario 1. Solo acabara cuando hayamos dibujado C y D de los 10 dias (va de 0 a 9)
            switch(Es_CoD[DiaDibujado]){
              case 0: printf(" C"); break;
              case 1: printf(" D"); break;
            }
            DiaDibujado=DiaDibujado+1;
            auxiliar=auxiliar+1;
          }else{
            printf("%2d",i);       //si no coincide el dia introducido escribimos el numero del día normal.
            }
          if (posicion%7==0){      //si la posicion es 7(domingo) tenemos que saltar de linea
            printf("\n");
          }else if(posicion%7==5){ //si la posicion es 5(Viernes) tenemos que poner " | "
            printf (" | ");
          }else{
            printf("  ");          //espacio entre posiciones
          }
            posicion=posicion+1;
        }
      /* Acabados los dias del mes, colocamos "." y "|" hasta acabar el mes */
         while (posicion%7!=1){    //mientras la posicion sea distinta de 1
           if(posicion%7==0){      //si es domingo imprimira un punto y borde lateral.
            printf(" .");
           }
           else{
           printf(" . ");
           }
           if (posicion%7==5){     //si la posicion es 5(Viernes) tenemos que poner "| "
             printf ("| ");
           }else{
             printf (" ");         //espacio entre posiciones
           }
           posicion=posicion+1;
         }
         printf ("\n"); //salto de linea final para diferenciar el dibujo del calendario de otras zonas.
  }
}
/*
 * Funcion de Inicio Plan. Pedimos el Dia,mes,año al usuario y
 * comprobamos que es una fecha correcta.
 */
void T_FechaPlan::InicioPlan(){
int DiasMesIntroducido; //Creamos esta variable en vez de utilizar DiasMes ya que una fecha introducida
                        //puede ser valida pero a la vez no ser correcta debido a que no es igual o superior a la actual.
do{
  printf("%cCUANDO QUIERES COMENZAR EL PLAN DE ENTRENAMIENTO?\n",168);
  printf("(introducir una fecha igual o superior a la actual)\n");
    /* Pedimos el dia, solo es valido valores entre 1 y 31*/
    do{
      printf(">>> %cDia(1..31): ",168);
      scanf("%d",&DiaIntroducido);
      fflush(stdin);
      if((DiaIntroducido<1)||(DiaIntroducido>31)){
          printf("Error: Dia elegido no valido\n");
        }
    }while((DiaIntroducido<1) || (DiaIntroducido>31));
    /*Pedimos el Mes, solo son validos valores entre 1 y 12*/
    do{
      printf(">>> %cMes?(1..12): ",168);
      scanf("%d",&MesIntroducido);
      fflush(stdin);
      if((MesIntroducido<1)||(MesIntroducido>12)){
          printf("Error: Mes elegido no valido\n");
        }
    }while((MesIntroducido<1)||(MesIntroducido>12));
    /*Pedimos el año*/
    printf(">>> %cA%co?(Formato Ejemplo:2017): ",168,164);
    scanf("%d",&AnnoIntroducido);
    fflush(stdin);
    /*Con los 3 datos podemos calcular los dias que tiene el mes*/
    DiasMesIntroducido=DiasTieneMes();
    /*Primero comprobamos que el mes introducido tenga el dia introducido, por si se da el caso de introducir 30 de febrero*/
    if(DiaIntroducido>DiasMesIntroducido){
      system("cls");
      printf("Error: El mes introducido del a%co %d no tiene tantos dias.\n\n",164,AnnoIntroducido);
    }
}while(DiaIntroducido>DiasMesIntroducido); //Si no se cumple volveremos a pedir los datos.
  /*Ahora comprobamos que la fecha sea superior a la actual, si no lo es volveremos a llamar a la función*/
  if (FechaCorrecta()==true){
      system("cls");
      printf("El plan de entrenamiento comenzara el %2d/%2d/%d.\n",DiaIntroducido,MesIntroducido,AnnoIntroducido);
      printf("Fecha guardada correctamente.\n");
      FechaGuardada=true; //Al almacenar una fecha correctamente tenemos que cambiar FechaGuardada de false a true.
  } else {
     system("cls");
     printf("Error: La fecha introducida tiene que ser igual o superior a la Actual\n\n");
     InicioPlan();
  }
}
  void T_FechaPlan::MostrarPlan(T_CarreraDescanso AlmacenarCD,bool PlanGuardado){
  //Guardamos el contenido pasado por refencia a una variable de T_FechaPlan con la que poder trabajar con comodidad en otras funciones.
  for (int i=0;i<10;i++){
  Es_CoD[i]=AlmacenarCD[i];
  }
  if ((FechaGuardada==false)||(PlanGuardado==false)){ //Unicamente mostraremos el calendario si se ha introducido un plan y una fecha.
      printf("Error: No has introducido Plan de Entrenamiento o Fecha de Inicio\n");
  }else{

    printf("MOSTRAR CALENDARIO DEL PLAN %2d/%2d/%d \n",DiaIntroducido,MesIntroducido,AnnoIntroducido);
    printf("      C=Entrenamiento  ---  D=Descanso \n\n");

    DiaSemana = CalcularDiaSemana(); //Calculamos el dia de la semana en que comienza el mes introducido y lo almacenamos en DiaSemana.
    DiasMes = DiasTieneMes();  //Calculamos los dias que tiene el mes introducido y lo almacenamos en DiasMes.

  /*Comprobamos si tenemos que dibujar 1 calendario o 2.*/
    if(DiasMes-DiaIntroducido>=10){  //Si los dias del mes, menos los dias introducidos son al menos 10, nos bastara con 1 calendario.
      ContadorMes=1; //Indicamos que tenemos que dibujar el calendario 1.
      DibujarCalendario();

    }else{           //Si por el contrario son menos de 10, deberemos dibujar 2 calendario.
      ContadorMes=1; //Indicamos que tenemos que dibujar el calendario 1.
      DibujarCalendario();
      printf("\n");
  /*Comprobamos cual es el mes siguiente*/
      if(MesIntroducido==12){ //Si el Mes es Diciembre(12), el siguiente mes sera Enero(1)
        MesIntroducido=1;    //Por lo que le indicamos que el siguiente mes es 1 y no 13 como seria si no tubieramos este IF.
        AnnoIntroducido=AnnoIntroducido+1; //Si pasamos diciembre estariamos en el siguiente año, por lo que añadimos 1.
      }else{
        MesIntroducido=MesIntroducido+1; //El mes a dibujar es el siguiente que teniamos en el calendario 1, por lo que le sumamos 1.
       }
      ContadorMes=2; //Indicamos que tenemos que dibujar el calendario 2.
      DiaSemana = CalcularDiaSemana(); //calculamos en que dia de la semana comienza el mes del calendario 2.
      DiasMes = DiasTieneMes();        //calculamos los dias que tiene el mes del calendario 2.
      DibujarCalendario();

    }
  /*Tras acabar de dibujar los calendarios, volvemos a poner el mes y año a sus valores iniciales(los introducidos por el usuario).
    De esta manera nos ahorramos el tener que crear variables extra para almacenar los datos introducidos por el usuario*/
      if(MesIntroducido==1){
        MesIntroducido=12;
        AnnoIntroducido=AnnoIntroducido-1;
      }else{
        MesIntroducido=MesIntroducido-1;
      }
  }
}