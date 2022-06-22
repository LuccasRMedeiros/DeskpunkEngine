#include <deskpunk_core.h>

SDL_Rect rect;

static void routine_fillRect(void)
{
    int mouseX;
    int mouseY;
    uint32_t rect_color = SDL_MapRGB(deskpunk_mainWindow.canvas->format, 0xFF, 0x0, 0x0);

    SDL_GetMouseState(&mouseX, &mouseY);

    if ((rect.x <= mouseX && rect.x >= mouseX - 32) && 
            (rect.y <= mouseY && rect.y >= mouseY - 32))
        rect_color = SDL_MapRGB(deskpunk_mainWindow.canvas->format, 0xFF, 0x3A, 0x0);

    SDL_FillRect(deskpunk_mainWindow.canvas, &rect, rect_color);
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

    rect.x = 0;
    rect.y = 0;
    rect.w = 32;
    rect.h = 32;

    deskpunk_core_mainLoop(stopCondition_escWasPressed, routine_fillRect);
    deskpunk_core_quit();

    return 0;
}
