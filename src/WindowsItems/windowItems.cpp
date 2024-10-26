#include "WindowItems.h"

/** 
 * @brief The Button object
*/
HWND WindowItems::hButton;

/** 
 * @brief Create the Button object
 * @param hwnd 
*/
void WindowItems::createButton(HWND hwnd) {
    hButton = CreateWindowEx(
        0, L"BUTTON", L"Mon Bouton", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_OWNERDRAW,
        50, 50, 100, 30, hwnd, NULL, (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL);
}

/** 
 * @brief Draw the Button object
 * @param dis 
*/
void WindowItems::drawButton(LPDRAWITEMSTRUCT dis) {
    HDC hdc = dis->hDC;
    SetBkMode(hdc, TRANSPARENT);

    if (dis->itemState & ODS_SELECTED) {
        SetDCBrushColor(hdc, RGB(40, 40, 40)); // Couleur sombre
        FillRect(hdc, &dis->rcItem, (HBRUSH)GetStockObject(DC_BRUSH));
        SetTextColor(hdc, RGB(255, 255, 255)); // Texte blanc
    } else {
        SetDCBrushColor(hdc, RGB(50, 50, 50)); // Couleur de fond
        FillRect(hdc, &dis->rcItem, (HBRUSH)GetStockObject(DC_BRUSH));
        SetTextColor(hdc, RGB(200, 200, 200)); // Texte gris
    }

    DrawText(hdc, L"Mon Bouton", -1, &dis->rcItem, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}