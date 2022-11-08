#pragma once
#include <wx/wx.h>

class MainFrame : public wxFrame
{
	private:
        void OnStart(wxCommandEvent &event);

	protected:
		wxStaticText* m_staticText6;
		wxButton* m_button1;

	public:
		MainFrame(wxString title);

};