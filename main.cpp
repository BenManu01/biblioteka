#include <wx/grid.h>

#include <iostream>
#include <vector>
#include <fstream>
#include "Client.h"
#include "Test.h"
#include "Menu.h"
#include "Tools.h"

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include <SettingsFrame.h>
#include <SearchPanel.h>
#include <SidePanel.h>

using namespace std;

class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};

class MyFrame : public wxFrame
{
public:
    MyFrame();

private:
    void OnHello(wxCommandEvent& event);
    void OnSettings(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);

    Library lib;
    Client c;
};

enum
{
    ID_Hello = 1,
    ID_Settings = 2,
    ID_Search = 3
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    MyFrame *frame = new MyFrame();
    frame->Show(true);
    return true;
}

MyFrame::MyFrame() : wxFrame(NULL, wxID_ANY, "BIBLIOTEKA")
{
    lib.load("books.txt");
    c.load(&lib);

    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&Hello...\tCtrl-H", "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);

    wxMenu *menuOptions = new wxMenu;
    menuOptions->Append(ID_Settings, "&Settings \tCtrl-P");

    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuOptions, "&Options");
    menuBar->Append(menuHelp, "&Help");

    SetMenuBar(menuBar);

    Bind(wxEVT_MENU, &MyFrame::OnHello, this, ID_Hello);
    Bind(wxEVT_MENU, &MyFrame::OnSettings, this, ID_Settings);
    Bind(wxEVT_MENU, &MyFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT);

    SearchPanel *searchPanel = new SearchPanel(this, &lib);
    SidePanel *sidePanel = new SidePanel(this, searchPanel);

    wxBoxSizer *dittoPanel = new wxBoxSizer(wxHORIZONTAL);
    dittoPanel->Add(searchPanel, 1, wxEXPAND | wxALL, 5);

    wxBoxSizer *mainSizer = new wxBoxSizer(wxHORIZONTAL);
    mainSizer->Add(sidePanel, 0, wxALIGN_LEFT | wxALL, 5);
    mainSizer->Add(dittoPanel, 1, wxEXPAND | wxALL, 5);

    SetSizerAndFit(mainSizer);
    SetSize(wxSize(800, 500));

}

void MyFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}

void MyFrame::OnAbout(wxCommandEvent& event)
{
    wxLogMessage("super biblioteka");
}

void MyFrame::OnHello(wxCommandEvent& event)
{
    wxLogMessage("Hello world from wxWidgets!");
}

void MyFrame::OnSettings(wxCommandEvent& event)
{
    SettingsFrame *frameSettings = new SettingsFrame();
    frameSettings->Show(true);
}

