#include <stdio.h>
#include <stdlib.h>

#define LENGTH 10
typedef struct node 
{
    int* value;
    struct node *next;
} Node;

Node* getSeenTrees(int trees[], float x, float y);

void printList(Node* list)
{
    while ( list != NULL )
    {
        printf("%d ", *(list -> value));
        list = list -> next;
    }
    printf("\n");
}

int main()
{

    int trees[LENGTH] = { 2, 1, 2, 1, 3, 7, 5, 6, 8, 9};

    printList(getSeenTrees(trees, -3, 2));

    return 0;
}

Node* getSeenTrees(int trees[], float x, float y)
{
    Node *head, *new;
    int cursor;
    float maxSlope, currentSlope;

    maxSlope = -1 *  ( ((float) trees[0]) - y ) / x;

    head = malloc(sizeof(Node));
    head -> value = &trees[0];
    head -> next = NULL;

    new = head;

    for ( cursor = 1; cursor < LENGTH; cursor++ )
    {
        currentSlope = ( ((float) trees[cursor]) - y ) / ( cursor - x );
        if ( currentSlope > maxSlope)
        {
            maxSlope = currentSlope;
            
            new -> next = malloc(sizeof(Node));
            new -> next -> value = &trees[cursor];
            new = new -> next;
        }
    }

    new -> next = NULL;

    return head;
}

