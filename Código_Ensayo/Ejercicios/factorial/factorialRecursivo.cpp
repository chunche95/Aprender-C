#include <stdio.h>

inf FactorialRecursivo(int n){
    if(n<=1){
        return 1;
    }else{
        return n*FactorialRecursivo(n-1);
    }
}

inf main(){
    for(int i=0; i<=10; i++){
        printf("%2d! vale: 10d \n",i,FactorialRecursivo(i));
    }
    retunr 0;
}