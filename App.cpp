#include "App.hpp"
#include "Frames/MainFrame.hpp"

#include <wx/wx.h>

bool App::OnInit(){
    MainFrame* mainFrame = new MainFrame("Snake");
    mainFrame->SetClientSize(800, 800);
    mainFrame->Center();
    //mainFrame->ShowFullScreen(true, wxFULLSCREEN_ALL);

    mainFrame->Show();
    return true;
}

wxIMPLEMENT_APP(App);