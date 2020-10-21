#pragma once

const int maxContMeses=13;
const int maxNombreg=21;
typedef char nombre_t[maxNombreg];
typedef int contadores_t[maxContMeses];

typedef struct TipoReserva{
    nombre_t nombrecompleto;
    int dia, mes, anyo, hc, duracion;
};

/* Sistema de almacenamiento de reservas a implementar. */
typedef TipoReserva RManno[maxContMeses][20];
typedef struct TAD_Gestor_Reservas{
    void iniciarCalendarios(int mmi, int ddi);
    bool crearReserva(nombre_t nomb, int dd, int mm, int aa, int hc, int dur);
    void mostrarReservasMes(int mm, int aa);
    void guardarReserva(int mm, TipoReserva reserv);
    int buscarReserva(int dd, int mm, int aa, int hc);
    bool borrarReserva(nombre_t nomb, int dd, int mm, int aa, int hc);
    void mostrarReservasDia(int dd, int mm, int aaaa);

    private:
    void iniciarAuxReserva();
    bool compararReservas(const TipoReserva reserva1, const TipoReserva reserva2);
    void verReservasDia(int dd,int mm, int contador);
    void dibujarR(int dd, int mm, int contador);
    bool noSolapa(int dd, int mm, int hc, int dur, int contador);
    bool esReservable(int dd, int mm, int aa, int hc, int dur);
    bool cambiarValorDiaMes(int dd, int mm, int valor);
    int horasOcupadas(int dd, int mm);
};