#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int value;
	struct node *next;
} Node;

Node *listPrimes(int limit);

void printList(Node *list);

int main()
{
	Node* list;

	list = listPrimes(31);
	printList(list);

	return 0;
}

Node *listPrimes(int limit)
{
	Node* new;
	int divisor, isPrime;
	if ( limit <= 1 ) return NULL;
	
	divisor = 2;
	while ( divisor * divisor < limit && limit % divisor != 0 )
		divisor++;

	if ( divisor * divisor > limit )
	{
		new = malloc(sizeof(Node));
		new -> value = limit;
		new -> next = listPrimes(limit - 1);
		
		return new;
	}
	else return listPrimes(limit - 1);
}

	
void printList(Node *list)
{
	if ( list != NULL )
	{
		printf("%d ", list -> value);
		printList(list -> next);
	}
	else printf("\n");
}
