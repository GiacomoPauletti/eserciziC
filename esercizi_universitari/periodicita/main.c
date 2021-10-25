#include <stdio.h>
#define BASE 2
#define MAX 100

int main(){
    float number;
    int integerPart;
    float decimalPart;
    float allDecimals[MAX];
    int counter;
    int bit;
    int allBits[MAX];
    int periodicityFound;
    int j;

    number = 1.0f/3.0f; 

    integerPart = number / 2;
    decimalPart =  number - (float) integerPart;
    periodicityFound = 0;
    counter = 0;
    while (decimalPart != 0.0 && !periodicityFound && counter < MAX){
        bit = (int) (decimalPart * BASE);
        allBits[counter] = bit;
        decimalPart = decimalPart * BASE - bit;
        
        for (j=0; j < counter; j++){
            if (allDecimals[j] == decimalPart){
                periodicityFound = 1;

            }
        }

        allDecimals[counter] = decimalPart;
        counter++;
        printf("bit: %d | decimalPart: %f\n", bit, decimalPart);

    }

    printf("periodicityFound %d \n", periodicityFound);
    

    return 0;
}