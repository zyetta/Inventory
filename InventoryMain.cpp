/***************************************************************
 * Name:      InventoryMain.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2021-01-17
 * Copyright:  ()
 * License:
 **************************************************************/

//================== Included Libraries ==================

#include <wx/msgdlg.h>
#include <iostream>
//(*InternalHeaders(InventoryFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)
#include "InventoryMain.h"
#include "sqlite3.h"
#include <string>
using namespace std;

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}


//================== Global Constants ==================

const char* filename = "data.db";
sqlite3 *database;

//(*IdInit(InventoryFrame)
const long InventoryFrame::ID_STATICBOX3 = wxNewId();
const long InventoryFrame::ID_STATICBOX2 = wxNewId();
const long InventoryFrame::ID_STATICBOX1 = wxNewId();
const long InventoryFrame::ID_BUTTON1 = wxNewId();
const long InventoryFrame::ID_STATICTEXT1 = wxNewId();
const long InventoryFrame::ID_TEXTCTRL1 = wxNewId();
const long InventoryFrame::ID_STATICTEXT2 = wxNewId();
const long InventoryFrame::ID_STATICTEXT3 = wxNewId();
const long InventoryFrame::ID_TEXTCTRL2 = wxNewId();
const long InventoryFrame::ID_TEXTCTRL3 = wxNewId();
const long InventoryFrame::ID_TEXTCTRL5 = wxNewId();
const long InventoryFrame::ID_STATICTEXT4 = wxNewId();
const long InventoryFrame::ID_STATICTEXT5 = wxNewId();
const long InventoryFrame::ID_TEXTCTRL6 = wxNewId();
const long InventoryFrame::ID_TEXTCTRL7 = wxNewId();
const long InventoryFrame::ID_STATICTEXT6 = wxNewId();
const long InventoryFrame::ID_STATICTEXT7 = wxNewId();
const long InventoryFrame::ID_TEXTCTRL8 = wxNewId();
const long InventoryFrame::ID_STATICTEXT9 = wxNewId();
const long InventoryFrame::ID_STATICTEXT10 = wxNewId();
const long InventoryFrame::ID_SPINCTRL1 = wxNewId();
const long InventoryFrame::ID_STATICTEXT8 = wxNewId();
const long InventoryFrame::ID_COMBOBOX1 = wxNewId();
const long InventoryFrame::ID_STATICTEXT11 = wxNewId();
const long InventoryFrame::ID_BUTTON2 = wxNewId();
const long InventoryFrame::ID_STATICTEXT12 = wxNewId();
const long InventoryFrame::ID_PANEL3 = wxNewId();
const long InventoryFrame::ID_NOTEBOOK1 = wxNewId();
const long InventoryFrame::idMenuQuit = wxNewId();
const long InventoryFrame::idMenuAbout = wxNewId();
const long InventoryFrame::ID_TIMER1 = wxNewId();
//*)



BEGIN_EVENT_TABLE(InventoryFrame,wxFrame)
    //(*EventTable(InventoryFrame)
    //*)
END_EVENT_TABLE()

//================== Class Constructor ==================



InventoryFrame::InventoryFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(InventoryFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(1175,435));
    Notebook1 = new wxNotebook(this, ID_NOTEBOOK1, wxPoint(0,0), wxSize(950,540), 0, _T("ID_NOTEBOOK1"));
    Panel3 = new wxPanel(Notebook1, ID_PANEL3, wxPoint(1,70), wxSize(1173,392), wxTAB_TRAVERSAL, _T("ID_PANEL3"));
    StaticBox1 = new wxStaticBox(Panel3, ID_STATICBOX3, wxEmptyString, wxPoint(600,232), wxSize(560,128), 0, _T("ID_STATICBOX3"));
    StaticBox_ItemInfo = new wxStaticBox(Panel3, ID_STATICBOX2, _("ITEM INFORMATION"), wxPoint(16,16), wxSize(560,216), wxALWAYS_SHOW_SB, _T("ID_STATICBOX2"));
    StaticBox_VendorInfo = new wxStaticBox(Panel3, ID_STATICBOX1, _("VENDOR INFORMATION"), wxPoint(600,16), wxSize(560,216), 0, _T("ID_STATICBOX1"));
    AddEntry = new wxButton(Panel3, ID_BUTTON1, _("ADD ENTRY"), wxPoint(16,280), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    StaticText_ItemName = new wxStaticText(Panel3, ID_STATICTEXT1, _("ITEM NAME"), wxPoint(32,48), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    TextCtrl_ItemName = new wxTextCtrl(Panel3, ID_TEXTCTRL1, wxEmptyString, wxPoint(184,40), wxSize(376,34), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    StaticText_ItemDesc = new wxStaticText(Panel3, ID_STATICTEXT2, _("DESCRIPTION"), wxPoint(32,96), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    StaticText_Manufacturer = new wxStaticText(Panel3, ID_STATICTEXT3, _("MANUFACTURER"), wxPoint(32,144), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    TextCtrl_Description = new wxTextCtrl(Panel3, ID_TEXTCTRL2, wxEmptyString, wxPoint(184,88), wxSize(376,34), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    TextCtrl_VendorURL = new wxTextCtrl(Panel3, ID_TEXTCTRL3, wxEmptyString, wxPoint(768,184), wxSize(376,34), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    TextCtrl_VendorCost = new wxTextCtrl(Panel3, ID_TEXTCTRL5, wxEmptyString, wxPoint(768,136), wxSize(376,34), 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
    StaticText4 = new wxStaticText(Panel3, ID_STATICTEXT4, _("VENDOR ITEM NO."), wxPoint(616,96), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    StaticText5 = new wxStaticText(Panel3, ID_STATICTEXT5, _("VENDOR NAME"), wxPoint(616,48), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    TextCtrl_VendorName = new wxTextCtrl(Panel3, ID_TEXTCTRL6, wxEmptyString, wxPoint(768,40), wxSize(376,34), 0, wxDefaultValidator, _T("ID_TEXTCTRL6"));
    TextCtrl_VenderNumber = new wxTextCtrl(Panel3, ID_TEXTCTRL7, wxEmptyString, wxPoint(768,88), wxSize(376,34), 0, wxDefaultValidator, _T("ID_TEXTCTRL7"));
    StaticText6 = new wxStaticText(Panel3, ID_STATICTEXT6, _("VENDOR UNIT COST"), wxPoint(616,144), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    StaticText7 = new wxStaticText(Panel3, ID_STATICTEXT7, _("VENDOR WEB URL"), wxPoint(616,192), wxDefaultSize, 0, _T("ID_STATICTEXT7"));
    TextCtrl_Manufacturer = new wxTextCtrl(Panel3, ID_TEXTCTRL8, wxEmptyString, wxPoint(184,136), wxSize(376,34), 0, wxDefaultValidator, _T("ID_TEXTCTRL8"));
    StaticText9 = new wxStaticText(Panel3, ID_STATICTEXT9, _("CATEGORY"), wxPoint(32,192), wxDefaultSize, 0, _T("ID_STATICTEXT9"));
    StaticText10 = new wxStaticText(Panel3, ID_STATICTEXT10, _("QUANTITY"), wxPoint(616,264), wxDefaultSize, 0, _T("ID_STATICTEXT10"));
    SpinCtrl_Quantity = new wxSpinCtrl(Panel3, ID_SPINCTRL1, _T("1"), wxPoint(768,256), wxSize(376,34), 0, 0, 100000, 1, _T("ID_SPINCTRL1"));
    SpinCtrl_Quantity->SetValue(_T("1"));
    StaticText_Notification = new wxStaticText(Panel3, ID_STATICTEXT8, wxEmptyString, wxPoint(184,288), wxDefaultSize, 0, _T("ID_STATICTEXT8"));
    ComboBox_Category = new wxComboBox(Panel3, ID_COMBOBOX1, wxEmptyString, wxPoint(184,184), wxSize(376,34), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX1"));
    StaticText1 = new wxStaticText(Panel3, ID_STATICTEXT11, _("DATASHEET"), wxPoint(616,312), wxDefaultSize, 0, _T("ID_STATICTEXT11"));
    Button_UploadDatasheet = new wxButton(Panel3, ID_BUTTON2, _("Find"), wxPoint(768,304), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    StaticText2 = new wxStaticText(Panel3, ID_STATICTEXT12, wxEmptyString, wxPoint(872,320), wxDefaultSize, 0, _T("ID_STATICTEXT12"));
    Notebook1->AddPage(Panel3, _("ADD ITEMS"), false);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    Timer1.SetOwner(this, ID_TIMER1);
    Timer1.Start(1000, true);
    FileDialog1 = new wxFileDialog(this, _("Select file"), _("$USER"), wxEmptyString, wxFileSelectorDefaultWildcardStr, wxFD_DEFAULT_STYLE, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&InventoryFrame::OnAddEntryClick);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&InventoryFrame::OnButton_UploadDatasheetClick);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&InventoryFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&InventoryFrame::OnAbout);
    Connect(ID_TIMER1,wxEVT_TIMER,(wxObjectEventFunction)&InventoryFrame::OnTimer1Trigger);
    //*)

    CreateDatabase(database, filename);
}



InventoryFrame::~InventoryFrame()
{
    //(*Destroy(InventoryFrame)
    //*)
}

//================== Event Handlers ==================
void InventoryFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void InventoryFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void InventoryFrame::OnSearchEntryClick(wxCommandEvent& event)
{
}


void InventoryFrame::OnAddEntryClick(wxCommandEvent& event)
{
    string pSQL = "INSERT INTO Stock(ItemName, ItemDescription, Manufacturer, Category, VendorName, VendorItemNo, VendorUnitCost, VendorWebURL, Quantity) VALUES ('";
    pSQL += string(TextCtrl_ItemName->GetValue()) + "','" + string(TextCtrl_Description->GetValue()) + "','" + string(TextCtrl_Manufacturer->GetValue()) + "','" + string(ComboBox_Category->GetValue()) + "','";
    pSQL += string(TextCtrl_VendorName->GetValue()) + "','" + string(TextCtrl_VenderNumber->GetValue()) + "'," + string(TextCtrl_VendorCost->GetValue()) + ",'" + string(TextCtrl_VendorURL->GetValue()) + "',";
    pSQL += to_string(SpinCtrl_Quantity->GetValue()) + ");";
    const char* pSQL_c = pSQL.c_str();

    InsertDatabase(database, filename, pSQL_c);
    StaticText_Notification->SetLabel("Successfully Added!");
    Timer1.Start(3000, true);

    TextCtrl_ItemName->Clear();
    TextCtrl_Description->Clear();
    TextCtrl_Manufacturer->Clear();
    ComboBox_Category->Clear();

    TextCtrl_VendorName->Clear();
    TextCtrl_VenderNumber->Clear();
    TextCtrl_VendorCost->Clear();
    TextCtrl_VendorURL->Clear();
    SpinCtrl_Quantity->SetValue(1);
}

void InventoryFrame::OnTimer1Trigger(wxTimerEvent& event)
{
    StaticText_Notification->SetLabel("");
}


//================== User Functions ==================
static int callback(void *NotUsed, int argc, char **argv, char **szColName) {
  for(int i = 0; i < argc; i++) {
    cout << szColName[i] << " = " << argv[i] << endl;
  }
  cout << endl;
  return 0;
}


void InventoryFrame::CreateDatabase(sqlite3* db, const char* filename) {
    const char *pSQL = "CREATE TABLE Stock(ItemName varchar(30), ItemDescription varchar(100), Manufacturer varchar(30), "
    "Category varchar(30), VendorName varchar(30), VendorItemNo varchar(30), VendorUnitCost REAL, VendorWebURL BLOB, Quantity INTEGER);";
    char *szErrMsg = 0;
    int rc = sqlite3_open(filename, &db);
    if(rc) {
        cout << "Error: Can't open database." << endl;
    }
    rc = sqlite3_exec(db, pSQL, callback, 0, &szErrMsg);
    if(rc != SQLITE_OK) {
        cout << "SQL Error: " << szErrMsg << endl;
        sqlite3_free(szErrMsg);
    }
    if(db) {
        sqlite3_close(db);
    }
}

void InventoryFrame::InsertDatabase(sqlite3* db, const char* filename, const char* data) {
    char *szErrMsg = 0;
    int rc = sqlite3_open(filename, &db);
    if(rc) {
        cout << "Error: Can't open database." << endl;
    }
    rc = sqlite3_exec(db, data, callback, 0, &szErrMsg);
    if(rc != SQLITE_OK) {
        cout << "SQL Error: " << szErrMsg << endl;
        sqlite3_free(szErrMsg);
    }
    if(db) {
        sqlite3_close(db);
    }
}








void InventoryFrame::OnButton_UploadDatasheetClick(wxCommandEvent& event)
{
    if (FileDialog1->ShowModal() == wxID_CANCEL) {
        return;
    }

    StaticText2->SetLabel(FileDialog1->GetFilename());



}
