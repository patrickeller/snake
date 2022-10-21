#pragma once

#include <wx/wx.h>

#include "Snake.hpp"

class BasicDrawPane : public wxPanel
{
public:
    BasicDrawPane(wxPanel *parent);
    void paintEvent(wxPaintEvent &evt);
    void paintNow(int** arena, Snake *snake);
    void render(wxDC &dc, int** arena, Snake *snake);
};