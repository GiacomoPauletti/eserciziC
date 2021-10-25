#include <stdio.h>
#define SEMICOLON ;
#define PRINTF printf
#define OPEN_PAR (
#define CLOSE_PAR )
#define COMMA ,
#define DECI_PLACEH %d

int main(){
    int i = 10 SEMICOLON
    PRINTF OPEN_PAR "%d\n" COMMA i CLOSE_PAR SEMICOLON

}