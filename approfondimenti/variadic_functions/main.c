#include <stdio.h>

int variadic_function(int par1, int par2, ...);

int main(){
    variadic_function(10, 20, "stringa", 37.2);

    variadic_function(10, 20, 'c', (long int) 32895492);
}

int variadic_function(int par1, int par2, ...)
{
    printf("variadic function called");
}