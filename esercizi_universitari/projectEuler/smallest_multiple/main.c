#include <stdio.h>

#define MAX_NUMBER 20

int main()
{
    long int smallestMultiple;

    int number, factorCursor;
    int revisedNumber;
    int factors[MAX_NUMBER];
    int factorNumber;
    int factorCounter;
    int isDivisor;

    factorNumber = 0;
    smallestMultiple = 1;
    for (number = 2; number <= MAX_NUMBER; number++)
    {
        isDivisor = 0;
        if (smallestMultiple % number == 0) isDivisor = 1;

        revisedNumber = number;
        for (factorCounter = 0; factorCounter < factorNumber; factorCounter++)
        {
            if (revisedNumber % factors[factorCounter] == 0)
                revisedNumber /= factors[factorCounter];
        }

        if (isDivisor == 0)
        {
            smallestMultiple *= revisedNumber;
            printf("%ld | %d\n", smallestMultiple, revisedNumber);
            factors[factorNumber] = revisedNumber;
            factorNumber++;
        }

    }

    printf("The smallest multiple is: %ld\n", smallestMultiple);
}