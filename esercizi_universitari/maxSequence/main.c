#include <stdio.h>
#define LENGTH 10

int main(){
    int sequence[LENGTH] = {1, 3, 4, 2, 7, 8, 3, 5, 6, 9};
    int maxSequence;
    int maxParziale;
    int i;

    maxParziale = 1;
    maxSequence = 0;

    for (i=1; i < LENGTH; i++){
        if (sequence[i] > sequence[i-1]){
            maxParziale++;
        }else
        {
            maxParziale = 1;
        }

        if (maxParziale > maxSequence){
            maxSequence = maxParziale;
        }
        
    }

    printf("maxSequence: %d \n", maxSequence);
    
}