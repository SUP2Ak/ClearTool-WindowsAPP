#ifndef WINDOW_STYLES_H
#define WINDOW_STYLES_H

#include <windows.h>

class WindowStyles {
public:
    static void setDarkTheme(HWND hwnd);
    static void setLayeredAttributes(HWND hwnd);
};

#endif // WINDOW_STYLES_H