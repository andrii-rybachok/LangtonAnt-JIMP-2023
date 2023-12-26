#include "langtonField.h"
#include <stdlib.h>
#include <stdio.h>
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

    int countOfblackCols = rows*cols/100*blackColsPercent;
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

    lngField.ant = initializeAnt(rows/2,cols/2,antStartDirection);
    return lngField;
}