#ifndef BUTTON_H
#define BUTTON_H

#include "State.h"
#include <string>

class Button
{
public:
    //Main menu button - Give the xy, wh, and the signal that we will forward to the MenuState
    Button(int left_x, int top_y, int w, int h, char* str_label, Color bg_col, StateSignal sig_gen);
    Button(int left_x, int top_y, char* str_label, int font_size, Color bg_col, Color txt_col, StateSignal sig_gen);
    ~Button();

    StateSignal Pressed();
    void DrawButton();

    int GetX() {return x;}
    int GetY() {return y;}
    int GetW() {return w;}
    int GetH() {return h;}

private:
    int x, y;
    int w, h;

    const char* c_label;
    int label_width;
    int font_size;

    //Bg and txt color
    Color bg_color;
    Color txt_color;

    StateSignal signal_to_send;

};

#endif
