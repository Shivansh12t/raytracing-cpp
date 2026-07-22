#include <iostream>
#include <SDL2/SDL.h>
#include <cmath>

#define WINDOW_WIDTH 810
#define WINDOW_HEIGHT 540

#define COLOR_WHITE 0xffffffff 

class Circle{
    private:
        double x;
        double y;
        double radius;
    public:
        Circle(double x, double y, double r) : x(x), y(y), radius(r) {}

        double getArea() const {
            return 3.14 * radius * radius;
        }
        void setRadius(double r) {
            this->radius = r;
        }
        void drawCircle(SDL_Surface* surf, Uint32 color){
            double radius_2 = radius * radius;
            // x^2 + y^2 <= r^2
            for (double px = x - radius; px <= x + radius; px++){
                for (double py = y - radius; py <= y +  radius; py++){
                    double dx = px - x;
                    double dy = py - y;
                    double distance_2 = dx * dx + dy * dy;
                    if (distance_2 < radius_2){
                        SDL_Rect pixel = (SDL_Rect) {(int)px,(int)py,1,1};
                        SDL_FillRect(surf, &pixel, color);
                    }
                }
            }
        }
};

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

    Circle c = Circle(WINDOW_WIDTH/2,WINDOW_HEIGHT/2,100);
    c.drawCircle(surf, COLOR_WHITE);

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
