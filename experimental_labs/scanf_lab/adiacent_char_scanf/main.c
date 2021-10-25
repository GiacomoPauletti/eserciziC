#include <stdio.h>

int main(){
    int var;
    printf("TEST: integer printf of 'a' + 1\n");
    printf("USING ' : %u\n", 'a'+1);

    printf("LOCAL VARIABLE var ADDRESS : %p\n", &var);
    printf("JUST \"a\" integer: %u\n", "a");
    printf("ADDRESS OF \"a\" - \"a\" - \"b\": %p - %p - %p\n", "a", "a", "b");
    printf("ADDRESS OF \"a\" - \"a\" - \"b\" - \"c\": %p - %p - %p - %p\n", "a", "a", "b", "c");
    printf("USING \" : %p\n", "a" + 1);
}
