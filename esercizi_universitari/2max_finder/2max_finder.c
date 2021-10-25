#include <stdio.h>

int main(){
    int primo, secondo;
    int temp;
    int i;
    int sequence[10] = {1, -3, 5, 75, 3, 5, 24, 0, 23, 44};

    primo = sequence[0];
    secondo = sequence[1];
    if (secondo > primo)
    {
        temp = secondo;
        secondo = primo;
        primo = temp;
    }

    for(i=2; i < 10; i++){
        if (sequence[i] > primo)
        {
            secondo = primo;
            primo = sequence[i];
        } else if (sequence[i] > secondo){
            secondo = sequence[i];
        }

        //printf("sequence[i]: %d \n\t primo: %d \n\t secondo: %d \n", sequence[i], primo, secondo);

    }
    printf("\n\n RISULTATI: \n primo: %d \nsecondo:%d \n", primo,secondo);
}