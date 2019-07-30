#pragma once
#include "gestion.h"

const int longitudFila = 27;

typedef enum TipoSemana {LU,MA,MI,JU,VI,SA,DO};
typedef enum TipoNombreMes {ENERO,FEBRERO,MARZO,ABRIL,MAYO,JUNIO,JULIO,AGOSTO,SEPTIEMBRE,OCTUBRE,NOVIEMBRE,DICIEMBRE};
typedef char TipoFila_str [longitudFila+1];
typedef char TipoSimbolo_str[2];
typedef struct TipoMesAnyo{ int mes; int anyo; };
typedef struct TipoNumSemanasDelMes { int semanas; int resto; };
typedef struct TipoCalendario{ 
    bool EsCorrecta(int dia, int mes, int anyo); 
    bool EsBisiesto(int anyo);
    void PedirFecha(TipoMesAnyo & fecha);
    void ImprimirCalendario (int unidad, int mes, int anyo, TipoVectorVenta vectorVenta);
    private:
        int DiaDelMes (TipoNombreMes mes, int anyo);
        TipoDiaSemana DiaSemana (int mes, int anyo);
        TipoNumSemanaDelMes CalcularNumSemanas (int dias, int primero);
        TipoNombreMes_str NombreDelMes (TipoNombreMes mes);
        void ImprimirLineaSimbolos (int longitud, TipoSimbolo_str simbolo);
        coid ImprimirSeparador (int & columna, int & fila, int semanas);
};