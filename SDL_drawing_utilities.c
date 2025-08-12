#include "SDL_drawing_utilities.h"

#include "ikoniq_utilities.h"
#include "SDL3/SDL.h"

Color CreateColor(int red, int green, int blue, int alpha) {
    Color newColor = { red, green, blue, alpha};
    return newColor;
}

FloatPair CreateScreenCoordinate(float x, float y) {
    FloatPair newCoordinate = { x, y };
    return newCoordinate;
}

FloatPair CreateSize(float width, float height) {
    FloatPair newSize = { width, height };
    return newSize;
}

void DrawBackground(SDL_Renderer *mainRenderer, Color color)
{
    SDL_SetRenderDrawColor(mainRenderer, color.red, color.green, color.blue, color.alpha);
}

void DrawRectWColor(SDL_Renderer *mainRenderer, FloatPair coordinate, FloatPair size, Color color) {
    SDL_FRect newRect;
    newRect.x = coordinate.x;
    newRect.y = coordinate.y;
    newRect.w = size.x;
    newRect.h = size.y;

    SDL_SetRenderDrawColor(mainRenderer, color.red, color.green, color.blue, color.alpha);
    SDL_RenderFillRect(mainRenderer, &newRect);
}