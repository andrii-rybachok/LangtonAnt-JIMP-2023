#ifndef langtonField
#define langtonField
#include "langtonAnt.h"
#include <stdio.h>
#include <wchar.h>

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

typedef struct {
    int** field;
    int rows;
    int cols;
    LangtonAnt ant;
} LangtonField;

LangtonField initializeField(int rows, int cols, int blackColsPercent, Direction antStartDirection);

int fieldIterate(LangtonField* langField);

void printField(LangtonField* field);

void printFieldToFile(LangtonField* field, FILE* file);

LangtonField initializeFieldWithMap(int rows, int cols, Direction antStartDirection, const char* mapFileName);

void loadMapFromFile(LangtonField* langField, const char* fileName);
#endif
