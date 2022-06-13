#include <SDL.h>

int main(void)
{
    int res = SDL_Init(SDL_INITIALIZE_EVERYTHING);

    if (res < 0)
    {
        perror();
        exit(-1);
    }
    printf("\e[0;33mSDL INITIALIZED WITH SUCCESS\e[0m\n");
}
