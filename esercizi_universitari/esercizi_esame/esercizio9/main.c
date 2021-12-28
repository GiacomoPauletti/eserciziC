#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int value;
	struct node *next;
}Node;

typedef struct fnode
{
	int value;
	int freq;
	struct fnode *next;
}FreqNode;

int getMFD(Node *list);

Node *inputList();

void printList(Node *list);

int main()
{
	Node* list;
	printf("Insert the list: ");
	list = inputList();

	printf("The most frequent distance is: %d\n", getMFD(list));
	return 0;
}


/* Most Frequent Distance */
int getMFD(Node *list)
{
	Node *mainCursor, *secCursor;
	FreqNode *distances;
	FreqNode *distancesCursor;
	FreqNode *mostFreq;
	FreqNode *tempGarbage;
	int curDistance;
	int found;

	if ( list == NULL ) return -1;

	distances = malloc(sizeof(FreqNode));
	distances -> value = 0;
	distances -> freq = 0;
	distances -> next = NULL;


	mainCursor = list;
	while ( mainCursor != NULL )
	{
		secCursor = mainCursor -> next;
		while ( secCursor != NULL )
		{
			curDistance = secCursor -> value - mainCursor -> value;

			distancesCursor = distances;

			found = 0;
			while ( distancesCursor -> next != NULL && found == 0 )
			{
				if ( distancesCursor -> value == curDistance )
				{
					found = 1;
					distancesCursor -> freq++;
				}
				distancesCursor = distancesCursor -> next;
			}
			if ( found == 0 )
			{
				if ( distancesCursor -> value == curDistance)
				{
					distancesCursor -> freq++;
				}
				else 
				{
					distancesCursor -> next = malloc(sizeof(FreqNode));
					distancesCursor -> next -> value = curDistance;
					distancesCursor -> next -> freq = 1;
					distancesCursor -> next -> next = NULL;
				}
			}
			secCursor = secCursor -> next;
		}
		mainCursor = mainCursor -> next;
	}


	mostFreq = distances;
	distancesCursor = distances -> next;

	while ( distancesCursor != NULL )
	{
		if ( distancesCursor -> freq > mostFreq -> freq )
		{
			tempGarbage = mostFreq;
			mostFreq = distancesCursor;
		}
		else
		{
			tempGarbage = distancesCursor;
		}

		distancesCursor = distancesCursor -> next;
		free(tempGarbage);
	}

	curDistance = mostFreq -> value;
	free(mostFreq);

	return curDistance;
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
	head -> next = inputList();

	return head;

}
