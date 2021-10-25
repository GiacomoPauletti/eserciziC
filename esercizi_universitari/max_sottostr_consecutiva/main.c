#include <stdio.h>
#include <stdlib.h>

#define DIMENSIONE_ARRAY 25

int main(){
    char charArray[DIMENSIONE_ARRAY] = "arettarettorettor";

    int dimensioneEffettiva;

    int cursorePrincipale; 
    int cursoreRicorrenza;
    int cursorePeriodo;

    int periodoCorrente;
    int periodoMax;

    int inizioPeriodo;

    int ricorrenzaVerificata;

    for (dimensioneEffettiva = 0; charArray[dimensioneEffettiva ] != '\0'; dimensioneEffettiva++);

    periodoMax = 0;
    periodoCorrente = 0;
    cursoreRicorrenza = 1;
    /* posto ad 1 perchè si inizia a controllare una possibile uguaglianza tra 1 elemento dell'array e il successivo*/
    for (cursorePrincipale = 0; cursorePrincipale < dimensioneEffettiva; cursorePrincipale++)
    {
        if (charArray[cursorePrincipale] == charArray[cursoreRicorrenza])
        {
            periodoCorrente = cursoreRicorrenza - cursorePrincipale;
            if (periodoCorrente <= dimensioneEffettiva / 2)
            /* se ho trovato un possibile periodo più grande di metà array, è impossibile */
            {
                ricorrenzaVerificata = 1;
                for (cursorePeriodo = 1; cursorePeriodo < periodoCorrente && ricorrenzaVerificata == 1; cursorePeriodo++)
                {
                    if (charArray[cursorePrincipale + cursorePeriodo] != charArray[cursoreRicorrenza + cursorePeriodo])
                        ricorrenzaVerificata = 0;
                }

                if (ricorrenzaVerificata == 1 && periodoCorrente > periodoMax)
                {
                    periodoMax = periodoCorrente;
                    inizioPeriodo = charArray[cursorePrincipale];
                }
            }

        }
        cursoreRicorrenza++;
    }

    printf("\n%d\n", periodoMax);

}