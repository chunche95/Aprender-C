typedef struct
{
    int idSerie;
    char nombre[50];
    char genero[20];
    int cantidadTemporadas;
    int estado;
}eSerie;

void inicializarSeriesEstado(eSerie[], int);
void inicializarSeriesHardCode(eSerie[]);
void mostrarListaSeries(eSerie[], int);
void AltaSeries(eSerie[], int);
void BajaSeries(eSerie[], int);
void ModificacionSeries(eSerie[]);
//void ListaSeriexUsuario(eSeries[], int, eUsuario[], int);