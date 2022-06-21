#include <SDL2/SDL.h>

int main(void)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        fprintf(stderr, "\e[0;31mDESKPUNKERROR: %s\e[0m\n", SDL_GetError());
        exit(-1);
    }

    SDL_Window *window = SDL_CreateWindow(  "Deskpunk Example", 
                                            SDL_WINDOWPOS_CENTERED, 
                                            SDL_WINDOWPOS_CENTERED, 
                                            640, 
                                            480, 
                                            SDL_WINDOW_SHOWN | SDL_WINDOW_BORDERLESS);
    if (!window) // When window come back null the program exit
    {
        fprintf(stderr, "\e[0;31mDESKPUNKERROR: %s\e[0m\n", SDL_GetError());
        exit(-1);
    }

    SDL_Surface *surface = SDL_GetWindowSurface(window);
    
    const Uint8 *keyState = SDL_GetKeyboardState(NULL);
    while (!keyState[SDL_SCANCODE_ESCAPE])
    {
        keyState = SDL_GetKeyboardState(NULL);

        SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0xFF, 0x0, 0x0));
        SDL_UpdateWindowSurface(window);

        printf("\rEsc state: %d", keyState[SDL_SCANCODE_ESCAPE]);
        fflush(stdout);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return (0);
}
