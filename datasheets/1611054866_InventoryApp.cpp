/***************************************************************
 * Name:      InventoryApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2021-01-17
 * Copyright:  ()
 * License:
 **************************************************************/

#include "InventoryApp.h"

//(*AppHeaders
#include "InventoryMain.h"
#include <wx/image.h>
//*)


IMPLEMENT_APP(InventoryApp);

bool InventoryApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	InventoryFrame* Frame = new InventoryFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
