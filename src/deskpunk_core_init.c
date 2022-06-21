#include "deskpunk_core.h"

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
static main_window_t setMainWindow(
        int width,
        int height,
        uint8_t n_displays,
        SDL_Window *desk,
        SDL_Surface *canvas)
{
    deskpunk_mainWindow = malloc(sizeof (deskpunk_mainWindow));
    if (!deskpunk_mainWindow)
    {
        fprintf(stderr, "\e[0;31mDESKPUNK ERROR:\e[0m Failed to allocate memory for main window pointer\n");
        SDL_DestroyWindow(desk);
        SDL_Quit();

        exit(-1);
    }

    deskpunk_mainWindow->width = width;
    deskpunk_mainWindow->height = height;
    deskpunk_mainWindow->n_displays = n_displays;
    deskpunk_mainWindow->desk = desk;
    deskpunk_mainWindow->canvas = canvas;
}

/**
 * @brief Create the desktop main window
 */
void deskpunk_core_init(void)
{
    SDL_DisplayMode DM;
    SDL_Window *desk;
    SDL_Surface *canvas;

    deskpunk_error_detect((SDL_Init() != 0));
    deskpunk_error_detect((SDL_GetDesktopDisplayMode(0, &DM) != 0));

    desk = SDL_CreateWindow(
                NULL,
                SDL_WINDOWPOS_CENTERED,
                SDL_WINDOWPOS_CENTERED,
                DM.w,
                DM.h,
                SDL_WINDOW_FULLSCREEN_DESKTOP | SDL_WINDOW_BORDERLESS
            );
    deskpunk_error_detect((desk == NULL));

    canvas = SDL_GetWindowSurface(desk);
    deskpunk_error_detect((canvas == NULL));

    setMainWindow(DM.w, DM.h, 1, desk, canvas);
}
