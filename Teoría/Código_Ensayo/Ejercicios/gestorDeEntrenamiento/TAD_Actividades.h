#pragma once

/*
 * T_AlmacenarActividades es un vector de 10 espacios de 1000 caracteres cada uno.
 */

typedef char T_CaracteresMaximos[1001];
typedef T_CaracteresMaximos T_AlmacenarActividades[10];

/*
 * T_CarreraDescanso es una enumeracion de 10 espacio cuyo contenido puede ser C o D.
 */

typedef enum T_CoD{C,D};
typedef T_CoD T_CarreraDescanso[10];

typedef struct T_Actividades{
    /* Variable que almacena la descripcion del plan de entrenamiento. */
    T_AlmacenarActividades GuardarDatos;
    /* Variable de tipo enum con los valores posibles C y D. */
    T_CarreraDescanso TipoCD; 
    /* Almacena True-> Si se introducen datos y False en caso contrario */
    bool PlanGuardado;

    /*
     * Funciones para las opciones 1 y 2.
     */
    void InicializarPlan();
    void IntroducirPlan();
    void ListarPlan();
};
