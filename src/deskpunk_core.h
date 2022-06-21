/**
 * @file deskpunk_core.h
 * @author Luccas Rocigno de Medeiros
 * @date 06/21/2022
 * @brief Header of the core of the engine
 *
 * Here are the prototypes of the core functions of the engine and so its
 * structures, enums, unions and defines that are used to manage images, events
 * and so on. Functions descriptions and examples can be found on the
 * documentation, doxygen comments are also available with the functions
 * definitions.
 */
#ifndef DESKPUNK_CORE_H
#define DESKPUNK_CORE_H

// Includes that are universally used by the core functions
#include <deskpunk_error.h>

/**
 * @brief Structure that controls the main window
 */
typedef struct main_window_s
{
    int width; // The total screen width
    int height; // The total screen height
    uint8_t n_displays; // The number of displays
    SDL_Window *desk; // The SDL window structure that represent the desktop
    SDL_Surface *canvas; // The SDL surface structure to draw into
} main_window_t;

const *main_window_t deskpunk_mainWindow; // Global address for the main window structure

void deskpunk_core_init(void);

#endif