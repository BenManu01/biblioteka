#ifndef SETTINGSFRAME_H
#define SETTINGSFRAME_H

#include <iostream>
#include <wx/wxprec.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif


class SettingsFrame : public wxFrame
{
  public:
    SettingsFrame();
    wxStaticText *label;
    wxTextCtrl *input;
    void OnButtonClicked(wxCommandEvent& event);

};

#endif // SETTINGSFRAME_H
