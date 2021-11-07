#include <stdio.h>

/*

A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,

a2 + b2 = c2
For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.

*/

#define MAX_RANGE 1000
int main()
{
    long a, b, c;
    int found;
    
    found = 0;
    for (c = 1; c < MAX_RANGE && found == 0; c++)
    {
        for (b = 1; b < c && found == 0; b++)
        {
            for (a = 1; a < b && found == 0; a++)
            {
                if ( (a + b + c == 1000) && ((a * a + b * b) ==  (c * c)) )
                {
                    found = 1;
                    printf("The triplet is: %ld, %ld, %ld\n", a, b, c);
                    printf("The product is: %ld\n", a*b*c);
                }
            }
        }
    }

}