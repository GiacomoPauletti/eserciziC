#include <stdio.h>

#define HEIGHT 	4
#define WIDTH 4

typedef int Matrix[HEIGHT][WIDTH];

void keepLocalMax(Matrix matrix);

void inputMatrix(Matrix matrix);

void printMatrix(Matrix matrix);

int main()
{

	Matrix matrix;
	inputMatrix(matrix);

	printf("Matrix before filtering :\n");
	printMatrix(matrix);

	keepLocalMax(matrix);
	
	printf("Matrix after filtering: \n");
	printMatrix(matrix);

	return 0;
}

void keepLocalMax(Matrix matrix)
{
	Matrix maxs;
	int col, row;
	int isMax;
	
	for ( row = 0; row < HEIGHT; row++)
	{
		for ( col = 0; col < WIDTH; col++)
		{
			isMax = 1;
			if ( ( row > 0 && matrix[row-1][col] > matrix[row][col] ) ||
			     ( row < HEIGHT - 1 && matrix[row+1][col] > matrix[row][col] ) ||
			     ( col > 0 && matrix[row][col-1] > matrix[row][col] ) ||
			     ( col < WIDTH - 1 && matrix[row][col+1] > matrix[row][col] ) )
				isMax = 0;

			if ( isMax == 1 )
				maxs[row][col] = 1;
			else
				maxs[row][col] = 0;
		}
	}

	
	for ( row = 0; row < HEIGHT; row++)
	{
		for ( col = 0; col < WIDTH; col++)
		{
			if ( maxs[row][col] == 0 )
				matrix[row][col] = 0;
		}
	}
}
			
void inputMatrix(Matrix matrix)
{
	int col, row;

	printf("Input numeri della matrice (x, y):\n");
	for ( row = 0; row < HEIGHT; row++)
	{
		for ( col = 0; col < WIDTH; col++)
		{
			printf("(%d, %d) ", col, row);
			scanf("%d", &(matrix[row][col]));
		}
	}
}

void printMatrix(Matrix matrix)
{
	int col, row;

	for ( row = 0; row < HEIGHT; row++)
	{
		printf("\t\t");
		for ( col = 0; col < WIDTH; col++)
			printf("%d\t", matrix[row][col]);
		printf("\n");
	}
}
