#pragma once
#include <SDL.h>

void cleanup(SDL_Window* window, SDL_Renderer* renderer);
SDL_Window* createWindow();
SDL_Renderer* createRenderer(SDL_Window* window);

void renderMandelbrot(SDL_Renderer* renderer);
void saveScreenshotBMP(const std::string& path, int width, int height, std::vector<double> bx, std::vector<double> by);
