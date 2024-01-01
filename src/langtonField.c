#include "langtonField.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
LangtonField initializeField(int rows,int cols,int blackColsPercent,Direction antStartDirection){
    LangtonField lngField;
    lngField.cols=cols;
    lngField.rows=rows;
    lngField.field=malloc(cols*rows*sizeof(int));
    for (int i = 0; i < rows; i++)
    {
        lngField.field[i] = (int*)calloc(cols,sizeof(int));
    }
    
    if(lngField.field==NULL){
        fprintf(stderr, "Alocation memory error for field!\n");

        exit(EXIT_FAILURE);
    }

    int countOfblackCols = ((rows*cols)/100.0)*blackColsPercent;
    int i=0;
    srand(time(NULL));

    while (i<countOfblackCols)
    {

        int rndRow = rand()%rows;
        int rndCol = rand()%cols;

        if(lngField.field[rndRow][rndCol]==0){
            lngField.field[rndRow][rndCol]=1;

            i++;
        }
    }

    lngField.ant = initializeAnt(((int)ceil((double)cols / 2))-1,((int)ceil((double)rows / 2))-1,antStartDirection);

    return lngField;
}

void fieldIterate(LangtonField* langField){
    if(langField->field==NULL){
        fprintf(stderr, "Field does not initialized!\n");
        exit(EXIT_FAILURE);
    }
    int* cell = &(langField->field[langField->ant.cords.y][langField->ant.cords.x]);
    CellColor color= *cell;
    antIterate(&langField->ant,color,langField->cols-1,langField->rows-1);
    color = toggleColor(color);
    *cell = (int)color;

}
void printField(LangtonField *field) {
    for (int i = 0; i < field->rows; i++)
    {
        for (int j = 0; j < field->cols; j++)
        {
            if (field->ant.cords.x == j && field->ant.cords.y == i)
            {
                switch (field->ant.direction)
                {
                case Top:
                    printf("\033[1;31m^[%d] \033[0m", field->field[i][j]);
                    break;
                case Bottom:
                    printf("\033[1;31mb[%d] \033[0m", field->field[i][j]);
                    break;
                case Left:
                    printf("\033[1;31m<[%d] \033[0m", field->field[i][j]);
                    break;
                case Right:
                    printf("\033[1;31m>[%d] \033[0m", field->field[i][j]);
                    break;
                default:
                    break;
                }
            }
            else{
                printf("%d ", field->field[i][j]);
            }
        }
        printf("\n");
    }
}


void printFieldToFile(LangtonField* field, FILE* file) {
    for (int i = 0; i < field->rows; i++)
    {
        for (int j = 0; j < field->cols; j++)
        {
            if (field->ant.cords.x == j && field->ant.cords.y == i){
                fprintf(file, "%d ", field->field[i][j]);
            }
            else{
                fprintf(file, "%d ", field->field[i][j]);
            }
        }
        fprintf(file, "\n");
    }
}

LangtonField initializeFieldWithObstacles(int rows, int cols, int obstaclesPercent, Direction antStartDirection) {
    LangtonField lngField;
    lngField.cols = cols;
    lngField.rows = rows;
    lngField.field = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
    {
        lngField.field[i] = (int *)calloc(cols, sizeof(int));
    }

    if (lngField.field == NULL)
    {
        fprintf(stderr, "Memory allocation error for field!\n");
        exit(EXIT_FAILURE);
    }

    int countOfObstacles = ((rows * cols) / 100.0) * obstaclesPercent;
    int i = 0;
    srand(time(NULL));

    while (i < countOfObstacles)
    {
        int rndRow = rand() % rows;
        int rndCol = rand() % cols;

        if (lngField.field[rndRow][rndCol] == 0)
        {
            lngField.field[rndRow][rndCol] = 1;
            i++;
        }
    }

    lngField.ant = initializeAnt(((int)ceil((double)cols / 2)) - 1, ((int)ceil((double)rows / 2)) - 1, antStartDirection);

    printf("Initial State with Obstacles:\n");
    printField(&lngField);
    printf("\n");

    return lngField;
}