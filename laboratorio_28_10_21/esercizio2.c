#include <stdio.h>

#define MAX_NUM_ELEM 50

typedef struct
{
    int sequenza[MAX_NUM_ELEM];
    int numero;
} Lista;

int main()
{

    int numeroElementi;
    int contatore;
    Lista ingresso, pari, dispari;
    ingresso.numero = 0;

    printf("Inserisci il numero di elementi che vuoi inserire (al massimo %d): ", MAX_NUM_ELEM);
    scanf("%d", &numeroElementi);

    for (contatore = 0; contatore < numeroElementi; contatore++)
    {
        printf("Inserisci il %d° elemento su %d -> ", contatore+1, numeroElementi);
        scanf("%d", &(ingresso.sequenza[contatore]));
        ingresso.numero++;
    }

    pari.numero = 0;
    dispari.numero = 0;

    for (contatore = 0; contatore < numeroElementi; contatore++)
    {
        if (ingresso.sequenza[contatore] % 2 == 0)
        {
            pari.sequenza[pari.numero] = ingresso.sequenza[contatore];
            pari.numero++;
        }
        else
        {
            printf("%d\n", ingresso.sequenza[contatore]);
            dispari.sequenza[dispari.numero] = ingresso.sequenza[contatore];
            dispari.numero++;
        }
    }

    printf("Numeri inseriti: { ");
    for (contatore = 0; contatore < numeroElementi - 1; contatore++)
        printf(" %d,", ingresso.sequenza[contatore]);
    printf(" %d}\n\n", ingresso.sequenza[contatore]);

    printf("Numeri pari: { ");
    for (contatore = 0; contatore < pari.numero - 1; contatore++)
        printf(" %d,", pari.sequenza[contatore]);
    printf(" %d}\n\n", pari.sequenza[contatore]);

    printf("Numeri dispari: { ");
    for (contatore = 0; contatore < dispari.numero - 1; contatore++)
        printf(" %d,", dispari.sequenza[contatore]);
    printf(" %d}\n", dispari.sequenza[contatore]);
}