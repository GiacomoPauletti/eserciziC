#include <stdio.h>

#define NUM_COLONNE 5
#define NUM_RIGHE 3

int main(){
    int matrice[NUM_RIGHE][NUM_COLONNE] = 
    {
        { 1, 6, 4, 5, 3},
        { 6, 54 , 3, 23 , 9},
        { 4, 65, 3, 43, 10}
    };

    int cursorePrincipale;
    int elementoPrincipale;

    int cursoreRiga;
    int cursoreColonna;

    int elementoTrovato;
    int elementoComuneTrovato;

    
    elementoComuneTrovato = 0;
    for (cursorePrincipale = 0; cursorePrincipale < NUM_COLONNE && elementoComuneTrovato == 0; cursorePrincipale++)
    {
        elementoPrincipale = matrice[0][cursorePrincipale];

        elementoTrovato = 1;
        for (cursoreRiga = 1; cursoreRiga < NUM_RIGHE && elementoTrovato == 1; cursoreRiga++)
        {
            elementoTrovato = 0;
            for (cursoreColonna = 0; cursoreColonna < NUM_COLONNE && elementoTrovato == 0; cursoreColonna++)
                if (matrice[cursoreRiga][cursoreColonna] == elementoPrincipale)
                    elementoTrovato = 1;

        }

        if (elementoTrovato == 1)
            elementoComuneTrovato = 1;
    }
    
    if (elementoComuneTrovato == 1){
        printf("E' stato trovato un elemento comune a tutte le righe dell'array\n");
        printf("L'elemento è: %d\n", elementoPrincipale);
    }
    else
        printf("Niente in comune è stato trovato\n");
}

