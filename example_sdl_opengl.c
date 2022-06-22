#include <deskpunk_core.h>

static void routine_fillRect(void)
{
    SDL_FillRect(deskpunk_mainWindow.canvas, NULL, SDL_MapRGB(deskpunk_mainWindow.canvas->format, 0xFF, 0x0, 0x0));
}

static int stopCondition_escWasPressed(void)
{
    SDL_Event event;
    if (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_KEYDOWN:
            if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
                return 1;
        break;
        }
    }

    return 0;
}

int main(void)
{
    deskpunk_core_init();
    deskpunk_core_mainLoop(stopCondition_escWasPressed, routine_fillRect);
    deskpunk_core_quit();

    return 0;
}
