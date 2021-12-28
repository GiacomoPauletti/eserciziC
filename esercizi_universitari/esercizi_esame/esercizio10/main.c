#include <stdio.h>
#include <stdlib.h>

#define TO_ADD 50

typedef struct node
{
	int value;
	struct node *prev;
	struct node *next;
} Node;

Node* inputList();

void printList(Node *head);

void insertOrdered(Node **pplist, int newValue);

int main()
{
	Node *list;

	printf("Inserisci la lista: ");
	list = inputList();

	printf("Lista prima dell'inserimento di %d: \n", TO_ADD);
	printList(list);

	insertOrdered(&list, TO_ADD);

	printf("Lista dopo l'inserimento di %d: \n", TO_ADD);
	printList(list);

	return 0;
}

void insertOrdered(Node **pplist, int newValue)
{
	Node *new;

	if ( *pplist == NULL || (*pplist) -> value > newValue )
	{
		new = malloc(sizeof(Node));
		new -> value = newValue;
		new -> next = *pplist;
		new -> prev = NULL;

		*pplist = new;
	}
	else if ( (*pplist) -> next == NULL || (*pplist) -> next -> value > newValue )
	{
		new = malloc(sizeof(Node));
		new -> value = newValue;

		new -> next = (*pplist) -> next;
		if ( (*pplist) -> next != NULL ) new -> next -> prev = new;

		new -> prev = *pplist;
		new -> prev -> next = new;
	}
	else
		insertOrdered(&((*pplist) -> next), newValue);

}

void printList(Node *head)
{
	while ( head != NULL)
	{
		printf("%d ", head -> value);
		head = head -> next;
	}
	printf("\n");
}

Node* inputList()
{
	Node* head;
	int input;
	
	scanf("%d", &input);
	if (input == -1) return NULL;

	head = malloc(sizeof(Node));
	head -> value = input;
	head -> prev = NULL;

	head -> next = inputList();
	if ( head -> next != NULL ) head -> next -> prev = head;

	return head;

}
