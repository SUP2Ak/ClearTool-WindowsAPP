#include <windows.h>
#include "windowManager.h"

/**
 * @param hInstance Handle to the current instance of the application.
 * @param hPrevInstance Handle to the previous instance of the application.
 * @param lpCmdLine Command line for the application, excluding the program name.
 * @param nCmdShow Controls how the window is to be shown.
*/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    WindowManager windowManager; // Create a window manager.
    return windowManager.run(hInstance, nCmdShow); // Run the window manager.
};