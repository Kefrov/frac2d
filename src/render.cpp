#include <iostream>
#include "render.hpp"

const int WIN_WIDTH = 800;
const int WIN_HEIGHT = 800;

const double BOUND_X[2] = {-2.0, 1.0};
const double BOUND_Y[2] = {-1.5, 1.5};

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
