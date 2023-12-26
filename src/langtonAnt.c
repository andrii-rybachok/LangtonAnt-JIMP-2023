#include "langtonAnt.h"

LangtonAnt initializeAnt(int xStartPosition,int yStartPosition,Direction direction){
    LangtonAnt ant;
    ant.xPosition=xStartPosition;
    ant.yPosition=yStartPosition;
    ant.direction=direction;
    return ant;
}