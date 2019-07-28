typedef struct
{
    int idUsuario;
    char nombre[50];
    int idSerie;
    int estado;
}eUsuario;

void inicializarUsuariosEstado(eUsuario[], int);
void inicializarUsuariosHardCode(eUsuario[]);
void mostrarListaUsuarios(eUsuario[], int);
void AltaUsuario(eUsuario[], int);
void BajaUsuario(eUsuario[],int);
void ModificacionUsuario(eUsuario[]);
/*
 * void ListaUsuarioxSerie(eUsuario[], int,  eSeries[], int);
 */