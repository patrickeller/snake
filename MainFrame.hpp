#pragma once
#include <wx/wx.h>

#include "Snake.hpp"
#include "DrawPane.hpp"

class MainFrame : public wxFrame
{
public:
    MainFrame(const wxString& title);
private:
    BasicDrawPane* drawPane;
    Snake snake;
    wxTimer *timer = nullptr;
    wxStaticText *arenaOutput;
    void OnTick(wxTimerEvent& evt);
    void OnKeyEvent(wxKeyEvent& evt);
};