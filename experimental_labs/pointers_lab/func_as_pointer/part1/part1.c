#include <stdio.h>

/* ----------------------FUNCTION AS POINTER------------------------- */
/*
 * PARTE1:
 * programma per vedere se una funzione è interpretata come pointer
 * quando non viene chiamata ma viene usato solo il suo nome
 * (ovvero "funzione" e non "funzione()")
 * RISPOSTA: viene trattato come puntatore
 * 
 * PARTE 2:
 * viene verificato che tipo di puntatore è funzione
 * 
 */

int function(int par1, char par2);
char function2(float par1);
void function3();

int main(){
    printf("\nFUNCTION POINTER: %p\n\n", function);

    printf("FUNCTION SIZE: %lu\n\n", sizeof(function));

}

int function(int par1, char par2){
    printf("In function : 'function'");
    return 0;
}

char function2(float par1){
    printf("In function : 'function2'");
}

void function3(){
    printf("In function : 'function3'");
}