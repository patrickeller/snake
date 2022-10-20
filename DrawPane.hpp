#pragma once

#include <wx/wx.h>

class BasicDrawPane : public wxPanel
{
public:
    BasicDrawPane(wxPanel *parent);
    void paintEvent(wxPaintEvent &evt);
    void paintNow(int** arena);
    void render(wxDC &dc, int** arena);
};