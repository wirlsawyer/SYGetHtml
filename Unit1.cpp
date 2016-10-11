//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "IdBaseComponent"
#pragma link "IdComponent"
#pragma link "IdHTTP"
#pragma link "IdTCPClient"
#pragma link "IdTCPConnection"
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{


   TStringStream *rStream = new TStringStream("", TEncoding::GetEncoding(65001), true);
   try
   {

	IdHTTP1->Get("http://ehealth.asus.com/asusapp/ehealth/upload.html", rStream);
	UnicodeString str = rStream->DataString;

	OutputDebugString( str.w_str() );
   }
   catch(...)
   {
   	OutputDebugString(L"fault");
   }


   delete rStream;


}
//---------------------------------------------------------------------------

