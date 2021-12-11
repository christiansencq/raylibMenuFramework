#ifndef LABEL_H
#define LABEL_H

#include "State.h"
#include <string>

class Label
{
public:
    Label(int left_x, int top_y, int w, int h, std::string str_label, Color txt_col, Color bg_col);
    ~Label();

    void DrawLabel();

    int GetX() { return x; }
    int GetY() { return y; }
    int GetW() { return w; }
    int GetH() { return h; }

private:
    int x, y;
    int w, h;
    Color txt_color;
    Color bg_color;

};

#endif
