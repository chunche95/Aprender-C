#include <stdio.h> //Libreria de E/S 
#include <conio.h>

int main(){
    int i;
	for ( i = 'A'; i <= 'Z'; i++) {	    
        printf("%c - ", i);
	}
	getch();
}