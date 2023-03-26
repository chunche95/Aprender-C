#include <stdio.h>

int main() {
    int edad, intentos = 3;
    char passwd, respuesta;
    printf("Introduzca su  edad? ");
    scanf("%i", &edad);
    printf(&edad);
    while (intentos != 0)
    {
        if (&edad < 18)
        {
            printf("Acceso no autorizado \n");
            intentos--;
            return 1;
        } else if ( &edad >= 18  && &edad < 30 )
        {
            printf("¿Tienes acceso autorizado? S/N");
            scanf("%c", respuesta);
            if (respuesta == 'S' || respuesta == 's')            
            {
                printf("Acceso autorizado!");
            } else {
                printf("Saliendo del programa");
                return 1;
            }            
        } else {
            printf("Introduzca la contrasennia de acceso:");
            scanf("%c", &passwd);
            if (&passwd == 'acceso')
            {
                printf("Acceso autorizado \n");                
            } else {
                intentos--;
                printf("Acceso no autorizado \n");
                printf("Numero de intentos disponible" + intentos);
                if (&intentos == 0 )
                {
                    printf("Acceso bloqueado \n");
                    return 1;
                }
                                        
            }        
        }
    }    
}