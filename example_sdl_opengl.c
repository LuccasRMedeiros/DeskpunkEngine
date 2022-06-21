#include <SDL2/SDL.h>

int main(void)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) // If SDL_Init fails exit the program
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
    
    uint8_t keep_looping = 1;
    while (keep_looping)
    {
        SDL_Event event;
        if (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_KEYDOWN:
                if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
                    keep_looping = 0;
            break;
            }
        }

        SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0xFF, 0x0, 0x0));
        SDL_UpdateWindowSurface(window);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return (0);
}
