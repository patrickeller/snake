#pragma once

#include <wx/wx.h>

#include "Snake.hpp"

class BasicDrawPane : public wxPanel
{
public:
    int **arenaBuffer;
    int snakeScoreBuffer;
    BasicDrawPane(wxPanel *parent);
    void onPaint(wxPaintEvent &evt);
    void onResize(wxSizeEvent &evt);
    void autoDraw();
    void manualDraw(int **arena, Snake *snake);
    void render(wxDC &dc, int **arena, int snakeScoreBuffer, bool forceRewirte);
};