// windowManager.h
#ifndef WINDOW_MANAGER_H
#define WINDOW_MANAGER_H

#include <windows.h>

/** 
 * @brief The WindowManager object
*/
class WindowManager {
public:
    static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
    int run(HINSTANCE hInstance, int nCmdShow);
};

#endif // WINDOW_MANAGER_H