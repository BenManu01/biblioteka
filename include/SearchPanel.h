#ifndef SEARCHPANEL_H
#define SEARCHPANEL_H

#include <wx/grid.h>
#include <wx/wxprec.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include <vector>
#include "Client.h"
#include "ListPanel.h"


class SearchPanel : public wxPanel
{
  public:
    SearchPanel(wxWindow* parent, Library *lib);

    wxTextCtrl *searchInput;
    wxChoice *searchOption;

    ListPanel *listPanel;

    Library *lib;
    wxWindow *parent;

    void OnSearch(wxCommandEvent& event);
};

#endif // SEARCHPANEL_H
