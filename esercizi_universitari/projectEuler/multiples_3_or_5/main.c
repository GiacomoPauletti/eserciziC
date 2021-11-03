#include <stdio.h>

#define MAX_NUMBER 1000
#define DIVISIOR1 3
#define DIVISIOR2 5

int main()
{
    int sum;
    int number;

    sum = 0;
    for (number = 0; number < MAX_NUMBER; number++)
    {
        if (number % DIVISIOR1 == 0 || number % DIVISIOR2 == 0)
        {
            sum += number;
        }
    }

    printf("The sum is: %d\n", sum);
}