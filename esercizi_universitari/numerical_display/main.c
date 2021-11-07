#include <stdio.h>

/*
I componenti delle cifre hanno abbinato un index
     __ 0
   1|__|3  (2 la barra centrale)
   4|__|6
     5

*/

#define NUM_DIGITS 6
#define NUM_COMPONENTS 7

const char* components[NUM_COMPONENTS] = {" __", "|", "__" , "|", "|", "__", "|"};

const int digitIndexes[NUM_DIGITS][NUM_COMPONENTS] = {
    {1, 1, 0, 1, 1, 1, 1},                                  //0
    {[3] = 1, [6] = 1},                                     //1
    {[0] = 1, [3] = 1, [2] = 1, [4] = 1, [5] = 1},          //2
    {[0] = 1, [3] = 1, [2] = 1, [6] = 1, [5] = 1},          //3
    {[1] = 1, [2] = 1, [3] = 1, [6] = 1},                   //4
    {[0] = 1, [1] = 1, [2] = 1, [6] = 1, [5] = 1}           //5
};

int printDigit(int digitIndex);

int main()
{
    int digitCursor;

    for (digitCursor = 0; digitCursor < NUM_DIGITS; digitCursor++)
        printDigit(digitCursor);
        printf("\n");
}

int printDigit(int digitIndex)
{
    int cursor;

    for (cursor = 0; cursor < NUM_COMPONENTS; cursor++)
    {
        if (digitIndexes[digitIndex][cursor] == 1) printf("%s", components[cursor]);
        else 
        {
            if (components[cursor] == "|") printf(" ");
            else printf("  ");
        }
        if (cursor == 0 || cursor == 3 || cursor == 6) printf("\n");
    }
}