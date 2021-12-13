#include <stdio.h>
#include <stdlib.h>

//#define DEBUG

#define STOP -1

typedef struct node
{
	int value;
	struct node *next;
} Node;

Node* RLC(Node* head);

Node* createList();

int printList(Node* head);

int spacedPrintList(Node* head);

int main()
{

	Node* binaryList;
	Node* RLCList;
	printf("Please write the binary list.\nStop with %d.\nRemember to put at least one space between binary digits\n", STOP);
	printf("-> ");
	binaryList = createList();
	printf("\n");

	#ifdef DEBUG
	printf("This is the list: ");
	printList(binaryList);
	printf("\n");
	#endif

	RLCList = RLC(binaryList);

	printf("This is the output list: ");
	spacedPrintList(RLCList);
	printf("\n");

	return 0;
}


Node* RLC(Node* head)
{
	Node* new;
	if ( head == NULL) return NULL;

	#ifdef DEBUG
	printf("value: %d\n", head -> value);
	#endif

	if ( head -> next == NULL || head -> next -> value != head -> value )
	{
		new = malloc(sizeof(Node));
		new -> value = 1;

		new -> next = RLC(head -> next);
		/* if current element is the last one, this call will return NULL */

		return new;
	}
	else
	{
		new = RLC(head -> next);
		new -> value += 1;

		return new;
	}
}

Node* createList()
{
	Node* new;
	int input;
	
	
	scanf("%d", &input);
	if ( input != STOP )
	{
		new = malloc(sizeof(Node));
		new -> value = input;
		new -> next = createList();
		return new;
	} else return NULL;

}

int printList(Node* head)
{
	while ( head != NULL )
	{
		printf("%d", head -> value);
		head = head -> next;
	}
	return 1;
}


int spacedPrintList(Node* head)
{
	while ( head != NULL )
	{
		printf("%d ", head -> value);
		head = head -> next;
	}
	return 1;
}

