#include "ship.h"

int placeShip(Map map, Ship ship)
{
    int cursor;

    switch (ship.direction)
    {
        case up:
            if ( ship.length <= ship.start.y + 1 )
            {
                for ( cursor = 0; cursor < ship.length; cursor++)
                {
                    map[ship.start.y - cursor][ship.start.x] = SAFE_SHIP_CHAR;
                }
            }             
        case down:
            if ( ship.length <= ( MAP_HEIGHT - 1 ) - ship.start.y)  
            /* MAX HEIGHT - 1 perchè ship.start.y arriva massimo a 7 (partendo da 0) e non 8 */
            {
                for ( cursor = 0; cursor < ship.length; cursor++)
                {
                    map[ship.start.y + cursor][ship.start.x] = SAFE_SHIP_CHAR;
                }
            }             
        case left:
            if ( ship.length <= ship.start.x + 1 )
            {
                for ( cursor = 0; cursor < ship.length; cursor++)
                {
                    map[ship.start.y][ship.start.x - cursor ] = SAFE_SHIP_CHAR;
                }
            }             
        case right:
            if ( ship.length <= ( MAP_WIDTH - 1 ) - ship.start.y)
            {
                for ( cursor = 0; cursor < ship.length; cursor++)
                {
                    map[ship.start.y][ship.start.x + cursor] = SAFE_SHIP_CHAR;
                }
            }             
    }
}
