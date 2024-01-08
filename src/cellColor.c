#include "cellColor.h"
CellColor toggleColor(CellColor color){
    switch (color)
    {
        case White:
            return Black;
        case Black:
            return White;
    default:
        break;
    }
    return color;
}