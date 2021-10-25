#include <stdio.h>

int printLine(int numeroIniziale, int numeroFinale){
    int numeroRighe;
    int rigaAttuale;
    int ripetitore;
    
    numeroRighe = numeroIniziale - numeroFinale;

    for(rigaAttuale = 0; rigaAttuale <= numeroRighe - 1; rigaAttuale++){
        printf("%d", numeroIniziale - rigaAttuale);
    }

    for (ripetitore=0; ripetitore < (2 * numeroFinale) - 1; ripetitore++){
        printf("%d", numeroFinale);
    }

    for(rigaAttuale = numeroRighe - 1; rigaAttuale >= 0; rigaAttuale--){
        printf("%d", numeroIniziale - rigaAttuale);
    }

    printf("\n");

}


int main(){
    int numero;
    int riga;
    int currentNumber;

    printf("Inserisci un numero compreso tra 1 e 9 -> ");
    do
    {
        scanf("%d", &numero);
    }while(numero < 1 || numero > 9);

    for (riga = 0; riga < numero; riga++){
        printLine(numero, numero - riga);
    }

    for (riga = numero - 2; riga >= 0; riga--){
        printLine(numero, numero - riga);
    }
}
