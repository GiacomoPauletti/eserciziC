#include <stdio.h>
#include <stdlib.h>

#define MAX_TEXT_LENGTH 100

#define STOP '-'

typedef struct node
{
	char value;
	struct node* next;
}Node;


int findCommonText(Node* text1, Node* text2, Node** common);

void printList(Node* head);

Node* inputList();

int main()
{
	Node* text1;
	Node* text2;
	Node* common;

	int length;

	printf("Inserisci il testo 1 carattere per carattere:\n");
	text1 = inputList();

	printf("Inserisci il testo 2 carattere per carattere:\n");
	text2 = inputList();

	printf("I due testi sono:\n");
	printf("- ");
	printList(text1);
	printf("\n- ");
	printList(text2);
	printf("\n\n");

	common = NULL;
	length = findCommonText(text1, text2, &common);

	printf("La sequenza è: ");
	while (	length > 0 )
	{
		printf("%c", common -> value);
		common = common -> next;
		length--;
	}
	printf("\n\n");

	return 0;
}


int findCommonText(Node* text1, Node* text2, Node** common)
{
	Node* mainCursor, *secondCursor;
	/* usate per scorrere la lista cercando dei valori uguali */
	Node* checkCursor;
	/* usato per verificare che i valori dopo mainCursor corrispondano a quelli
	 * indicati da secondCursor */
	Node* secondCursorBackup;
	/* usato per far tornare secondCursor alla posizione originale dopo aver trovato
	 * una sequenza comune */

	int maxLength;
	/* lunghezza massima trovata fino ad ora */
	Node* maxSequence;
	/* sequenza più lunga trovata fino ad ora */
	int currentLength;
	/* lunghezza della sequenza corrente */
	Node* currentSequence;
	/* sequenza corrente */

	int inSequence;
	/* indica se si sta trovando una sequenza uguale */

	maxLength = 0;
	mainCursor = text1;
	while ( mainCursor != NULL )
	{
		secondCursor = text2;
		currentLength = 0;
		inSequence = 0;
		
		checkCursor = mainCursor;
		while ( secondCursor != NULL )
		{
			if ( checkCursor != NULL && checkCursor -> value == secondCursor -> value )
			{
				if ( inSequence == 0 )
				{
					secondCursorBackup = secondCursor;
					currentSequence = secondCursor;
					inSequence = 1;
				}
					
				checkCursor = checkCursor -> next;
				currentLength++;

			}
			else
			{
				if ( inSequence == 1 && currentLength > maxLength )
				{
					secondCursor = secondCursorBackup -> next;
					maxLength = currentLength;
					maxSequence = currentSequence;
				}
				checkCursor = mainCursor;
				inSequence = 0;
				currentLength = 0;
			}

			secondCursor = secondCursor -> next;

		}

		if ( inSequence == 1 && currentLength > maxLength )
		{
			maxLength = currentLength;
			maxSequence = currentSequence;
		}

		mainCursor = mainCursor -> next;
	}
	
	*common = malloc(sizeof(Node));
	(*common) -> value = maxSequence -> value;
	(*common) -> next = maxSequence -> next;
	return maxLength;
}

void printList(Node *head)
{
	while ( head != NULL )
	{
		printf("%c", head -> value);
		head = head -> next;
	}
}

Node *inputList()
{
	Node* head;
	char input;

	scanf("%c", &input);
	if (input == STOP)
	{
		fflush(stdin);
		return NULL;
	}
	if ( input != '\n')
	{
		head = malloc(sizeof(Node));
		head -> value = input;
		head -> next = inputList();
	}
	else head = inputList();



	return head;
}
