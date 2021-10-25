#include <stdio.h>
#include <stdlib.h>

#define MAX_LUNGHEZZA_STRINGHE 30


int main(){
    char TestoA[MAX_LUNGHEZZA_STRINGHE] = "alternativamente"; 
    char TestoB[MAX_LUNGHEZZA_STRINGHE] = "eternita";

    int cursoreA, cursoreB;
    int cursoreAParziale;

    int lunghezzaMassima;
    int lunghezzaCorrente;

    int fineSequenzaMassima;

    lunghezzaMassima = 0;
    cursoreA = 0;
    while ('\0' != TestoA[cursoreA])
    {
        lunghezzaCorrente = 0;
        cursoreAParziale = cursoreA;
        cursoreB = 0;
        while ('\0' != TestoB[cursoreB])
        {
            if (TestoA[cursoreAParziale] == TestoB[cursoreB]){
                lunghezzaCorrente++;
                cursoreAParziale++;
            }
            else
            {
                if (lunghezzaCorrente > lunghezzaMassima) 
                {
                    lunghezzaMassima = lunghezzaCorrente;
                    fineSequenzaMassima = cursoreAParziale;
                }

                lunghezzaCorrente = 0;
            }
            
            cursoreB++;
        }
        if (lunghezzaCorrente > lunghezzaMassima)
        {
            lunghezzaMassima = lunghezzaCorrente;
            fineSequenzaMassima = cursoreAParziale;
        }

        cursoreA++;
    }


    for (int i = lunghezzaMassima; i > 0; i--)
    {
        printf("\n%c", TestoA[fineSequenzaMassima - i]);
    }
    printf("\n");
}