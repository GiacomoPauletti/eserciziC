#include <stdio.h>

/* LE STRUTTURE SONO POINTERS?
 * Questo programma è scritto per testare se le strutture agiscono come
 * pointers quando viene usato solo il loro nome (come succede con
 * array o funzioni)
 * 
 * Si scopre poi che le strutture NON agiscono come puntatori, quindi
 * non si può nè dereferenziarli, né incrementare il valore (tramite 
 * index come con array oppure "ptr + 1" come con i puntatori).
 * Non essendoci il placeholder apposta, le struct non possono essere
 * direttamente stampate con printf.
*/

#define DIMENSIONE_SEQUENZA 10


typedef struct {
    int posizioniOccupate;
    int sequenza[DIMENSIONE_SEQUENZA];
} Lista;

int main(){
    Lista lista1;
    printf("PRINTING LISTA1: %c", lista1);
    printf("DEREFERENCING LISTA1 %c", *lista1);
    printf("ARITMETICS WITH LISTA1 %c", lista1 + 1);
}