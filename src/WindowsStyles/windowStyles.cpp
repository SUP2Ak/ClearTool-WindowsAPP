#include "WindowStyles.h"
#include <uxtheme.h>
#include <vssym32.h>

/** 
 * @brief Set the Dark Theme object
 * @param hwnd 
*/
void WindowStyles::setDarkTheme(HWND hwnd) {
    SetThemeAppProperties(0);
    // Autres propriétés de thème si nécessaire
}

/** 
 * @brief Set the Layered Attributes object
 * @param hwnd 
*/
void WindowStyles::setLayeredAttributes(HWND hwnd) {
    SetLayeredWindowAttributes(hwnd, RGB(0, 0, 0), 255, LWA_COLORKEY);
}