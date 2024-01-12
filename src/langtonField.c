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
                char antSymbol;
                switch (field->ant.direction) {
                    case Top:
                        antSymbol = (field->field[i][j] == 0) ? ARROW_NORTH_WHITE : ARROW_NORTH_BLACK;
                        break;
                    case Bottom:
                        antSymbol = (field->field[i][j] == 0) ? ARROW_SOUTH_WHITE : ARROW_SOUTH_BLACK;
                        break;
                    case Left:
                        antSymbol = (field->field[i][j] == 0) ? ARROW_WEST_WHITE : ARROW_WEST_BLACK;
                        break;
                    case Right:
                        antSymbol = (field->field[i][j] == 0) ? ARROW_EAST_WHITE : ARROW_EAST_BLACK;
                        break;
                    default:
                        break;
                }
                fprintf(file, "%c", antSymbol);
            } else {
                char squareSymbol = (field->field[i][j] == 0) ? SQUARE_WHITE : SQUARE_BLACK;
                fprintf(file, "%c", squareSymbol);
            }
            fprintf(file, " ");
        }
        fprintf(file, "\n");
    }
}

void loadMapFromFile(LangtonField* langField, FILE* file) {
    char line[256];
    int row =0;
    while (fgets(line, sizeof(line), file)) {
        char** tiles = strSplit(line,' ');
        for (int j = 0; j < langField->cols; j++) {
            switch (tiles[j][0])
            {
            case SQUARE_WHITE:
                langField->field[row][j]=0;
                break;
            case SQUARE_BLACK:
                langField->field[row][j]=0;
                break;
            case ARROW_NORTH_WHITE:
            case ARROW_SOUTH_WHITE:
            case ARROW_WEST_WHITE:
            case ARROW_EAST_WHITE:
                langField->field[row][j]=0;
                langField->ant.cords.x=j;
                langField->ant.cords.y=row;
                break;
            default:
                break;
            }
        }
    }
   

    fclose(file);
}

char** strSplit(char* a_str, const char a_delim)
{
    char** result    = 0;
    size_t count     = 0;
    char* tmp        = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

    while (*tmp)
    {
        if (a_delim == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    count += last_comma < (a_str + strlen(a_str) - 1);
    count++;

    result = malloc(sizeof(char*) * count);

    if (result)
    {
        size_t idx  = 0;
        char* token = strtok(a_str, delim);

        while (token)
        {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }

    return result;
}

LangtonField initializeFieldWithMap(int rows, int cols, Direction antStartDirection, const char* mapFileName) {
    FILE* file = fopen(mapFileName, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    LangtonField lngField;
    if(checkMap(file,&lngField.cols,&lngField.rows)==-1){
        fprintf(stderr, "Wrong map sizes!!!\n");
        fclose(file);
        exit(EXIT_FAILURE);
    }
   

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
#define BUF_SIZE 65536

int checkMap(FILE* file,int* cols,int* rows)
{
    char buf[BUF_SIZE];
    int counter = 0;
    for(;;)
    {
        size_t res = fread(buf, 1, BUF_SIZE, file);
        if (ferror(file))
            return -1;

        int i;
        int prevRows;
        for(i = 0; i < res; i++){

            *rows++;
            if (buf[i] == '\n'){
                counter++;
                if(counter==1){
                    prevRows=*rows;
                }
                if(prevRows==*rows){
                    rows==0;
                }
                else{
                    return -1;
                }
            }
        }
        if (feof(file))
            *rows=prevRows;
            break;
    }
    
    return 0;
}