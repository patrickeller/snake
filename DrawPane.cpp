#include <wx/wx.h>

#include "config.cpp"

#include "DrawPane.hpp"
#include "Arena.hpp"
#include "Snake.hpp"


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
    render(dc, nullptr, nullptr);
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
void BasicDrawPane::paintNow(int **arena, Snake *snake)
{
    wxClientDC dc(this);
    render(dc, arena, snake);
}

/*
 * Here we do the actual rendering. I put it in a separate
 * method so that it can work no matter what type of DC
 * (e.g. wxPaintDC or wxClientDC) is used.
 */
void BasicDrawPane::render(wxDC &dc, int **arena, Snake *snake)
{
    if (arena == nullptr && snake == nullptr)
        return;
    wxSize panelSize = dc.GetSize();

    wxSize roundedDrawSize = wxSize((int)panelSize.x / ARENA_WIDTH, (int)panelSize.y / ARENA_HEIGHT);

    int drawSize = std::min(roundedDrawSize.x, roundedDrawSize.y);

    int startX = (int)(panelSize.x - (drawSize * ARENA_WIDTH)) / 2;
    int startY = (int)(panelSize.y - (drawSize * ARENA_HEIGHT)) / 2;

    dc.Clear();
    for (unsigned int y = 0; y < ARENA_HEIGHT; y++)
    {
        for (unsigned int x = 0; x < ARENA_WIDTH; x++)
        {
            switch (arena[y][x])
            {
            case Arena::BORDER:
                dc.SetPen(*wxBLACK_PEN);
                dc.SetBrush(*wxBLACK_BRUSH);
                break;
            case Arena::SNACK:
                dc.SetPen(*wxGREEN_PEN);
                dc.SetBrush(*wxGREEN_BRUSH);
                break;
            case Arena::SNAKE:
                dc.SetPen(*wxYELLOW_PEN);
                dc.SetBrush(*wxYELLOW_BRUSH);
                break;
            }
            if (arena[y][x] != Arena::BLANK)
            {
                dc.DrawRectangle((x * drawSize) + startX, (y * drawSize) + startY, drawSize, drawSize);
            }
        }
    }

    int textSize = (int) drawSize / 2;

    wxFont font(textSize, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
    dc.SetFont(font);
    dc.SetTextForeground(wxColour(255,255,255));

    int textY = (int)(drawSize * (ARENA_HEIGHT - 1)) + drawSize / 4;
    int snakeSore = snake->history.size();
    wxString text = wxString::Format(wxT("Punkte: %i"), snakeSore);
    dc.DrawText(text, startX + drawSize, textY);
    

    for (int c = 0; c < ARENA_HEIGHT; c++)
    {
        if (arena[c] != nullptr)
        {
            delete[] arena[c];
        }
    }
    delete[] arena;
}