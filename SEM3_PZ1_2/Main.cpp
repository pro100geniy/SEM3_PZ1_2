#include <iostream>
#include <windows.h>
#include <conio.h>

struct color {
    int R;
    int G;
    int B;
};
class Rect {

private:
    COORD left_bottom;
    COORD right_top;
    color color_type;

public:
    Rect() {
        left_bottom = {};
        right_top = {}; 
        color_type = {};
    
    }
    void set_rect(COORD lb, COORD rb, color c) {
        left_bottom = lb;
        right_top = rb;
        color_type = c;
    }

    void draw_rect() {
        
        HWND hWindow = GetConsoleWindow();
        HDC hDeviceContext = GetDC(hWindow);
        HBRUSH hBrush = CreateSolidBrush(RGB(color_type.R, color_type.G, color_type.B));
        SelectObject(hDeviceContext, hBrush);
        Rectangle(hDeviceContext, left_bottom.X, left_bottom.Y, right_top.X, right_top.Y);
        
        DeleteObject(hBrush);
        ReleaseDC(hWindow, hDeviceContext);
        
    }
};



int main() {
    system("color 3F");
    Rect obj1, obj2, obj3, obj4;

    obj1.set_rect({100,100}, { 200,300 }, { 255,0,255 });
    obj2.set_rect({ 300,300 }, { 400,400 }, { 0,255,0 });
    obj3.set_rect({500,100 }, { 600,400 }, { 255,255,0 });
    obj4.set_rect({ 700,200 }, { 800,400 }, { 100,255,255 });

    obj1.draw_rect();
    obj2.draw_rect();
    obj3.draw_rect();
    obj4.draw_rect();

    getchar();
    return 0;
}