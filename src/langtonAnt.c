#include "langtonAnt.h"
#include <stdio.h>
LangtonAnt initializeAnt(int xStartPosition,int yStartPosition,Direction direction){
    LangtonAnt ant;
    ant.cords.x=xStartPosition;
    ant.cords.y=yStartPosition;
    ant.direction=direction;
    return ant;
}

int antIterate(LangtonAnt* ant,CellColor color,int xMax,int yMax){
    switch (color)
    {
        case Black:
            ant->direction = ToLeftChangeDirection(ant->direction);
            break;
        case White:
            ant->direction = ToRightChangeDirection(ant->direction);
            break;
    default:
        break;
    }
    move(&(ant->cords),ant->direction);

   
    if((ant->cords.x>xMax || ant->cords.x<0 || ant->cords.y>yMax || ant->cords.y<0)){
        return -1;
    }
    return 0;
}
Direction getAntDirection(char antSymbol){
    switch (antSymbol)
    {
        case ARROW_EAST_BLACK:
        case ARROW_EAST_WHITE:
            return Right;
        case ARROW_WEST_BLACK:
        case ARROW_WEST_WHITE:
            return Left;
        case ARROW_NORTH_BLACK:
        case ARROW_NORTH_WHITE:
            return Top;
        case ARROW_SOUTH_BLACK:
        case ARROW_SOUTH_WHITE:
            return Bottom;
        default:
            break;
    }
    return Right;
}
Direction ToLeftChangeDirection(Direction currentDirection){
    switch (currentDirection)
    {
        case Bottom:
            return Left;
            break;
        case Left:
            return Bottom;
            break;
        case Top:
            return Left;
        case Right:
            return Top;
        default:
            break;
    }
    return currentDirection;
}

Direction ToRightChangeDirection(Direction currentDirection){
    switch (currentDirection)
    {
        case Bottom:
            return Right;
            break;
        case Left:
            return Top;
            break;
        case Top:
            return Right;
        case Right:
            return Bottom;
        default:
            break;
    }
    return currentDirection;
}