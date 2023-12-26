#include <stdio.h>  
#include <unistd.h>  
#include <stdlib.h>
#include "langtonAnt.h"
#include "langtonField.h"
int main(int argc, char *argv[])  
{ 
    int opt,rows,cols,iterationsCount,blackCellsPercent; 
    Direction startDirection= Right;
    while((opt = getopt(argc, argv, "r:c:i:d:b:")) != -1)  
    {  
        switch(opt)  
        {  
            
            case 'r':  
                printf("rows: %s\n", optarg); 
                rows=atoi(optarg); 
                break;  
            case 'c':  
                printf("columns: %s\n", optarg);  
                cols=atoi(optarg);
                break; 
            case 'i':  
                printf("Count of iterations: %s\n", optarg);  
                iterationsCount=atoi(optarg);
                break; 
            case 'd':  
                printf("Start direction: %s\n", optarg);
                int startDirectionCheck=atoi(optarg);
                if(startDirectionCheck<0 && startDirectionCheck>3){
                    printf("Direction could only be in range 0-3");
                    startDirection=0;
                }
                else{
                    startDirection=startDirectionCheck;
                }
                break; 
            case 'b':  
                printf("Black cells percent: %s\n", optarg);
                blackCellsPercent=atoi(optarg);
                break; 
            case ':':  
                printf("option needs a value\n");  
                break;  
        }  
    }  
    LangtonField field = initializeField(rows,cols,blackCellsPercent,startDirection);
    for (int i = 0; i < field.rows; i++)
    {
        for (int j = 0; j < field.cols; j++)
        {
            printf("%d ",field.field[i][j]);
        }
        printf("\n");
    }
    
    return 0; 
} 