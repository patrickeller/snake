#include "MainFrame.hpp"
#include <wx/wx.h>

#include "config.cpp"

#include "Snake.hpp"
#include "Arena.hpp"
#include "DrawPane.hpp"

#include "wx/sizer.h"

MainFrame::MainFrame(const wxString &title) : wxFrame(nullptr, wxID_ANY, title)
{
    wxPanel *panel = new wxPanel(this);
    panel->SetBackgroundColour(wxColour(*wxBLACK));

    panel->Bind(wxEVT_CHAR_HOOK, &MainFrame::OnKeyEvent, this);

    SetFont(wxFont(16, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));


    if(IS_SYMBOL_DRAWING){
        arenaOutput = new wxStaticText(this, wxID_ANY, "Example Text", wxPoint(0,0), wxSize(800, 800), wxALIGN_CENTRE | wxST_NO_AUTORESIZE);
        arenaOutput->IsDoubleBuffered();
        CreateStatusBar();
    }else{
        wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
        drawPane = new BasicDrawPane(panel);
        sizer->Add(drawPane, 1, wxEXPAND);
        panel->SetSizer(sizer);
        panel->SetAutoLayout(true);
        panel->IsDoubleBuffered();
    }
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
        wxMessageBox("Game Over!");
    }else{
        if(IS_SYMBOL_DRAWING){
            wxString arenaString(Arena::drawArenaSymbols(snake).c_str(), wxConvWhateverWorks);
            arenaOutput->SetLabel(arenaString);
        }else{
            int** arena = Arena::getArena(snake);
            drawPane->paintNow(arena, &snake);
        }
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