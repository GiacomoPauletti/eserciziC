#include <stdio.h>

#define NUMBER 600851475143
#define SQRT_OF_NUMBER 775146
/* non è proprio la radice esatta, un po di più, ma almeno riduce i
 * conti */

int findNumberDigits(long int number);

int isPrime(long int number);

int main()
{
    int factor;
    int maxPrimeFactor;

    int digitNumber;
    int digitLimit;
    long int comparedNumber;
    int digitCounter;
    

    digitNumber = findNumberDigits(NUMBER);
    digitLimit = ( digitNumber + 1 ) / 2;

    maxPrimeFactor = 1;
    for (factor = 2; factor < SQRT_OF_NUMBER; factor++)
    {
        if (NUMBER % factor == 0 && isPrime(factor))
            if (maxPrimeFactor < factor) maxPrimeFactor = factor;
    }

    printf("The largest prime factor is: %d\n", maxPrimeFactor);
}

int isPrime(long int number)
{

    int digitNumber;
    int digitLimit;
    int digitCounter;
    long int comparedNumber;

    int divisor;
    
    digitNumber = findNumberDigits(number);

    if (digitNumber != 1)
    {

        digitLimit = ( digitNumber + 1 ) / 2;
        /* il numero limite di cifre serve per creare una potenza di 10
        * con quel numero di cifre. Quest'ultimo numero sarà il numero
        * fino al quale si cercheranno i numeri primi, dopo di ciò
        * non ha senso continuare, perchè si ha superato la radice del
        * numero e quindi i numeri trovati avranno un corrispettivo 
        * fattore che per forza si ha già trovato
        * 
        * Il + 1 è dato dal fatto che il " / 2" tronca il numero 
        * (11 / 2 = 5) aggiungendo 1 si arrotonda per eccesso (12 / 2 = 6)
        */
        
        comparedNumber = 10;
        for (digitCounter = 1; digitCounter < digitLimit; digitCounter++)
        {
            comparedNumber *= 10;
        }
    }else comparedNumber = number - 1;

    divisor = 2;
    while (divisor <= comparedNumber)
    {
        if (number % divisor == 0) return 0;
        divisor++;
    }

    return 1;
}

int findNumberDigits(long int number)
{
    int digitCounter;
    long int comparedNumber;


    digitCounter = 1;
    comparedNumber = 10;


    while (number >= comparedNumber )
    {
        digitCounter++;
        comparedNumber *= 10;
    }
    return digitCounter;
}