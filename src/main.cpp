#include <cmath>
#include <SDL.h>
using namespace std;

int main() {
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    SDL_Event event;

    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(640, 480, 0, &window, &renderer);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    int center_w = 640 / 2;
    int center_h = 480 / 2;
    
    int r = 150;
    int x = -r;
    pair<int, int> p1 = {x + center_w, center_h};
    pair<int, int> p2 = {x + center_w, center_h};
    
    bool running = true;
    while (running) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_QUIT:
            case SDL_KEYDOWN:
                running = false;
                break;
            }
        }

        if (x < r) {
            x++;
            // x² + y² = r² (circle equation) 
            // y = ± sqrt(r² - x²)
            pair<int, int> np1 = {x + center_w, sqrt(r * r - x * x) + center_h};
            pair<int, int> np2 = {x + center_w, -sqrt(r * r - x * x) + center_h};

            SDL_RenderDrawLine(renderer, p1.first, p1.second, np1.first, np1.second);
            SDL_RenderDrawLine(renderer, p2.first, p2.second, np2.first, np2.second);

            swap(p1, np1);
            swap(p2, np2);
        }
        
        SDL_RenderPresent(renderer);
        SDL_Delay(8);
    }
    
    return 0;
}
