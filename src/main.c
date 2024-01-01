#include <stdio.h>  
#include <unistd.h>  
#include <stdlib.h>
#include "steptime.h"
#include "langtonAnt.h"
#include "langtonField.h"

int main(int argc, char *argv[])  
{ 
    int opt, rows, cols, iterationsCount, blackCellsPercent, obstaclesPercent; 
    Direction startDirection = Right;
    char filePrefix[20] = "file";  // Default file prefix

    while ((opt = getopt(argc, argv, "r:c:i:d:b:p:m:o:")) != -1)  
    {  
        switch (opt)   
        {  
            case 'r':  
                printf("rows: %s\n", optarg); 
                rows = atoi(optarg); 
                break;  
            case 'c':  
                printf("columns: %s\n", optarg);  
                cols = atoi(optarg);
                break; 
            case 'i':  
                iterationsCount = atoi(optarg);
                printf("Count of iterations: %d\n", iterationsCount);  
                break; 
            case 'd':  
                printf("Start direction: %s\n", optarg);
                int startDirectionCheck = atoi(optarg);
                if (startDirectionCheck < 0 || startDirectionCheck > 3){
                    printf("Direction could only be in range 0-3");
                    startDirection = 0;
                }
                else{
                    startDirection = startDirectionCheck;
                }
                break; 
            case 'b':  
                printf("Black cells percent: %s\n", optarg);
                blackCellsPercent = atoi(optarg);
                break; 
            case 'p':  
                printf("File prefix: %s\n", optarg);
                strncpy(filePrefix, optarg, sizeof(filePrefix) - 1);
                break;
            case 'm':
                printf("Create map with obstacles\n");
                obstaclesPercent = atoi(optarg);
                break;
            case 'o':
                printf("Obstacles percent: %s\n", optarg);
                obstaclesPercent = atoi(optarg);
                break;
            case ':':  
                printf("option needs a value\n");  
                break;  
        }  
    }  

    LangtonField field;

    if (obstaclesPercent > 0)
    {
        field = initializeFieldWithObstacles(rows, cols, obstaclesPercent, startDirection);
    }
    else
    {
        field = initializeField(rows, cols, blackCellsPercent, startDirection);
    }

    char fileName[50];

    snprintf(fileName, sizeof(fileName), "%s_nriteracji.txt", filePrefix);
    FILE* outputFile = fopen(fileName, "w");
    if (outputFile == NULL) {
        perror("Error opening output file");
        return 1;
    }

    printFieldToFile(&field, outputFile);
    fclose(outputFile);

    clearScreen();
    printField(&field);
    sleepMillis(500);

    for (int i = 0; i < iterationsCount; i++)
    {
        fieldIterate(&field);

        snprintf(fileName, sizeof(fileName), "%s_nriteracji%d.txt", filePrefix, i + 1);
        outputFile = fopen(fileName, "w");
        if (outputFile == NULL) {
            perror("Error opening output file");
            return 1;
        }

        printFieldToFile(&field, outputFile);
        fclose(outputFile);

        clearScreen();
        printField(&field);
        sleepMillis(500);
    }

    for (int i = 0; i < field.rows; i++)
    {
        free(field.field[i]);
    }
    free(field.field);

    return 0; 
}
