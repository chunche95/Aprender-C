/*
 * Interfaz.
 * 
 *  #pragma --> El comando del preprocesador #pragma permite al programador entregar un comando al compilador
 * que éste podrá ejecutar para realizar ciertas tareas. Dado que las capacidades de #pragma de cada compilador
 * son específicas y definidas por su implementación, el uso de etiquetas #pragma cambia de un compilador a otro.
 * 
 * Esta directiva imprime en la consola de compilación un mensaje informacional; este mensaje no resulta ni en un 
 * error de compilación ni en una advertencia. Puede usarse, por ejemplo, para dar aviso al momento de agregar 
 * cierta cabecera que ésta requiere la activación de alguna directiva especial del compilador.
 * 
 * Pragma es una directiva del procesador no estándar pero con un extenso soporte. Está diseñado para asegurar  
 * que el código fuente que lo invoca sea incluido una única vez. Así pues, #pragma once sirve al mismo propósito  
 * que la protección de macros, pero con una menor cantidad de código y sin la posibilidad de que lleguen a coincidir
 * las identificaciones. 
 * 
 * El código con #pragma once sería:
 *  +------------------ abuelo.h 
 *  | #pragma once     |
 *  |                  |
 *  | struct foo{      |
 *  |   int miembro;   |
 *  | };               |
 *  +------------------+
 * 
 *  +--------------------- padre.h
 *  | #include "abuelo.h" |
 *  +---------------------+
 * 
 *  +--------------------- hijos.c
 *  | #include "abuelo.h" |
 *  | #include "padre.h"  |
 *  +---------------------+
 * 
 */

#pragma once 

const int numGrados=10;
typedef float TipoPolinomio[numGrados];
typedef struct TipoOperacion{
    void SumarPolinomio (TipoPolinomio P, float coeficiente, int n);
    float Evaluar (const TipoPolinomio P, int b);
    void Imprimir (const TipoPolinomio P);
    TipoPolinomio Pol;
};