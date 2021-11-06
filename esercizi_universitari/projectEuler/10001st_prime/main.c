#include <stdio.h>

#define PRIME_INDEX 10001

int findNumberDigits(long int number);

int isPrime(long int number);

int main()
{
    int primeCounter;
    long int currentNumber;

    currentNumber = 2;
    primeCounter = 0;

    while( primeCounter < PRIME_INDEX )
    {
        if (isPrime(currentNumber))
        {
            primeCounter++;

        }
        currentNumber++;
    }

    printf("The %dth prime is : %ld\n", PRIME_INDEX, currentNumber - 1);

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