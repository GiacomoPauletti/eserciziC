#include <stdio.h>

/* ----------------------FUNCTION AS POINTER------------------------- */
/*
 * PARTE1:
 * programma per vedere se una funzione è interpretata come pointer
 * quando non viene chiamata ma viene usato solo il suo nome
 * (ovvero "funzione" e non "funzione()")
 * RISPOSTA: viene trattato come puntatore
 * 
 * PARTE 2: DEREFERENZIAMENTO
 * si prova a dereferenziare il puntatore alla funzione per vedere 
 * cosa si ottiene. Si vuole in particolare vedere il tipo di contenuto
 * a cui punta sfruttando i warning di gcc, che avvisano indicando
 * l'incopatibilità tra il placeholder usato in printf e il tipo dell'
 * argomento passato.
 * 
 * PARTE 3: ARITMETICA
 * Si prova a sommare valori al puntatore alla funzione, per vedere 
 * cosa si ottiene
 */

int function(int par1, char par2);
char function2(float par1);
void function3();

int main(){
    printf("\nFUNCTION POINTER: %p\n", function);

    printf("\nFUNCTION SIZE: %lu\n\n", sizeof(function));

    printf("DEREFERENCING FUNCTION: %c\n\n", *function);
    //si usa %c ma qualsiasi altro placeholder va bene

    /*RISULTATO
     * Il risultato ottenuto è 
     *      int (*)(int, char)
     * E' evidente che: 
     *      -il primo int rappresenti il return type
     *      -int, char rappresentino i tipi dei due parametri
     *       della funzione "funzione"
     * Questo possiamo verificarlo facendo la stessa operazione con due
     * funzioni diverse "function2" (return type: char, parametri: char) 
     * e "function3" (return type: void, parametri: / ) 
     * che invece danno come risultati:
     *      -function2: char (*)(float)
     *      -function3: void (*)()
     */

    printf("DEREFERENCING FUNCTION2: %c\n\n", *function2);
    printf("DEREFERENCING FUNCTION3: %c\n\n", *function3);

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