/*
 * Interfaz del módulo calendario.
 * Este módulo define el tipo abstracto calendario que almacena la representación de los días usados.
 */

#pragma once

/* Nº de columnas que contiene el cuerpo del mes. */
const int nColumnas = 7;
const int MaxNombreMes = 15;

typedef char nombreMes_t[maxNombreMes];
typedef nombreMes_t listaNombres_t[13];
typdef int diasMes[45];

typedef struct TAD_Calendario{
    /* variables de entorno. */
    int zeta, totalDias;
    diasMes mesCalendario;
    bool setDia(int dia, int valor);
    int DiaSemana(int anyo, int mes, int dia);
    int TotalDiasMes(int m, int a);
    void ImprimirDiasCalendario();
    void RellenarMesCalendario(int m, int a);

    private:
    bool valida;
    int nFilas;
    int mes;
    int anno;
    void ImprimirCabecera();
};