#include <stdio.h>  
#include <unistd.h>  
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>
#include "langtonAnt.h"
#include "langtonField.h"

int main(int argc, char *argv[])  
{ 
    int opt, rows, cols, iterationsCount, blackCellsPercent; 
    Direction startDirection = Right;
    char filePrefix[20] = "file";
    const char* mapFilePrefix = NULL;
    
    wchar_t name[] = L"test"; 
    setlocale(LC_ALL, "C.UTF-8");
    wchar_t *wc = L"▶ hhh";
    wprintf(L"%ls  \n", wc);
    while ((opt = getopt(argc, argv, "r:c:i:d:b:p:m:")) != -1)  
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
                mapFilePrefix = optarg;
                break;
            case ':':  
                printf("option needs a value\n");  
                break;  
        }  
    }  

    LangtonField field = initializeField(rows, cols, blackCellsPercent, startDirection);

    if (mapFilePrefix != NULL) {
        char mapFileName[50];
        snprintf(mapFileName, sizeof(mapFileName), "%s%d.txt", mapFilePrefix, 1);
        field = initializeFieldWithMap(rows, cols, startDirection, mapFileName);
    } else {
        field = initializeField(rows, cols, blackCellsPercent, startDirection);
    }

    char inputFileName[50], outputFileName[50];

    snprintf(inputFileName, sizeof(inputFileName), "%s_nriteracji.txt", filePrefix);
    FILE* initialFile = fopen(inputFileName, "w");
    if (initialFile == NULL) {
        perror("Error opening initial file");
        return 1;
    }
    printFieldToFile(&field, initialFile);
    fclose(initialFile);

    for (int i = 0; i < iterationsCount; i++)
    {
        if(fieldIterate(&field)==-1){
            break;
        }

        snprintf(outputFileName, sizeof(outputFileName), "%s_nriteracji%d.txt", filePrefix, i + 1);
        FILE* outputFile = fopen(outputFileName, "w");
        if (outputFile == NULL) {
            perror("Error opening output file");
            return 1;
        }
        printFieldToFile(&field, outputFile);
        fclose(outputFile);

    }

    return 0; 
}
