#pragma once
#include <SDL.h>

void cleanup(SDL_Window* window, SDL_Renderer* renderer);
SDL_Window* createWindow();
SDL_Renderer* createRenderer(SDL_Window* window);

void renderMandelbrot(SDL_Renderer* renderer);
