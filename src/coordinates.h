#ifndef LangtonCoordinates
#define LangtonCoordinates

#define ARROW_NORTH_WHITE '^'
#define ARROW_NORTH_BLACK 'N'
#define ARROW_EAST_WHITE '>'
#define ARROW_EAST_BLACK 'E'
#define ARROW_SOUTH_WHITE 'v'
#define ARROW_SOUTH_BLACK 'S'
#define ARROW_WEST_WHITE '<'
#define ARROW_WEST_BLACK 'W'
#define SQUARE_WHITE '#'
#define SQUARE_BLACK '@'




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