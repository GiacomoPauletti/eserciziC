#include <stdio.h>

#define MAP_WIDTH 8
#define MAP_HEIGHT 8

#define EMPTY_CHAR '.'
#define HIT_SHIP_CHAR 'X'
#define SAFE_SHIP_CHAR 'O'


#if !defined(MAP_H)
#define MAP_H
typedef struct
{
    int x;
    int y;

} Coordinate;


typedef char Map[MAP_HEIGHT][MAP_WIDTH];


void empty(Map map);

void add(Map map, Coordinate coord, char symbol);

void printMap(Map map);
#endif