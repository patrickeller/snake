#pragma once
#include <wx/wx.h>

#include "../Model/Snake.hpp"
#include "../Model/DrawPane.hpp"

class GameFrame : public wxFrame
{
public:
    GameFrame(wxWindow *parent, wxWindowID id = wxID_ANY, const wxString &title = wxT("Snake"), const wxPoint &pos = wxDefaultPosition, const wxSize &size = wxSize(300, 250), long style = wxCAPTION | wxCLOSE_BOX | wxTAB_TRAVERSAL, const wxString &name = wxT("Snake"));

private:
    BasicDrawPane *drawPane;
    Snake snake;
    wxTimer *timer = nullptr;
    wxStaticText *arenaOutput;
    void OnTick(wxTimerEvent &evt);
    void OnKeyEvent(wxKeyEvent &evt);
};