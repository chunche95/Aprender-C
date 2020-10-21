#include <stdio.h>

int main(){
    typedef struct TipoMoneda{
        float valor;
        int cantidad;
    }

    typedef TipoMoneda TipoVectorMoneda[0];
    typedef itn TipoCantidades[0];

    TipoVectorMonedas monedas;
    TipoCantidades monedasDevueltas;

    float resto, valorPedido;
    int i;
    char c;

    /* Inicializacion */
    monedas[0].valor=2;
    monedas[1].valor=1;
    monedas[2].valor=0.5;
    monedas[3].valor=0.2;
    monedas[4].valor=0.1;
    monedas[5].valor=0.05;
    monedas[5].valor=0.02;
    monedas[5].valor=0.01;
    
    for(int i=0; i<=5; i++){
        monedas[i].cantidad=100;
    }
    do{
        printf("Introduzca el valor solicitado: ");;
        scanf("%f",&valorPedido);
        resto=valorPedido;

        for(int i=0; i<=7; i++){
            monedasDevueltas[i]=0;
        }

        while(i<5 && resto != 0.0){
            if(monedas[i].cantidad==0){
                continue;
            }
            if(resto/monedas[i].valor >= monedas[i].cantidad){
                monedasDevueltas[i]=resto/monedas[i].valor;
            }else{
                monedasDevueltas[i]=monedas[i].cantidad;
            }

            resto=resto-monedasDevueltas[i]*monedas[i].valor;
            i++;
        }

        if(resto>0.0){
            printf("Sólo podemos darle %f euros. \n", valorPedido-resto);
            printf("¿Desea continuar? (S/N) \n");
            scanf("%c",&c);
            if(c=='S'){
                for(i=0; i<=7; i++){
                    printf("%d monedas de %f euro(s) \n", monedasDevueltas[i], monedas[i].valor);
                    monedas[i].cantidad=monedas[i].cantidad-monedasDevueltas[i];
                }
            }
        }else{
            for(i=0;i<=7; i++){
                printf("%d monedas de %f euros \n", monedasDevueltas[i], monedas[i].valor);
                monedas[i].cantidad=monedas[i].cantidad-monedasDevueltas[i];
            }
        }
        printf("¿Desea realizar otra operación? (S/N) ");
        scanf("%c",&c);
    }while(c=='S');
}