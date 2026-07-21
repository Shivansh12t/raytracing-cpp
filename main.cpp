#include <iostream>
#include <SDL2/SDL.h>

#define WINDOW_WIDTH 810
#define WINDOW_HEIGHT 540

int main(int argc, char* argv[]){
    // initialise SDL2
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0){
        std::cout << "Error Initializing SDL :" << SDL_GetError() << std::endl;
        return 1;
    };
    
    // initialise window
    SDL_Window* win = SDL_CreateWindow("Ray Tracing in C++", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (!win) {
        std::cout << "Error creating Window: " << SDL_GetError() << std::endl;
        return 1;
    }

    // create surface
    SDL_Surface* surf = SDL_GetWindowSurface(win);

    // draw rectangle
    SDL_FillRect(surf, NULL, SDL_MapRGB(surf->format, 255, 255, 0));

    // updates surface
    SDL_UpdateWindowSurface(win);

    // pause for keystroke
    std::cin.get();

    // cleanup
    SDL_DestroyWindow(win);
    SDL_Quit();

    // ensuring no dangling pointers left
    win = NULL;
    surf = NULL;
    
    return 0;
}
