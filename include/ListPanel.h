#ifndef LISTPANEL_H
#define LISTPANEL_H

#include <wx/grid.h>
#include <wx/wxprec.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
class ListPanel : public wxPanel
{
  public:
    ListPanel(wxWindow* parent);

    wxGrid *searchResultsGrid;

};

#endif // LISTPANEL_H
