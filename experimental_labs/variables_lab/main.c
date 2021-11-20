#include <stdio.h>

#define MY_MACRO(tk1, tk2) tk1 ## tk2

int main()
{
    int a,b;

    a = 1;
    b = 2;
    printf("%d", MY_MACRO(a, b));
}