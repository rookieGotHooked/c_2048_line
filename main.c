#include <stdio.h>
#include "SDL3/SDL.h"
#include "SDL3/SDL_main.h"
#include "SDL_drawing_utilities.h"

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 640

#define BOX_WIDTH 80
#define BOX_HEIGHT 80
#define COLUMN_PADDING 32
#define ROW_PADDING 32
#define ROW_COUNT 5
#define COLUMN_COUNT 5
#define POINTER_START_X 56
#define POINTER_START_Y 72

static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;
static SDL_Event event;

SDL_AppResult SDL_AppInit(void **appstate, int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) == false) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Couldn't initialize SDL!", SDL_GetError(), NULL);
        return SDL_APP_FAILURE;
    }

    if (SDL_CreateWindowAndRenderer("New Game Window", WINDOW_WIDTH, WINDOW_HEIGHT, 0, &window, &renderer) == false) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Couldn't create window / renderer!", SDL_GetError(), NULL);
        return SDL_APP_FAILURE;
    }

    return SDL_APP_CONTINUE;
}

void DrawRowOfRects(int rects, FloatPair drawPointer,
    FloatPair rectSize, Color rectColor, float padding) {
    for (int i = 0; i < rects; i++) {
        DrawRectWColor(renderer, drawPointer, rectSize, rectColor);
        drawPointer.x += padding + rectSize.x;
    }
}

SDL_AppResult SDL_AppIterate(void *appstate) {

    // Rendering

    SDL_RenderClear(renderer);

    FloatPair mainDrawPointer = {POINTER_START_X, POINTER_START_Y};

    for (int i = 0; i < ROW_COUNT; i++) {
        DrawRowOfRects(
            COLUMN_COUNT,
            mainDrawPointer,
            CreateSize(BOX_WIDTH, BOX_HEIGHT),
            CreateColor(255, 255, 255, 255),
            COLUMN_PADDING);

        mainDrawPointer.y += ROW_PADDING + BOX_HEIGHT;
    }

    DrawBackground(renderer, CreateColor(255, 255, 0, 255));

    SDL_RenderPresent(renderer);

    // Interacting

    while (SDL_PollEvent(&event) != 0) {
        // switch (event.type) {
        //     case SDL_EVENT_MOUSE_BUTTON_DOWN:
        //         printf("Clicked at (%f,%f) in game window\n", event.button.x, event.button.y);
        //         break;
        // }
        if (event.type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
            printf("Clicked at (%f,%f) in game window\n", event.button.x, event.button.y);
            break;
        }
    }

    return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void *appstate, SDL_AppResult result) {

}

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event) {
    switch (event->type) {
        case SDL_EVENT_QUIT:
            return SDL_APP_SUCCESS;
        case SDL_EVENT_KEY_DOWN:
            if (event->key.key == SDLK_ESCAPE) {
                return SDL_APP_SUCCESS;
            }
        default:
            break;
    }

    return SDL_APP_CONTINUE;
}


