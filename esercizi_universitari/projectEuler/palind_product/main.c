#include <stdio.h>

#define DIGIT_NUMBER 3

int isPalindromicNumber(int number);

int power(int base, int exponent);

int main()
{
    int factor1, factor2;
    int digitCounter;
    int maxNumber;

    int palindromicNumber;

    maxNumber = 10;
    digitCounter = 1;
    while (digitCounter < DIGIT_NUMBER)
    {
        maxNumber *= 10;
        digitCounter++;
    }

    palindromicNumber = 0;
    for (factor1 = 101; factor1 < maxNumber; factor1++)
        for (factor2 = 1; factor2 < maxNumber; factor2++)
        {
            if (isPalindromicNumber(factor1 * factor2))
                if (factor1 * factor2 > palindromicNumber)
                    palindromicNumber = factor1 * factor2; 
        }

    printf("The largest palindromic product is: %d\n", palindromicNumber);
}

int isPalindromicNumber(int number)
{
    int numberCursor1, numberCursor2;
    int digit1, digit2;
    int correct;

    int digitCounter;
    int comparedNumber;

    comparedNumber = 10;
    digitCounter = 1;
    while( number >= comparedNumber )
    {
        comparedNumber *= 10;
        digitCounter++;
    }

    numberCursor1 = 0;
    numberCursor2 = digitCounter - 1;
    correct = 1;
    while (numberCursor2 > numberCursor1 && correct == 1)
    {
        digit1 = (number / power( 10, numberCursor1) ) % 10;
        digit2 = (number / power( 10, numberCursor2) ) % 10;

        if (digit1 != digit2) correct = 0;

        numberCursor1++;
        numberCursor2--;
    }

    return correct;
}

int power(int base, int exponent)
{
    int expCounter;

    if (exponent == 0) return 1;

    for (expCounter = 1; expCounter < exponent; expCounter++)
        base *= 10;

    return base;
}