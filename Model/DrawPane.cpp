#include <wx/wx.h>

#include "../config.cpp"

#include "DrawPane.hpp"
#include "Arena.hpp"
#include "Snake.hpp"

BasicDrawPane::BasicDrawPane(wxPanel *parent) : wxPanel(parent)
{
    this->arenaBuffer = nullptr;
    this->snakeScoreBuffer = 0;
    this->Bind(wxEVT_PAINT, onPaint, this);
    this->Bind(wxEVT_SIZE, onResize, this);
}

void BasicDrawPane::onPaint(wxPaintEvent &evt)
{
    wxPaintDC dc(this);
    render(dc, this->arenaBuffer, this->snakeScoreBuffer, true);
}

void BasicDrawPane::onResize(wxSizeEvent &evt)
{
    wxClientDC dc(this);
    render(dc, arenaBuffer, snakeScoreBuffer, true);
}

void BasicDrawPane::manualDraw(int **arena, Snake *snake)
{
    wxClientDC dc(this);
    render(dc, arena, snake->history.size(), false);

    if (this->arenaBuffer != nullptr)
    {
        for (int c = 0; c < ARENA_HEIGHT; c++)
        {
            if (this->arenaBuffer[c] != nullptr)
            {
                delete[] this->arenaBuffer[c];
            }
        }
        delete[] this->arenaBuffer;
    }

    this->arenaBuffer = arena;
    this->snakeScoreBuffer = snake->history.size();
}

void BasicDrawPane::render(wxDC &dc, int **arena, int snakeScore, bool forceRewirte = false)
{
    if (arena == nullptr)
        return;
    wxSize panelSize = dc.GetSize();

    wxSize roundedDrawSize = wxSize((int)panelSize.x / ARENA_WIDTH, (int)panelSize.y / ARENA_HEIGHT);

    int drawSize = std::min(roundedDrawSize.x, roundedDrawSize.y);

    int startX = (int)(panelSize.x - (drawSize * ARENA_WIDTH)) / 2;
    int startY = (int)(panelSize.y - (drawSize * ARENA_HEIGHT)) / 2;

    if (forceRewirte)
        dc.Clear();

    for (unsigned int y = 0; y < ARENA_HEIGHT; y++)
    {
        for (unsigned int x = 0; x < ARENA_WIDTH; x++)
        {
            if (forceRewirte == true || arenaBuffer == nullptr || (arena[y][x] != arenaBuffer[y][x]))
            {
                switch (arena[y][x])
                {
                case Arena::BORDER:
                    dc.SetPen(*wxBLACK_PEN);
                    dc.SetBrush(*wxBLACK_BRUSH);
                    break;
                case Arena::SNACK:
                    dc.SetPen(*wxYELLOW_PEN);
                    dc.SetBrush(*wxYELLOW_BRUSH);
                    break;
                case Arena::SNAKE_LIGHT:
                    dc.SetPen(wxPen(wxColor(144, 238, 144)));
                    dc.SetBrush(wxBrush(wxColor(144, 238, 144)));
                    break;
                case Arena::SNAKE_DARK:
                    dc.SetPen(wxPen(wxColor(0, 100, 0)));
                    dc.SetBrush(wxBrush(wxColor(0, 100, 0)));
                    break;
                case Arena::BLANK:
                    dc.SetPen(*wxWHITE_PEN);
                    dc.SetBrush(*wxWHITE_BRUSH);
                    break;
                }
                dc.DrawRectangle((x * drawSize) + startX, (y * drawSize) + startY, drawSize, drawSize);
            }
        }
    }

    if (forceRewirte == true || snakeScoreBuffer != 0 || snakeScore != snakeScoreBuffer)
    {
        int textSize = (int)drawSize / 2;
        wxFont font(textSize, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
        dc.SetFont(font);
        dc.SetBackgroundMode(wxSOLID);
        dc.SetTextForeground(wxColour(255, 255, 255));
        dc.SetTextBackground(wxColour(0, 0, 0));

        int textY = (int)(drawSize * (ARENA_HEIGHT - 1)) + drawSize / 4;
        wxString text = wxString::Format(wxT("Punkte: %i"), snakeScoreBuffer);
        dc.DrawText(text, startX + drawSize, textY);
    }
}