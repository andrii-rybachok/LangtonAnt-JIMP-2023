#ifndef langtonAnt
#define langtonAnt
typedef enum{
    Left=0,Right,Top,Bottom
} Direction;

typedef struct 
{
    int xPosition;
    int yPosition;
    Direction direction;
} LangtonAnt;


LangtonAnt initializeAnt(int xStartPosition,int yStartPosition,Direction direction);
#endif