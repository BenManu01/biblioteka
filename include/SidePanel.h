#ifndef SIDEPANEL_H
#define SIDEPANEL_H

#include <wx/grid.h>
#include <wx/wxprec.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
class SidePanel : public wxPanel
{
  public:
    SidePanel(wxWindow* parent, wxPanel* searchPanel);

    void OnLibrary(wxCommandEvent&);
    void OnClient(wxCommandEvent&);

    wxWindow *parent;

    wxSizer* dittoSizer;
    wxPanel* searchPanel;

};

#endif // SIDEPANEL_H
