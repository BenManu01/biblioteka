#include "SearchPanel.h"

SearchPanel::SearchPanel(wxWindow* parent, Library *lib) : wxPanel(parent, wxID_ANY)
{
    this->lib = lib;
    this->parent = parent;

    searchInput = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, 0);
    wxString searchChoices[] = {"Name", "Author", "Genre", "ISBN"};
    searchOption = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 4, searchChoices);
    searchOption->SetSelection(0);

    wxButton *searchButton = new wxButton(this, 0, "Search", wxDefaultPosition, wxDefaultSize, 0);
    Bind(wxEVT_BUTTON, &SearchPanel::OnSearch, this, 0);

    wxBoxSizer *searchSizer = new wxBoxSizer(wxHORIZONTAL);
    searchSizer->Add(searchInput, 1, wxEXPAND | wxALL, 5);
    searchSizer->Add(searchOption, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);
    searchSizer->Add(searchButton, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

    listPanel = new ListPanel(this);

    wxBoxSizer *mainSearchSizer = new wxBoxSizer(wxVERTICAL);
    mainSearchSizer->Add(searchSizer, 0, wxEXPAND | wxALL, 5);
    mainSearchSizer->Add(listPanel, 1, wxEXPAND | wxALL, 5);

    SetSizerAndFit(mainSearchSizer);
}

void SearchPanel::OnSearch(wxCommandEvent& event)
{
    listPanel->searchResultsGrid->ClearGrid();
    int numRows = listPanel->searchResultsGrid->GetNumberRows();

    for (int i = numRows - 1; i >= 0; --i) {
      listPanel->searchResultsGrid->DeleteRows(i);
    }

    vector<Book*> searchResults;

    wxString searchText = searchInput->GetValue();
    int searchOptionIndex = searchOption->GetSelection();

    searchResults = lib->search(searchText.ToStdString(), searchOptionIndex);

    listPanel->searchResultsGrid->AppendRows(searchResults.size());
    parent->Layout();

    for (int i = 0; i < searchResults.size(); ++i) {
        string genresText;
        for (int j = 0; j < searchResults[i]->genres.size(); j++) {
            genresText += searchResults[i]->genres[j];
            if (j != searchResults[i]->genres.size() - 1) {
                genresText += ", ";
            }
        }

        string availableText = searchResults[i]->available ? "Yes" : "No";

        listPanel->searchResultsGrid->SetCellValue(i, 0, searchResults[i]->name);
        listPanel->searchResultsGrid->SetCellValue(i, 1, searchResults[i]->author);
        listPanel->searchResultsGrid->SetCellValue(i, 2, genresText);
        listPanel->searchResultsGrid->SetCellValue(i, 3, searchResults[i]->isbn);
        listPanel->searchResultsGrid->SetCellValue(i, 4, availableText);
    }
}
