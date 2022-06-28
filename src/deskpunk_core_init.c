#include "deskpunk_core.h"

#include <SDL2/SDL_Vulkan.h>
#include <string.h>

/**
 * @brief Destroy everthing, clean the memory and let the program finish
 */
void deskpunk_core_quit(void)
{
    SDL_DestroyWindow(deskpunk_mainWindow.desk);
    SDL_Quit();
    
    memset(&deskpunk_mainWindow, 0, sizeof (deskpunk_mainWindow));
}

/**
 * @brief Sets the main window
 *
 * @param: int width - The screen physical width
 * @param: int height - The screen physical height
 * @param: uint8_t n_displays - The total number of displays
 * @param: SDL_Window *desk - The initialized structure of a window in SDL
 * @param: SDL_Surface *canvas - The initialized structure of a window surface 
 * SDL
 */
static void setMainWindow(
        int width,
        int height,
        uint8_t n_displays,
        SDL_Window *desk,
        SDL_Surface *canvas)
{
    deskpunk_mainWindow.width = width;
    deskpunk_mainWindow.height = height;
    deskpunk_mainWindow.n_displays = n_displays;
    deskpunk_mainWindow.desk = desk;
    deskpunk_mainWindow.canvas = canvas;
}

/**
 * @brief Create the desktop main window
 */
void deskpunk_core_init(void)
{
    SDL_DisplayMode DM;
    SDL_Window *desk;
    SDL_Surface *canvas;

    unsigned int pCount;

    deskpunk_error_detect((SDL_Init(SDL_INIT_EVERYTHING) != 0));
    deskpunk_error_detect((SDL_GetDesktopDisplayMode(0, &DM) != 0));

    desk = SDL_CreateWindow(
                NULL,
                SDL_WINDOWPOS_CENTERED,
                SDL_WINDOWPOS_CENTERED,
                DM.w,
                DM.h,
                SDL_WINDOW_FULLSCREEN | SDL_WINDOW_VULKAN
            );
    deskpunk_error_detect((desk == NULL));
    deskpunk_error_detect(SDL_Vulkan_GetInstanceExtensions(desk, &pCount, NULL));

    canvas = SDL_GetWindowSurface(desk);
    deskpunk_error_detect((canvas == NULL));

    setMainWindow(DM.w, DM.h, 1, desk, canvas);
}
