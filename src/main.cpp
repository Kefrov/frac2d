#include <iostream>
#include <vector>
#include "render.hpp"

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window* window = createWindow();
    if (!window) {
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = createRenderer(window);
    if (!renderer) {
        cleanup(window, nullptr);
        return 1;
    }
    
    SDL_Event event;
    bool running = true;
    while (running) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    running = false;
                    break;

                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym) {
                        case SDLK_ESCAPE:
                            running = false;
                            break;
                        case SDLK_s:
                            std::vector<double> bx = {-1.0, -0.6};
                            std::vector<double> by = {-0.4, 0.0};

                            saveScreenshotBMP(
                                "/mnt/c/Users/GX3/Pictures/Screenshots/screenshot2.bmp",
                                10000, 10000,
                                bx, by
                            );
                            break;
                    }
            }
        }

        renderMandelbrot(renderer);
        
        SDL_RenderPresent(renderer);
    }

    cleanup(window, renderer);
    return 0;
}
