#include <iostream>
#include "render.hpp"
#include "fractal.hpp"

const int WIN_WIDTH = 1000;
const int WIN_HEIGHT = 1000;

const double BOUND_X[2] = {-2.0, 1.0};
const double BOUND_Y[2] = {-1.5, 1.5};

// STEP is the same for both axis (to maintain a 1:1 aspect ratio)
const double STEP = (BOUND_X[1] - BOUND_X[0]) / WIN_WIDTH;

SDL_Window* createWindow() {
    SDL_Window* window = SDL_CreateWindow(
        "Frac2D",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WIN_WIDTH, WIN_HEIGHT,
        0
    );
    if (!window) std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
    return window;
}

SDL_Renderer* createRenderer(SDL_Window* window) {
    SDL_Renderer* renderer = SDL_CreateRenderer(
        window, 
        -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );
    if (!renderer) std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
    return renderer;
}

void cleanup(SDL_Window* window, SDL_Renderer* renderer) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void renderMandelbrot(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    double pointX = BOUND_X[0];
    double pointY = BOUND_Y[1];
    for (int i = 0; i < WIN_HEIGHT; i++) {
        for (int j = 0; j < WIN_WIDTH; j++) {
            SDL_Color color = getColor(pointX, pointY);
            SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
            SDL_RenderDrawPoint(renderer, j, i);

            pointX += STEP;
        }
        
        pointX = BOUND_X[0];
        pointY -= STEP;
    }
}
