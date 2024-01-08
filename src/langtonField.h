#ifndef langtonField
#define langtonField
#include "langtonAnt.h"
typedef struct {
    int** field;
    int rows;
    int cols;
    LangtonAnt ant;
} LangtonField;


LangtonField initializeField(int rows,int cols,int blackColsPercent,Direction antStartDirection);

int fieldIterate(LangtonField* langField);

void printField(LangtonField* field);
#endif