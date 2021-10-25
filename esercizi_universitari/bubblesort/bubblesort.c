#include <stdio.h>
#define L 6

int main(){
    int i, j, c;
    int temp;
    int sequence[L] = {5, 7, 6, 4, 9, 2};

    for(i=L - 1; i > 0; i--){
        for(j=0; j < i; j++){
           if(sequence[j] > sequence[j+1]){
               temp = sequence[j+1];
               sequence[j+1] = sequence[j];
               sequence[j] = temp;
           }
        }
    }
    
    for(c=0; c < L-1; c++){
        printf("%d, ", sequence[c]);
    }
    printf("%d \n", sequence[L-1]);
}