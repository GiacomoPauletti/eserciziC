#include "../map/map.h"

typedef enum { up, right, down, left} Direction;

typedef struct 
{
    //char skin; 
    Coordinate start; 
    int length; 
    Direction direction;
    
} Ship;
