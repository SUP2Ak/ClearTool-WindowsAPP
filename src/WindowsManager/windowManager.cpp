#include "windowManager.h"

/**
 * @param hwnd Handle to the window.
 * @param uMsg The message.
 * @param wParam Additional message information.
 * @param lParam Additional message information.
 * @return The result of the message processing and depends on the message sent.
*/
LRESULT CALLBACK WindowManager::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
    case WM_DESTROY:
        PostQuitMessage(0); // Posts a quit message to the thread's message queue.
        return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

/**
 * @param hInstance Handle to the current instance of the application.
 * @param nCmdShow Controls how the window is to be shown.
 * @return The exit code of the application.
*/
int WindowManager::run(HINSTANCE hInstance, int nCmdShow) {
    const wchar_t CLASS_NAME[]  = L"Sample Window Class";

    WNDCLASSW wc = { }; // Contains the window class attributes.
    wc.lpfnWndProc   = WindowProc; // Pointer to the window procedure.
    wc.hInstance     = hInstance; // Handle to the instance that contains the window procedure for the class.
    wc.lpszClassName = CLASS_NAME; // Pointer to a null-terminated string or an atom that specifies the class name.

    RegisterClassW(&wc);

    HWND hwnd = CreateWindowExW(
        0, // Optional window styles.
        CLASS_NAME, // Window class.
        L"ClearTool \u00A9 SUP2Ak", // Window title. (©)
        WS_OVERLAPPEDWINDOW, // Window style.
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, // Size and position.
        NULL, NULL, hInstance, NULL // No parent window, no menu, no additional data.
    );

    if (hwnd == NULL) {
        return 0;
    }

    // SetWindowTextW(hwnd, L"ClearTool \u00A9 SUP2Ak"); // Set the window title. (©)
    ShowWindow(hwnd, nCmdShow); // Show the window.

    MSG msg = { }; // Contains message information from a thread's message queue.
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg); // Translates virtual-key messages into character messages.
        DispatchMessage(&msg); // Dispatches a message to a window procedure.
    }

    return 0;
}