#pragma once
#include <wx/wx.h>

#include "Snake.hpp"

class MainFrame : public wxFrame
{
public:
    MainFrame(const wxString& title);
private:
    Snake snake;
    wxTimer *timer = nullptr;
    wxStaticText *arenaOutput;
    void OnTick(wxTimerEvent& evt);
    void OnKeyEvent(wxKeyEvent& evt);
};