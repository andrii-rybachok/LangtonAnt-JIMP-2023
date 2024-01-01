#ifndef langtonField
#define langtonField
#include "langtonAnt.h"
#include <stdio.h>
#include <string.h>

typedef struct {
    int** field;
    int rows;
    int cols;
    LangtonAnt ant;
} LangtonField;


LangtonField initializeField(int rows,int cols,int blackColsPercent,Direction antStartDirection);

void fieldIterate(LangtonField* langField);

void printField(LangtonField* field);

void printFieldToFile(LangtonField* field, FILE* file);

LangtonField initializeFieldWithObstacles(int rows, int cols, int obstaclesPercent, Direction antStartDirection);
#endif