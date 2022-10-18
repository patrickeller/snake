#include "MainFrame.hpp"
#include <wx/wx.h>

MainFrame::MainFrame(const wxString &title) : wxFrame(nullptr, wxID_ANY, title)
{
    wxPanel *panel = new wxPanel(this);

    panel->Bind(wxEVT_CHAR_HOOK, &MainFrame::OnKeyEvent, this);

    CreateStatusBar();
}

void MainFrame::OnKeyEvent(wxKeyEvent &evt)
{
    int keyCode = evt.GetKeyCode();

    wxString input;
    switch (keyCode)
    {
    case 87:
    case 315:
        input = "UP";
        break;
    case 83:
    case 317:
        input = "DOWN";
        break;
    case 65:
    case 314:
        input = "LEFT";
        break;
    case 68:
    case 316:
        input = "RIGHT";
        break;
    default:
        input = wxString::Format("%d", keyCode);;
        break;
    }

    wxLogStatus(input);
}