#include "cursor_DVD.h"
#include <iostream>
#include <windows.h>

void cursorDVD()
{
    int screenWidth = GetSystemMetrics(SM_CXVIRTUALSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYVIRTUALSCREEN);

    POINT cp;

    int dx = 1;
    int dy = 1;

    GetCursorPos(&cp);
    int x = cp.x;
    int y = cp.y;

    while (true)
    {
        SetCursorPos(x, y);

        Sleep(5);
        if (GetAsyncKeyState(VK_ESCAPE))
            break;


        if (x + dx > screenWidth || x + dx < 0)
            dx = -dx;

        if (y + dy > screenHeight || y + dy < 0)
            dy = -dy;


        x += dx;
        y += dy;
    }
}
