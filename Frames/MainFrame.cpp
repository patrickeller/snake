#include "MainFrame.hpp"
#include <wx/wx.h>

#include "GameFrame.hpp"

MainFrame::MainFrame(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &pos, const wxSize &size, long style, const wxString &name) : wxFrame(parent, id, title, pos, size, style, name)
{
    this->SetSizeHints(wxSize(300, 250), wxSize(300, 250));
    this->SetForegroundColour(wxColour(0, 0, 0));
    this->SetBackgroundColour(wxColour(0, 128, 192));

    wxBoxSizer *sizer;
    sizer = new wxBoxSizer(wxVERTICAL);
    sizer->SetMinSize(wxSize(300, 250));

    m_staticText3 = new wxStaticText(this, wxID_ANY, wxT("Snake"), wxDefaultPosition, wxSize(-1, -1), 0);
    m_staticText3->Wrap(-1);
    m_staticText3->SetFont(wxFont(20, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_HEAVY, false, wxT("Arial Black")));

    sizer->Add(m_staticText3, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

    wxStaticBoxSizer *spSizer;
    spSizer = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, wxT("Singelplayer")), wxVERTICAL);

    startBtn = new wxButton(spSizer->GetStaticBox(), wxID_ANY, wxT("START!"), wxDefaultPosition, wxSize(-1, -1), 0);
    spSizer->Add(startBtn, 0, wxALL | wxEXPAND, 5);

    sizer->Add(spSizer, 0, wxEXPAND, 5);

    wxStaticBoxSizer *mpSizer;
    mpSizer = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, wxT("Multiplayer")), wxVERTICAL);

    wxGridSizer *gSizer2;
    gSizer2 = new wxGridSizer(2, 2, 0, 0);

    hostBtn = new wxButton(mpSizer->GetStaticBox(), wxID_ANY, wxT("Hosten"), wxDefaultPosition, wxDefaultSize, 0);
    gSizer2->Add(hostBtn, 0, wxALL | wxEXPAND, 5);

    hostPrvBtn = new wxButton(mpSizer->GetStaticBox(), wxID_ANY, wxT("Privat Hosten"), wxDefaultPosition, wxDefaultSize, 0);
    gSizer2->Add(hostPrvBtn, 0, wxALL | wxEXPAND, 5);

    joinBtn = new wxButton(mpSizer->GetStaticBox(), wxID_ANY, wxT("Beitreten"), wxDefaultPosition, wxDefaultSize, 0);
    gSizer2->Add(joinBtn, 0, wxALL | wxEXPAND, 5);

    joinPrvBtn = new wxButton(mpSizer->GetStaticBox(), wxID_ANY, wxT("Manuell Beitreten"), wxDefaultPosition, wxDefaultSize, 0);
    gSizer2->Add(joinPrvBtn, 0, wxALL | wxEXPAND, 5);

    mpSizer->Add(gSizer2, 1, wxEXPAND, 5);

    sizer->Add(mpSizer, 1, wxEXPAND, 5);

    this->SetSizer(sizer);
    this->Layout();

    this->Centre(wxBOTH);

    // Connect Events
    startBtn->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnStartClick), NULL, this);
    hostBtn->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnHostClick), NULL, this);
    hostPrvBtn->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnHostPrvClick), NULL, this);
    joinBtn->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnJoinClick), NULL, this);
    joinPrvBtn->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnJoinPrvClick), NULL, this);
}

void MainFrame::OnStartClick(wxCommandEvent &event)
{

    GameFrame *gameFrame = new GameFrame(this);
    gameFrame->SetClientSize(800, 800);
    gameFrame->Center();
    gameFrame->ShowFullScreen(true, wxFULLSCREEN_ALL);
    gameFrame->Show();
}

void MainFrame::OnHostClick(wxCommandEvent &event)
{
}

void MainFrame::OnHostPrvClick(wxCommandEvent &event)
{
}

void MainFrame::OnJoinClick(wxCommandEvent &event)
{
}

void MainFrame::OnJoinPrvClick(wxCommandEvent &event)
{
}

MainFrame::~MainFrame()
{
    // Disconnect Events
    startBtn->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnStartClick), NULL, this);
    hostBtn->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnHostClick), NULL, this);
    hostPrvBtn->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnHostPrvClick), NULL, this);
    joinBtn->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnJoinClick), NULL, this);
    joinPrvBtn->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnJoinPrvClick), NULL, this);
}
