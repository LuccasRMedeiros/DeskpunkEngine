#include "deskpunk_error.h"

#include <SDL2/SDL.h>
#include <stdio.h>

/**
 * @brief We use this function to see if a SDL action will be successful or not.
 * When such action fails, the function will emit a error message and then leave
 * the program.
 *
 * @param: uint8_t res - The result of an if condition
 */
void deskpunk_error_detect(uint8_t res)
{
    if (!res) // When there are no errors in whatever the engine is doing just quit the routine
        return ;
    
    fprintf(stderr, "\e[0;31mDESKPUNK ERROR:\e[0m %s\n", SDL_GetError());
    exit(-1);
}
