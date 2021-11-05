#include <stdio.h>

#define LIMIT 100

int main()
{
    
    int squaredSum;
    int summedSquares;

   squaredSum = (LIMIT * (LIMIT + 1)) / 2; 
   squaredSum *= squaredSum;

    summedSquares = 0;
    for ( int i = 0; i <= LIMIT; i++)
        summedSquares += i * i;

    printf("The difference is: %d\n", squaredSum - summedSquares);
}

