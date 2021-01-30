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
#include <wx/wx.h>
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/wxsqlite3.h>
#include "InventoryMain.h"
#include <iostream>
#include <string>
#include <time.h>
using namespace std;


//================== Function Prototypes ==================

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

string filename = "data.db";
wxSQLite3Database* database = new wxSQLite3Database();


//(*IdInit(InventoryFrame)
const long InventoryFrame::ID_STATICTEXT13 = wxNewId();
const long InventoryFrame::ID_STATICTEXT14 = wxNewId();
const long InventoryFrame::ID_STATICTEXT15 = wxNewId();
const long InventoryFrame::ID_STATICTEXT16 = wxNewId();
const long InventoryFrame::ID_GRID1 = wxNewId();
const long InventoryFrame::ID_COMBOBOX4 = wxNewId();
const long InventoryFrame::ID_COMBOBOX5 = wxNewId();
const long InventoryFrame::ID_COMBOBOX6 = wxNewId();
const long InventoryFrame::ID_COMBOBOX7 = wxNewId();
const long InventoryFrame::ID_HYPERLINKCTRL1 = wxNewId();
const long InventoryFrame::ID_HYPERLINKCTRL2 = wxNewId();
const long InventoryFrame::ID_STATICLINE1 = wxNewId();
const long InventoryFrame::ID_BUTTON3 = wxNewId();
const long InventoryFrame::ID_BUTTON4 = wxNewId();
const long InventoryFrame::ID_STATICTEXT17 = wxNewId();
const long InventoryFrame::ID_PANEL1 = wxNewId();
const long InventoryFrame::ID_STATICBOX4 = wxNewId();
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
const long InventoryFrame::ID_TEXTCTRL7 = wxNewId();
const long InventoryFrame::ID_STATICTEXT6 = wxNewId();
const long InventoryFrame::ID_STATICTEXT7 = wxNewId();
const long InventoryFrame::ID_STATICTEXT9 = wxNewId();
const long InventoryFrame::ID_STATICTEXT10 = wxNewId();
const long InventoryFrame::ID_SPINCTRL1 = wxNewId();
const long InventoryFrame::ID_STATICTEXT8 = wxNewId();
const long InventoryFrame::ID_COMBOBOX1 = wxNewId();
const long InventoryFrame::ID_STATICTEXT11 = wxNewId();
const long InventoryFrame::ID_BUTTON2 = wxNewId();
const long InventoryFrame::ID_STATICTEXT12 = wxNewId();
const long InventoryFrame::ID_COMBOBOX2 = wxNewId();
const long InventoryFrame::ID_COMBOBOX3 = wxNewId();
const long InventoryFrame::ID_CHECKBOX1 = wxNewId();
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
    SetClientSize(wxSize(1200,390));
    SetMinSize(wxSize(1200,390));
    SetMaxSize(wxSize(1200,390));
    Notebook1 = new wxNotebook(this, ID_NOTEBOOK1, wxPoint(0,0), wxSize(950,450), 0, _T("ID_NOTEBOOK1"));
    Panel1 = new wxPanel(Notebook1, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT13, _("1. CATEGORY"), wxPoint(24,24), wxDefaultSize, 0, _T("ID_STATICTEXT13"));
    StaticText8 = new wxStaticText(Panel1, ID_STATICTEXT14, _("2. MANUFACTURER"), wxPoint(24,72), wxDefaultSize, 0, _T("ID_STATICTEXT14"));
    StaticText11 = new wxStaticText(Panel1, ID_STATICTEXT15, _("3. VENDOR"), wxPoint(24,120), wxDefaultSize, 0, _T("ID_STATICTEXT15"));
    StaticText12 = new wxStaticText(Panel1, ID_STATICTEXT16, _("4. ITEM NAME"), wxPoint(24,168), wxDefaultSize, 0, _T("ID_STATICTEXT16"));
    Select_Grid = new wxGrid(Panel1, ID_GRID1, wxPoint(440,16), wxSize(744,288), wxVSCROLL|wxALWAYS_SHOW_SB, _T("ID_GRID1"));
    Select_Grid->CreateGrid(0,8);
    wxFont Select_GridFont(7,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    Select_Grid->SetFont(Select_GridFont);
    Select_Grid->EnableEditing(false);
    Select_Grid->EnableGridLines(true);
    Select_Grid->SetRowLabelSize(40);
    wxFont GridLabelFont_1(8,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    Select_Grid->SetLabelFont(GridLabelFont_1);
    Select_Grid->SetColLabelValue(0, _("Items"));
    Select_Grid->SetColLabelValue(1, _("Manufacturer"));
    Select_Grid->SetColLabelValue(2, _("Category"));
    Select_Grid->SetColLabelValue(3, _("Vendor"));
    Select_Grid->SetColLabelValue(4, _("Vendor No."));
    Select_Grid->SetColLabelValue(5, _("Vendor Cost"));
    Select_Grid->SetColLabelValue(6, _("Vendor URL"));
    Select_Grid->SetColLabelValue(7, _("Quantity"));
    Select_Grid->SetDefaultCellFont( Select_Grid->GetFont() );
    Select_Grid->SetDefaultCellTextColour( Select_Grid->GetForegroundColour() );
    ComboBox_SearchCategory = new wxComboBox(Panel1, ID_COMBOBOX4, wxEmptyString, wxPoint(160,16), wxSize(264,34), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX4"));
    ComboBox_SeardManufacturer = new wxComboBox(Panel1, ID_COMBOBOX5, wxEmptyString, wxPoint(160,64), wxSize(264,34), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX5"));
    ComboBox_Vendor = new wxComboBox(Panel1, ID_COMBOBOX6, wxEmptyString, wxPoint(160,112), wxSize(264,34), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX6"));
    ComboBox_Item = new wxComboBox(Panel1, ID_COMBOBOX7, wxEmptyString, wxPoint(160,160), wxSize(264,34), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX7"));
    HyperlinkCtrl1 = new wxHyperlinkCtrl(Panel1, ID_HYPERLINKCTRL1, _("DATASHEET"), wxEmptyString, wxPoint(288,256), wxDefaultSize, wxHL_CONTEXTMENU|wxHL_ALIGN_CENTRE, _T("ID_HYPERLINKCTRL1"));
    HyperlinkCtrl1->Disable();
    HyperlinkCtrl2 = new wxHyperlinkCtrl(Panel1, ID_HYPERLINKCTRL2, _("VENDOR SITE"), wxEmptyString, wxPoint(136,256), wxDefaultSize, wxHL_CONTEXTMENU|wxHL_ALIGN_CENTRE, _T("ID_HYPERLINKCTRL2"));
    HyperlinkCtrl2->Disable();
    StaticLine1 = new wxStaticLine(Panel1, ID_STATICLINE1, wxPoint(24,216), wxSize(400,0), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
    Button1 = new wxButton(Panel1, ID_BUTTON3, _("+"), wxPoint(24,256), wxSize(40,34), 0, wxDefaultValidator, _T("ID_BUTTON3"));
    Button1->Disable();
    Button2 = new wxButton(Panel1, ID_BUTTON4, _("-"), wxPoint(72,256), wxSize(40,34), 0, wxDefaultValidator, _T("ID_BUTTON4"));
    Button2->Disable();
    StaticText13 = new wxStaticText(Panel1, ID_STATICTEXT17, _("QUANTITY"), wxPoint(32,232), wxDefaultSize, 0, _T("ID_STATICTEXT17"));
    Panel3 = new wxPanel(Notebook1, ID_PANEL3, wxPoint(1,70), wxSize(1173,392), wxTAB_TRAVERSAL, _T("ID_PANEL3"));
    StaticBox2 = new wxStaticBox(Panel3, ID_STATICBOX4, wxEmptyString, wxPoint(160,232), wxSize(416,72), 0, _T("ID_STATICBOX4"));
    StaticBox1 = new wxStaticBox(Panel3, ID_STATICBOX3, wxEmptyString, wxPoint(608,232), wxSize(568,72), 0, _T("ID_STATICBOX3"));
    StaticBox_ItemInfo = new wxStaticBox(Panel3, ID_STATICBOX2, _("ITEM INFORMATION"), wxPoint(16,16), wxSize(560,216), wxALWAYS_SHOW_SB, _T("ID_STATICBOX2"));
    StaticBox_VendorInfo = new wxStaticBox(Panel3, ID_STATICBOX1, _("VENDOR INFORMATION"), wxPoint(608,16), wxSize(568,216), 0, _T("ID_STATICBOX1"));
    AddEntry = new wxButton(Panel3, ID_BUTTON1, _("ADD ENTRY"), wxPoint(16,256), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    StaticText_ItemName = new wxStaticText(Panel3, ID_STATICTEXT1, _("ITEM NAME"), wxPoint(32,48), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    TextCtrl_ItemName = new wxTextCtrl(Panel3, ID_TEXTCTRL1, wxEmptyString, wxPoint(184,40), wxSize(376,34), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    StaticText_ItemDesc = new wxStaticText(Panel3, ID_STATICTEXT2, _("DESCRIPTION"), wxPoint(32,96), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    StaticText_Manufacturer = new wxStaticText(Panel3, ID_STATICTEXT3, _("MANUFACTURER"), wxPoint(32,144), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    TextCtrl_Description = new wxTextCtrl(Panel3, ID_TEXTCTRL2, wxEmptyString, wxPoint(184,88), wxSize(376,34), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    TextCtrl_VendorURL = new wxTextCtrl(Panel3, ID_TEXTCTRL3, wxEmptyString, wxPoint(784,184), wxSize(376,34), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    TextCtrl_VendorCost = new wxTextCtrl(Panel3, ID_TEXTCTRL5, wxEmptyString, wxPoint(784,136), wxSize(376,34), 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
    StaticText4 = new wxStaticText(Panel3, ID_STATICTEXT4, _("VENDOR ITEM NO."), wxPoint(624,96), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    StaticText5 = new wxStaticText(Panel3, ID_STATICTEXT5, _("VENDOR NAME"), wxPoint(624,48), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    TextCtrl_VenderNumber = new wxTextCtrl(Panel3, ID_TEXTCTRL7, wxEmptyString, wxPoint(784,88), wxSize(376,34), 0, wxDefaultValidator, _T("ID_TEXTCTRL7"));
    StaticText6 = new wxStaticText(Panel3, ID_STATICTEXT6, _("VENDOR UNIT COST"), wxPoint(624,144), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    StaticText7 = new wxStaticText(Panel3, ID_STATICTEXT7, _("VENDOR WEB URL"), wxPoint(624,192), wxDefaultSize, 0, _T("ID_STATICTEXT7"));
    StaticText9 = new wxStaticText(Panel3, ID_STATICTEXT9, _("CATEGORY"), wxPoint(32,192), wxDefaultSize, 0, _T("ID_STATICTEXT9"));
    StaticText10 = new wxStaticText(Panel3, ID_STATICTEXT10, _("QUANTITY"), wxPoint(624,264), wxDefaultSize, 0, _T("ID_STATICTEXT10"));
    SpinCtrl_Quantity = new wxSpinCtrl(Panel3, ID_SPINCTRL1, _T("1"), wxPoint(784,256), wxSize(376,34), 0, 0, 100000, 1, _T("ID_SPINCTRL1"));
    SpinCtrl_Quantity->SetValue(_T("1"));
    StaticText_Notification = new wxStaticText(Panel3, ID_STATICTEXT8, wxEmptyString, wxPoint(24,320), wxSize(32,15), 0, _T("ID_STATICTEXT8"));
    ComboBox_Category = new wxComboBox(Panel3, ID_COMBOBOX1, wxEmptyString, wxPoint(184,184), wxSize(376,34), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX1"));
    StaticText1 = new wxStaticText(Panel3, ID_STATICTEXT11, _("DATASHEET"), wxPoint(176,264), wxDefaultSize, 0, _T("ID_STATICTEXT11"));
    Button_UploadDatasheet = new wxButton(Panel3, ID_BUTTON2, _("Upload File"), wxPoint(288,256), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    Button_UploadDatasheet->Disable();
    StaticText2 = new wxStaticText(Panel3, ID_STATICTEXT12, wxEmptyString, wxPoint(384,264), wxSize(64,16), 0, _T("ID_STATICTEXT12"));
    ComboBox_Manufacturer = new wxComboBox(Panel3, ID_COMBOBOX2, wxEmptyString, wxPoint(184,136), wxSize(376,34), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX2"));
    ComboBox_VenderName = new wxComboBox(Panel3, ID_COMBOBOX3, wxEmptyString, wxPoint(784,40), wxSize(376,34), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX3"));
    FileUploadCheck = new wxCheckBox(Panel3, ID_CHECKBOX1, wxEmptyString, wxPoint(264,264), wxSize(24,22), 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
    FileUploadCheck->SetValue(false);
    Notebook1->AddPage(Panel1, _("Search"), false);
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
    FileDialog1 = new wxFileDialog(this, _("Select file"), _("$USER"), wxEmptyString, wxFileSelectorDefaultWildcardStr, wxFD_DEFAULT_STYLE|wxFD_CHANGE_DIR, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
    FileDialog2 = new wxFileDialog(this, _("Select file"), wxEmptyString, wxEmptyString, wxFileSelectorDefaultWildcardStr, wxFD_SAVE|wxFD_CHANGE_DIR, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
    FileDialog3 = new wxFileDialog(this, _("Select file"), wxEmptyString, wxEmptyString, wxFileSelectorDefaultWildcardStr, wxFD_SAVE, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));

    Connect(ID_COMBOBOX4,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&InventoryFrame::OnComboBox_SearchCategorySelected);
    Connect(ID_COMBOBOX5,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&InventoryFrame::OnComboBox_SeardManufacturerSelected);
    Connect(ID_COMBOBOX6,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&InventoryFrame::OnComboBox_VendorSelected);
    Connect(ID_COMBOBOX7,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&InventoryFrame::OnComboBox_ItemSelected);
    Connect(ID_HYPERLINKCTRL2,wxEVT_COMMAND_HYPERLINK,(wxObjectEventFunction)&InventoryFrame::OnHyperlinkCtrl2Click);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&InventoryFrame::OnButton1Click1);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&InventoryFrame::OnButton2Click1);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&InventoryFrame::OnAddEntryClick);
    Connect(ID_COMBOBOX1,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&InventoryFrame::OnComboBox_CategorySelected);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&InventoryFrame::OnButton_UploadDatasheetClick);
    Connect(ID_CHECKBOX1,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&InventoryFrame::OnFileUploadCheckClick);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&InventoryFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&InventoryFrame::OnAbout);
    Connect(ID_TIMER1,wxEVT_TIMER,(wxObjectEventFunction)&InventoryFrame::OnTimer1Trigger);
    //*)

    if (FileDialog3->ShowModal() == wxID_CANCEL) {
        return;
    }

    filename = string(FileDialog3->GetPath());
    CreateDatabase(database, filename.c_str());
    UpdateLists(database, filename.c_str());
    SearchLists(database, filename.c_str());
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
    char sql[2048];
    int i = 0;

    database->Open(wxString::FromUTF8(filename));
    snprintf(sql, 2048, "SELECT * FROM STOCK;");
    wxSQLite3ResultSet result = database->ExecuteQuery(sql);

    while(result.NextRow()) {
        i++;
    }
    database->Close();
    wxString msg = "Database: \t\t" + filename + "\nEntries Created: \t" + to_string(i);
    wxMessageBox(msg, _("Welcome to..."));
}

void InventoryFrame::OnSearchEntryClick(wxCommandEvent& event)
{
}

void InventoryFrame::OnAddEntryClick(wxCommandEvent& event)
{
    InsertDatabase(database, filename.c_str());
    StaticText_Notification->SetLabel("Successfully Added!");
    Timer1.Start(3000, true);
    TextCtrl_ItemName->Clear();
    TextCtrl_Description->Clear();
    ComboBox_Manufacturer->Clear();
    ComboBox_Category->Clear();
    ComboBox_VenderName->Clear();
    TextCtrl_VenderNumber->Clear();
    TextCtrl_VendorCost->Clear();
    TextCtrl_VendorURL->Clear();
    SpinCtrl_Quantity->SetValue(1);
    FileUploadCheck->SetValue(false);
    UpdateLists(database, filename.c_str());
}

void InventoryFrame::OnTimer1Trigger(wxTimerEvent& event)
{
    StaticText_Notification->SetLabel("");
}

void InventoryFrame::OnComboBox_CategorySelected(wxCommandEvent& event)
{
}

//================== User Functions ==================

void InventoryFrame::CreateDatabase(wxSQLite3Database* db, const char* filename) {
    const char *sql = "CREATE TABLE Stock(ItemName varchar(30), ItemDescription varchar(100), Manufacturer varchar(30), Category varchar(30), "
    "VendorName varchar(30), VendorItemNo varchar(30), VendorUnitCost REAL, VendorWebURL BLOB, Quantity INTEGER, DS_Dir BLOB);";
    db->Open(wxString::FromUTF8(filename));
    if(!db->TableExists("Stock")) {
        db->ExecuteUpdate(sql);
    }
    db->Close();
}

void InventoryFrame::InsertDatabase(wxSQLite3Database* db, const char* filename) {
    string item_name = (TextCtrl_ItemName->GetValue() != "") ? string(TextCtrl_ItemName->GetValue()) : "";
    string item_description = (TextCtrl_Description->GetValue() != "") ? string(TextCtrl_Description->GetValue()) : "";
    string item_manufacturer = (ComboBox_Manufacturer->GetValue() != "") ? string(ComboBox_Manufacturer->GetValue()) : "";
    string item_category = (ComboBox_Category->GetValue() != "") ? string(ComboBox_Category->GetValue()) : "";
    string vendor_name = (ComboBox_VenderName->GetValue() != "") ? string(ComboBox_VenderName->GetValue()) : "";
    string vendor_number = (TextCtrl_VenderNumber->GetValue() != "") ? string(TextCtrl_VenderNumber->GetValue()) : "";
    string vendor_url = (TextCtrl_VendorURL->GetValue() != "") ? string(TextCtrl_VendorURL->GetValue()) : "";
    string vendor_cost = (check_digit(string(TextCtrl_VendorCost->GetValue()))) ? string(TextCtrl_VendorCost->GetValue()) : "0.0";
    string quantity = to_string(SpinCtrl_Quantity->GetValue());
    string file_dest = "";
    if(FileDialog1->GetPath() != "" && (FileUploadCheck->GetValue())) {
        file_dest = "./datasheets/" +to_string((int)time(NULL)) + "_" + string(FileDialog1->GetFilename());
        wxCopyFile(string(FileDialog1->GetPath()), file_dest, FALSE);
    }
    string sql = "INSERT INTO Stock(ItemName, ItemDescription, Manufacturer, Category, VendorName, VendorItemNo, VendorUnitCost, VendorWebURL, Quantity, DS_Dir) VALUES ('";
    sql += item_name + "','" + item_description + "','" + item_manufacturer + "','" + item_category + "','";
    sql += vendor_name + "','" + vendor_number + "'," + vendor_cost + ",'" + vendor_url + "'," + quantity + ",'" + file_dest + "');";

    const char* sql_c = sql.c_str();
    db->Open(wxString::FromUTF8(filename));
    db->ExecuteUpdate(sql_c);
    db->Close();
}

void InventoryFrame::SearchLists(wxSQLite3Database* db, const char* filename) {


    db->Open(wxString::FromUTF8(filename));
    string sql_query = sql_item_query(string(ComboBox_SearchCategory->GetStringSelection()), string(ComboBox_SeardManufacturer->GetStringSelection()), string(ComboBox_Vendor->GetStringSelection()), string(ComboBox_Item->GetStringSelection()));


    wxSQLite3ResultSet result = db->ExecuteQuery(sql_query.c_str());
    Select_Grid->ClearGrid();
    (Select_Grid->GetNumberRows() > 1) ? Select_Grid->DeleteRows(0, Select_Grid->GetNumberRows()) : Select_Grid->GetNumberRows();

    for (int i = 0; result.NextRow(); i++) {
        Select_Grid->AppendRows(1);
        Select_Grid->SetCellValue(i, 0, wxString::Format(_("%s"), result.GetAsString(0)));
        Select_Grid->SetCellValue(i, 1, wxString::Format(_("%s"), result.GetAsString(2)));
        Select_Grid->SetCellValue(i, 2, wxString::Format(_("%s"), result.GetAsString(3)));
        Select_Grid->SetCellValue(i, 3, wxString::Format(_("%s"), result.GetAsString(4)));
        Select_Grid->SetCellValue(i, 4, wxString::Format(_("%s"), result.GetAsString(5)));
        Select_Grid->SetCellValue(i, 5, wxString::Format(_("%s"), result.GetAsString(6)));
        Select_Grid->SetCellValue(i, 6, wxString::Format(_("%s"), result.GetAsString(7)));
        Select_Grid->SetCellValue(i, 7, wxString::Format(_("%s"), result.GetAsString(8)));
    }
    result.Finalize();
    db->Close();
}

std::string sql_item_query(std::string category, std::string manufacturer, std::string vendor, std::string item) {
    string sql = "SELECT * FROM STOCK ";
    bool key = false;

    if (category != "") {
        sql += (!key) ? key = true, " WHERE " : " AND ";
        sql += "Category = '" + category + "'";
    }
    if (manufacturer != "") {
        sql += (!key) ? key = true, " WHERE " : " AND ";
        sql += "Manufacturer = '" + manufacturer + "'";
    }
    if (vendor != "") {
        sql += (!key) ? key = true, " WHERE " : " AND ";
        sql += "VendorName = '" + vendor + "'";
    }
    if (item != "") {
        sql += (!key) ? key = true, " WHERE " : " AND ";
        sql += "ItemName = '" + item + "'";
    }
    sql += ";";
    return sql;
}

void InventoryFrame::UpdateLists(wxSQLite3Database* db, const char* filename) {
    char sql[42];
    db->Open(wxString::FromUTF8(filename));

    strcpy(sql, "SELECT DISTINCT Category FROM STOCK;");
    wxSQLite3ResultSet result = db->ExecuteQuery(sql);
    ComboBox_Category->Clear();
    ComboBox_SearchCategory->Clear();
    ComboBox_Vendor->Clear();
    ComboBox_Item->Clear();
    while (result.NextRow()) {
            ComboBox_Category->Append(_(wxString::Format(_("%s"), result.GetAsString(0))));
            ComboBox_SearchCategory->Append(_(wxString::Format(_("%s"), result.GetAsString(0))));
    }

    strcpy(sql, "SELECT DISTINCT VendorName FROM STOCK;");
    result = db->ExecuteQuery(sql);
    ComboBox_VenderName->Clear();
    while (result.NextRow()) {
            ComboBox_VenderName->Append(_(wxString::Format(_("%s"), result.GetAsString(0))));
    }

    strcpy(sql, "SELECT DISTINCT Manufacturer FROM STOCK;");
    result = db->ExecuteQuery(sql);
    ComboBox_Manufacturer->Clear();
    while (result.NextRow()) {
            ComboBox_Manufacturer->Append(_(wxString::Format(_("%s"), result.GetAsString(0))));
    }
    db->Close();
}

bool check_digit(string my_digit) {
    bool flag = 1;
    for (unsigned int i = 0; i < sizeof(my_digit) / sizeof(string); i++) {
            if(!isdigit(my_digit[i]) ) {
                flag = 0;
                break;
            }
    }
    return flag;
}

void InventoryFrame::OnButton_UploadDatasheetClick(wxCommandEvent& event)
{
    if (FileDialog1->ShowModal() == wxID_CANCEL) {
        return;
    }
    StaticText2->SetLabel(FileDialog1->GetFilename());
}

void InventoryFrame::OnTextCtrl_ManufacturerText(wxCommandEvent& event)
{
}

void InventoryFrame::OnFileUploadCheckClick(wxCommandEvent& event)
{
    (FileUploadCheck->GetValue()) ? Button_UploadDatasheet->Enable() : Button_UploadDatasheet->Disable();
}

void InventoryFrame::OnComboBox_SearchCategorySelected(wxCommandEvent& event)
{
    SearchLists(database, filename.c_str());
    Button2->Disable();
    Button1->Disable();
    HyperlinkCtrl2->Disable();
    HyperlinkCtrl1->Disable();
    char sql[1024];
    database->Open(wxString::FromUTF8(filename.c_str()));
    snprintf(sql, 1024, "SELECT DISTINCT Manufacturer FROM STOCK WHERE Category = '%s';", string(ComboBox_SearchCategory->GetStringSelection()).c_str());
    wxSQLite3ResultSet result = database->ExecuteQuery(sql);
    ComboBox_SeardManufacturer->Clear();
    ComboBox_Vendor->Clear();
    ComboBox_Item->Clear();

    while (result.NextRow()) {
            ComboBox_SeardManufacturer->Append(_(wxString::Format(_("%s"), result.GetAsString(0))));
    }
    database->Close();
}

void InventoryFrame::OnComboBox_SeardManufacturerSelected(wxCommandEvent& event)
{
    SearchLists(database, filename.c_str());
    Button2->Disable();
    Button1->Disable();
    HyperlinkCtrl2->Disable();
    HyperlinkCtrl1->Disable();
    char sql[1024];
    database->Open(wxString::FromUTF8(filename.c_str()));
    snprintf(sql, 1024, "SELECT DISTINCT VendorName FROM STOCK WHERE Category = '%s' AND Manufacturer = '%s';", string(ComboBox_SearchCategory->GetStringSelection()).c_str(), string(ComboBox_SeardManufacturer->GetStringSelection()).c_str());
    wxSQLite3ResultSet result = database->ExecuteQuery(sql);
    ComboBox_Vendor->Clear();
    ComboBox_Item->Clear();
    while (result.NextRow()) {
            ComboBox_Vendor->Append(_(wxString::Format(_("%s"), result.GetAsString(0))));
    }
    database->Close();
}

void InventoryFrame::OnComboBox_VendorSelected(wxCommandEvent& event)
{
    Button2->Disable();
    Button1->Disable();
    HyperlinkCtrl2->Disable();
    HyperlinkCtrl1->Disable();
    SearchLists(database, filename.c_str());
    char sql[1024];
    database->Open(wxString::FromUTF8(filename.c_str()));
    snprintf(sql, 1024, "SELECT DISTINCT ItemName FROM STOCK WHERE Category = '%s' AND Manufacturer = '%s' AND VendorName = '%s';",string(ComboBox_SearchCategory->GetStringSelection()).c_str(), string(ComboBox_SeardManufacturer->GetStringSelection()).c_str(), string(ComboBox_Vendor->GetStringSelection()).c_str());
    wxSQLite3ResultSet result = database->ExecuteQuery(sql);
    ComboBox_Item->Clear();
    while (result.NextRow()) {
            ComboBox_Item->Append(_(wxString::Format(_("%s"), result.GetAsString(0))));
    }
    database->Close();
}

void InventoryFrame::OnComboBox_ItemSelected(wxCommandEvent& event)
{
    SearchLists(database, filename.c_str());
    char sql[1024];
    database->Open(wxString::FromUTF8(filename.c_str()));
    snprintf(sql, 2048, "SELECT * FROM STOCK WHERE Category = '%s' AND Manufacturer = '%s' AND VendorName = '%s' AND ItemName = '%s';",string(ComboBox_SearchCategory->GetStringSelection()).c_str(), string(ComboBox_SeardManufacturer->GetStringSelection()).c_str(), string(ComboBox_Vendor->GetStringSelection()).c_str(), string(ComboBox_Item->GetStringSelection()).c_str());
    wxSQLite3ResultSet result = database->ExecuteQuery(sql);
    HyperlinkCtrl2->Enable();
    HyperlinkCtrl1->Enable();
    Button2->Enable();
    Button1->Enable();
    HyperlinkCtrl2->SetURL(_(wxString::Format(_("%s"), result.GetAsString(7))));
    HyperlinkCtrl1->SetURL(_(wxString::Format(_("%s"), result.GetAsString(9))));
    database->Close();
}

void InventoryFrame::OnHyperlinkCtrl2Click(wxCommandEvent& event)
{
}

void InventoryFrame::OnButton1Click1(wxCommandEvent& event)
{
    char sql[2048];
    database->Open(wxString::FromUTF8(filename.c_str()));
    snprintf(sql, 2048, "SELECT * FROM STOCK WHERE Category = '%s' AND Manufacturer = '%s' AND VendorName = '%s' AND ItemName = '%s';",string(ComboBox_SearchCategory->GetStringSelection()).c_str(), string(ComboBox_SeardManufacturer->GetStringSelection()).c_str(), string(ComboBox_Vendor->GetStringSelection()).c_str(), string(ComboBox_Item->GetStringSelection()).c_str());
    wxSQLite3ResultSet result = database->ExecuteQuery(sql);
    int qty = atoi(wxString::Format(_("%d"), result.GetInt(8)).c_str()) + 1;
    snprintf(sql, 2048, "UPDATE STOCK SET Quantity =  %d WHERE Category = '%s' AND Manufacturer = '%s' AND VendorName = '%s' AND ItemName = '%s';", qty, string(ComboBox_SearchCategory->GetStringSelection()).c_str(), string(ComboBox_SeardManufacturer->GetStringSelection()).c_str(), string(ComboBox_Vendor->GetStringSelection()).c_str(), string(ComboBox_Item->GetStringSelection()).c_str());
    database->ExecuteUpdate(sql);
    database->Close();
    SearchLists(database, filename.c_str());
}

void InventoryFrame::OnButton2Click1(wxCommandEvent& event)
{
    char sql[2048];
    database->Open(wxString::FromUTF8(filename.c_str()));
    snprintf(sql, 2048, "SELECT * FROM STOCK WHERE Category = '%s' AND Manufacturer = '%s' AND VendorName = '%s' AND ItemName = '%s';",string(ComboBox_SearchCategory->GetStringSelection()).c_str(), string(ComboBox_SeardManufacturer->GetStringSelection()).c_str(), string(ComboBox_Vendor->GetStringSelection()).c_str(), string(ComboBox_Item->GetStringSelection()).c_str());
    wxSQLite3ResultSet result = database->ExecuteQuery(sql);
    int qty = atoi(wxString::Format(_("%d"), result.GetInt(8)).c_str()) - 1;
    snprintf(sql, 2048, "UPDATE STOCK SET Quantity =  %d WHERE Category = '%s' AND Manufacturer = '%s' AND VendorName = '%s' AND ItemName = '%s';", qty, string(ComboBox_SearchCategory->GetStringSelection()).c_str(), string(ComboBox_SeardManufacturer->GetStringSelection()).c_str(), string(ComboBox_Vendor->GetStringSelection()).c_str(), string(ComboBox_Item->GetStringSelection()).c_str());
    database->ExecuteUpdate(sql);
    database->Close();
    SearchLists(database, filename.c_str());
}
