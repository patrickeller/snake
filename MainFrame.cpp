#include "MainFrame.hpp"
#include <wx/wx.h>

#include "config.cpp"

#include "Snake.hpp"
#include "Arena.hpp"

MainFrame::MainFrame(const wxString &title) : wxFrame(nullptr, wxID_ANY, title)
{
    wxPanel *panel = new wxPanel(this);

    panel->Bind(wxEVT_CHAR_HOOK, &MainFrame::OnKeyEvent, this);

    SetFont(wxFont(16, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));

    arenaOutput = new wxStaticText(this, wxID_ANY, "Example Text", wxPoint(0,0), wxSize(800, 800), wxALIGN_CENTRE | wxST_NO_AUTORESIZE);
    arenaOutput->IsDoubleBuffered();

    CreateStatusBar();

    // GAME
    snake.snack = snake.generateSnack();

    timer = new wxTimer(this, wxID_ANY);
    Bind(wxEVT_TIMER, &MainFrame::OnTick, this, timer->GetId());
    timer->Start(GAME_TICK);
}

void MainFrame::OnTick(wxTimerEvent &evt)
{
    if (!snake.moveSnake()){
        timer->Stop();
    }else{
        wxString arenaString(Arena::drawArena(snake).c_str(), wxConvWhateverWorks);
        arenaOutput->SetLabel(arenaString);
    }
}

void MainFrame::OnKeyEvent(wxKeyEvent &evt)
{
    int keyCode = evt.GetKeyCode();

    int xOffset = snake.history.end()[-1].x - snake.history.end()[-2].x;
    int yOffset = snake.history.end()[-1].y - snake.history.end()[-2].y;

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