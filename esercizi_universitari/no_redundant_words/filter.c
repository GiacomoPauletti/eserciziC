#include <stdio.h>

#define MAX_SENTENCE_SIZE 20
#define MAX_WORD_SIZE 10

typedef struct
{
    char list[MAX_SENTENCE_SIZE][MAX_WORD_SIZE + 1]; // + 1 for the '\0' terminator
    int wordCounter; 
} Words;

int getWord(char word[]);

int areWordsEqual(char word0[], char word1[]);

int main()
{
    Words words;

    int secWordCounter;
    int isRedundant;
    int endOfInput;
    
    words.wordCounter = 0;
    endOfInput = 0;
    do
    {
        
        endOfInput = getWord(words.list[words.wordCounter]);

        isRedundant = 0;
        for (secWordCounter = 0; secWordCounter < words.wordCounter && isRedundant == 0; secWordCounter++)
        {
            if ( areWordsEqual(words.list[secWordCounter], words.list[words.wordCounter]) ) isRedundant = 1;

        }

        if ( isRedundant == 0 )
        {
            printf("%s\n", words.list[words.wordCounter]);
            words.wordCounter++;
        }
            

    }while ( endOfInput == 0 && words.wordCounter < MAX_SENTENCE_SIZE );

}

int getWord(char word[])
{
    char currentChar;
    int charCounter;

    charCounter = 0;
    currentChar = getchar();
    while ( currentChar != ' ' && currentChar != '\n' && charCounter < MAX_WORD_SIZE)
    {
        word[charCounter] = currentChar;
        charCounter++;

        currentChar = getchar();
    } 

    word[charCounter] = '\0';

    if (currentChar == '\n') return 1;
    return 0;
}

int areWordsEqual(char word0[], char word1[])
{
    int cursor;

    cursor = 0;
    while ( word0[cursor] == word1[cursor] && word0[cursor] != '\0' && word1[cursor] != '\0' )
    {
        cursor++;
    }

    if ( word0[cursor] == '\0' && word1[cursor] == '\0' ) return 1;
    return 0;
}