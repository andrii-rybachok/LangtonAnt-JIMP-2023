#ifndef langtonCellColor
#define langtonCellColor

typedef enum{
    White=0,Black=1
} CellColor;

CellColor toggleColor(CellColor color);
#endif