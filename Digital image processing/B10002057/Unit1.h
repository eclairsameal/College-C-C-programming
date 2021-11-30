//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Dialogs.hpp>
#include <ExtDlgs.hpp>
#include <Menus.hpp>
#include <ExtCtrls.hpp>
#include <Chart.hpp>
#include <Series.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *MainMenu1;
        TOpenPictureDialog *OpenPictureDialog1;
        TSavePictureDialog *SavePictureDialog1;
        TMenuItem *File1;
        TMenuItem *Open1;
        TMenuItem *Save1;
        TMenuItem *Close1;
        TMenuItem *Edit1;
        TMenuItem *N1;
        TMenuItem *N3;
        TGroupBox *Select;
        TRadioButton *BMP;
        TRadioButton *JPEG;
        TStatusBar *StatusBar1;
        TLabel *Label1;
        TMenuItem *N4;
        TEdit *Edit2;
        TMenuItem *N5;
        TMenuItem *N6;
        TButton *Button1;
        TLabel *Label2;
        TMenuItem *N2;
        TMenuItem *N2561281;
        TMenuItem *N128641;
        TMenuItem *N64321;
        TMenuItem *N32161;
        TMenuItem *N1681;
        TMenuItem *N841;
        TMenuItem *N421;
        TMenuItem *N7;
        TMenuItem *N8;
        TMenuItem *N9;
        TMenuItem *N7_1;
        TMenuItem *N7_2;
        TMenuItem *Laplacian1;
        TMenuItem *Sobel1;
        TPageControl *f;
        TTabSheet *open_file;
        TScrollBox *ScrollBox1;
        TImage *Image1;
        TTabSheet *TabSheet1;
        TScrollBox *ScrollBox2;
        TImage *Image2;
        TTabSheet *TabSheet2;
        TScrollBox *ScrollBox3;
        TImage *Image3;
        TTabSheet *TabSheet3;
        TScrollBox *ScrollBox4;
        TImage *Image4;
        TTabSheet *TabSheet4;
        TScrollBox *ScrollBox5;
        TImage *Image5;
        TChart *Chart1;
        TBarSeries *Series1;
        TTabSheet *TabSheet5;
        TLabel *Label3;
        TScrollBox *ScrollBox6;
        TImage *Image6;
        TEdit *Edit3;
        TTabSheet *TabSheet6;
        TScrollBox *ScrollBox7;
        TImage *Image7;
        TTabSheet *TabSheet7;
        TScrollBox *ScrollBox8;
        TImage *Image8;
        TMenuItem *Laplacian2;
        TMenuItem *N10;
        TMenuItem *N11;
        TTabSheet *TabSheet8;
        TTabSheet *TabSheet9;
        TScrollBox *ScrollBox9;
        TImage *Image9;
        TScrollBox *ScrollBox10;
        TImage *Image10;
        TMenuItem *DFT1;
        TMenuItem *IDFT1;
        TTabSheet *TabSheet10;
        TTabSheet *TabSheet11;
        TTabSheet *TabSheet12;
        TScrollBox *ScrollBox11;
        TImage *Image11;
        TScrollBox *ScrollBox12;
        TImage *Image12;
        TScrollBox *ScrollBox13;
        TImage *Image13;
        TButton *Button2;
        TButton *Button3;
        TButton *Button4;
        TButton *Button5;
        TGroupBox *GroupBox1;
        TRadioButton *RadioButton3;
        TRadioButton *RadioButton4;
        TRadioButton *RadioButton5;
        TTabSheet *TabSheet13;
        TScrollBox *ScrollBox14;
        TImage *Image14;
        TMenuItem *Colorquantization1;
        TMenuItem *RGB1;
        TMenuItem *YIQ1;
        TMenuItem *HSI1;
        TMenuItem *N2561282;
        TMenuItem *N126641;
        TMenuItem *N64322;
        TMenuItem *N32162;
        TMenuItem *N1682;
        TMenuItem *N842;
        TMenuItem *N422;
        TTabSheet *TabSheet14;
        TScrollBox *ScrollBox15;
        TImage *Image15;
        TMenuItem *colormodels1;
        TMenuItem *RGBYIQ1;
        TMenuItem *RGB2;
        TMenuItem *RGBHSI1;
        TMenuItem *N1281;
        TMenuItem *N641;
        TMenuItem *N321;
        TMenuItem *N161;
        TMenuItem *N81;
        TMenuItem *N41;
        TMenuItem *N21;
        void __fastcall Open1Click(TObject *Sender);
        void __fastcall Close1Click(TObject *Sender);
        void __fastcall Image1MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall Image1MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void __fastcall Save1Click(TObject *Sender);
        void __fastcall N3Click(TObject *Sender);
        void __fastcall N1Click(TObject *Sender);
        void __fastcall N4Click(TObject *Sender);
        void __fastcall N5Click(TObject *Sender);
        void __fastcall N6Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall N2561281Click(TObject *Sender);
        void __fastcall N128641Click(TObject *Sender);
        void __fastcall N64321Click(TObject *Sender);
        void __fastcall N32161Click(TObject *Sender);
        void __fastcall N1681Click(TObject *Sender);
        void __fastcall N841Click(TObject *Sender);
        void __fastcall N421Click(TObject *Sender);
        void __fastcall N7_1Click(TObject *Sender);
        void __fastcall N7_2Click(TObject *Sender);
        void __fastcall Laplacian1Click(TObject *Sender);
        void __fastcall Laplacian2Click(TObject *Sender);
        void __fastcall Sobel1Click(TObject *Sender);
        void __fastcall N10Click(TObject *Sender);
        void __fastcall N11Click(TObject *Sender);
        void __fastcall DFT1Click(TObject *Sender);
        void __fastcall IDFT1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall N2561282Click(TObject *Sender);
        void __fastcall N126641Click(TObject *Sender);
        void __fastcall N64322Click(TObject *Sender);
        void __fastcall N32162Click(TObject *Sender);
        void __fastcall N1682Click(TObject *Sender);
        void __fastcall N842Click(TObject *Sender);
        void __fastcall N422Click(TObject *Sender);
        void __fastcall RGBYIQ1Click(TObject *Sender);
        void __fastcall RGB2Click(TObject *Sender);
        void __fastcall RGBHSI1Click(TObject *Sender);
        void __fastcall N1281Click(TObject *Sender);
        void __fastcall N641Click(TObject *Sender);
        void __fastcall N321Click(TObject *Sender);
        void __fastcall N161Click(TObject *Sender);
        void __fastcall N81Click(TObject *Sender);
        void __fastcall N41Click(TObject *Sender);
        void __fastcall N21Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
