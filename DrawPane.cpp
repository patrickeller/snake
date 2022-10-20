#include <wx/wx.h>

#include "config.cpp"

#include "DrawPane.hpp"
#include "Arena.hpp"

BasicDrawPane::BasicDrawPane(wxPanel *parent) : wxPanel(parent)
{
    this->Bind(wxEVT_PAINT, paintEvent, this);
}

/*
 * Called by the system of by wxWidgets when the panel needs
 * to be redrawn. You can also trigger this call by
 * calling Refresh()/Update().
 */

void BasicDrawPane::paintEvent(wxPaintEvent &evt)
{
    wxPaintDC dc(this);
    render(dc, nullptr);
}

/*
 * Alternatively, you can use a clientDC to paint on the panel
 * at any time. Using this generally does not free you from
 * catching paint events, since it is possible that e.g. the window
 * manager throws away your drawing when the window comes to the
 * background, and expects you will redraw it when the window comes
 * back (by sending a paint event).
 *
 * In most cases, this will not be needed at all; simply handling
 * paint events and calling Refresh() when a refresh is needed
 * will do the job.
 */
void BasicDrawPane::paintNow(int **arena)
{
    wxClientDC dc(this);
    render(dc, arena);
}

/*
 * Here we do the actual rendering. I put it in a separate
 * method so that it can work no matter what type of DC
 * (e.g. wxPaintDC or wxClientDC) is used.
 */
void BasicDrawPane::render(wxDC &dc, int **arena)
{
    if (arena == nullptr)return;
    //wxSize size = dc.GetSize();

    int drawSize = 15;

    dc.Clear();
    dc.SetBrush(*wxBLACK_BRUSH);  
    for (unsigned int y = 1; y <= ARENA_HEIGHT; y++)
    {
        for (unsigned int x = 1; x <= ARENA_WIDTH; x++)
        {
            if (arena[y][x] != Arena::BLANK)
            {
                dc.DrawRectangle(x*drawSize, y*drawSize, drawSize, drawSize);
            }
        }
    }

    for (int c = 1; c <= ARENA_HEIGHT; c++)
    {
        if(arena[c] != nullptr){
            delete [] arena[c];
        }
    }
    delete [] arena;
}