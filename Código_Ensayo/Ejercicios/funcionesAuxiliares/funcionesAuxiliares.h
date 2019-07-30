/*
 * Fichero de caecera creado por el usuario con funciones auxiliares.
 */

int DuplicarValor(int numero){
    return numero*2;
}

float AreaTriangulo(float base, float altura){
    return (base*altura)/2;
}

int Maximo(int primerValor, int segundoValor){
    if(primerValor >= segundoValor){
        return primerValor;
    }else{
        return segundoValor;
    }
}