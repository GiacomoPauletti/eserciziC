#include <stdio.h>
#define LENGTH 5

int main(){
    int sequence[LENGTH];
    int i, j;
    printf("Scrivi %d numeri separati da virgole (,) ", LENGTH);
    for (i=0; i<=LENGTH-2; i++){
        scanf("%d,", &sequence[i]);
    }
    scanf("%d", &sequence[LENGTH-1]);

    for (j=0; j < LENGTH; j++){
        printf("%d: %d\n", j, sequence[j]);
    }
}

/*
    18, 43, 134, 542, 532 -> si può popolare l'array scrivendo così in input (spazi facoltativi)

*/