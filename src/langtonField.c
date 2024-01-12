#include "langtonField.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
#include <wchar.h>

LangtonField initializeField(int rows, int cols, int blackColsPercent, Direction antStartDirection) {
    LangtonField lngField;
    lngField.cols = cols;
    lngField.rows = rows;

    lngField.field = malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        lngField.field[i] = calloc(cols, sizeof(int));
    }

    if (lngField.field == NULL) {
        fprintf(stderr, "Allocation memory error for field!\n");
        exit(EXIT_FAILURE);
    }

    int countOfBlackCols = (int)((rows * cols) * (blackColsPercent / 100.0));
    srand(time(NULL));

    for (int i = 0; i < countOfBlackCols; i++) {
        int rndRow = rand() % rows;
        int rndCol = rand() % cols;

        if (lngField.field[rndRow][rndCol] == 0) {
            lngField.field[rndRow][rndCol] = 1;
        } else {
            i--;
        }
    }

    lngField.ant = initializeAnt((int)ceil((double)cols / 2) - 1, (int)ceil((double)rows / 2) - 1, antStartDirection);

    return lngField;
}


int fieldIterate(LangtonField* langField){
    if(langField->field==NULL){
        fprintf(stderr, "Field does not initialized!\n");
        exit(EXIT_FAILURE);
    }

    int* cell = &(langField->field[langField->ant.cords.y][langField->ant.cords.x]);

    CellColor color= *cell;
    int returnValue= antIterate(&langField->ant,color,langField->cols-1,langField->rows-1);
    color = toggleColor(color);
    *cell = (int)color;
    return returnValue;
}

void printField(LangtonField* field) {
    for (int i = 0; i < field->rows; i++) {
        for (int j = 0; j < field->cols; j++) {
            if (field->ant.cords.x == j && field->ant.cords.y == i) {
                switch (field->ant.direction) {
                    case Top:
                        printf("^[%d] ", field->field[i][j]);
                        break;
                    case Bottom:
                        printf("b[%d] ", field->field[i][j]);
                        break;
                    case Left:
                        printf("<[%d] ", field->field[i][j]);
                        break;
                    case Right:
                        printf(">[%d] ", field->field[i][j]);
                        break;
                    default:
                        break;
                }
            } else {
                printf("%d ", field->field[i][j]);
            }
        }
        printf("\n");
    }
}

void printFieldToFile(LangtonField* field, FILE* file) {
    for (int i = 0; i < field->rows; i++) {
        for (int j = 0; j < field->cols; j++) {
            if (field->ant.cords.x == j && field->ant.cords.y == i) {
                char* antSymbol;
                switch (field->ant.direction) {
                    case Top:
                        antSymbol = (field->field[i][j] == 0) ? ARROW_NORTH_WHITE : ARROW_NORTH_BLACK;
                        break;
                    case Bottom:
                        antSymbol = (field->field[i][j] == 0) ? ARROW_SOUTH_WHITE : ARROW_SOUTH_BLACK;
                        break;
                    case Left:
                        antSymbol = (field->field[i][j] == 0) ?  ARROW_EAST_WHITE : ARROW_EAST_BLACK ;
                        break;
                    case Right:
                        antSymbol = (field->field[i][j] == 0) ? ARROW_WEST_WHITE : ARROW_WEST_BLACK;
                        break;
                    default:
                        break;
                }
                fprintf(file, "%s", antSymbol);
            } else {
                char squareSymbol = (field->field[i][j] == 0) ? SQUARE_WHITE : SQUARE_BLACK;
                fprintf(file, "%c", squareSymbol);
            }
            fprintf(file, " ");
        }
        fprintf(file, "\n");
    }
}

void loadMapFromFile(LangtonField* langField, const char* fileName) {
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < langField->rows; i++) {
        for (int j = 0; j < langField->cols; j++) {
            if (fscanf(file, "%d", &(langField->field[i][j])) != 1) {
                fprintf(stderr, "Error reading from file");
                exit(EXIT_FAILURE);
            }
        }
    }

    fclose(file);
}

LangtonField initializeFieldWithMap(int rows, int cols, Direction antStartDirection, const char* mapFileName) {
    LangtonField lngField;
    lngField.cols = cols;
    lngField.rows = rows;

    lngField.field = malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        lngField.field[i] = calloc(cols, sizeof(int));
    }

    if (lngField.field == NULL) {
        fprintf(stderr, "Allocation memory error for field!\n");
        exit(EXIT_FAILURE);
    }

    loadMapFromFile(&lngField, mapFileName);


    return lngField;
}
