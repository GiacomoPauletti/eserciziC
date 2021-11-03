#include <stdio.h>

#define NUMBER_LIMIT 4000000 //4mln

int main()
{
    int number1, number2;
    int temporaryNumber;
    int sum;

    number1 = 1;
    number2 = 2;

    while (number2 < NUMBER_LIMIT)
    {
        if (number2 % 2 == 0) sum += number2;

        temporaryNumber = number2;
        number2 += number1;
        number1 = temporaryNumber;
    }

    printf("The sum is: %d\n", sum);
}