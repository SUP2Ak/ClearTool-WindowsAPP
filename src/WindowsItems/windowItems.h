#ifndef WINDOW_ITEMS_H
#define WINDOW_ITEMS_H

#include <windows.h>

class WindowItems {
public:
    static HWND hButton;

    static void createButton(HWND hwnd);
    static void drawButton(LPDRAWITEMSTRUCT dis);
};

#endif // WINDOW_ITEMS_H