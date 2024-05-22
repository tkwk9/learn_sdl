#include <iostream>
#include <cstdlib>

#include <SDL2/SDL.h>
#include <glad/glad.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char *argv[])
{
    // The window we'll be rendering to
    SDL_Window *window = NULL;

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
    }
    else
    {
        // Create window
        window = SDL_CreateWindow("SDL Tutorial",
                                  SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                  SCREEN_WIDTH, SCREEN_HEIGHT,
                                  SDL_WINDOW_SHOWN);
        if (window == NULL)
        {
            std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        }
        else
        {
            // Get window surface
            SDL_Surface *screenSurface = SDL_GetWindowSurface(window);

            // Fill the surface white
            SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

            // Update the surface
            SDL_UpdateWindowSurface(window);

            // Hack to get window to stay up
            SDL_Event e;
            bool quit = false;
            while (!quit)
            {
                while (SDL_PollEvent(&e))
                {
                    if (e.type == SDL_QUIT)
                        quit = true;
                }
            }

            // Destroy window
            SDL_DestroyWindow(window);
        }
    }

    // Quit SDL subsystems
    SDL_Quit();

    return 0;
}
