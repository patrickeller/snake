#include "MainFrame.hpp"
#include <wx/wx.h>

#include "GameFrame.hpp"

MainFrame::MainFrame(wxString title) : wxFrame(nullptr, wxID_ANY, title)
{
    this->SetSizeHints(wxDefaultSize, wxDefaultSize);
    this->SetForegroundColour(wxColour(0, 0, 0));
    this->SetBackgroundColour(wxColour(0, 128, 192));

    wxBoxSizer *bSizer1 = new wxBoxSizer(wxVERTICAL);

    m_staticText6 = new wxStaticText(this, wxID_ANY, wxT("Snake"), wxPoint(-1, -1), wxSize(100, -1), 0);
    m_staticText6->Wrap(-1);
    m_staticText6->SetFont(wxFont(20, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_HEAVY, false, wxT("Arial Black")));

    bSizer1->Add(m_staticText6, 0, wxALL, 5);

    wxButton *m_button1 = new wxButton(this, wxID_ANY, wxT("Start"), wxDefaultPosition, wxDefaultSize, 0);
    bSizer1->Add(m_button1, 0, wxALL, 5);

    this->SetSizer(bSizer1);
    this->Layout();

    this->Centre(wxBOTH);

    m_button1->Bind(wxEVT_BUTTON, &MainFrame::OnStart, this);
}

void MainFrame::OnStart(wxCommandEvent &event)
{
    GameFrame *gameFrame = new GameFrame("Snake");
    gameFrame->SetClientSize(800, 800);
    gameFrame->Center();
    // gameFrame->ShowFullScreen(true, wxFULLSCREEN_ALL);

    gameFrame->Show();
}