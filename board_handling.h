#ifndef BOARD_HANDLING_H
#define BOARD_HANDLING_H
#include "ikoniq_utilities.h"

typedef struct {
    IntPair coordinate;
    long value;
    bool occupied;
    bool isClicked;
} TileState;

typedef struct {
    FloatPair bottomLeft;
    FloatPair topRight;
} Tile;

#endif //BOARD_HANDLING_H
