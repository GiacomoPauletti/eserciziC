#include <stdio.h>

/* ----------------------FUNCTION AS POINTER------------------------- */
/*
 * PARTE 4: CREARE I TIPI DELLE FUNZIONI
 */

int function(int par1, char par2);
char function2(float par1);
void function3();

int main(){

    /*typedef permette di creare un nuovo tipo di dato usato per salvare le funzioni in una variabile
     *La sintassi è la seguente:
     *      typedef returnType (* functionType)(param1Type param1Name, 
     *                                          param2Type param2Name, ...)
     *(* functionType) indica di che la variabile che conterrà la funzione
     *sarà di tipo "functionType" e sarà un puntatore
     */

    typedef int (* printer_t)(int i, char c);;

    printer_t f = &function; 

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