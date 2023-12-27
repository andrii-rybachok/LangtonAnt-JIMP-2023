#ifndef LangtonCoordinates
#define LangtonCoordinates

typedef enum{
    Left=0,Top,Right,Bottom
} Direction;

typedef struct
{
    int x;
    int y;
} Coordinates;

void move(Coordinates* cords, Direction direction);
#endif