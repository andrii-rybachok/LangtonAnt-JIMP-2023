#include "langtonAnt.h"
#ifndef langtonField
#define langtonField
typedef struct {
    int** field;
    int rows;
    int cols;
    LangtonAnt ant;
} LangtonField;

LangtonField initializeField(int rows,int cols,int blackColsPercent,Direction antStartDirection);

void antMove(LangtonField* langField);
#endif