#include "coordinates.h"
#ifndef langtonAnt
#define langtonAnt
#include "cellColor.h"



typedef struct 
{
    Coordinates cords;
    Direction direction;
} LangtonAnt;


LangtonAnt initializeAnt(int xStartPosition,int yStartPosition,Direction direction);

int antIterate(LangtonAnt* ant,CellColor color,int xMax,int yMax);

Direction ToLeftChangeDirection(Direction currentDirection);

Direction ToRightChangeDirection(Direction currentDirection);

#endif