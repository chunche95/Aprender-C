#include <stdio.h>
#include <math.h>

tydef struct TipoPunto{
    float x;
    float y;

    void Leer();
    void Escribir();

    float Distancia(TipoPunto p);
}

typedef enum TipoPunto(PuntoNoLeido);

void TipoPunto::Leer(){
    int campos;
    campos=scanf("(%g,%g")
}