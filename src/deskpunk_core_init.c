#include "deskpunk_core.h"

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
 * @param SDL_DisplayMode mode: The display info
 * @param SDL_Window *desk: The initialized structure of a window in SDL
 * @param SDL_Surface *canvas: The initialized structure of a window surface 
 * SDL
 */
static void setMainWindow(SDL_DisplayMode mode, SDL_Window *desk, SDL_Surface *canvas)
{
    deskpunk_mainWindow.mode = mode;
    deskpunk_mainWindow.desk = desk;
    deskpunk_mainWindow.canvas = canvas;

    const vkApplicationInfo app = {
        .sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        .pNext = NULL;
        .pApplicationName = "Deskpunk";
        .applicationVersion = VK_MAKE_VERSION(0, 0, 0);
        .pEngineName = "Deskpunk";
        .engineVersion = VK_MAKE_VERSION(0, 0, 0);
        .apiVersion = VK_API_VERSION_1_0;
    };
    
    // First we count how many extensions are enabled
    // Then we get their names
    
    size_t extCount;
    deskpunk_error_detect((SDL_GetInstanceExtensions(desk, &extCount, NULL) == SDL_FALSE));

    string_t extNames[extCount];
    deskpunk_error_detect((SDL_GetInstanceExtensions(desk, &extCount, extNames);
    
}

/**
 * @brief Create the desktop main window
 */
void deskpunk_core_init(void)
{
    SDL_DisplayMode mode;
    SDL_Window *desk;
    SDL_Surface *canvas;

    deskpunk_error_detect((SDL_Init(SDL_INIT_EVERYTHING) != 0));
    deskpunk_error_detect((SDL_GetDesktopDisplayMode(0, &DM) != 0));

    desk = SDL_CreateWindow(
            NULL,
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            mode.w,
            mode.h,
            SDL_WINDOW_FULLSCREEN | SDL_WINDOW_VULKAN
            );
    deskpunk_error_detect((desk == NULL));

    canvas = SDL_GetWindowSurface(desk);
    deskpunk_error_detect((canvas == NULL));

    setMainWindow(mode, desk, canvas);
}
