#include <iostream>
#include <SDL2/SDL.h>

SDL_Window* CreateWindow(int height, int width){
    SDL_Window* win = SDL_CreateWindow("Ray Tracing in CPP", 100, 100, width, height, SDL_WINDOW_SHOWN);
    if (!win) {
        std::cout << "Failed to create a window!" << SDL_GetError() << std::endl;
    }
    return win; 
}

int main(int argc, char* argv[]){
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* win = CreateWindow(720, 1080);
    std::cin.get();
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 0;
}
