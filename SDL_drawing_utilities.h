#ifndef SDL_DRAWING_UTILITIES_H
#define SDL_DRAWING_UTILITIES_H
#include "SDL3/SDL_render.h"
#include "ikoniq_utilities.h"

typedef struct  {
    int red;
    int green;
    int blue;
    int alpha;
} Color;

void DrawBackground(SDL_Renderer *mainRenderer, Color color);

void DrawRectWColor(
    SDL_Renderer *mainRenderer,
    FloatPair coordinate,
    FloatPair size,
    Color color);

void DrawRectBorder(
    SDL_Renderer *mainRenderer,
    FloatPair coordinate,
    FloatPair size,
    Color borderColor);

void DrawRectWBorder(
    SDL_Renderer *mainRenderer,
    FloatPair coordinate,
    FloatPair size,
    Color fillColor,
    Color borderColor);

Color CreateColor(int red, int green, int blue, int alpha);
FloatPair CreateScreenCoordinate(float x, float y);
FloatPair CreateSize(float width, float height);

#endif //SDL_DRAWING_UTILITIES_H
