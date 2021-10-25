#include <stdio.h>

#define MAX_LUNGH_SEQ 60

int main(){
    char sequenza[MAX_LUNGH_SEQ] = "aaaaaaaaaaaabbbbbbbbbbbbbbcccccccccdd";
    int cursore;
    
    char carattereCorrente;
    int lunghezzaCorrente;
    
    carattereCorrente = sequenza[0];
    lunghezzaCorrente = 1;
    cursore = 1;
    while (sequenza[cursore] != '\0')
    {
        if (carattereCorrente == sequenza[cursore])
            lunghezzaCorrente++;
        else
        {
            printf("%c | %d\n", carattereCorrente, lunghezzaCorrente);
            carattereCorrente = sequenza[cursore];
            lunghezzaCorrente = 1;
        }

        cursore++;
    }

    printf("%c | %d\n", carattereCorrente, lunghezzaCorrente);
}