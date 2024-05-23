#include "SidePanel.h"

SidePanel::SidePanel(wxWindow* parent, wxPanel* searchPanel) : wxPanel(parent, wxID_ANY)
{
  this->parent = parent;
  this->searchPanel = searchPanel;

  wxButton *libraryButton = new wxButton(this, 0, "Library", wxDefaultPosition, wxDefaultSize, 0);
  wxButton *clientButton = new wxButton(this, 1, "Client", wxDefaultPosition, wxDefaultSize, 0);
  wxButton *profileButton = new wxButton(this, 2, "Profile", wxDefaultPosition, wxDefaultSize, 0);
  wxBoxSizer *sideSizer = new wxBoxSizer(wxVERTICAL);
  sideSizer->Add(libraryButton, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);
  sideSizer->Add(clientButton, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);
  sideSizer->Add(profileButton, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

  SetSizerAndFit(sideSizer);

  Bind(wxEVT_BUTTON, &SidePanel::OnLibrary, this, 0);
  Bind(wxEVT_BUTTON, &SidePanel::OnClient, this, 1);
}

void SidePanel::OnLibrary(wxCommandEvent& event){
  std::cout << "library" << std::endl;
  wxSizerItemList children = parent->GetSizer()->GetChildren();
  wxSizerItem* secondItem = children[1];
  wxSizer* dittoSizer = secondItem->GetSizer();
  dittoSizer->Clear();

  dittoSizer->Add(searchPanel, 1, wxEXPAND | wxALL, 5);

  parent->GetSizer()->Layout();


}
void SidePanel::OnClient(wxCommandEvent& event){
  std::cout << "client" << std::endl;

  wxSizerItemList children = parent->GetSizer()->GetChildren();
  wxSizerItem* secondItem = children[1];
  wxSizer* dittoSizer = secondItem->GetSizer();
  dittoSizer->Clear();
  dittoSizer->Layout();
}
