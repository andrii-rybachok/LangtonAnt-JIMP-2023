#include "coordinates.h"

void move(Coordinates* cords, Direction direction){
    switch (direction)
    {
        case Top:
            cords->y--;
            break;
        case Bottom:
            cords->y++;
            break;
        case Left:
            cords->x--;
            break;
        case Right:
            cords->x++;
            break;
        default:
            break;
    }
}