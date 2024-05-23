#include "ListPanel.h"

ListPanel::ListPanel(wxWindow* parent) : wxPanel(parent, wxID_ANY)
{
    searchResultsGrid = new wxGrid(this, wxID_ANY);
    searchResultsGrid->EnableEditing(false);
    searchResultsGrid->CreateGrid(0, 5);

    searchResultsGrid->SetColLabelValue(0, "Name");
    searchResultsGrid->SetColLabelValue(1, "Author");
    searchResultsGrid->SetColLabelValue(2, "Genre");
    searchResultsGrid->SetColLabelValue(3, "ISBN");
    searchResultsGrid->SetColLabelValue(4, "Available");

    wxBoxSizer *gridSizer = new wxBoxSizer(wxVERTICAL);
    gridSizer->SetSizeHints(this);
    gridSizer->Add(searchResultsGrid, 1, wxEXPAND | wxALL, 5);

    SetSizerAndFit(gridSizer);
}
