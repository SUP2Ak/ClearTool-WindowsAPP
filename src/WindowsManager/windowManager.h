#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H
#define UNICODE
#define _UNICODE

#include <windows.h>

class WindowManager {
public:
    int run(HINSTANCE hInstance, int nCmdShow);
private:
    static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
};

#endif