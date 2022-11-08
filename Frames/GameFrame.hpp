#pragma once
#include <wx/wx.h>

#include "../Model/Snake.hpp"
#include "../Model/DrawPane.hpp"

class GameFrame : public wxFrame
{
public:
    GameFrame(const wxString& title);
private:
    BasicDrawPane* drawPane;
    Snake snake;
    wxTimer *timer = nullptr;
    wxStaticText *arenaOutput;
    void OnTick(wxTimerEvent& evt);
    void OnKeyEvent(wxKeyEvent& evt);
};