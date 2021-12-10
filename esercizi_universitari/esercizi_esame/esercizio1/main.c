#include <stdio.h>
#include <stdlib.h>

#define ITEM int
#define STOP -1

typedef struct node
{
	ITEM value;
	struct node* next;
}Node;
	
Node* inputList();

void printList(Node* head);

int inList(Node* head, Node* toFind);

void simplify(Node** phead);

int main()
{
	Node *head;

	printf("Write list items and use %d to stop\n", STOP);
	head = inputList();

	printf("List before simplifing: ");
	printList(head);

	simplify(&head);

	printf("List after simplifing: ");
	printList(head);

	return 0;
}


//checks whether toFind is present in the given list
int inList(Node* head, Node* toFind)
{
	if ( toFind == NULL ) return 1;

	while ( head != NULL && head -> value != toFind -> value)
		head = head -> next;

	/* if node was found in list, then head will not be NULL */
	return (head != NULL);
}

void simplify(Node **head)
{
	Node* tmp;
	int isInList;
	if ( head == NULL || *head == NULL || (*head) -> next == NULL ) return;

	isInList = inList((*head)->next, *head);
	if (  isInList == 1 )
	{
		tmp = *head;
		*head = (*head) -> next;
		free(tmp);
	}

	if (isInList == 0) simplify(&((*head) -> next));
	else simplify(head);
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
	ITEM input;
	
	scanf("%d", &input);
	if (input == STOP) return NULL;

	head = malloc(sizeof(Node));
	head -> value = input;
	head -> next = inputList();

	return head;

}
