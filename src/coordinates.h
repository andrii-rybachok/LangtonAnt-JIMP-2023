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
#define SQUARE_WHITE L' '
#define SQUARE_BLACK L'█'

#define MAP_ARROW_NORTH_WHITE '^'
#define MAP_ARROW_NORTH_BLACK 'N'
#define MAP_ARROW_EAST_WHITE '>'
#define MAP_ARROW_EAST_BLACK 'E'
#define MAP_ARROW_SOUTH_WHITE 'v'
#define MAP_ARROW_SOUTH_BLACK 'S'
#define MAP_ARROW_WEST_WHITE '<'
#define MAP_ARROW_WEST_BLACK 'W'
#define MAP_SQUARE_WHITE '0'
#define MAP_SQUARE_BLACK '1'


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