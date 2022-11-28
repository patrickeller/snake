#pragma once
#include <wx/wx.h>

class MainFrame : public wxFrame
{
private:
protected:
	wxStaticText *m_staticText3;
	wxButton *startBtn;
	wxButton *hostBtn;
	wxButton *hostPrvBtn;
	wxButton *joinBtn;
	wxButton *joinPrvBtn;

	// Virtual event handlers, override them in your derived class
	void OnStartClick(wxCommandEvent &event);
	void OnHostClick(wxCommandEvent &event);
	void OnHostPrvClick(wxCommandEvent &event);
	void OnJoinClick(wxCommandEvent &event);
	void OnJoinPrvClick(wxCommandEvent &event);

public:
	MainFrame(wxWindow *parent, wxWindowID id = wxID_ANY, const wxString &title = wxT("Snake"), const wxPoint &pos = wxDefaultPosition, const wxSize &size = wxSize(300, 250), long style = wxCAPTION | wxCLOSE_BOX | wxTAB_TRAVERSAL, const wxString &name = wxT("Snake"));

	~MainFrame();
};