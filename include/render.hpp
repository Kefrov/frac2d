#pragma once
#include <SDL.h>

extern const int WIN_WIDTH;
extern const int WIN_HEIGHT;

extern const double BOUND_X[2];
extern const double BOUND_Y[2];

void cleanup(SDL_Window* window, SDL_Renderer* renderer);
SDL_Window* createWindow();
SDL_Renderer* createRenderer(SDL_Window* window);
