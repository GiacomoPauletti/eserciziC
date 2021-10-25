#include <stdio.h>

/* ----------------------FUNCTION AS POINTER------------------------- */
/*
 * PARTE 3: ARITMETICA
 * Si prova a sommare valori al puntatore alla funzione, per vedere 
 * cosa si ottiene
 */

int function(int par1, char par2);
char function2(float par1);
void function3();

int main(){
    printf("\nARITHMETICS WITH FUNCTION: %c\n\n", *(function + 10));
    printf("\nARITHMETICS WITH FUNCTION: %c\n\n", *(function) + 10);
    /*RISULTATO:
     * Il risultato è piuttosto banale e scontato, anche prevedibile.
     * Sommando n al puntatore non si cambia il suo tipo quindi si ha
     * il solito warning di incompatibilità tra "%c" e "int (*)(int, char)"
     * 
    */

    return 0;
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