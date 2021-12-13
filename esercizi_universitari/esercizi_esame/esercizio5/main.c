#include <stdio.h>

#define HEIGHT 8
#define WIDTH 8
/* board dimensions */

#define PIECE_TYPE char
/* type of symbols which fill the board */

#define PLAYER1 'R'
#define PLAYER2 'B'
#define EMPTY 'E'
/* symbols that will fill the board */

#define PIECE_NUM ( 3 * ( WIDTH / 2 ) )

typedef PIECE_TYPE Board[HEIGHT][WIDTH];
/* for convention the top-right cell ( at (0,0) ) is black.
 * This means that cells whose indexs sum is even are black,
 * others are white */

int jump(Board board, PIECE_TYPE piece);

int initBoard(Board board);

void i

int main()
{

	Board board;

	return 0;
}

int initBoard(Board board)
{
	int col, row;
	int pieceCounter;
	

	if ( HEIGHT - 2 * ( PIECE_NUM / ( WIDTH / 2 ) ) < 2 ) return 0;
	/* 2 empty row (in the middle) are required.
	 * If pieces occupy HEIGHT - 1 rows (or more) the board
	 * will not be filled */

	/* player 1 initialization */
	pieceCounter = PIECE_NUM;
	for ( row = 0; row < HEIGHT && pieceCounter > 0; row++)
	{
		for ( col = 0; col < WIDTH; col++) 
		{
			if ( ( row + col ) % 2 == 0 )
			{
				board[row][col] = PLAYER1;
				pieceCounter--;
			}
		}
	}
			
	/* player 2 initialization */
	pieceCounter = PIECE_NUM;
	for ( row = HEIGHT - 1; row > 0 && pieceCounter > 0; row++)
	{
		for ( col = 0; col < WIDTH; col++) 
		{
			if ( ( row + col ) % 2 == 0 )
			{
				board[row][col] = PLAYER2;
				pieceCounter--;
			}
		}
	}

	
}

int jump(Board board, PIECE_TYPE piece)
{

	int col, row;
	int jumped;

	if ( ( piece != PLAYER1 ) && ( player != PLAYER2 ) ) return 0;

	jumped = 0;
	for ( row = 0; row < HEIGHT; row++ )
	{
		for ( col = 0; col < WIDTH; col++) 
		{
			if ( board[row][col] == piece )
			{
				if ( ( row - 2 >= 0 && col - 2 >= 0 ) &&
				     ( board[row - 2 ][col - 2] == VUOTO ) &&
				     ( board[row - 1][col - 1] != piece ) )
				{
					board[row - 1][col - 1] = VUOTO;
					board[row - 2][col - 2] = piece;
					board[row][col] = VUOTO;
					jumped = 1;
				}
				else if ( ( row - 2 > 0 && col + 2 < HEIGHT ) &&
				     	  ( board[row - 2 ][col + 2] == VUOTO ) &&
				     	  ( board[row - 1][col + 1] != piece ) )
				{
					board[row - 1][col + 1] = VUOTO;
					board[row - 2][col + 2] = piece;
					board[row][col] = VUOTO;
					jumped = 1;
				}
			}
		}
	}

	return jumped;
}
