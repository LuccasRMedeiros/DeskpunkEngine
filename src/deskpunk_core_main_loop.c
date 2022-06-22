#include "deskpunk_core.h"

/**
 * @brief Keep the program runnig until the stop condition be met
 *
 * @param: stopCondition (int function) - Any function that return a int and
 * does not receive a argument, which test for a condition to stop the main loop
 * @param: routine (void function) - Any function that does not return anything
 * neither receive a argument, which execute the routine of the engine
 */
void deskpunk_core_mainLoop(int (stopCondition)(void), void (routine)(void))
{
    while (stopCondition() == 0)
    {
        SDL_FillRect(deskpunk_mainWindow.canvas, NULL, SDL_MapRGB(deskpunk_mainWindow.canvas->format, 0x0, 0x0, 0x0)); // Fill the background with black
        
        routine();
        SDL_UpdateWindowSurface(deskpunk_mainWindow.desk);
    }
}
