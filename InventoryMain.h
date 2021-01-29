/***************************************************************
 * Name:      InventoryMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2021-01-17
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef INVENTORYMAIN_H
#define INVENTORYMAIN_H

#include <wx/wxsqlite3.h>
//(*Headers(InventoryFrame)
#include <wx/button.h>
#include <wx/checkbox.h>
#include <wx/combobox.h>
#include <wx/filedlg.h>
#include <wx/frame.h>
#include <wx/grid.h>
#include <wx/hyperlink.h>
#include <wx/menu.h>
#include <wx/notebook.h>
#include <wx/panel.h>
#include <wx/spinctrl.h>
#include <wx/statbox.h>
#include <wx/statline.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/timer.h>
//*)
#include <string>


class InventoryFrame: public wxFrame
{
    public:

        InventoryFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~InventoryFrame();
        void CreateDatabase(wxSQLite3Database* db, const char* filename);
        void InsertDatabase(wxSQLite3Database* db, const char* filename);
        void UpdateLists(wxSQLite3Database* db, const char* filename);
        void SearchLists(wxSQLite3Database* db, const char* filename);
    private:

        //(*Handlers(InventoryFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnSearchEntryClick(wxCommandEvent& event);
        void OnAddEntryClick(wxCommandEvent& event);
        void OnTimer1Trigger(wxTimerEvent& event);
        void OnButton_UploadDatasheetClick(wxCommandEvent& event);
        void OnComboBox_CategorySelected(wxCommandEvent& event);
        void OnTextCtrl_ManufacturerText(wxCommandEvent& event);
        void OnFileUploadCheckClick(wxCommandEvent& event);
        void OnChoice_SearchCategorySelect(wxCommandEvent& event);
        void OnChoice_SeardManufacturerSelect(wxCommandEvent& event);
        void OnComboBox_SeardManufacturerSelected(wxCommandEvent& event);
        void OnComboBox_SearchCategorySelected(wxCommandEvent& event);
        void OnComboBox_VendorSelected(wxCommandEvent& event);
        void OnComboBox_ItemSelected(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnButton2Click(wxCommandEvent& event);
        void OnSimpleHtmlListBox1Select(wxCommandEvent& event);
        void OnHyperlinkCtrl2Click(wxCommandEvent& event);
        void OnButton1Click1(wxCommandEvent& event);
        void OnButton2Click1(wxCommandEvent& event);
        //*)



        //(*Identifiers(InventoryFrame)
        static const long ID_STATICTEXT13;
        static const long ID_STATICTEXT14;
        static const long ID_STATICTEXT15;
        static const long ID_STATICTEXT16;
        static const long ID_GRID1;
        static const long ID_COMBOBOX4;
        static const long ID_COMBOBOX5;
        static const long ID_COMBOBOX6;
        static const long ID_COMBOBOX7;
        static const long ID_HYPERLINKCTRL1;
        static const long ID_HYPERLINKCTRL2;
        static const long ID_STATICLINE1;
        static const long ID_BUTTON3;
        static const long ID_BUTTON4;
        static const long ID_STATICTEXT17;
        static const long ID_PANEL1;
        static const long ID_STATICBOX4;
        static const long ID_STATICBOX3;
        static const long ID_STATICBOX2;
        static const long ID_STATICBOX1;
        static const long ID_BUTTON1;
        static const long ID_STATICTEXT1;
        static const long ID_TEXTCTRL1;
        static const long ID_STATICTEXT2;
        static const long ID_STATICTEXT3;
        static const long ID_TEXTCTRL2;
        static const long ID_TEXTCTRL3;
        static const long ID_TEXTCTRL5;
        static const long ID_STATICTEXT4;
        static const long ID_STATICTEXT5;
        static const long ID_TEXTCTRL7;
        static const long ID_STATICTEXT6;
        static const long ID_STATICTEXT7;
        static const long ID_STATICTEXT9;
        static const long ID_STATICTEXT10;
        static const long ID_SPINCTRL1;
        static const long ID_STATICTEXT8;
        static const long ID_COMBOBOX1;
        static const long ID_STATICTEXT11;
        static const long ID_BUTTON2;
        static const long ID_STATICTEXT12;
        static const long ID_COMBOBOX2;
        static const long ID_COMBOBOX3;
        static const long ID_CHECKBOX1;
        static const long ID_PANEL3;
        static const long ID_NOTEBOOK1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_TIMER1;
        //*)

        //(*Declarations(InventoryFrame)
        wxButton* AddEntry;
        wxButton* Button1;
        wxButton* Button2;
        wxButton* Button_UploadDatasheet;
        wxCheckBox* FileUploadCheck;
        wxComboBox* ComboBox_Category;
        wxComboBox* ComboBox_Item;
        wxComboBox* ComboBox_Manufacturer;
        wxComboBox* ComboBox_SearchCategory;
        wxComboBox* ComboBox_SeardManufacturer;
        wxComboBox* ComboBox_VenderName;
        wxComboBox* ComboBox_Vendor;
        wxFileDialog* FileDialog1;
        wxFileDialog* FileDialog2;
        wxFileDialog* FileDialog3;
        wxGrid* Select_Grid;
        wxHyperlinkCtrl* HyperlinkCtrl1;
        wxHyperlinkCtrl* HyperlinkCtrl2;
        wxNotebook* Notebook1;
        wxPanel* Panel1;
        wxPanel* Panel3;
        wxSpinCtrl* SpinCtrl_Quantity;
        wxStaticBox* StaticBox1;
        wxStaticBox* StaticBox2;
        wxStaticBox* StaticBox_ItemInfo;
        wxStaticBox* StaticBox_VendorInfo;
        wxStaticLine* StaticLine1;
        wxStaticText* StaticText10;
        wxStaticText* StaticText11;
        wxStaticText* StaticText12;
        wxStaticText* StaticText13;
        wxStaticText* StaticText1;
        wxStaticText* StaticText2;
        wxStaticText* StaticText3;
        wxStaticText* StaticText4;
        wxStaticText* StaticText5;
        wxStaticText* StaticText6;
        wxStaticText* StaticText7;
        wxStaticText* StaticText8;
        wxStaticText* StaticText9;
        wxStaticText* StaticText_ItemDesc;
        wxStaticText* StaticText_ItemName;
        wxStaticText* StaticText_Manufacturer;
        wxStaticText* StaticText_Notification;
        wxTextCtrl* TextCtrl_Description;
        wxTextCtrl* TextCtrl_ItemName;
        wxTextCtrl* TextCtrl_VenderNumber;
        wxTextCtrl* TextCtrl_VendorCost;
        wxTextCtrl* TextCtrl_VendorURL;
        wxTimer Timer1;
        //*)

        DECLARE_EVENT_TABLE()
};

bool check_digit(std::string my_digit) ;


#endif // INVENTORYMAIN_H
