#include "SettingsFrame.h"

SettingsFrame :: SettingsFrame() : wxFrame(NULL, wxID_ANY, "Settings")
{
  wxPanel* panel = new wxPanel(this, wxID_ANY);

  wxButton *button = new wxButton(panel, wxID_ANY, "buttonik", wxPoint(10, 10), wxDefaultSize);

  input = new wxTextCtrl(panel, wxID_ANY, "enter text...", wxPoint(100, 10), wxDefaultSize);

  button->Bind(wxEVT_BUTTON, &SettingsFrame::OnButtonClicked, this);

  label = new wxStaticText(panel, wxID_ANY, "text", wxPoint(10, 40), wxDefaultSize);
}

void SettingsFrame :: OnButtonClicked(wxCommandEvent& event)
  {
    label->SetLabel(input->GetValue());
  }
