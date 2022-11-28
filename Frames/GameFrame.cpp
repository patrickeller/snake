#include "GameFrame.hpp"
#include <wx/wx.h>
#include <wx/sizer.h>

#include "../config.cpp"

#include "../Model/Snake.hpp"
#include "../Model/Arena.hpp"
#include "../Model/DrawPane.hpp"

GameFrame::GameFrame(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &pos, const wxSize &size, long style, const wxString &name) : wxFrame(parent, id, title, pos, size, style, name)
{
    wxPanel *panel = new wxPanel(this);
    panel->SetBackgroundColour(wxColour(*wxBLACK));

    panel->Bind(wxEVT_CHAR_HOOK, &GameFrame::OnKeyEvent, this);

    SetFont(wxFont(16, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));

    if (IS_SYMBOL_DRAWING)
    {
        arenaOutput = new wxStaticText(this, wxID_ANY, "Example Text", wxPoint(0, 0), wxSize(800, 800), wxALIGN_CENTRE | wxST_NO_AUTORESIZE);
        arenaOutput->IsDoubleBuffered();
        CreateStatusBar();
    }
    else
    {
        wxBoxSizer *sizer = new wxBoxSizer(wxHORIZONTAL);
        drawPane = new BasicDrawPane(panel);
        sizer->Add(drawPane, 1, wxEXPAND);
        panel->SetSizer(sizer);
        panel->SetAutoLayout(true);
        panel->IsDoubleBuffered();
    }
    // GAME
    // Snake snake = *new Snake();
    snake.snack = snake.generateSnack();

    timer = new wxTimer(this, wxID_ANY);
    Bind(wxEVT_TIMER, &GameFrame::OnTick, this, timer->GetId());
    timer->Start(GAME_TICK);
}

void GameFrame::OnTick(wxTimerEvent &evt)
{
    if (!snake.moveSnake())
    {
        timer->Stop();
        wxMessageBox(wxString::Format(wxT("Game Over!\nDein Score: %i"), (int)snake.history.size()));
        Close();
    }
    else
    {
        if (IS_SYMBOL_DRAWING)
        {
            wxString arenaString(Arena::drawArenaSymbols(snake).c_str(), wxConvWhateverWorks);
            arenaOutput->SetLabel(arenaString);
        }
        else
        {
            int **arena = Arena::getArena(snake);
            drawPane->manualDraw(arena, &snake);
        }
    }
}

void GameFrame::OnKeyEvent(wxKeyEvent &evt)
{
    int keyCode = evt.GetKeyCode();

    int xOffset = snake.history[0].x - snake.history[1].x;
    int yOffset = snake.history[0].y - snake.history[1].y;

    switch (keyCode)
    {
    case 87:
    case 315:
        if (yOffset != 1)
        {
            snake.directionY = -1;
            snake.directionX = 0;
        }
        break;
    case 83:
    case 317:
        if (yOffset != -1)
        {
            snake.directionY = 1;
            snake.directionX = 0;
        }
        break;
    case 65:
    case 314:
        if (xOffset != 1)
        {
            snake.directionX = -1;
            snake.directionY = 0;
        }
        break;
    case 68:
    case 316:
        if (xOffset != -1)
        {
            snake.directionX = 1;
            snake.directionY = 0;
        }
        break;
    }
}