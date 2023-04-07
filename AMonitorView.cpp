// AMonitorView.cpp : implementation of the CAMonitorView class
//

#include "stdafx.h"
#include "AMonitor.h"

#include "AMonitorDoc.h"
#include "AMonitorView.h"
#include "WINDOWS.H"
#include "MMSYSTEM.H"
#include "math.h"
#include "afxmt.h"      //perhaps  for  afxBegerThread(*****)
#include <fstream.h>
#include <stdio.h>
#include "resource.h"
#include "CommunicationDlg.h"
#include "CommunicationWorking.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAMonitorView

#pragma comment(lib, "winmm.lib")

IMPLEMENT_DYNCREATE(CAMonitorView, CView)

BEGIN_MESSAGE_MAP(CAMonitorView, CView)
	ON_MESSAGE(WM_GOODBYE, OnGoodbye)
	//{{AFX_MSG_MAP(CAMonitorView)
	ON_COMMAND(ID_MONIT, OnMonit)
	ON_UPDATE_COMMAND_UI(ID_MONIT, OnUpdateMonit)
	ON_COMMAND(ID_DATA, OnData)
	ON_UPDATE_COMMAND_UI(ID_DATA, OnUpdateData)
	ON_COMMAND(ID_AVAH, OnAvah)
	ON_UPDATE_COMMAND_UI(ID_AVAH, OnUpdateAvah)
	ON_COMMAND(ID_TIMED, OnTimed)
	ON_UPDATE_COMMAND_UI(ID_TIMED, OnUpdateTimed)
	ON_COMMAND(ID_SETT1, OnSett1)
	ON_UPDATE_COMMAND_UI(ID_SETT1, OnUpdateSett1)
	ON_COMMAND(ID_SETT2, OnSett2)
	ON_UPDATE_COMMAND_UI(ID_SETT2, OnUpdateSett2)
	ON_COMMAND(ID_BUTTON32786, OnButton32786)
	ON_UPDATE_COMMAND_UI(ID_BUTTON32786, OnUpdateButton32786)
	ON_WM_DESTROY()
	ON_WM_PAINT()
	ON_WM_TIMER()
	ON_COMMAND(ID_EXEC, OnExec)
	ON_COMMAND(ID_STOP, OnStop)
	ON_COMMAND(ID_RESTART, OnRestart)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_KEYDOWN()
	ON_WM_CHAR()
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_HELP, OnHelp)
	ON_COMMAND(ID_HELPFILE, OnHelpfile)
	ON_UPDATE_COMMAND_UI(ID_HELPFILE, OnUpdateHelpfile)
	ON_UPDATE_COMMAND_UI(ID_EXEC, OnUpdateExec)
	ON_UPDATE_COMMAND_UI(ID_STOP, OnUpdateStop)
	ON_COMMAND(ID_OPENAEDIT, OnOpenaedit)
	ON_COMMAND(ID_TOOLBAR3, OnToolbar3)
	ON_COMMAND(ID_TOOLBAR4, OnToolbar4)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAMonitorView construction/destruction

CAMonitorView::CAMonitorView():m_sizeEllipse(100, -100),
							 m_pointTopLeft(10, -10),
   						     m_sizeOffset(0, 0)
//							 m_rectEllipse(30,20,200,150),
//                           m_sizeTotal(800, 1050), // 8 by 10.5 inches
                                                     //  when printed
//                             m_rectTracker(30, 20, 600, 350)
{
//	m_pPropFrame = NULL;
	m_pDlg = new CCommunicationWorking(this);

	l2 = NULL;
	try {
		l2 = new CPtrArray();
	}
	catch (CMemoryException *e)
	{
		AfxMessageBox("Can't allocate memory for reading file contents");
		TRACE0("Unable to allocate memory for file contents\n");
		e->Delete();
	}

	TRACE0("Allocated lines array\n");	
    
    l3 = NULL;
	try {
		l3 = new CPtrArray();
	}
	catch (CMemoryException *e)
	{
		AfxMessageBox("Can't allocate memory for reading file contents");
		TRACE0("Unable to allocate memory for file contents\n");
		e->Delete();
	}

	TRACE0("Allocated lines array\n");	

    m_SelectMoveX = m_SelectMoveY = m_SelectMoveYadd = 0;
	m_Set2SelectMoveX = m_Set2SelectMoveY = m_Set2SelectMoveYadd = 0;
	m_SelectTimeY = -1;
	m_bCaptured = FALSE;
    m_TextEditCopyEnable = FALSE;
    m_TextEditPasteEnable = FALSE;
    AppComunication = FALSE;
	m_Exit = FALSE;
	m_HelpTextDisplay = FALSE;
    b_Exit = FALSE;
	Execute = FALSE;
	Button32778 = TRUE;
    m_bmp2able = false;
	m_bmp8able = false;
	DataFontCreate = false;
	b_PrepareExitBMP = 0;
    m_vpoXable = 1;
    m_vpoYable = 1;
	maxX=GetSystemMetrics(SM_CXSCREEN);
	maxY=GetSystemMetrics(SM_CYSCREEN);
    y = 0;
    b_Timer2 = 0;
	fCapture = FALSE;
	fBoxing = FALSE;
	b_AlarmSound = FALSE;

	m_vpoX = 0;
	m_vpoY = 0;

	MenuID = "NULL";
    TimeAddSub = TRUE;	
	SettingBMPBitBlt = TRUE;
    s_OutsideDataInput = "----------------------------------------------------------------------";
    s_OutsideDataInputML.Empty();
	TimeSetPAT = 0;
    PrevTime1=0;

	CursorY = 0;
	currentLine = 0;
	currentLine3 = 0;

	F1BookMark=0;
	F2BookMark=0;
	F3BookMark=0;
	F4BookMark=0;
	F5BookMark=0;
	F6BookMark=0;
	EndBookMark=0;

	margin = 0;
    EditLineNo = 0;
    SubEditString = "  ";
    VKDOWNi = 0;

    TimeAddSub = FALSE;
    PicturePrepar = TRUE;
	b_LoadFileData = FALSE;
	b_LoadHelpFile = FALSE;
    Dstinvert = FALSE;
	b_ToolBar3 = TRUE;
    m = 4;
	m_Fly = 5;
	i_MoveChart = 0;

        c_RecordingMLNo = 0;
 		c_RecordingL1N ="0000";
	    c_RecordingL1U ="00.00";
        c_RecordingL1A ="000.0";
	    c_RecordingL1AH ="0.000";
		c_RecordingL1T1 ="00.00";
	    c_RecordingL1T2 ="00.00";
        c_RecordingL1CW ="c   ";
		c_RecordingL2N ="0000";
	    c_RecordingL2U ="00.00";
        c_RecordingL2A ="000.0";
	    c_RecordingL2AH ="0.000";
	    c_RecordingL2T1 ="00.00";
	    c_RecordingL2T2 ="00.00";
        c_RecordingL2CW ="c   ";
		c_RecordingL3N ="0000";
	    c_RecordingL3U ="00.00";
        c_RecordingL3A ="000.0";
	    c_RecordingL3AH ="0.000";
	    c_RecordingL3T1 ="00.00";
	    c_RecordingL3T2 ="00.00";
        c_RecordingL3CW ="c   ";
	    c_RecordingL1Time ="000:00:00";
      	c_RecordingL2Time ="000:00:00";
      	c_RecordingL3Time ="000:00:00";
     
		CaretCreated = false;
        CaretX = CaretY = 0;
	    k2 = k3 =2;
	    k=0;
		b_Timer4 = 0;

		CWinApp* pApp = AfxGetApp();

		m_Edit1 = pApp->GetProfileString("Settings","m_Edit1","   IT9   500 ");
		m_Edit2 = pApp->GetProfileString("Settings","m_Edit2","   IT8   300 ");
		m_CommuncationLink = pApp->GetProfileInt("Settings","m_CommuncationLink",0);
		m_PrinterLink = pApp->GetProfileInt("Settings","m_PrinterLink",0);

		m_FreqAdj = pApp->GetProfileInt("Settings","m_FreqAdj",10000);
		m_FreqAdj = m_FreqAdj/10000.0;
		m_Radio = pApp->GetProfileInt("Settings","m_Radio",1);
		ChargeModel = pApp->GetProfileInt("Settings","ChargeModel",1);
		m_SysMaxV = pApp->GetProfileInt("Settings","m_SysMaxV",150);
		m_SysMaxA = pApp->GetProfileInt("Settings","m_SysMaxA",100);
		RemnantHour = pApp->GetProfileInt("Settings","RemnantHour",999);
		RemnantMinute = pApp->GetProfileInt("Settings","RemnantMinute",59);
		RemnantSecond = pApp->GetProfileInt("Settings","RemnantSecond",59);
		WorkedHour = pApp->GetProfileInt("Settings","WorkedHour",0);
		WorkedMinute = pApp->GetProfileInt("Settings","WorkedMinute",0);
		WorkedSecond = pApp->GetProfileInt("Settings","WorkedSecond",0);
		c_RecordingMLNo = pApp->GetProfileInt("Settings","c_RecordingMLNo",1);

		IT1SetCur = pApp->GetProfileInt("Settings","IT1SetCur",1);
		IT2SetCur = pApp->GetProfileInt("Settings","IT2SetCur",1);
		m_CollectHreq = pApp->GetProfileInt("Settings","m_CollectHreq",2);
		m_1ndLimV = pApp->GetProfileInt("Settings","m_1ndLimV",1500000);
		m_1ndLimV = m_1ndLimV/10000.0;
		m_2ndLimV = pApp->GetProfileInt("Settings","m_2ndLimV",1450000);
		m_2ndLimV = m_2ndLimV/10000.0;
		m_1ndLimA = pApp->GetProfileInt("Settings","m_1ndLimA",1800000);
		m_1ndLimA = m_1ndLimA/10000.0;
		m_2ndLimA = pApp->GetProfileInt("Settings","m_2ndLimA",1500000);
		m_2ndLimA = m_2ndLimA/10000.0;
		m_LAH = pApp->GetProfileInt("Settings","m_LAH",1300000);
		m_LAH = m_LAH/10000.0;
		m_LT1 = pApp->GetProfileInt("Settings","m_LT1",450000);
		m_LT1 = m_LT1/10000.0;

		m_XScale = pApp->GetProfileInt("Settings","m_XScale",1);
		m_YScale = pApp->GetProfileInt("Settings","m_YScale",1);
		m_SelectV = pApp->GetProfileInt("Settings","m_SelectV",0);
		m_SelectA = pApp->GetProfileInt("Settings","m_SelectA",1);
		m_SelectAH = pApp->GetProfileInt("Settings","m_SelectAH",0);
		m_SelectT1 = pApp->GetProfileInt("Settings","m_SelectT1",0);
		m_SelectT2 = pApp->GetProfileInt("Settings","m_SelectT2",0);

		m_TitleText = pApp->GetProfileString("Settings","m_TitleText","A - Time Chart");
		m_XText = pApp->GetProfileString("Settings","m_XText","Time");
		m_YText = pApp->GetProfileString("Settings","m_YText","A");
		m_RadioLineType = pApp->GetProfileInt("Settings","m_RadioLineType",0);
		m_NonoNet = pApp->GetProfileInt("Settings","m_NonoNet",0);

		m_pointTopLeft.x = pApp->GetProfileInt("Settings","m_pointTopLeft.x",197);
		m_pointTopLeft.y = pApp->GetProfileInt("Settings","m_pointTopLeft.y",196);
		
		m_Farq = pApp->GetProfileInt("Settings","m_Farq",5000);
		m_Farq = m_Farq/10000.0;

		m_OutAutoXonoff = pApp->GetProfileInt("Settings","m_OutAutoXonoff",1);
		m_OutRata = pApp->GetProfileInt("Settings","m_OutRata",4800);
		m_OutStopBit = pApp->GetProfileInt("Settings","m_OutStopBit",1);
		m_OutWordsLength = pApp->GetProfileInt("Settings","m_OutWordsLength",7);
		m_OutParity = pApp->GetProfileString("Settings","m_OutParity","EVEN");
		m_OutCode = pApp->GetProfileString("Settings","m_OutCode","ASCII");
		m_OutComPort = pApp->GetProfileString("Settings","m_OutComPort","COM2");
		m_InAutoXonoff = pApp->GetProfileInt("Settings","m_InAutoXonoff",1);
		m_InRata = pApp->GetProfileInt("Settings","m_InRata",4800);
		m_InStopBit = pApp->GetProfileInt("Settings","m_InStopBit",1);
		m_InWordsLength = pApp->GetProfileInt("Settings","m_InWordsLength",7);
		m_InParity = pApp->GetProfileString("Settings","m_InParity","EVEN");
		m_InCode = pApp->GetProfileString("Settings","m_InCode","ASCII");
		m_InComPort = pApp->GetProfileString("Settings","m_InComPort","COM2");

		AuxTim1Minute = pApp->GetProfileInt("Settings","AuxTim1Minute",0);
		AuxTim1Hour = pApp->GetProfileInt("Settings","AuxTim1Hour",0);
		AuxTim2Minute = pApp->GetProfileInt("Settings","AuxTim2Minute",0);
		AuxTim2Hour = pApp->GetProfileInt("Settings","AuxTim2Hour",0);
		SumSysTimMinute = pApp->GetProfileInt("Settings","SumSysTimMinute",0);
		SumSysTimHour = pApp->GetProfileInt("Settings","SumSysTimHour",0);
		Stpart1TimMinute = pApp->GetProfileInt("Settings","Stpart1TimMinute",0);
		Stpart1TimHour = pApp->GetProfileInt("Settings","Stpart1TimHour",0);
		m_RecSound = pApp->GetProfileInt("Settings","m_RecSound",1);
		m_AlarmSound = pApp->GetProfileInt("Settings","m_AlarmSound",1);

		
		m_SaveTime = pApp->GetProfileInt("Settings","m_SaveTime",10000);
		m_SaveTime = m_SaveTime/10000.0;
		m_SaveCurr = pApp->GetProfileInt("Settings","m_SaveCurr",10000);
		m_SaveCurr = m_SaveCurr/10000.0;
		m_SaveVolt = pApp->GetProfileInt("Settings","m_SaveVolt",14400);
		m_SaveVolt = m_SaveVolt/10000.0;
		m_SaveAH = pApp->GetProfileInt("Settings","m_SaveAH",100000);
		m_SaveAH = m_SaveAH/10000.0;
		m_SaveTemp = pApp->GetProfileInt("Settings","m_SaveTemp",3600);
		m_SaveTemp = m_SaveTemp/10000.0;
		m_StartTime = pApp->GetProfileInt("Settings","m_StartTime",0);
		m_StartTime = m_StartTime/10000.0;
		m_StartCurr = pApp->GetProfileInt("Settings","m_StartCurr",0);
		m_StartCurr = m_StartCurr/10000.0;
		m_StartVolt = pApp->GetProfileInt("Settings","m_StartVolt",1000000);
		m_StartVolt = m_StartVolt/10000.0;
		m_StopTime = pApp->GetProfileInt("Settings","m_StopTime",0);
		m_StopTime = m_StopTime/10000.0;
		m_StopCurr = pApp->GetProfileInt("Settings","m_StopCurr",1500000);
		m_StopCurr = m_StopCurr/10000.0;
		m_StopVolt = pApp->GetProfileInt("Settings","m_StopVolt",1960000);
		m_StopVolt = m_StopVolt/10000.0;

		m_SaveRec = pApp->GetProfileInt("Settings","m_SaveRec",100);
		ColAHBar = pApp->GetProfileInt("Settings","ColAHBar",5);
		ColVoltBar = pApp->GetProfileInt("Settings","ColVoltBar",2);
		ColCurrBar = pApp->GetProfileInt("Settings","ColCurrBar",0);
		ColMoveLine = pApp->GetProfileInt("Settings","ColMoveLine",5);
		ColGroLine1 = pApp->GetProfileInt("Settings","ColGroLine1",5);
		ColGroLine2 = pApp->GetProfileInt("Settings","ColGroLine2",0);
		ColMoveBar = pApp->GetProfileInt("Settings","ColMoveBar",0);

		RecSaveFileName = pApp->GetProfileString("Settings","RecSaveFileName","C:/My documents/Record1.dat");
		StartConWord = pApp->GetProfileString("Settings","StartConWord","0050");
		StopConWord = pApp->GetProfileString("Settings","StopConWord","0900");
		m_StartModle = pApp->GetProfileInt("Settings","m_StartModle",0);
		m_StopModle = pApp->GetProfileInt("Settings","m_StopModle",0);
		m_EnglishChinese = pApp->GetProfileInt("Settings","m_EnglishChinese",1);

/*
        BYTE buf;
	    CFile file("c:\\cddyV3.0\\V3Config.sys",CFile::modeRead);
        CArchive ar(&file,CArchive::load);
		ar >> m_Edit1 >> m_Edit2;
		ar >> m_CommuncationLink >> m_PrinterLink;
		ar >> m_FreqAdj >> m_Radio >> ChargeModel;
		ar >> m_SysMaxV >> m_SysMaxA;		
		ar >> RemnantHour >> RemnantMinute >> RemnantSecond;
		ar >> WorkedHour >> WorkedMinute >> WorkedSecond;
		ar >> c_RecordingMLNo;
		ar >> buf >> buf;
		ar >> IT1SetCur >> IT2SetCur >> m_CollectHreq;
        ar >> m_1ndLimV >> m_2ndLimV >> m_1ndLimA >> m_2ndLimA;
	    ar >> m_LAH >> m_LT1;
	 	ar >> buf >> buf;
		ar >> m_XScale >> m_YScale >> m_SelectV >> m_SelectA;
		ar >> m_SelectAH >> m_SelectT1 >> m_SelectT2;
    	ar >> m_TitleText >> m_XText >> m_YText >> m_RadioLineType >> m_NonoNet;
		ar >> m_pointTopLeft;
		ar >> m_Farq;
		ar >> m_OutAutoXonoff >> m_OutRata >> m_OutStopBit >> m_OutWordsLength;
		ar >> m_OutParity >> m_OutCode >> m_OutComPort;
		ar >> m_InAutoXonoff >> m_InRata >> m_InStopBit >> m_InWordsLength;
        ar >> m_InParity >> m_InCode >> m_InComPort;
	    ar >> buf >> buf;
        ar >> AuxTim1Minute >> AuxTim1Hour >> AuxTim2Minute >> AuxTim2Hour;
        ar >> SumSysTimMinute >> SumSysTimHour;
	    ar >> Stpart1TimMinute >> Stpart1TimHour;
		ar >> buf >> buf;
		ar >> m_RecSound >> m_AlarmSound;
		ar >> m_SaveTime >> m_SaveCurr >> m_SaveVolt >> m_SaveAH >> m_SaveTemp;
		ar >> m_StartTime >> m_StartCurr >> m_StartVolt >> m_StopTime >> m_StopCurr >> m_StopVolt;
        ar >> m_SaveRec >> ColAHBar >> ColVoltBar >> ColCurrBar >> ColMoveLine >> ColGroLine1 >> ColGroLine2 >> ColMoveBar;
        ar >> RecSaveFileName >> StartConWord >> StopConWord;
		ar >> m_StartModle >> m_StopModle;
		ar >> m_EnglishChinese;

		ar.Close();
		file.Close();
 */       
		OnChangeProgrees();
		
        RedBrush.CreateSolidBrush(RGB(255,0,0));
        GreenBrush.CreateSolidBrush(RGB(0,255,0));
	    BlueBrush.CreateSolidBrush(RGB(0,0,255));
        YellowBrush.CreateSolidBrush(RGB(255,255,0));
	    GrayBrush.CreateSolidBrush(RGB(192,192,192));
		HelpTextBoxBrush.CreateSolidBrush(RGB(245,245,200));

	    RedPen.CreatePen(PS_INSIDEFRAME,0.1,RGB(255,0,0));
        GreenPen.CreatePen(PS_SOLID,1,RGB(0,255,0));

	    ColorPen[0].CreatePen(PS_SOLID,1,RGB(255,0,0));
	    ColorPen[1].CreatePen(PS_SOLID,1,RGB(0,255,0));
	    ColorPen[2].CreatePen(PS_SOLID,1,RGB(0,0,255));
	    ColorPen[3].CreatePen(PS_SOLID,1,RGB(255,255,0));
	    ColorPen[4].CreatePen(PS_SOLID,1,RGB(0,255,255));
	    ColorPen[5].CreatePen(PS_SOLID,1,RGB(255,0,255));
	    ColorPen[6].CreatePen(PS_SOLID,1,RGB(0,0,0));

	    ColorBrush[0].CreateSolidBrush(RGB(255,0,0));
	    ColorBrush[1].CreateSolidBrush(RGB(0,255,0));
	    ColorBrush[2].CreateSolidBrush(RGB(0,0,255));
	    ColorBrush[3].CreateSolidBrush(RGB(255,250,0));
	    ColorBrush[4].CreateSolidBrush(RGB(0,255,255));
	    ColorBrush[5].CreateSolidBrush(RGB(255,0,255));
	    ColorBrush[6].CreateSolidBrush(RGB(0,0,0));

        BigFont.CreateFont(60,0,0,0,550,FALSE,FALSE,0,ANSI_CHARSET,
			OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,
			DEFAULT_QUALITY,
            DEFAULT_PITCH|FF_SWISS,"Arial");

	    s_StatString[0] = "Max 9999 V and Min 1 V";
	    s_StatString[1] = "Max 9999 A and Min 1 A";
        s_StatString[3] = "Change modle: 1:HY,2:HY-HL,3:HL";
	    s_StatString[5] = "First alarm votage";
	    s_StatString[6] = "Second alarm votage";
	    s_StatString[7] = "First alarm current";
        s_StatString[8] = "Second alarm current";
        s_StatString[9] = "AH alarm";
	    s_StatString[10] = "Tempreture alarm";
	    s_StatString[12] = "Communication conect: 1:conect,2:disconect";
	    s_StatString[14] = "Collect bend: 1:house,2:minues,3:seconde";
	    s_StatString[15] = "Collect speed: ** times/Collect bend";
        s_StatString[16] = "Collect cycile:  **.**second/times";
	    s_StatString[18] = "Paint conect:1:conect,2:disconect";
	    s_StatString[21] = "600,1200,2400,4800,9600,19200";
	    s_StatString[22] = "1: EVEN; 2: ODD";
	    s_StatString[23] = "Stop bit:0,or 1";
	    s_StatString[24] = "Word lengh :7,or 8";
        s_StatString[25] = "1: ASCII; 2: BIN";
	    s_StatString[26] = "1: COM1; 2: COM2";
	    s_StatString[28] = "Handshaking: 1:Xon/Xoff ON.....";
	    s_StatString[30] = "600,1200,2400,4800,9600,19200";
	    s_StatString[31] = "1: EVEN; 2: ODD";
	    s_StatString[32] = "Stop bit:0,or 1";
	    s_StatString[33] = "Word lengh :7,or 8";
        s_StatString[34] = "1: ASCII; 2: BIN";
	    s_StatString[35] = "1: COM1; 2: COM2";
	    s_StatString[37] = "Handshaking: 1:Xon/Xoff ON.....";
}

void CAMonitorView::OnDestroy() 
{
	    CView::OnDestroy();
/*	
        CFile file("c:\\cddyV3.0\\V3Config.sys",CFile::modeWrite);
        CArchive ar(&file,CArchive::store);
		ar << m_Edit1 << m_Edit2;
		ar << m_CommuncationLink << m_PrinterLink;
		ar << m_FreqAdj << m_Radio << ChargeModel;
		ar << m_SysMaxV << m_SysMaxA;
		ar << RemnantHour << RemnantMinute << RemnantSecond;
		ar << WorkedHour << WorkedMinute << WorkedSecond;
		ar << c_RecordingMLNo;
		ar << '\r' << '\n';
		ar << IT1SetCur << IT2SetCur << m_CollectHreq;
        ar << m_1ndLimV << m_2ndLimV << m_1ndLimA;
	    ar << m_2ndLimA << m_LAH << m_LT1;
		ar << '\r' << '\n';
		ar << m_XScale << m_YScale<< m_SelectV << m_SelectA;
		ar << m_SelectAH << m_SelectT1 << m_SelectT2 << m_TitleText;
		ar << m_XText << m_YText << m_RadioLineType << m_NonoNet;
		ar << m_pointTopLeft;
		ar << m_Farq;
		ar << m_OutAutoXonoff << m_OutRata << m_OutStopBit << m_OutWordsLength;
		ar << m_OutParity << m_OutCode << m_OutComPort;
		ar << m_InAutoXonoff << m_InRata << m_InStopBit << m_InWordsLength;
        ar << m_InParity << m_InCode << m_InComPort;
		ar << '\r' << '\n';
		ar << AuxTim1Minute << AuxTim1Hour << AuxTim2Minute << AuxTim2Hour;
        ar << SumSysTimMinute << SumSysTimHour;
	    ar << Stpart1TimMinute << Stpart1TimHour;
		ar << '\r' << '\n';
		ar << m_RecSound << m_AlarmSound;
		ar << m_SaveTime << m_SaveCurr << m_SaveVolt << m_SaveAH << m_SaveTemp;
		ar << m_StartTime << m_StartCurr << m_StartVolt << m_StopTime << m_StopCurr << m_StopVolt;
        ar << m_SaveRec << ColAHBar << ColVoltBar << ColCurrBar << ColMoveLine << ColGroLine1 << ColGroLine2 << ColMoveBar;
        ar << RecSaveFileName << StartConWord << StopConWord;
		ar << m_StartModle << m_StopModle;
		ar << m_EnglishChinese;
		ar.Close();
        file.Close();
*/
		RecSaveFileName = "C:/My documents/Record1.dat";

		CWinApp* pApp = AfxGetApp();

		pApp->WriteProfileString("Settings","m_Edit1",m_Edit1);
		pApp->WriteProfileString("Settings","m_Edit2",m_Edit2);
		pApp->WriteProfileInt("Settings","m_CommuncationLink",m_CommuncationLink);
		pApp->WriteProfileInt("Settings","m_PrinterLink",m_PrinterLink);
		 m_FreqAdj = m_FreqAdj*10000.0;
		pApp->WriteProfileInt("Settings","m_FreqAdj",m_FreqAdj);
		
		pApp->WriteProfileInt("Settings","m_Radio",m_Radio);
		pApp->WriteProfileInt("Settings","ChargeModel",ChargeModel);
		pApp->WriteProfileInt("Settings","m_SysMaxV",m_SysMaxV);
		pApp->WriteProfileInt("Settings","m_SysMaxA",m_SysMaxA);
		pApp->WriteProfileInt("Settings","RemnantHour",RemnantHour);
		pApp->WriteProfileInt("Settings","RemnantMinute",RemnantMinute);
		pApp->WriteProfileInt("Settings","RemnantSecond",RemnantSecond);
		pApp->WriteProfileInt("Settings","WorkedHour",WorkedHour);
		pApp->WriteProfileInt("Settings","WorkedMinute",WorkedMinute);
		pApp->WriteProfileInt("Settings","WorkedSecond",WorkedSecond);
		pApp->WriteProfileInt("Settings","c_RecordingMLNo",c_RecordingMLNo);

		pApp->WriteProfileInt("Settings","IT1SetCur",IT1SetCur);
		pApp->WriteProfileInt("Settings","IT2SetCur",IT2SetCur);
		pApp->WriteProfileInt("Settings","m_CollectHreq",m_CollectHreq);
		m_1ndLimV = m_1ndLimV*10000.0;
		pApp->WriteProfileInt("Settings","m_1ndLimV",m_1ndLimV);
		m_2ndLimV = m_2ndLimV*10000.0;
		pApp->WriteProfileInt("Settings","m_2ndLimV",m_2ndLimV);
		m_1ndLimA = m_1ndLimA*10000.0;
		pApp->WriteProfileInt("Settings","m_1ndLimA",m_1ndLimA);
		m_2ndLimA = m_2ndLimA*10000.0;
		pApp->WriteProfileInt("Settings","m_2ndLimA",m_2ndLimA);
		m_LAH = m_LAH*10000.0;
		pApp->WriteProfileInt("Settings","m_LAH",m_LAH);
		m_LT1 = m_LT1*10000.0;
	    pApp->WriteProfileInt("Settings","m_LT1",m_LT1);

		pApp->WriteProfileInt("Settings","m_XScale",m_XScale);
		pApp->WriteProfileInt("Settings","m_YScale",m_YScale);
		pApp->WriteProfileInt("Settings","m_SelectV",m_SelectV);
		pApp->WriteProfileInt("Settings","m_SelectA",m_SelectA);
		pApp->WriteProfileInt("Settings","m_SelectAH",m_SelectAH);
		pApp->WriteProfileInt("Settings","m_SelectT1",m_SelectT1);
		pApp->WriteProfileInt("Settings","m_SelectT2",m_SelectT2);

		pApp->WriteProfileString("Settings","m_TitleText",m_TitleText);
		pApp->WriteProfileString("Settings","m_XText",m_XText);
		pApp->WriteProfileString("Settings","m_YText",m_YText);
		pApp->WriteProfileInt("Settings","m_RadioLineType",m_RadioLineType);
		pApp->WriteProfileInt("Settings","m_NonoNet",m_NonoNet);

		pApp->WriteProfileInt("Settings","m_pointTopLeft.x",m_pointTopLeft.x);
		pApp->WriteProfileInt("Settings","m_pointTopLeft.y",m_pointTopLeft.y);
		m_Farq = m_Farq*10000.0;
		pApp->WriteProfileInt("Settings","m_Farq",m_Farq);

		pApp->WriteProfileInt("Settings","m_OutAutoXonoff",m_OutAutoXonoff);
		pApp->WriteProfileInt("Settings","m_OutRata",m_OutRata);
		pApp->WriteProfileInt("Settings","m_OutStopBit",m_OutStopBit);
		pApp->WriteProfileInt("Settings","m_OutWordsLength",m_OutWordsLength);
		pApp->WriteProfileString("Settings","m_OutParity",m_OutParity);
		pApp->WriteProfileString("Settings","m_OutCode",m_OutCode);
		pApp->WriteProfileString("Settings","m_OutComPort",m_OutComPort);
		pApp->WriteProfileInt("Settings","m_InAutoXonoff",m_InAutoXonoff);
		pApp->WriteProfileInt("Settings","m_InRata",m_InRata);
		pApp->WriteProfileInt("Settings","m_InStopBit",m_InStopBit);
		pApp->WriteProfileInt("Settings","m_InWordsLength",m_InWordsLength);
		pApp->WriteProfileString("Settings","m_InParity",m_InParity);
		pApp->WriteProfileString("Settings","m_InCode",m_InCode);
		pApp->WriteProfileString("Settings","m_InComPort",m_InComPort);

		pApp->WriteProfileInt("Settings","AuxTim1Minute",AuxTim1Minute);
		pApp->WriteProfileInt("Settings","AuxTim1Hour",AuxTim1Hour);
		pApp->WriteProfileInt("Settings","AuxTim2Minute",AuxTim2Minute);
		pApp->WriteProfileInt("Settings","AuxTim2Hour",AuxTim2Hour);
		pApp->WriteProfileInt("Settings","SumSysTimMinute",SumSysTimMinute);
		pApp->WriteProfileInt("Settings","SumSysTimHour",SumSysTimHour);
		pApp->WriteProfileInt("Settings","Stpart1TimMinute",Stpart1TimMinute);
		pApp->WriteProfileInt("Settings","Stpart1TimHour",Stpart1TimHour);
		pApp->WriteProfileInt("Settings","m_RecSound",m_RecSound);
		pApp->WriteProfileInt("Settings","m_AlarmSound",m_AlarmSound);

		m_SaveTime = m_SaveTime*10000.0;
		pApp->WriteProfileInt("Settings","m_SaveTime",m_SaveTime);
		m_SaveCurr = m_SaveCurr*10000.0;
		pApp->WriteProfileInt("Settings","m_SaveCurr",m_SaveCurr);
		m_SaveVolt = m_SaveVolt*10000.0;
		pApp->WriteProfileInt("Settings","m_SaveVolt",m_SaveVolt);
		m_SaveAH = m_SaveAH*10000.0;
		pApp->WriteProfileInt("Settings","m_SaveAH",m_SaveAH);
		m_SaveTemp = m_SaveTemp*10000.0;
		pApp->WriteProfileInt("Settings","m_SaveTemp",m_SaveTemp);
		m_StartTime = m_StartTime*10000.0;
		pApp->WriteProfileInt("Settings","m_StartTime",m_StartTime);
		m_StartCurr = m_StartCurr*10000.0;
		pApp->WriteProfileInt("Settings","m_StartCurr",m_StartCurr);
		m_StartVolt = m_StartVolt*10000.0;
		pApp->WriteProfileInt("Settings","m_StartVolt",m_StartVolt);
		m_StopTime = m_StopTime*10000.0;
		pApp->WriteProfileInt("Settings","m_StopTime",m_StopTime);
		m_StopCurr = m_StopCurr*10000.0;
		pApp->WriteProfileInt("Settings","m_StopCurr",m_StopCurr);
		m_StopVolt = m_StopVolt*10000.0;
		pApp->WriteProfileInt("Settings","m_StopVolt",m_StopVolt);

		pApp->WriteProfileInt("Settings","m_SaveRec",m_SaveRec);
		pApp->WriteProfileInt("Settings","ColAHBar",ColAHBar);
		pApp->WriteProfileInt("Settings","ColVoltBar",ColVoltBar);
		pApp->WriteProfileInt("Settings","ColCurrBar",ColCurrBar);
		pApp->WriteProfileInt("Settings","ColMoveLine",ColMoveLine);
		pApp->WriteProfileInt("Settings","ColGroLine1",ColGroLine1);
		pApp->WriteProfileInt("Settings","ColGroLine2",ColGroLine2);
		pApp->WriteProfileInt("Settings","ColMoveBar",ColMoveBar);

		pApp->WriteProfileString("Settings","RecSaveFileName",RecSaveFileName);
		pApp->WriteProfileString("Settings","StartConWord",StartConWord);
		pApp->WriteProfileString("Settings","StopConWord",StopConWord);
		pApp->WriteProfileInt("Settings","m_StartModle",m_StartModle);
		pApp->WriteProfileInt("Settings","m_StopModle",m_StopModle);
		pApp->WriteProfileInt("Settings","m_EnglishChinese",m_EnglishChinese);
}

CAMonitorView::~CAMonitorView()
{
	   delete m_pDlg;
	   int i = 0;
	   if (l2 != NULL)
	   {
	   while (i < l2->GetSize())
	   delete (CString *) l2->GetAt(i++);
	   l2->RemoveAll();
	   delete l2;
	   l2 = NULL;
	   }
	   TRACE0("Deleted lines array\n");

	   if (l3 != NULL)
	   {
	   while (i < l3->GetSize())
	   delete (CString *) l3->GetAt(i++);
	   l3->RemoveAll();
	   delete l3;
	   l3 = NULL;
	   }
	   TRACE0("Deleted lines array\n");
}

BOOL CAMonitorView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CAMonitorView drawing

void CAMonitorView::OnDraw(CDC* pDC)
{
	CAMonitorDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CAMonitorView printing

BOOL CAMonitorView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CAMonitorView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CAMonitorView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CAMonitorView diagnostics

#ifdef _DEBUG
void CAMonitorView::AssertValid() const
{
	  CView::AssertValid();
}

void CAMonitorView::Dump(CDumpContext& dc) const
{
	  CView::Dump(dc);
}

CAMonitorDoc* CAMonitorView::GetDocument() // non-debug version is inline
{
	  ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CAMonitorDoc)));
	  return (CAMonitorDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CAMonitorView message handlers

void CAMonitorView::OnMonit() 
{
    if(( b_ToolBar3 == TRUE )&&( MenuID!="Monitor" ))
	{
	  m_SelectedMenuToolBar = "MainViewStart";
	  if (PicturePrepar == 1)
	  {
	  PreparePicture();
	  }
      memDC3.PatBlt(0,0,maxX,356,WHITENESS);

	  if( SettingBMPBitBlt != FALSE)
		{
	  LoadFileData();
      PrepareChartData();  
		}
	  if(m_bmp8able == TRUE)
	  {
		  m_EditTextOutSide.ShowWindow(0);
	  }
	  MenuID="Monitor";
	  m_HelpTextDisplay = false;
	  currentLine3 = 0;
//	  KillTimer(3);
      Invalidate(0);
	}
	if( b_ToolBar3 == false )
	{
		if(!Execute){OnExec();}
	}    
}

void CAMonitorView::OnUpdateMonit(CCmdUI* pCmdUI) 
{
//	  pCmdUI->Enable(MenuID!="Monitor");
}

void CAMonitorView::OnData() 
{
      if(( b_ToolBar3 == TRUE )&&( MenuID!="Data" ))
	{
	  CAMonitorDoc *pDoc = GetDocument();
      CPtrArray *l = pDoc->GetLines();
	  if (PicturePrepar == 1)
	  {
      PreparePicture();
	  }
      memDC3.PatBlt(0,0,640,356,WHITENESS);
      if(DataFontCreate == false)
	  {
	  DataFont.CreateFont(19, 0, 0, 0, FW_NORMAL, FALSE, FALSE,
		FALSE, ANSI_CHARSET, OUT_TT_PRECIS, CLIP_TT_ALWAYS,
		DEFAULT_QUALITY, DEFAULT_PITCH, "Courier New");
	  CFont* oldFont;
	  oldFont = memDC3.SelectObject(&DataFont);
	  TEXTMETRIC tm;
	  memDC3.GetTextMetrics(&tm);
	  lHeight = tm.tmHeight + tm.tmExternalLeading;
	  cWidth = tm.tmAveCharWidth;	
      memDC3.SelectObject(oldFont);
      DataFontCreate = true;
	  }
	  if(m_bmp8able == TRUE){m_EditTextOutSide.ShowWindow(0);}
	  MenuID = "Data";
	  m_HelpTextDisplay = false;
	  currentLine3 = 0;
      currentLine = l->GetSize() - 8;
	  if(currentLine < 0){currentLine = 0;}
      Invalidate(0);
	  }
	  if( b_ToolBar3 == false )
	  {
	  if(Execute){OnStop();}
	  }
}

void CAMonitorView::OnUpdateData(CCmdUI* pCmdUI) 
{
//	  pCmdUI->Enable(MenuID!="Data");
}

void CAMonitorView::OnAvah() 
{
      if(( b_ToolBar3 == TRUE )&&( MenuID!="A-V-AH" ))
	  {
	  if (PicturePrepar == 1)
	  {
      PreparePicture();
	  }
	  if(m_bmp8able == TRUE){m_EditTextOutSide.ShowWindow(0);}
	  MenuID = "A-V-AH";
	  m_HelpTextDisplay = false;
	  currentLine3 = 0;
      Invalidate(0);
	  }
	  if( b_ToolBar3 == false )
	  {
	  OnRestart();
	  }
}

void CAMonitorView::OnUpdateAvah(CCmdUI* pCmdUI) 
{
//	  pCmdUI->Enable(MenuID!="A-V-AH");
}

void CAMonitorView::OnTimed() 
{
      if(( b_ToolBar3 == TRUE )&&( MenuID!="TimeData" ))
	  {
	  if (PicturePrepar == 1)
	  {
      PreparePicture();
	  }
	  CommondString.Empty();
	  EndCommondString.Empty();
	  k=0;
	  if(m_bmp8able == TRUE){m_EditTextOutSide.ShowWindow(0);}
	  MenuID = "TimeData";
	  m_HelpTextDisplay = false;
	  currentLine3 = 0;
      InvalidateRect(NULL,0);
	  }
	  if( b_ToolBar3 == false )
	  {
	  OnOpenaedit();
	  }
}

void CAMonitorView::OnUpdateTimed(CCmdUI* pCmdUI) 
{
	  pCmdUI->Enable(MenuID!="TimeData");
}

void CAMonitorView::OnSett1() 
{
      if(( b_ToolBar3 == TRUE )&&( MenuID!="Setting 1" ))
	  {
	  if (m_bmp2able == false)
	  {
	  AfxGetApp()->BeginWaitCursor();
	  CClientDC DC(this);  
	  CBitmap m_bmp0,m_bmp2;

      m_bmp0.LoadBitmap(IDB_BITMAP0);
	  memDC0.CreateCompatibleDC(&DC);
      memDC0.SelectObject(&m_bmp0);
	  m_bmp2.LoadBitmap(IDB_BITMAP2);
	  memDC2.CreateCompatibleDC(&DC);
      memDC2.SelectObject(&m_bmp2);    

	  m_bmp2able = TRUE;
	  AfxGetApp()->EndWaitCursor();
	  }
	  if (PicturePrepar == 1)
	  {
	  PreparePicture();
	  }
	  if( SettingBMPBitBlt != FALSE)
	  {
	  LoadFileData();
      PrepareChartData();  
	  }
	  if(m_bmp8able == TRUE){m_EditTextOutSide.ShowWindow(0);}
	  CommondString.Empty();
	  EndCommondString.Empty();
	  k=0;
      memDC3.PatBlt(0,0,640,356,WHITENESS);
      MenuID = "Setting 1";
	  m_HelpTextDisplay = false;
	  currentLine3 = 0;
	  {
	  memDC2.PatBlt(((TimeapartmV*Timeapartm) * m)/60 + 355,-(atof(c_RecordingL1A)*(140/(VapartmV*Vapartm))-229),
			   4,4,WHITENESS);
	  }
	  if(Execute == TRUE){SetTimer(1, 25, NULL);}
      memDC2.PatBlt(361,60,250,150,WHITENESS);
	  Invalidate(0);
	  }
}

void CAMonitorView::OnUpdateSett1(CCmdUI* pCmdUI) 
{
	  pCmdUI->Enable(MenuID!="Setting 1");
}

void CAMonitorView::OnSett2() 
{
    if(( b_ToolBar3 == TRUE )&&( MenuID!="Setting 2" ))
	  {
	if (m_bmp8able == false)
	{
	AfxGetApp()->BeginWaitCursor();
	CClientDC DC(this);  
	CBitmap m_bmp8,m_bmp9;
	m_bmp8.LoadBitmap(IDB_BITMAP8);
	memDC8.CreateCompatibleDC(&DC);
    memDC8.SelectObject(&m_bmp8);
    m_bmp9.LoadBitmap(IDB_BITMAP9);
	memDC9.CreateCompatibleDC(&DC);
    memDC9.SelectObject(&m_bmp9);
	m_EditTextOutSide.Create( 
			  ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL |
			  WS_VSCROLL | ES_NOHIDESEL | WS_HSCROLL |WS_VISIBLE ,CRect(341,36,628,259),this,107);
	m_bmp8able = TRUE;
	}
	m_EditTextOutSide.ShowWindow(1);

//	m_EditTextOutSide.EnableWindow(!Execute);

	if (PicturePrepar == 1)
	  {
	PreparePicture();
	  }
    AfxGetApp()->EndWaitCursor();
	
	CommondString.Empty();
	EndCommondString.Empty();
	k=0;
    memDC3.PatBlt(0,0,640,356,WHITENESS);
    MenuID = "Setting 2";
	m_HelpTextDisplay = false;
	currentLine3 = 0;
	Invalidate(0);
	}
}

void CAMonitorView::OnUpdateSett2(CCmdUI* pCmdUI) 
{
	   pCmdUI->Enable(MenuID!="Setting 2");
}

void CAMonitorView::OnButton32786() 
{
       m_Exit ^=1;
	   if (PicturePrepar != 1)
	   {
       if(MenuID == "Setting 2")
	   {
	   memDC3.PatBlt(58,103,402,318,WHITENESS);
	   InvalidateRect(CRect(58,103,402,318),0);
	   }
	   else
	   {
	   memDC3.PatBlt(198,103,442,318,WHITENESS);
	   InvalidateRect(CRect(198,103,450,318),0);
	   }
	   }
	   else
	   {
	   if(b_PrepareExitBMP == 0)
	   {
       CClientDC DC(this);
	   CBitmap m_bmp15,m_bmp3;

	   m_bmp3.CreateCompatibleBitmap(&DC,maxX,356);
	   memDC3.CreateCompatibleDC(&DC);
       memDC3.SelectObject(&m_bmp3);
       memDC3.PatBlt(0,0,maxX,356,WHITENESS);

	   m_bmp15.LoadBitmap(IDB_BITMAP15);    //ExitDlg
	   memDC15.CreateCompatibleDC(&DC);
       memDC15.SelectObject(&m_bmp15);
	   b_PrepareExitBMP = 1;
	   }
	   InvalidateRect(CRect(198,103,450,318),0);
	   }
}

void CAMonitorView::OnUpdateButton32786(CCmdUI* pCmdUI) 
{
       pCmdUI->SetCheck(m_Exit);	
}


void CAMonitorView::OnHelp() 
{

}

void CAMonitorView::OnHelpfile() 
{
	if (PicturePrepar == 1)
	{
    PreparePicture();
	}
	m_HelpTextDisplay ^=1;

	if (MenuID == "Setting 2") //For "Setting 2" menu.
	{
	memDC3.PatBlt(200,260,618,387,WHITENESS);
	InvalidateRect(CRect(200,260,618,387),0);
	}
	else
	{
	memDC3.PatBlt(200,200,618,327,WHITENESS);
	InvalidateRect(CRect(200,200,618,327),0);
	}
}

void CAMonitorView::OnUpdateHelpfile(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable(MenuID!="Help");	
}

void CAMonitorView::OutsideDataInput()
{
//	if (m_pDlg->GetSafeHwnd() == 0) {
//		m_pDlg->Create();       
//		}
//		m_pDlg->Input();
		  
		LoadFileData();

        CAMonitorDoc *pDoc = GetDocument();
	    n = s_OutsideDataInputML.GetLength();
	    if (k3 < n-56)
		{
        s_OutsideDataInput.Empty();
Loop:	k3++;
        s_OutsideDataInput += s_OutsideDataInputML.GetAt(k3) ;
		if(s_OutsideDataInputML.GetAt(k3)!='\n')
		{
		goto Loop;
		}
		else
        pDoc->lines->Add(new CString(s_OutsideDataInput));
	 }
		s_EditString += s_OutsideDataInput;
		if (MenuID == "Setting 2") //For "Setting 2" menu.
		{
		InvalidateRect(CRect(341,36,628,259),0);
		m_EditTextOutSide.LineScroll(m_EditTextOutSide.GetLineCount(),0);
		}
}

void CAMonitorView::ComunicationMl()
{
		   OutsideDataInput();
		   RecSound();
		   
		   if(m_Farq > 1.0)
		   {CAMonitorApp *app = (CAMonitorApp *)AfxGetApp();
		   app->m_ProgreesReStart = 1;}

           m = m+1;
           if (m == 298){m = 4;}

          c_RecordingL3N = c_RecordingL2N;
          c_RecordingL3U = c_RecordingL2U;
          c_RecordingL3A = c_RecordingL2A;
          c_RecordingL3AH = c_RecordingL2AH;
          c_RecordingL3T1 = c_RecordingL2T1;
          c_RecordingL3T2 = c_RecordingL2T2;
          c_RecordingL3CW = c_RecordingL2CW;
          c_RecordingL2N = c_RecordingL1N;
          c_RecordingL2U = c_RecordingL1U;
          c_RecordingL2A = c_RecordingL1A;
          c_RecordingL2AH = c_RecordingL1AH;
          c_RecordingL2T1 = c_RecordingL1T1;
          c_RecordingL2T2 = c_RecordingL1T2;
          c_RecordingL2CW = c_RecordingL1CW;

          c_RecordingL3Time =  c_RecordingL2Time;
          c_RecordingL2Time =  c_RecordingL1Time;

	       for(int j = 0;j<65;j++)
		   {
	       if (j>4){  
//         if (j<10){
//	         c_RecordingL1N[j-5]=CHART;
//		   }
           if (j>13&&j<19){
	         c_RecordingL1U.SetAt((j-14),s_OutsideDataInput.GetAt(j+3));
		   }        
	       if (j>19&&j<25){
	         c_RecordingL1A.SetAt((j-20),s_OutsideDataInput.GetAt(j+4));
		   }
           if (j>25&&j<31){	 
		     c_RecordingL1AH.SetAt((j-26),s_OutsideDataInput.GetAt(j+5));
		   }		   
		   if (j>31&&j<37){
             c_RecordingL1T1.SetAt((j-32),s_OutsideDataInput.GetAt(j+6));
		   }
           if (j>37&&j<43){
             c_RecordingL1T2.SetAt((j-38),s_OutsideDataInput.GetAt(j+7));
		   }
           if (j>42&&j<47){
             c_RecordingL1CW.SetAt((j-43),s_OutsideDataInput.GetAt(j+9));
		   }
		   }
		   }
          char str[6];
          c_RecordingMLNo =  c_RecordingMLNo + 1;
          if (  c_RecordingMLNo > 9999){
		  c_RecordingMLNo = 1; }
	      itoa( c_RecordingMLNo,str,10);
	      if (  c_RecordingMLNo <= 9){
		  c_RecordingL1N.SetAt(3,str[0]);}
	      if (( c_RecordingMLNo <= 99) && (  c_RecordingMLNo > 9)){
          c_RecordingL1N.SetAt(2,str[0]);
		  c_RecordingL1N.SetAt(3,str[1]);}
	      if (( c_RecordingMLNo <= 999) && (  c_RecordingMLNo > 99)){
          c_RecordingL1N.SetAt(1,str[0]);
          c_RecordingL1N.SetAt(2,str[1]);
		  c_RecordingL1N.SetAt(3,str[2]);}
	      if (( c_RecordingMLNo <= 9999) && ( c_RecordingMLNo > 999)){
          c_RecordingL1N.SetAt(0,str[0]);
          c_RecordingL1N.SetAt(1,str[1]);
          c_RecordingL1N.SetAt(2,str[2]);
		  c_RecordingL1N.SetAt(3,str[3]);}		 
	
    	  itoa( WorkedHour,str,10);

	      if (( WorkedHour <= 9) && ( WorkedHour> 0)){
          c_RecordingL1Time.SetAt(2,str[0]);}
	      if (( WorkedHour <= 99) && ( WorkedHour> 9)){
          c_RecordingL1Time.SetAt(1,str[0]);
          c_RecordingL1Time.SetAt(2,str[1]);}
	      if (( WorkedHour <= 999) && ( WorkedHour> 99)){
          c_RecordingL1Time.SetAt(0,str[0]);
          c_RecordingL1Time.SetAt(1,str[1]);
          c_RecordingL1Time.SetAt(2,str[2]);}
    	
	      c_RecordingL1Time.SetAt(3,':');
          itoa( WorkedMinute,str,10);
	      if (str[1]=='\0'){
          c_RecordingL1Time.SetAt(4,'0');
          c_RecordingL1Time.SetAt(5,str[0]);}
	      else{
          c_RecordingL1Time.SetAt(4,str[0]);
          c_RecordingL1Time.SetAt(5,str[1]);}
    
	      c_RecordingL1Time.SetAt(6,':');
          itoa( WorkedSecond,str,10);
	      if (str[1]=='\0'){
          c_RecordingL1Time.SetAt(7,'0');
          c_RecordingL1Time.SetAt(8,str[0]);}
	      else{
          c_RecordingL1Time.SetAt(7,str[0]);
          c_RecordingL1Time.SetAt(8,str[1]);}
		  
}

void CAMonitorView::WhiteReDraw()
{
          memDC3.PatBlt(0,0,maxX,356,WHITENESS);
          Invalidate(0);
}

void CAMonitorView::LoadHelpFile()
{
     if (b_LoadHelpFile == FALSE)
	 {
	 CString s;
     BYTE buf;
	 int i = 0;
	 CFile file("ChineseHelpText.txt",CFile::modeRead);
     CArchive ar(&file,CArchive::load);
		while (1)
		{
			try {
	 ar >> buf;
			}
			catch (CArchiveException *e)
			{
				if (e->m_cause != CArchiveException::endOfFile)
				{
					TRACE0("Unknown exception loading file!\n");
					throw;
				} else
				{
					TRACE0("End of file reached...\n");
					e->Delete();
				}
				break;
			}
    		s += buf;
			if (buf == '\n')
			{
				try {
					i++;
						if(s.Find("F1")==0){F1BookMark=i;}
						if(s.Find("F2")==0){F2BookMark=i;}
						if(s.Find("F3")==0){F3BookMark=i;}
						if(s.Find("F4")==0){F4BookMark=i;}
						if(s.Find("F5")==0){F5BookMark=i;}
						if(s.Find("F6")==0){F6BookMark=i;}
						if(s.Find("End")==0){EndBookMark=i;}
					
					l3->Add(new CString(s));
				}
				catch (CMemoryException *e)
				{
					AfxMessageBox("Not enough memory to load entire file");
					TRACE1("Not enough memory to load entire file; only %d lines loaded\n", lines->GetSize());
					e->Delete();
					break;
				}
				s.Empty();
			}
		}
#ifdef _DEBUG
//		afxDump.SetDepth(1);
//		afxDump << pDoc->lines;
#endif
		ar.Close();
		file.Close();

	    HelpTextFont.CreateFont(17, 0, 0, 0, FW_NORMAL, FALSE, FALSE,
		FALSE, ANSI_CHARSET, OUT_TT_PRECIS, CLIP_TT_ALWAYS,
		DEFAULT_QUALITY, DEFAULT_PITCH, "Courier New");
	    CFont* oldFont;
	    oldFont = memDC3.SelectObject(&HelpTextFont);
	    TEXTMETRIC tm;
	    memDC3.GetTextMetrics(&tm);
	    HelpTextHeight = tm.tmHeight + tm.tmExternalLeading;
	    HelpTextWidth = tm.tmAveCharWidth;
        memDC3.SelectObject(oldFont);

        b_LoadHelpFile = TRUE;
}
}

void CAMonitorView::LoadFileData()
{
     if (b_LoadFileData == FALSE)
	 {
	 CString s;
     BYTE buf;
	 CFile file("ShowRecord.ddy",CFile::modeRead);
     CArchive ar(&file,CArchive::load);
		while (1)
		{
			try {
	 ar >> buf;
			}
			catch (CArchiveException *e)
			{
				if (e->m_cause != CArchiveException::endOfFile)
				{
					TRACE0("Unknown exception loading file!\n");
					throw;
				} else
				{
					TRACE0("End of file reached...\n");
					e->Delete();
				}
				break;
			}
    		s += buf;
			if (buf == '\n')
			{
				try {
					l2->Add(new CString(s));
                    s_OutsideDataInputML += s; 
				}
				catch (CMemoryException *e)
				{
					AfxMessageBox("Not enough memory to load entire file");
					TRACE1("Not enough memory to load entire file; only %d lines loaded\n", lines->GetSize());
					e->Delete();
					break;
				}
				s.Empty();
			}
		}

		ar.Close();
		file.Close();
//#ifdef _DEBUG
//		afxDump.SetDepth(1);
//		afxDump << lines;
//#endif
        b_LoadFileData = TRUE;
	    c = l2->GetSize();
}
}

void CAMonitorView::PrepareChartData()
{
     TimeapartmV = Timeapartm = VapartmV = Vapartm = 0;	 
	 CString Totals;
     CString Vs = "00000";
     CString TimeHmins = "000";
     CString TimeHmaxs = "000";
	 CString TimeMmins = "00";
	 CString TimeMmaxs = "00";
	 CString TimeSmins = "00";
	 CString TimeSmaxs = "00";
	 double DrawMaxV = 0.0f;
	 int Vindex;
     double d_Vindex,DrawMaxVs;
	 
	 for (int i = 1; i < c-1; i++)
	 {
	    CString *line = (CString *) l2->GetAt(i);
	    Totals = *line;		

		for (int j = 0; j < 5; j++)
		{
		if (Totals.GetAt(24 + j) != ' ') 
	        Vs.SetAt(j,Totals.GetAt(24 + j));
		}
	    DrawV[i] = atof(Vs);
        Vs = "00000";	
    if (DrawMaxV < DrawV[i])
		DrawMaxV = DrawV[i];	 
	 }
        DrawMaxVs = DrawMaxV;
        d_Vindex = log10(DrawMaxV);
	    Vindex = d_Vindex;

     for (int o = 0; o < Vindex; o++)
	   {
	   DrawMaxVs = DrawMaxVs/10;
	   }

       Vapartm = DrawMaxVs *2;
       Vapartm = Vapartm + 1;
       VapartmV = 0.5;
	 for (int p = 0; p < Vindex; p++)
	   {
	   VapartmV = VapartmV*10.0;
	   }
	 
	    CString *line = (CString *) l2->GetAt(2);
	    Totals = *line;		
		for (int r = 0; r < 3; r++)
		{
		TimeHmins.SetAt(r,Totals.GetAt(6 + r));
		}

		TimeMmins.SetAt(0,Totals.GetAt(10));
		TimeMmins.SetAt(1,Totals.GetAt(11));

		TimeSmins.SetAt(0,Totals.GetAt(13));
		TimeSmins.SetAt(1,Totals.GetAt(14));
	    
		line= (CString *) l2->GetAt(c-2);
	    Totals = *line;		
		for (int x = 0; x < 3; x++)
		{
		TimeHmaxs.SetAt(x,Totals.GetAt(6 + x));
		}

		TimeMmaxs.SetAt(0,Totals.GetAt(10));
		TimeMmaxs.SetAt(1,Totals.GetAt(11));

		TimeSmaxs.SetAt(0,Totals.GetAt(13));
        TimeSmaxs.SetAt(1,Totals.GetAt(14));

		double DrawTime,DrawTimes;
        DrawTime = (((atoi(TimeHmaxs)-atoi(TimeHmins))*60)+(atoi(TimeMmaxs)-atoi(TimeMmins))+
			((atof(TimeSmaxs)-atof(TimeSmins))/60.0));
        
		int d_Timeindex,Timeindex;
	    DrawTimes = DrawTime;
        d_Timeindex = log10(DrawTime);
	    Timeindex = d_Timeindex;

     for (int u = 0; u < Timeindex; u++)
	   {
	   DrawTimes = DrawTimes/10;
	   }
       Timeapartm = DrawTimes *2;
       Timeapartm = Timeapartm + 1;
       TimeapartmV = 0.5;
	   for (int v = 0; v < Timeindex; v++)
	   {
	   TimeapartmV = TimeapartmV*10;
	   }
}

void CAMonitorView::PreparePicture()
{
	  AfxGetApp()->BeginWaitCursor();
	  CClientDC DC(this);
	  CBitmap m_bmp1,m_bmp3,m_bmp4,m_bmp5,m_bmp6,m_bmp7,m_bmp10,m_bmp11,
			  m_bmp12,m_bmp13,m_bmp14,m_bmp15,m_bmp16,m_bmp17,m_bmpHelpTop,m_bmpHelpBottom,
			  m_bmpHelpLeft,m_bmpHelpRight;

	  m_bmp1.LoadBitmap(IDB_BITMAP1);    //SystemChart
	  memDC1.CreateCompatibleDC(&DC);
      memDC1.SelectObject(&m_bmp1);
     
	  m_bmp4.LoadBitmap(IDB_BITMAP4);    //ActChart
	  memDC4.CreateCompatibleDC(&DC);
      memDC4.SelectObject(&m_bmp4);

	  m_bmp5.LoadBitmap(IDB_BITMAP5);    //SelectBar
	  memDC5.CreateCompatibleDC(&DC);
      memDC5.SelectObject(&m_bmp5);

	  m_bmp6.LoadBitmap(IDB_BITMAP6);    //SelectedBar
	  memDC6.CreateCompatibleDC(&DC);
      memDC6.SelectObject(&m_bmp6);

	  m_bmp7.LoadBitmap(IDB_BITMAP7);    //SelectedBar
	  memDC7.CreateCompatibleDC(&DC);
      memDC7.SelectObject(&m_bmp7);

	  m_bmp10.LoadBitmap(IDB_BITMAP10);    //DataEnglish
	  memDC10.CreateCompatibleDC(&DC);
      memDC10.SelectObject(&m_bmp10);

	  m_bmp11.LoadBitmap(IDB_BITMAP11);    //DataChinese
	  memDC11.CreateCompatibleDC(&DC);
      memDC11.SelectObject(&m_bmp11);

	  m_bmp12.LoadBitmap(IDB_BITMAP12);    //AVAHChinese1
	  memDC12.CreateCompatibleDC(&DC);
      memDC12.SelectObject(&m_bmp12);

	  m_bmp13.LoadBitmap(IDB_BITMAP13);    //AVAHChinese2
	  memDC13.CreateCompatibleDC(&DC);
      memDC13.SelectObject(&m_bmp13);

	  m_bmp14.LoadBitmap(IDB_BITMAP14);    //MontorChinese
	  memDC14.CreateCompatibleDC(&DC);
      memDC14.SelectObject(&m_bmp14);

	  m_bmp16.LoadBitmap(IDB_BITMAP16);    //ToolBar3
	  memDC16.CreateCompatibleDC(&DC);
      memDC16.SelectObject(&m_bmp16);

	  m_bmp17.LoadBitmap(IDB_BITMAP17);    //ToolBar4
	  memDC17.CreateCompatibleDC(&DC);
      memDC17.SelectObject(&m_bmp17);

	  m_bmpHelpTop.LoadBitmap(IDB_HelpTop);
	  memDCHelpTop.CreateCompatibleDC(&DC);
      memDCHelpTop.SelectObject(&m_bmpHelpTop);

	  m_bmpHelpBottom.LoadBitmap(IDB_HelpBottom);
	  memDCHelpBottom.CreateCompatibleDC(&DC);
      memDCHelpBottom.SelectObject(&m_bmpHelpBottom);

	  m_bmpHelpLeft.LoadBitmap(IDB_HelpLeft); 
	  memDCHelpLeft.CreateCompatibleDC(&DC);
      memDCHelpLeft.SelectObject(&m_bmpHelpLeft);

	  m_bmpHelpRight.LoadBitmap(IDB_HelpRight);
	  memDCHelpRight.CreateCompatibleDC(&DC);
      memDCHelpRight.SelectObject(&m_bmpHelpRight);

      if(b_PrepareExitBMP == 0)
	  {
      m_bmp3.CreateCompatibleBitmap(&DC,maxX,356);
	  memDC3.CreateCompatibleDC(&DC);
      memDC3.SelectObject(&m_bmp3);
      memDC3.PatBlt(0,0,maxX,356,WHITENESS);

	  m_bmp15.LoadBitmap(IDB_BITMAP15);    //ExitDlg
	  memDC15.CreateCompatibleDC(&DC);
      memDC15.SelectObject(&m_bmp15);
	  b_PrepareExitBMP = 1;
	  }

	  if (m_pDlg->GetSafeHwnd() == 0) {
	  m_pDlg->Create(); // displays the modleness dialog window
	  }
      PicturePrepar = 0;
	  AfxGetApp()->EndWaitCursor();
}

void CAMonitorView::OnPaint() 
{
	 CPaintDC dc(this); // device context for painting

     if (MenuID == "Monitor") //For "Monitor" menu. 
	 {
     CPen* pOriginalPen;
     pOriginalPen=memDC3.SelectObject(&GreenPen);
	 memDC3.PatBlt(5,14,171,128,WHITENESS); 
          	 	
	 CBrush* pOriginalBrush;
	 pOriginalBrush = memDC3.SelectObject(&ColorBrush[ColAHBar]);
     memDC3.Rectangle(10,30,(atof( c_RecordingL1AH ))*2000+10,48);
	 memDC3.SelectObject(&ColorBrush[ColVoltBar]);
     memDC3.Rectangle(10,70,(atof( c_RecordingL1U ))*10+10,88);
	 memDC3.SelectObject(&ColorBrush[ColCurrBar]);
     memDC3.Rectangle(10,110,(atof( c_RecordingL1A )-50)/1.55+42,128);

	 if(m_EnglishChinese == 1)
	 {memDC3.BitBlt(8,12,628,331,&memDC14,0,0,SRCAND);}
	 else {
	 memDC3.SetTextColor(RGB(0,0,0));
     memDC3.SetBkColor(RGB(134,255,255));
     memDC3.TextOut(10,13,"  BET.  CAP   ");
     memDC3.TextOut(10,53,"  BET.  VOT   ");
     memDC3.TextOut(10,93,"  CH.   CUR   ");

     memDC3.TextOut(10,140,"  SYS. M.V   ");
     memDC3.TextOut(10,156,"  SYS. M.C   ");
     memDC3.TextOut(10,236," 1st L.V      ");
     memDC3.TextOut(10,252," 2nd L.V     ");
     memDC3.TextOut(10,268," 1st L.C      ");
     memDC3.TextOut(10,284," 2nd L.C     ");
     memDC3.TextOut(10,300," L. AH        ");
     memDC3.TextOut(10,316," L. T1         ");

     memDC3.TextOut(465,196," SPEED    ");
	 memDC3.TextOut(465,212," FARQ       ");
     memDC3.TextOut(465,284," CUR.TIM    ");
     memDC3.TextOut(465,300," WOR.TIM   ");
     memDC3.TextOut(465,316," REM.TIM    ");

     memDC3.SetBkColor(RGB(157,157,255));
     memDC3.TextOut(10,180," CHANG MOD                  "); 
     memDC3.TextOut(10,220," LI. ITEM                         ");
     memDC3.TextOut(465,124," COMMU. LIN                   ");     
     memDC3.TextOut(465,164," SPE. BIN                         ");
     memDC3.TextOut(465,236," PRINT. LIN                      ");
     memDC3.TextOut(465,268," TIME                                ");

	 memDC3.SetBkColor(RGB(255,255,255));    
	 wsprintf(m_str," 1:ON   0:OFF  ",NULL);
     memDC3.TextOut(540,140,m_str,strlen(m_str));	 	
     memDC3.TextOut(522,180," 1:H   2:M   3:S  ");
     memDC3.TextOut(540,252," 1:ON   0:OFF ");
     memDC3.TextOut(26,196," 1:HY  2:HY-HL  3:HL ");

	 memDC3.TextOut(202,27,"No:",3);
	 memDC3.TextOut(264,27,"TIME",3);     
	 memDC3.TextOut(330,27,"VOL",3);
	 memDC3.TextOut(383,27,"CUR",3);
     memDC3.TextOut(436,27,"AH",2);
	 memDC3.TextOut(489,27,"T1",2);
     memDC3.TextOut(542,27,"T2",2);
	 memDC3.TextOut(595,27,"CWO",3);

	 memDC3.TextOut(145,13," AH ");
     memDC3.TextOut(146,53,"  V  ");
     memDC3.TextOut(146,93,"  A  ");
     memDC3.TextOut(146,140,"  V  ");
     memDC3.TextOut(146,156,"  A  ");

     memDC3.TextOut(579,196,"  TIMES  ");
     memDC3.TextOut(610,212,"S"); 
	 
	 memDC3.BitBlt(8,29,162,19,&memDC7,0,0,SRCAND);
	 memDC3.BitBlt(8,69,162,19,&memDC7,0,0,SRCAND);
	 memDC3.BitBlt(8,109,162,19,&memDC7,0,0,SRCAND);
	 }

     if (ChargeModel==0)
	 {
     memDC3.BitBlt(24,196,72,212,&memDC6,0,0,SRCAND);
	 }
     if (ChargeModel==1)
	 {
     memDC3.BitBlt(63,196,114,212,&memDC6,0,0,SRCAND);
     memDC3.BitBlt(87,196,134,212,&memDC6,0,0,SRCAND);
	 }
     if (ChargeModel==2)
	 {
     memDC3.BitBlt(126,196,167,212,&memDC6,0,0,SRCAND);
	 }
     if (m_CommuncationLink)
     memDC3.BitBlt(539,140,580,156,&memDC6,0,0,SRCAND);
     else memDC3.BitBlt(585,140,624,156,&memDC6,0,0,SRCAND);
     if (m_PrinterLink)
     memDC3.BitBlt(539,252,577,268,&memDC6,0,0,SRCAND);
     else memDC3.BitBlt(585,252,621,268,&memDC6,0,0,SRCAND);
     if ( m_Radio == 2)
	 {memDC3.BitBlt(515,180,572,196,&memDC6,0,0,SRCAND);}
     if ( m_Radio == 1)
	 {memDC3.BitBlt(551,180,607,196,&memDC6,0,0,SRCAND);}
     if ( m_Radio == 0)
	 {memDC3.BitBlt(585,180,625,196,&memDC6,0,0,SRCAND);}
	
    CRect AlarmMessageCircle1 (150,238,162,250);
    CRect AlarmMessageCircle2 (150,254,162,266);
    CRect AlarmMessageCircle3 (150,270,162,282);
    CRect AlarmMessageCircle4 (150,286,162,298);
    CRect AlarmMessageCircle5 (150,302,162,314);
    CRect AlarmMessageCircle6 (150,318,162,330);

    if (atoi( c_RecordingL1U ) >= m_1ndLimV){
	AlarmSound();
	memDC3.SelectObject(&RedBrush);}
    else	
    memDC3.SelectObject(&GreenBrush);
    memDC3.Ellipse (&AlarmMessageCircle1);
    if (atoi( c_RecordingL1U ) >= m_2ndLimV){
    AlarmSound();
	memDC3.SelectObject(&RedBrush);}
    else	
    memDC3.SelectObject(&GreenBrush);
    memDC3.Ellipse (&AlarmMessageCircle2);
    if (atoi( c_RecordingL1A ) >= m_1ndLimA){
    AlarmSound();
	memDC3.SelectObject(&RedBrush);}
    else	
    memDC3.SelectObject(&GreenBrush);
    memDC3.Ellipse (&AlarmMessageCircle3);
    if (atoi( c_RecordingL1A ) >= m_2ndLimA){
    AlarmSound();
	memDC3.SelectObject(&RedBrush);}
    else	
    memDC3.SelectObject(&GreenBrush);
    memDC3.Ellipse (&AlarmMessageCircle4);
    if (atof( c_RecordingL1AH ) >= m_LAH){
    AlarmSound();
	memDC3.SelectObject(&RedBrush);}
    else	
    memDC3.SelectObject(&GreenBrush);
    memDC3.Ellipse (&AlarmMessageCircle5);
    if (atof( c_RecordingL1T1 ) >= m_LT1){
    AlarmSound();
	memDC3.SelectObject(&RedBrush);}
    else	
    memDC3.SelectObject(&GreenBrush);
    memDC3.Ellipse (&AlarmMessageCircle6);

	 memDC3.TextOut(202,79,c_RecordingL1N,4);
     memDC3.TextOut(256,79,c_RecordingL1Time,9);
     memDC3.TextOut(330,79,c_RecordingL1U,5);
	 memDC3.TextOut(383,79,c_RecordingL1A,5);
     memDC3.TextOut(436,79,c_RecordingL1AH,5);
	 memDC3.TextOut(489,79,c_RecordingL1T1,5);
     memDC3.TextOut(542,79,c_RecordingL1T2,5);
	 memDC3.TextOut(595,79,c_RecordingL1CW,4);

	 memDC3.TextOut(202,63,c_RecordingL2N,4);
     memDC3.TextOut(256,63,c_RecordingL2Time,9);
     memDC3.TextOut(330,63,c_RecordingL2U,5);
	 memDC3.TextOut(383,63,c_RecordingL2A,5);
     memDC3.TextOut(436,63,c_RecordingL2AH,5);
	 memDC3.TextOut(489,63,c_RecordingL2T1,5);
     memDC3.TextOut(542,63,c_RecordingL2T2,5);
	 memDC3.TextOut(595,63,c_RecordingL2CW,4);

	 memDC3.TextOut(202,48,c_RecordingL3N,4);
     memDC3.TextOut(256,48,c_RecordingL3Time,9);
     memDC3.TextOut(330,48,c_RecordingL3U,5);
	 memDC3.TextOut(383,48,c_RecordingL3A,5);
     memDC3.TextOut(436,48,c_RecordingL3AH,5);
     memDC3.TextOut(489,48,c_RecordingL3T1,5);
     memDC3.TextOut(542,48,c_RecordingL3T2,5);
	 memDC3.TextOut(595,48,c_RecordingL3CW,4);

     CString s;
     s.Format("   %6.3f",atof(c_RecordingL1AH));
     memDC3.TextOut(90,13,s);
     s.Format("    %5.2f",atof(c_RecordingL1U));
     memDC3.TextOut(90,53,s);
     s.Format("  %5.2f",atof(c_RecordingL1A));
     memDC3.TextOut(90,93,s);
     wsprintf(m_str,"      %d ",m_SysMaxV);
     memDC3.TextOut(90,140,m_str,strlen(m_str));
     wsprintf(m_str,"      %d ",m_SysMaxA);
     memDC3.TextOut(90,156,m_str,strlen(m_str));

     s.Format("    %5.2f",m_1ndLimV);
     memDC3.TextOut(80,236,s);
     s.Format("    %5.2f",m_2ndLimV);
     memDC3.TextOut(80,252,s);
     s.Format("    %5.2f",m_1ndLimA);
     memDC3.TextOut(80,268,s);
     s.Format("    %5.2f",m_2ndLimA);
     memDC3.TextOut(80,284,s);
     s.Format("   %6.3f",m_LAH);     
     memDC3.TextOut(80,300,s);
     s.Format("    %4.1f",m_LT1);       
     memDC3.TextOut(80,316,s);

     s.Format("  %4.2f",m_FreqAdj);
     memDC3.TextOut(542,196,s);
	
     s.Format("    %6.3f",m_Farq);
     memDC3.TextOut(531,212,s);

     memDC3.TextOut(542,284,"                   ");
     memDC3.TextOut(557,284,CTime::GetCurrentTime().Format("%I : %M : %S %P"));

	  wsprintf(m_str,"                      ",WorkedSecond);
      memDC3.TextOut(542,300,m_str,strlen(m_str));
	  wsprintf(m_str," : %2d",WorkedSecond);
      memDC3.TextOut(601,300,m_str,strlen(m_str));
      wsprintf(m_str," : %2d ",WorkedMinute);
      memDC3.TextOut(572,300,m_str,strlen(m_str));
      wsprintf(m_str,"%2d",WorkedHour);
      memDC3.TextOut(544,300,m_str,strlen(m_str));

      wsprintf(m_str,"                      ",RemnantSecond);
      memDC3.TextOut(542,316,m_str,strlen(m_str));
	  wsprintf(m_str," : %2d",RemnantSecond);
      memDC3.TextOut(601,316,m_str,strlen(m_str));
 	  wsprintf(m_str," : %2d ",RemnantMinute);
      memDC3.TextOut(572,316,m_str,strlen(m_str));
      wsprintf(m_str,"%2d",RemnantHour);
      memDC3.TextOut(544,316,m_str,strlen(m_str));

	  memDC4.BitBlt(0,0,245,145,&memDC1,0,0,SRCAND);
	  memDC3.BitBlt(m_pointTopLeft.x,m_pointTopLeft.y,245,145,&memDC4,0,0,SRCCOPY);	

	  if(m_HelpTextDisplay == TRUE)
	  {
	  memDC3.BitBlt(200,306,600,319,&memDCHelpBottom,0,0,SRCCOPY);
	  memDC3.BitBlt(200,200,505,298,&memDCHelpLeft,0,0,SRCCOPY);
	  memDC3.BitBlt(200,200,600,205,&memDCHelpTop,0,0,SRCCOPY);
	  memDC3.BitBlt(600,200,618,298,&memDCHelpRight,0,0,SRCCOPY);

	  CBrush* pOriginalBrush;
	  pOriginalBrush = memDC3.SelectObject(&HelpTextBoxBrush);
      memDC3.PatBlt(205,205,398,102,PATCOPY);
      memDC3.SelectObject(&pOriginalBrush);

	  LoadHelpFile();
   	  CFont *oldFont;
	  oldFont = memDC3.SelectObject(&HelpTextFont);
	  memDC3.SetBkColor(RGB(245,245,200));
	  int y = 0;
	  if(currentLine3>(F2BookMark-F1BookMark-7)){currentLine3=F2BookMark-F1BookMark-7;}
	  for (int i = F1BookMark+currentLine3; (i-(F1BookMark+currentLine3))<6; i++)
	  {
		 CString *line = (CString *) l3->GetAt(i);
		 memDC3.TextOut(210, y+205, line->Mid(0), line->GetLength() - 2);
		 y += HelpTextHeight;
	  }
	  memDC3.SelectObject(oldFont);
	  memDC3.SetBkColor(RGB(255,255,255));
	  }

	  if(m_Exit == TRUE)
	  {
	  memDC3.BitBlt(198,103,442,318,&memDC15,0,0,SRCCOPY);
	  }
	  dc.BitBlt(0,0,640,356,&memDC3,0,0,SRCCOPY);
      
	  memDC3.SelectObject(&pOriginalBrush); 
	  memDC3.SelectObject(&pOriginalPen);
      }

      if (MenuID == "Data") //For "Data" menu. 
	  {
	  CAMonitorDoc* pDoc = GetDocument();
	  ASSERT_VALID(pDoc);

	  CPtrArray *l = pDoc->GetLines();

      memDC3.TextOut(5,5,"L.No.");
	  memDC3.TextOut(61,5,"R.No.");
	  memDC3.TextOut(150,5,"TIM");
	  memDC3.TextOut(235,5,"VOL");
	  memDC3.TextOut(308,5,"CUR");
	  memDC3.TextOut(380,5,"AH");
	  memDC3.TextOut(452,5,"T1");
	  memDC3.TextOut(520,5,"T2");
      memDC3.TextOut(578,5,"CWO");

	  CFont *oldFont;
	  oldFont = memDC3.SelectObject(&DataFont);
      CRect clientRect;
	  int y = 0;
	  GetClientRect(&clientRect);

	  for (int i = currentLine; i < l->GetSize(); i++)
	  {
		 CString *line = (CString *) l->GetAt(i);
//		 if (line->GetLength() - 2 > margin)
		 memDC3.TextOut(55, y+23, line->Mid(margin), line->GetLength() - margin -2);
         wsprintf(m_str,"%d",i+1);
         memDC3.TextOut(5,y+23,m_str,strlen(m_str));
		 y += lHeight;
		 if ((y > clientRect.Height()-30)&&((l->GetSize()-currentLine)<20))
		 {
		 currentLine = currentLine+18;
         WhiteReDraw();
		 break;
		 }
	  }

	  if(m_EnglishChinese == 1)
	  {memDC3.BitBlt(3,4,630,20,&memDC11,0,0,SRCCOPY);}

	  if(m_HelpTextDisplay == TRUE)
	  {
	  memDC3.BitBlt(200,306,600,319,&memDCHelpBottom,0,0,SRCCOPY);
	  memDC3.BitBlt(200,200,505,298,&memDCHelpLeft,0,0,SRCCOPY);
	  memDC3.BitBlt(200,200,600,205,&memDCHelpTop,0,0,SRCCOPY);
	  memDC3.BitBlt(600,200,618,298,&memDCHelpRight,0,0,SRCCOPY);

	  CBrush* pOriginalBrush;
	  pOriginalBrush = memDC3.SelectObject(&HelpTextBoxBrush);
      memDC3.PatBlt(205,205,398,102,PATCOPY);
      memDC3.SelectObject(&pOriginalBrush);
	  	 
	  LoadHelpFile();
   	  CFont *oldFont;
	  oldFont = memDC3.SelectObject(&HelpTextFont);
	  memDC3.SetBkColor(RGB(245,245,200));
	  int y = 0;
	  if(currentLine3>(F3BookMark-F2BookMark-7)){currentLine3=F3BookMark-F2BookMark-7;}
	  for (int i = F2BookMark+currentLine3; (i-(F2BookMark+currentLine3))<6; i++)
	  {
		 CString *line = (CString *) l3->GetAt(i);
		 memDC3.TextOut(210, y+205, line->Mid(0), line->GetLength() - 2);
		 y += HelpTextHeight;
	  }
	  memDC3.SelectObject(oldFont);
	  memDC3.SetBkColor(RGB(255,255,255));
	  }

         if(m_Exit == TRUE)
		 {
	     memDC3.BitBlt(198,103,442,318,&memDC15,0,0,SRCCOPY);
		 }

		 dc.BitBlt(0,0,640,356,&memDC3,0,0,SRCCOPY);
		 
	     memDC3.SelectObject(oldFont);
	 }

     if (MenuID == "Setting 1") //For "Setting 1" menu.
	 {
     wsprintf(m_str,"     %d  ",m_SysMaxV);
     memDC3.TextOut(82,20,m_str,strlen(m_str));
     wsprintf(m_str,"     %d  ",m_SysMaxA);
     memDC3.TextOut(82,36,m_str,strlen(m_str));

     wsprintf(m_str,"%d",m_OutRata);
     memDC3.TextOut(292,53,m_str,strlen(m_str));
     wsprintf(m_str,"%d",m_OutStopBit);
     memDC3.TextOut(292,85,m_str,strlen(m_str));
     wsprintf(m_str,"%d",m_OutWordsLength);
     memDC3.TextOut(292,101,m_str,strlen(m_str));
     memDC3.TextOut(292,69,m_OutParity);
	 memDC3.TextOut(292,117,m_OutCode);
	 memDC3.TextOut(292,133,m_OutComPort);

     wsprintf(m_str,"%d",m_InRata);
     memDC3.TextOut(292,196,m_str,strlen(m_str));
     wsprintf(m_str,"%d",m_InStopBit);
     memDC3.TextOut(292,228,m_str,strlen(m_str));
     wsprintf(m_str,"%d",m_InWordsLength);
     memDC3.TextOut(292,244,m_str,strlen(m_str));
     memDC3.TextOut(292,212,m_InParity);
	 memDC3.TextOut(292,260,m_InCode);
	 memDC3.TextOut(292,276,m_InComPort);

     CString s;
     s.Format("    %5.2f            ",m_1ndLimV);
     memDC3.TextOut(66,101,s);
     s.Format("    %5.2f            ",m_2ndLimV);
     memDC3.TextOut(66,117,s);
     s.Format("    %5.2f           ",m_1ndLimA);
     memDC3.TextOut(66,133,s);
     s.Format("    %5.2f           ",m_2ndLimA);
     memDC3.TextOut(66,149,s);
     s.Format("   %6.3f             ",m_LAH);     
     memDC3.TextOut(66,165,s);
     s.Format("    %4.1f               ",m_LT1);       
     memDC3.TextOut(66,181,s);

     s.Format("%7.3f",m_Farq);       
     memDC3.TextOut(80,277,s);

     s.Format("  %4.2f",m_FreqAdj);
     memDC3.TextOut(70,261,s);

      memDC3.TextOut(429,276,CTime::GetCurrentTime().Format("%I : %M : %S %P"));

      memDC3.TextOut(415,292,"                           ");
	  wsprintf(m_str," : %2d",WorkedSecond);
      memDC3.TextOut(473,292,m_str,strlen(m_str));
      wsprintf(m_str," : %2d ",WorkedMinute);
      memDC3.TextOut(445,292,m_str,strlen(m_str));
      wsprintf(m_str,"%2d",WorkedHour);
      memDC3.TextOut(417,292,m_str,strlen(m_str));

      memDC3.TextOut(415,308,"                           ");
	  wsprintf(m_str," : %2d",RemnantSecond);
      memDC3.TextOut(473,308,m_str,strlen(m_str));
 	  wsprintf(m_str," : %0d ",RemnantMinute);
      memDC3.TextOut(445,308,m_str,strlen(m_str));
      wsprintf(m_str,"%2d",RemnantHour);
      memDC3.TextOut(417,308,m_str,strlen(m_str));

     if (ChargeModel==0)
	 {
     memDC3.BitBlt(26,68,65,84,&memDC6,0,0,SRCAND);
	 }
     if (ChargeModel==1)
	 {
     memDC3.BitBlt(65,68,127,84,&memDC6,0,0,SRCAND);
     memDC3.BitBlt(85,68,127,84,&memDC6,0,0,SRCAND);
	 }
     if (ChargeModel==2)
	 {
     memDC3.BitBlt(127,68,166,84,&memDC6,0,0,SRCAND);
	 }
     if (m_CommuncationLink)
	 {memDC3.BitBlt(80,212,122,228,&memDC6,0,0,SRCAND);}
     else{memDC3.BitBlt(122,212,168,228,&memDC6,0,0,SRCAND);} 
     if (m_PrinterLink)
	 {memDC3.BitBlt(80,308,122,324,&memDC6,0,0,SRCAND);} 
     else{memDC3.BitBlt(126,308,168,324,&memDC6,0,0,SRCAND);} 
     if ( m_Radio == 2)
	 {memDC3.BitBlt(40,244,78,260,&memDC6,0,0,SRCAND);}
     if ( m_Radio == 1)
	 {memDC3.BitBlt(78,244,120,260,&memDC6,0,0,SRCAND);}
     if ( m_Radio == 0)
	 {memDC3.BitBlt(120,244,161,260,&memDC6,0,0,SRCAND);}
	 if (m_OutAutoXonoff == 1)
	 {memDC3.BitBlt(245,164,287,180,&memDC6,0,0,SRCAND);}
     else{memDC3.BitBlt(291,164,333,180,&memDC6,0,0,SRCAND);}
	 if (m_InAutoXonoff == 1)
	 {memDC3.BitBlt(245,308,287,324,&memDC6,0,0,SRCAND);}
     else{memDC3.BitBlt(291,308,333,324,&memDC6,0,0,SRCAND);}

    CRect AlarmMessageCircle1 (150,102,162,114);
    CRect AlarmMessageCircle2 (150,118,162,130);
    CRect AlarmMessageCircle3 (150,134,162,146);
    CRect AlarmMessageCircle4 (150,150,162,162);
    CRect AlarmMessageCircle5 (150,166,162,178);
    CRect AlarmMessageCircle6 (150,182,162,194);

    if (atoi( c_RecordingL1U ) >= m_1ndLimV){
    memDC3.SelectObject(&RedBrush);
	}
    else	
    memDC3.SelectObject(&GreenBrush);
    memDC3.Ellipse (&AlarmMessageCircle1);
    if (atoi( c_RecordingL1U ) >= m_2ndLimV)
	memDC3.SelectObject(&RedBrush);
    else	
    memDC3.SelectObject(&GreenBrush);
    memDC3.Ellipse (&AlarmMessageCircle2);
    if (atoi( c_RecordingL1A ) >= m_1ndLimA)
	memDC3.SelectObject(&RedBrush);
    else	
    memDC3.SelectObject(&GreenBrush);
    memDC3.Ellipse (&AlarmMessageCircle3);
    if (atoi( c_RecordingL1A ) >= m_2ndLimA)
	memDC3.SelectObject(&RedBrush);
    else	
    memDC3.SelectObject(&GreenBrush);
    memDC3.Ellipse (&AlarmMessageCircle4);
    if (atof( c_RecordingL1AH ) >= m_LAH)
	memDC3.SelectObject(&RedBrush);
    else	
    memDC3.SelectObject(&GreenBrush);
    memDC3.Ellipse (&AlarmMessageCircle5);
    if (atof( c_RecordingL1T1 ) >= m_LT1)
	memDC3.SelectObject(&RedBrush);
    else	
    memDC3.SelectObject(&GreenBrush);
    memDC3.Ellipse (&AlarmMessageCircle6);
 
     memDC3.SelectObject(&RedPen);
	 for (int q = 1; q < Vapartm +1; q++)
	 {
     memDC3.MoveTo(360,(VapartmV*q)*(165/(VapartmV*Vapartm))+42);
	 memDC3.LineTo(364,(VapartmV*q)*(165/(VapartmV*Vapartm))+42);
	 }
	 for (int w = 1; w < Timeapartm +1; w++)
	 {
	 memDC3.MoveTo(360 + (TimeapartmV*w)*(250/(TimeapartmV*Timeapartm)),230);
     memDC3.LineTo(360 + (TimeapartmV*w)*(250/(TimeapartmV*Timeapartm)),226);
	 }

     memDC3.PatBlt(30,336,640,352,WHITENESS);      
	 EndCommondString.MakeReverse();
	 memDC3.TextOut(30,336,CommondString + EndCommondString);
     EndCommondString.MakeReverse();
      if(k!=0){
     memDC3.SelectObject(&YellowBrush);
     CSize size;
	 size = memDC3.GetTextExtent(CommondString,strlen(CommondString));
	 memDC3.PatBlt(30+size.cx,336,2,16,PATINVERT);}
  
	 memDC3.PatBlt(((TimeapartmV*Timeapartm) * (m-1))/60 + 355,
	                 -(atof(c_RecordingL2A)*(140/(VapartmV*Vapartm))-229),4,4,WHITENESS);
	 memDC3.SelectObject(&ColorPen[ColGroLine1]);   
	 for (int h=2;h<=k2;h++)
	 { 
	 memDC3.MoveTo(((TimeapartmV*Timeapartm) * (h-1))/60 + 360,-(DrawV[(h-1)]*(140/(VapartmV*Vapartm))-230));
	 memDC3.LineTo(((TimeapartmV*Timeapartm) * h)/60 + 360,-(DrawV[h]*(140/(VapartmV*Vapartm))-230));
	 } 	  

     memDC3.SelectObject(&ColorBrush[ColMoveBar]);
	 memDC3.PatBlt(((TimeapartmV*Timeapartm) * m)/60 + 355,-(atof(c_RecordingL1A)*(140/(VapartmV*Vapartm))-229),
			   4,4,PATCOPY);
     
     memDC3.BitBlt(5+m_SelectMoveX*166,20 + ((m_SelectMoveY *16)-(m_SelectMoveX*16*19))+m_SelectMoveYadd,166,16,&memDC5,0,0,SRCAND);

     if(m_EnglishChinese == 0)
	 {memDC3.BitBlt(0,0,630,335,&memDC2,0,0,SRCAND);}
	 else {memDC3.BitBlt(0,0,630,335,&memDC0,0,0,SRCAND);}

	 if(m_HelpTextDisplay == TRUE)
	  {
	  memDC3.BitBlt(200,306,600,319,&memDCHelpBottom,0,0,SRCCOPY);
	  memDC3.BitBlt(200,200,505,298,&memDCHelpLeft,0,0,SRCCOPY);
	  memDC3.BitBlt(200,200,600,205,&memDCHelpTop,0,0,SRCCOPY);
	  memDC3.BitBlt(600,200,618,298,&memDCHelpRight,0,0,SRCCOPY);

	  CBrush* pOriginalBrush;
	  pOriginalBrush = memDC3.SelectObject(&HelpTextBoxBrush);
      memDC3.PatBlt(205,205,398,102,PATCOPY);
      memDC3.SelectObject(&pOriginalBrush);
	  	 
	  LoadHelpFile();
   	  CFont *oldFont;
	  oldFont = memDC3.SelectObject(&HelpTextFont);
	  memDC3.SetBkColor(RGB(245,245,200));
	  int y = 0;
	  if(currentLine3>(F6BookMark-F5BookMark-7)){currentLine3=F6BookMark-F5BookMark-7;}
	  for (int i = F5BookMark+currentLine3; (i-(F5BookMark+currentLine3))<6; i++)
	  {
		 CString *line = (CString *) l3->GetAt(i);
		 memDC3.TextOut(210, y+205, line->Mid(0), line->GetLength() - 2);
		 y += HelpTextHeight;
	  }
	  memDC3.SelectObject(oldFont);
	  memDC3.SetBkColor(RGB(255,255,255));
	  }

     if(m_Exit == TRUE)
	  {
	  memDC3.BitBlt(198,103,442,318,&memDC15,0,0,SRCCOPY);
	  }

	 dc.BitBlt(4,0,630,356,&memDC3,0,0,SRCCOPY);
	 
	 SettingBMPBitBlt = FALSE;
     }

     if (MenuID == "Setting 2") //For "Setting 2" menu.
	 {
     memDC3.TextOut(10,36,RecSaveFileName);
	 memDC3.TextOut(275,132,StartConWord);
     memDC3.TextOut(275,228,StopConWord);  
		   
	 CString s;
     s.Format("%7.3f",m_SaveTime);
     memDC3.TextOut(80,84,s);
     s.Format("    %5.2f            ",m_SaveCurr);
     memDC3.TextOut(80,116,s);
     s.Format("    %5.2f           ",m_SaveVolt);
     memDC3.TextOut(80,100,s);
     s.Format("    %5.2f           ",m_SaveAH);
     memDC3.TextOut(80,132,s);
     s.Format("%3.1f",m_SaveTemp);     
     memDC3.TextOut(100,148,s);
     s.Format("%7.3f",m_StartTime);
     memDC3.TextOut(235,84,s);
     s.Format("    %5.2f            ",m_StartVolt);
     memDC3.TextOut(235,100,s);
     s.Format("    %5.2f           ",m_StartCurr);
     memDC3.TextOut(235,116,s);
     s.Format("%7.3f",m_StopTime);
     memDC3.TextOut(235,180,s);
     s.Format("    %5.2f            ",m_StopVolt);
     memDC3.TextOut(235,196,s);
     s.Format("    %5.2f           ",m_StopCurr);
     memDC3.TextOut(235,212,s);
	 
     wsprintf(m_str,"%d",m_SaveRec);
     memDC3.TextOut(100,68,m_str,strlen(m_str));
     wsprintf(m_str,"%d",ColAHBar);
     memDC3.TextOut(130,212,m_str,strlen(m_str));
     wsprintf(m_str,"%d",ColVoltBar);
     memDC3.TextOut(130,228,m_str,strlen(m_str));
	 wsprintf(m_str,"%d",ColCurrBar);
     memDC3.TextOut(130,244,m_str,strlen(m_str));
     wsprintf(m_str,"%d",ColMoveLine);
     memDC3.TextOut(130,260,m_str,strlen(m_str));
	 wsprintf(m_str,"%d",ColGroLine1);
     memDC3.TextOut(130,276,m_str,strlen(m_str));
	 wsprintf(m_str,"%d",ColGroLine2);
     memDC3.TextOut(130,292,m_str,strlen(m_str));

	 if (m_EnglishChinese)
	 {memDC3.BitBlt(25,308,66,324,&memDC6,0,0,SRCAND);
	 memDC3.BitBlt(37,308,78,324,&memDC6,0,0,SRCAND);} 
      else{memDC3.BitBlt(92,308,133,324,&memDC6,0,0,SRCAND);
	 memDC3.BitBlt(119,308,160,324,&memDC6,0,0,SRCAND);} 

     if (m_RecSound)
	 {memDC3.BitBlt(221,260,263,276,&memDC6,0,0,SRCAND);} 
      else{memDC3.BitBlt(270,260,286,276,&memDC6,0,0,SRCAND);} 
     if (m_AlarmSound)
	 {memDC3.BitBlt(221,292,263,308,&memDC6,0,0,SRCAND);} 
      else{memDC3.BitBlt(270,292,286,308,&memDC6,0,0,SRCAND);} 
  
	  if (m_StartModle)
	  {memDC3.BitBlt(208,68,249,84,&memDC6,0,0,SRCAND);
	  memDC3.BitBlt(215,68,258,84,&memDC6,0,0,SRCAND);} 
      else{memDC3.BitBlt(261,68,302,84,&memDC6,0,0,SRCAND);
	  memDC3.BitBlt(294,68,335,84,&memDC6,0,0,SRCAND);} 
      if (m_StopModle)
	  {memDC3.BitBlt(208,164,249,180,&memDC6,0,0,SRCAND);
	  memDC3.BitBlt(215,164,258,180,&memDC6,0,0,SRCAND);} 
      else{memDC3.BitBlt(261,164,302,180,&memDC6,0,0,SRCAND);
	  memDC3.BitBlt(294,164,335,180,&memDC6,0,0,SRCAND);}
	 
	  if((m_Set2SelectMoveY == 0)||(m_Set2SelectMoveY == 1)){
	  memDC3.BitBlt(5+166,20 + (m_Set2SelectMoveY *16),166,16,&memDC5,0,0,SRCAND);}

	   memDC3.BitBlt(5+m_Set2SelectMoveX*166,20 + ((m_Set2SelectMoveY *16)-
				 (m_Set2SelectMoveX*16*19))+m_Set2SelectMoveYadd,166,16,&memDC5,0,0,SRCAND);
	 
	   memDC3.PatBlt(30,336,640,352,WHITENESS);      
	   EndCommondString.MakeReverse();
	   memDC3.TextOut(30,336,CommondString + EndCommondString);
       EndCommondString.MakeReverse();
        if(k!=0){
     memDC3.SelectObject(&YellowBrush);
     CSize size;
	 size = memDC3.GetTextExtent(CommondString,strlen(CommondString));
	 memDC3.PatBlt(30+size.cx,336,2,16,PATINVERT);}
	 
	 if(m_EnglishChinese == 0)
	 {memDC3.BitBlt(0,0,630,335,&memDC8,0,0,SRCAND);}
	 else {memDC3.BitBlt(0,0,630,335,&memDC9,0,0,SRCAND);}

	 if(m_HelpTextDisplay == TRUE)
	  {
	  memDC3.BitBlt(200,260,505,350,&memDCHelpLeft,0,0,SRCCOPY);
	  memDC3.BitBlt(200,260,600,265,&memDCHelpTop,0,0,SRCCOPY);
	  memDC3.BitBlt(598,260,616,350,&memDCHelpRight,0,0,SRCCOPY);
	  memDC3.BitBlt(200,350,608,363,&memDCHelpBottom,0,0,SRCCOPY);

	  CBrush* pOriginalBrush;
	  pOriginalBrush = memDC3.SelectObject(&HelpTextBoxBrush);
      memDC3.PatBlt(205,265,396,86,PATCOPY);
      memDC3.SelectObject(&pOriginalBrush);
	  	 
	  LoadHelpFile();
   	  CFont *oldFont;
	  oldFont = memDC3.SelectObject(&HelpTextFont);
	  memDC3.SetBkColor(RGB(245,245,200));
	  int y = 0;
	  if(currentLine3>(EndBookMark-F6BookMark-6)){currentLine3=EndBookMark-F6BookMark-6;}
	  for (int i = F6BookMark+currentLine3; (i-(F6BookMark+currentLine3))<5; i++)
	  {
		 CString *line = (CString *) l3->GetAt(i);
		 memDC3.TextOut(210, y+265, line->Mid(0), line->GetLength() - 2);
		 y += HelpTextHeight;
	  }
	  memDC3.SelectObject(oldFont);
	  memDC3.SetBkColor(RGB(255,255,255));
	  }
	  dc.BitBlt(4,0,maxX,maxY,&memDC3,0,0,SRCCOPY);
	  if(m_Exit == TRUE)
	  {
	  dc.BitBlt(58,103,402,318,&memDC15,0,0,SRCCOPY);
	  CPoint a(0,0);
      OnLButtonDown(NULL, a); 
	  }
	  m_EditTextOutSide.SetWindowText(s_EditString);
 }

    if (MenuID == "A-V-AH") //For "A-V-AH" menu.
    { 
    CBrush* pOriginalBrush;
	pOriginalBrush = memDC3.SelectObject(&GrayBrush);
    memDC3.PatBlt(0,0,640,356,PATCOPY);
    memDC3.SelectObject(&pOriginalBrush);

	 CFont *oldFont;
	 oldFont = memDC3.SelectObject(&BigFont);

     memDC3.SetBkColor(RGB(0,128,128));

     memDC3.TextOut(78,78,"  CAP           ");
     memDC3.TextOut(78,148,"  VOT          ");
     memDC3.TextOut(78,218,"  CUR          ");
     memDC3.TextOut(513,78," AH  ");
     memDC3.TextOut(513,148,"  V   ");
     memDC3.TextOut(513,218,"  A   ");
     
	 memDC3.SetBkColor(RGB(192,192,192));
     CString s;
     memDC3.TextOut(250,78,"                  ");
     s.Format("    %6.3f",atof(c_RecordingL1AH));
     memDC3.TextOut(250,78,s);
     memDC3.TextOut(250,148,"                  ");
     s.Format("     %5.2f",atof(c_RecordingL1U));
     memDC3.TextOut(250,148,s);
     memDC3.TextOut(250,218,"                  ");
     s.Format("   %5.2f",atof(c_RecordingL1A));
     memDC3.TextOut(250,218,s);

     
	 CBrush* pOriginalBrush2;
	 pOriginalBrush2 = memDC3.SelectObject(&GrayBrush);
     memDC3.PatBlt(612,78,17,250,PATCOPY);
	 memDC3.SelectObject(&pOriginalBrush2);
	 
	 if(m_EnglishChinese == 1)
		 {memDC3.BitBlt(78,78,249,277,&memDC12,0,0,SRCCOPY);
	      memDC3.BitBlt(513,78,611,277,&memDC13,0,0,SRCCOPY);}
     
	 if(m_HelpTextDisplay == TRUE)
	  {
	  memDC3.BitBlt(200,306,600,319,&memDCHelpBottom,0,0,SRCCOPY);
	  memDC3.BitBlt(200,200,505,298,&memDCHelpLeft,0,0,SRCCOPY);
	  memDC3.BitBlt(200,200,600,205,&memDCHelpTop,0,0,SRCCOPY);
	  memDC3.BitBlt(600,200,618,298,&memDCHelpRight,0,0,SRCCOPY);

	  CBrush* pOriginalBrush;
	  pOriginalBrush = memDC3.SelectObject(&HelpTextBoxBrush);
      memDC3.PatBlt(205,205,398,102,PATCOPY);
      memDC3.SelectObject(&pOriginalBrush);
	  	 
	  LoadHelpFile();
   	  CFont *oldFont;
	  oldFont = memDC3.SelectObject(&HelpTextFont);
	  memDC3.SetBkColor(RGB(245,245,200));
	  int y = 0;
	  if(currentLine3>(F4BookMark-F3BookMark-7)){currentLine3=F4BookMark-F3BookMark-7;}
	  for (int i = F3BookMark+currentLine3; (i-(F3BookMark+currentLine3))<6; i++)
	  {
		 CString *line = (CString *) l3->GetAt(i);
		 memDC3.TextOut(210, y+205, line->Mid(0), line->GetLength() - 2);
		 y += HelpTextHeight;
	  }
	  memDC3.SelectObject(oldFont);
	  memDC3.SetBkColor(RGB(255,255,255));
	  }

	 if(m_Exit == TRUE)
	  {
	  memDC3.BitBlt(198,103,442,318,&memDC15,0,0,SRCCOPY);
	  }

	 dc.BitBlt(0,0,maxX,maxY,&memDC3,0,0,SRCCOPY);

     memDC3.SelectObject(&pOriginalBrush2);
	 memDC3.SelectObject(oldFont);
	 memDC3.SetBkColor(RGB(255,255,255));
	}

     if (MenuID == "TimeData")	//For "TimeData" menu.
	 {
     CBrush* pOriginalBrush1;
	 pOriginalBrush1 = memDC3.SelectObject(&GrayBrush);
     memDC3.PatBlt(0,0,640,356,PATCOPY);
	 memDC3.SelectObject(&pOriginalBrush1);
			 
	 memDC3.PatBlt(200,24,249,96,WHITENESS);
	 memDC3.PatBlt(200,136,249,32,WHITENESS);

	 memDC3.SetBkColor(RGB(157,157,255));	 
	 memDC3.TextOut(200,24," TIME:                                                    ");
     memDC3.TextOut(200,136," SUM SYS TIME:        ");
     memDC3.TextOut(200,152," ST PART TIME:        ");	 

	 memDC3.SetBkColor(RGB(134,255,255));	 
     memDC3.TextOut(200,40,"     CUR. TIM:      ");
     memDC3.TextOut(200,56,"   WOR. TIM:      ");
     memDC3.TextOut(200,72,"     RET. TIM:      ");
     memDC3.TextOut(200,88,"   AUX. TIM1:      ");
     memDC3.TextOut(200,104,"   AUX. TIM2:      ");
	 
      memDC3.SetBkColor(RGB(255,255,255));	     
	  memDC3.TextOut(341,40,CTime::GetCurrentTime().Format("%I  :  %M  :  %S %P"));	 
	  wsprintf(m_str,"                 S",WorkedSecond);
      memDC3.TextOut(365,56,m_str,strlen(m_str));
	  wsprintf(m_str," M %2d",WorkedSecond);
      memDC3.TextOut(393,56,m_str,strlen(m_str));
      wsprintf(m_str," H %2d ",WorkedMinute);
      memDC3.TextOut(358,56,m_str,strlen(m_str));
      wsprintf(m_str,"%2d",WorkedHour);
      memDC3.TextOut(326,56,m_str,strlen(m_str));
      wsprintf(m_str,"                   S",RemnantSecond);
      memDC3.TextOut(357,72,m_str,strlen(m_str));
	  wsprintf(m_str," M %2d",RemnantSecond);
      memDC3.TextOut(393,72,m_str,strlen(m_str));
 	  wsprintf(m_str," H %2d ",RemnantMinute);
      memDC3.TextOut(358,72,m_str,strlen(m_str));
      wsprintf(m_str,"%2d",RemnantHour);
      memDC3.TextOut(326,72,m_str,strlen(m_str));

	  wsprintf(m_str," H %2d ",AuxTim1Minute);
      memDC3.TextOut(358,88,m_str,strlen(m_str));
      wsprintf(m_str,"%2d",AuxTim1Hour);
      memDC3.TextOut(326,88,m_str,strlen(m_str));
	  wsprintf(m_str," H %2d ",AuxTim2Minute);
      memDC3.TextOut(358,104,m_str,strlen(m_str));
      wsprintf(m_str,"%2d",AuxTim2Hour);
      memDC3.TextOut(326,104,m_str,strlen(m_str));
	  wsprintf(m_str,"H %2d   ",SumSysTimMinute);
      memDC3.TextOut(386,136,m_str,strlen(m_str));
      wsprintf(m_str,"   %2d   ",SumSysTimHour);
      memDC3.TextOut(326,136,m_str,strlen(m_str));
	  wsprintf(m_str,"H %2d   ",Stpart1TimMinute);
      memDC3.TextOut(386,152,m_str,strlen(m_str));
      wsprintf(m_str," %2d ",Stpart1TimHour);
      memDC3.TextOut(326,152,m_str,strlen(m_str));
	  
	  memDC3.TextOut(397,88,"M");
      memDC3.TextOut(397,104,"M");      
	  memDC3.TextOut(417,136,"M");
      memDC3.TextOut(417,152,"M");
      memDC3.PatBlt(300,40,10,80,WHITENESS);

	  if(m_EnglishChinese == 1)
		 {memDC3.BitBlt(200,24,311,168,&memDC10,0,0,SRCCOPY);}	  	  

      memDC3.SetBkColor(RGB(192,192,192));
	  EndCommondString.MakeReverse();
	  memDC3.TextOut(30,336,CommondString + EndCommondString);
      EndCommondString.MakeReverse();
	  memDC3.SetBkColor(RGB(255,255,255));
      if(k!=0){
      CBrush* pOriginalBrush;
	  pOriginalBrush = memDC3.SelectObject(&YellowBrush);
      CSize size;
	  size = memDC3.GetTextExtent(CommondString,strlen(CommondString));
	  memDC3.PatBlt(30+size.cx,336,2,16,PATINVERT);
	  memDC3.SelectObject(&pOriginalBrush);}
	  
	  memDC3.BitBlt(200,40 + (m_SelectTimeY *16),166,16,&memDC5,0,0,SRCAND);
	  memDC3.BitBlt(283,40 + (m_SelectTimeY *16),166,16,&memDC5,0,0,SRCAND);

      if(m_HelpTextDisplay == TRUE)
	  {
	  memDC3.BitBlt(200,306,600,319,&memDCHelpBottom,0,0,SRCCOPY);
	  memDC3.BitBlt(200,200,505,298,&memDCHelpLeft,0,0,SRCCOPY);
	  memDC3.BitBlt(200,200,600,205,&memDCHelpTop,0,0,SRCCOPY);
	  memDC3.BitBlt(600,200,618,298,&memDCHelpRight,0,0,SRCCOPY);

	  CBrush* pOriginalBrush;
	  pOriginalBrush = memDC3.SelectObject(&HelpTextBoxBrush);
      memDC3.PatBlt(205,205,398,102,PATCOPY);
      memDC3.SelectObject(&pOriginalBrush);
	  	 	  	 
	  LoadHelpFile();
   	  CFont *oldFont;
	  oldFont = memDC3.SelectObject(&HelpTextFont);
	  memDC3.SetBkColor(RGB(245,245,200));

	  int y = 0;
	  if(currentLine3>(F5BookMark-F4BookMark-7)){currentLine3=F5BookMark-F4BookMark-7;}
	  for (int i = F4BookMark+currentLine3; (i-(F4BookMark+currentLine3))<6; i++)
	  {
		 CString *line = (CString *) l3->GetAt(i);
		 memDC3.TextOut(210, y+205, line->Mid(0), line->GetLength() - 2);
		 y += HelpTextHeight;
	  }
	  memDC3.SelectObject(oldFont);
	  memDC3.SetBkColor(RGB(255,255,255));
	  }

     if(m_Exit == TRUE)
	  {
	  memDC3.BitBlt(202,103,446,318,&memDC15,0,0,SRCCOPY);
	  }
	  
	  dc.BitBlt(0,0,maxX,maxY,&memDC3,0,0,SRCCOPY);
	 }

      if(MenuID == "Help")	//For "Help" menu.
	  {
      if(m_Exit == TRUE)
	  {
	  memDC3.BitBlt(198,103,442,318,&memDC15,0,0,SRCCOPY);
	  }
//	  dc.BitBlt(0,0,640,356,&memDC3,0,0,SRCCOPY);
//	  memDC3.SelectObject(oldFont);
	 }
	  if(MenuID == "NULL")
	  {
	  if(m_Exit == TRUE)
	  {
	  dc.BitBlt(198,103,442,318,&memDC15,0,0,SRCCOPY);
	  }
	  else
	  {
//	  memDC15.PatBlt(0,0,246,117,WHITENESS);
      dc.PatBlt(198,103,442,318,WHITENESS);
	  }
	  }
	  if(b_ToolBar3 == TRUE){dc.BitBlt(9,360,645,34,&memDC16,0,0,SRCCOPY);}
	  else{dc.BitBlt(9,360,645,34,&memDC17,0,0,SRCCOPY);}

	// Do not call CView::OnPaint() for painting messages
}

void CAMonitorView::OnTimer(UINT nIDEvent) 
{
        if(nIDEvent ==1)
		{
		  if (MenuID == "Setting 1")
		{	 
//      memDC3.PatBlt(361,80,250,170,WHITENESS);
		memDC3.SelectObject(&ColorPen[ColGroLine1]);
 		for (int i=2;i<=k2;i++)
		{ 
	    memDC3.MoveTo(((TimeapartmV*Timeapartm) * (i-1))/60 + 360,
				  -(DrawV[(i-1)]*(140/(VapartmV*Vapartm))-230));
	    memDC3.LineTo(((TimeapartmV*Timeapartm) * i)/60 + 360,
				  -(DrawV[i]*(140/(VapartmV*Vapartm))-230));
		}
		if (k2 < c-2)
		{ 
		k2++;
	    memDC3.MoveTo(((TimeapartmV*Timeapartm) * (k2-1))/60 + 360,
				  -(DrawV[(k2-1)]*(140/(VapartmV*Vapartm))-230));
	    memDC3.LineTo(((TimeapartmV*Timeapartm) * k2)/60 + 360,
				  -(DrawV[k2]*(140/(VapartmV*Vapartm))-230));
	    CRect rect1(360,50,625,230);
	    InvalidateRect(rect1,FALSE);
		}
//      else KillTimer(1);
        CString s1;
        s1.Format("  %5.2f",((TimeapartmV*Timeapartm) * k2)/60 + 360);
        memDC3.TextOut(548,50,s1);
        s1.Format("  %5.2f",-(DrawV[(k2-1)]*(140/(VapartmV*Vapartm))-250));
        memDC3.TextOut(548,66,s1);
        memDC3.TextOut(528,50,"X =");
        memDC3.TextOut(528,66,"Y ="); 	  

/*		m_Fly = m_Fly +1;
		if (m_Fly == 21){m_Fly = 6;}
	    switch (m_Fly)
	    {
	    case 6:		
	    memDC3.BitBlt(542,283,50,50,&memDC16,0,0,SRCCOPY);		
		break;
        case 8:
	    memDC3.BitBlt(542,283,50,50,&memDC17,0,0,SRCCOPY);
        break;
        case 10:
	    memDC3.BitBlt(542,283,50,50,&memDC18,0,0,SRCCOPY);
        break;	
	    case 12:		
	    memDC3.BitBlt(542,283,50,50,&memDC19,0,0,SRCCOPY);		
		break;
        case 14:
	    memDC3.BitBlt(542,283,50,50,&memDC20,0,0,SRCCOPY);
        break;
        case 16:
	    memDC3.BitBlt(542,283,50,50,&memDC21,0,0,SRCCOPY);
        break;		
        case 18:
	    memDC3.BitBlt(542,283,50,50,&memDC22,0,0,SRCCOPY);
        break;
        case 20:
	    memDC3.BitBlt(542,283,50,50,&memDC23,0,0,SRCCOPY);
        break;		
	    }
	    CRect rect2(540,285,600,320);
	    InvalidateRect(rect2,FALSE);*/
		}

        if (MenuID == "Monitor")
		{
		memDC4.SelectObject(&ColorPen[ColMoveLine]);
        i_MoveChart = i_MoveChart +1;
        if(i_MoveChart==134){i_MoveChart = 0;}
        memDC4.PatBlt(16,22,220,105,WHITENESS);
		for (int j=2+i_MoveChart ;(j-i_MoveChart)<=164;j++)
		{ 
	    memDC4.MoveTo(((TimeapartmV*Timeapartm) * ((j-1)))/45 
				  + (15-i_MoveChart),-(DrawV[((j-1)+0)]*(140/(VapartmV*Vapartm))-160));
	    memDC4.LineTo(((TimeapartmV*Timeapartm) * (j))/45 + (15-i_MoveChart),
				  -(DrawV[(j+0)]*(140/(VapartmV*Vapartm))-160));
		}
	    CRect rect3(m_pointTopLeft.x+16,m_pointTopLeft.y+20,
				  m_pointTopLeft.x+212,m_pointTopLeft.y+130);
	    InvalidateRect(rect3,FALSE);
		}
}
        if(nIDEvent ==2)
		{
        b_Timer2 =! KillTimer(2);
		
        b_AlarmSound = FALSE;
		}

		if(nIDEvent ==3)
		{
		OnMonit();				   //Automatic Run For Show
		KillTimer(3);
		SetTimer(4,2000,NULL);
		}

		if(nIDEvent ==4)
		{
		if(!Execute)
		{
		OnExec();
		b_Timer4 = 0;
		}
		b_Timer4++;
		if(b_Timer4>22)
		{
		b_Timer4 = 0;
		}
		switch (b_Timer4)
		{
        case 3:
			OnData();
		break;
		case 6:
			OnAvah();
		break;
		case 9:
            OnTimed();
		break;
		case 12:
			OnSett1();
		break;
		case 15:
			OnSett2();
		break;
		case 18:
			OnHelp();
		break;
		case 21:
			OnMonit();
			b_Timer4 = 0;
		break;
		}
		}
	    CView::OnTimer(nIDEvent);
}

void CAMonitorView::OnExec() 
{
	    LoadFileData();
        PrepareChartData();  

	 	SetTimer(1, 25, NULL);
	    if (MenuID == "NULL")  	
		{OnMonit();}
	    Execute = TRUE;
		
		AfxGetApp()->m_pMainWnd->SetWindowText(" Working.....");
	    CAMonitorApp *app = (CAMonitorApp *)AfxGetApp();
	    app->m_Progrees = 1;
//      HWND hWnd = GetSafeHwnd();
//	    AfxBeginThread(CollectThreadProc,hWnd , THREAD_PRIORITY_NORMAL);	
        AfxBeginThread(CollectThreadProc,this, THREAD_PRIORITY_NORMAL);
		Invalidate(0);
}

UINT CollectThreadProc(LPVOID WinObjPtr)
{
	
	CAMonitorView* pView = (CAMonitorView*) WinObjPtr;

	static DWORD CurrentTime1 = 0;
    static DWORD PrevTime1 = 0;
	static DWORD CurrentTime2 = 0;
    static DWORD PrevTime2 = 0;

while(pView->Execute)
{
	 CurrentTime1 = GetTickCount();
	 
	 if (CurrentTime1 >= PrevTime1 + 1000*pView->m_Farq)
	 {
         PrevTime1 = CurrentTime1;
         pView->ComunicationMl();
	    if (pView->MenuID == "Monitor" )	 
		{
		 pView->InvalidateRect((CRect(10,14,171,128)),0);
		 pView->InvalidateRect((CRect(202,48,600,95)),0);
		 pView->InvalidateRect((CRect(150,238,162,330)),0);
		}
		 if (pView->MenuID == "Data" )	 
		{
          pView->Invalidate(0);		 
		 }
	 }
	 
	 CurrentTime2 = GetTickCount();
     if (CurrentTime2 >= PrevTime2 + 1000)
	 {
         PrevTime2 = CurrentTime2;
		 pView->WorkedSecond++;
             if (pView->WorkedSecond >= 60)
 			 {
				 pView->WorkedSecond = 0;
				 pView->WorkedMinute++;
				 if (pView->WorkedMinute >= 60)
				 {
					 pView->WorkedMinute = 0;
                     pView->WorkedHour++;
				 }
				 pView->SumSysTimMinute++;
				 if (pView->SumSysTimMinute >= 60)
				 {
					 pView->SumSysTimMinute = 0;
                     pView->SumSysTimHour++;
				 }
				 pView->AuxTim1Minute++;
				 if (pView->AuxTim1Minute >= 60)
				 {
					 pView->AuxTim1Minute = 0;
                     pView->AuxTim1Hour++;
				 }
				 pView->AuxTim2Minute--;
				 if (pView->AuxTim2Minute < 0)
				 {
					 pView->AuxTim2Minute = 59;
                     pView->AuxTim2Hour--;
				 }
				 pView->Stpart1TimMinute++;
				 if (pView->Stpart1TimMinute >= 60)
				 {
					 pView->Stpart1TimMinute = 0;
                     pView->Stpart1TimHour++;
				 }
			 }
          pView->RemnantSecond--;
			 if (pView->RemnantSecond < 0)
			 {
				 pView->RemnantSecond = 59;
                 pView->RemnantMinute--;
				 if (pView->RemnantMinute < 0)
				 {
					 pView->RemnantMinute = 59;	
					 pView->RemnantHour--;
				 }
			 }
			 if((pView->MenuID == "Monitor")||(pView->MenuID == "A-V-AH")||(pView->MenuID == "TimeData")||(pView->MenuID == "Setting 1"))
			 pView->Invalidate(FALSE);	 
		}    
	 }
	 
		  return 0; // ends the thread
}

void CAMonitorView::OnStop() 
{
//	AfxEndThread(NULL);
	Execute = FALSE;
	AfxGetApp()->m_pMainWnd->SetWindowText(" Stop");
	CAMonitorApp *app = (CAMonitorApp *)AfxGetApp();
	app->m_Progrees = 0;
	KillTimer(1);
	KillTimer(4);
	if( m_pDlg->m_Comm2.GetPortOpen() ){
	m_pDlg->m_Comm2.SetPortOpen(FALSE);}
	int CurrentTime=0;
	if(m_bmp8able == TRUE)
		{
    m_EditTextOutSide.EnableWindow(!Execute);
	}
    Invalidate(0);	
}

void CAMonitorView::OnRestart() 
{
	    if (PicturePrepar == 1)
		{
        PreparePicture();
		}
	    c_RecordingMLNo = 0;
 		c_RecordingL1N = "0000";
	    c_RecordingL1U = "00.00";
        c_RecordingL1A = "000.0";
	    c_RecordingL1AH = "0.000";
		c_RecordingL1T1 = "00.00";
	    c_RecordingL1T2 = "00.00";
        c_RecordingL1CW = "cccc";
		c_RecordingL2N = "0000";
	    c_RecordingL2U = "00.00";
        c_RecordingL2A = "000.0";
	    c_RecordingL2AH = "0.000";
	    c_RecordingL2T1 = "00.00";
	    c_RecordingL2T2 = "00.00";
        c_RecordingL2CW = "cccc";
		c_RecordingL3N = "0000";
	    c_RecordingL3U = "00.00";
        c_RecordingL3A = "000.0";
	    c_RecordingL3AH = "0.000";
	    c_RecordingL3T1 = "00.00";
	    c_RecordingL3T2 = "00.00";
        c_RecordingL3CW = "cccc";
	    c_RecordingL1Time = "000:00:00";
      	c_RecordingL2Time = "000:00:00";
      	c_RecordingL3Time = "000:00:00";

 	    PrevTime1=0;
        WorkedSecond = 0;
	    WorkedMinute = 0;
	    WorkedHour = 0;
        RemnantSecond = 59;
	    RemnantMinute = 59;
	    RemnantHour = 999;
	    k2 = 2;
        k3 = 2;
	    if (MenuID == "Setting 1")
		{
	    memDC3.PatBlt(((TimeapartmV*Timeapartm) * m)/60 + 355,-(atof(c_RecordingL1A)*(140/(VapartmV*Vapartm))-229),
			   4,4,WHITENESS);
        memDC3.PatBlt(361,80,250,150,WHITENESS);
        memDC3.SelectObject(&ColorPen[ColGroLine1]);
	    for (int q = 1; q < Vapartm +1; q++)
		{
        memDC3.MoveTo(360,(VapartmV*q)*(165/(VapartmV*Vapartm))+42);
	    memDC3.LineTo(364,(VapartmV*q)*(165/(VapartmV*Vapartm))+42);
		}
	    for (int w = 1; w < Timeapartm +1; w++)
		{
	    memDC3.MoveTo(360 + (TimeapartmV*w)*(250/(TimeapartmV*Timeapartm)),230);
        memDC3.LineTo(360 + (TimeapartmV*w)*(250/(TimeapartmV*Timeapartm)),226);
		}
	    m = 4;
		}
	    CAMonitorApp *app = (CAMonitorApp *)AfxGetApp();
	    app->m_ProgreesReStart = 1;
        Invalidate(0);	
}

void CAMonitorView::OnLButtonDown(UINT nFlags, CPoint point) 
{
      if (MenuID == "Monitor")
	  {
	  CRect m_rectEllipse(m_pointTopLeft.x,m_pointTopLeft.y,
		(m_pointTopLeft.x + 245),(m_pointTopLeft.y + 145)); // still logical
//	  CRgn  circle;

//	  CClientDC dc(this);
//	  OnPrepareDC(&dc);
//	
//	  dc.LPtoDP(rectEllipse); // Now it's in device coordinates
//	  circle.CreateEllipticRgnIndirect(rectEllipse);	
	  if (m_rectEllipse.PtInRect(point)) 
	  {
		Dstinvert = TRUE;
        // Capturing the mouse ensures subsequent LButtonUp message
		SetCapture();
		m_bCaptured = TRUE;
		CPoint pointTopLeft(m_pointTopLeft);
//		dc.LPtoDP(&pointTopLeft);
		m_sizeOffset = point - pointTopLeft; // device coordinates
        // New mouse cursor is active while mouse is captured
		::SetCursor(::LoadCursor(NULL, IDC_CROSS));
		InvalidateRect(m_rectEllipse,FALSE);
	  }
	  }
	  if (MenuID == "Setting 2")
	  {
	  CRect m_EditBox(341,36,628,259);
	  if (!m_EditBox.PtInRect(point)) 
	  {
	  m_EditTextOutSide.ShowWindow(0);
      m_EditTextOutSide.ShowWindow(1);
	  }
	  }
	    CView::OnLButtonDown(nFlags, point);
}

void CAMonitorView::OnMouseMove(UINT nFlags, CPoint point) 
{
	    if ((MenuID == "Monitor") && m_bCaptured) {
////		CClientDC dc(this);
////		OnPrepareDC(&dc);
////	    Dstinvert = FALSE;
////		CRect rectOld(m_pointTopLeft, m_sizeEllipse);
//      CRect rectOld(m_pointTopLeft.x,m_pointTopLeft.y,
//		(m_pointTopLeft.x + 270),(m_pointTopLeft.y + 150));
//		memDC3.LPtoDP(rectOld);
////		InvalidateRect(rectOld, FALSE);
		m_pointTopLeft = point - m_sizeOffset;
////		memDC3.DPtoLP(&m_pointTopLeft);
		CRect rectNew(m_pointTopLeft.x,m_pointTopLeft.y,
			(m_pointTopLeft.x + 270),(m_pointTopLeft.y + 150));
//		memDC3.LPtoDP(rectNew);
		InvalidateRect(rectNew, FALSE);
		}		
	    CView::OnMouseMove(nFlags, point);
}

void CAMonitorView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	    if ((MenuID == "Monitor") && m_bCaptured)
		{
		::ReleaseCapture();
		m_bCaptured = FALSE;
	    Dstinvert = FALSE;
		}			
	    CView::OnLButtonUp(nFlags, point);
}

void CAMonitorView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
        if ( MenuID=="Monitor" )
		{
	    switch (nChar)
		{
        case 'I':
		if (m_FreqAdj < 59)
		m_FreqAdj = m_FreqAdj + 1;
		m_Farq = pow(60.,m_Radio)/m_FreqAdj;
		OnChangeProgrees();
		memDC3.PatBlt(542,196,85,32,WHITENESS);
	    InvalidateRect(CRect(542,196,630,228),0);
		break;
	    case 'D':
		if (m_FreqAdj > 1)
		m_FreqAdj = m_FreqAdj - 1;
		m_Farq = pow(60.,m_Radio)/m_FreqAdj;
		OnChangeProgrees();
        memDC3.PatBlt(542,196,85,32,WHITENESS);
	    InvalidateRect(CRect(542,196,630,228),0);
        break;
		}
		}	

	    if (( MenuID=="Data" )&&(m_HelpTextDisplay == false))
		{
        CAMonitorDoc *pDoc = GetDocument();
        CPtrArray *l = pDoc->GetLines();
	    switch (nChar)
		{
	    case VK_UP:
	         currentLine = currentLine - 1;
	     if (currentLine < 0)
	         currentLine = 0;
	     break;

	     case VK_DOWN:
	         currentLine = currentLine +1;
		 if (currentLine > l->GetSize())
			 currentLine = l->GetSize()-1;
	     break;

	     case VK_END:
		     currentLine = l->GetSize()-1;
	     break;

	     case VK_HOME:
		     currentLine = 0;
	     break;

	     case VK_PRIOR:
			 currentLine = currentLine - 17;
		 if (currentLine < 0)
			 currentLine = 0;
	     break;

	     case VK_NEXT:
			 currentLine = currentLine + 17;
		 if (currentLine > l->GetSize())
			 currentLine = l->GetSize()-1;
	     break;
		}
			WhiteReDraw();
		}

         if ((MenuID=="Setting 1")&&(k == 0)&&(m_HelpTextDisplay == false)) 
		 {
	     switch (nChar)
		 {
	case VK_UP:
	memDC3.PatBlt(5+m_SelectMoveX*166,16 +((m_SelectMoveY *16)-(m_SelectMoveX*16*19))+m_SelectMoveYadd,170,22,WHITENESS);
	InvalidateRect(CRect(5+m_SelectMoveX*166,(20 + +((m_SelectMoveY *16)-(m_SelectMoveX*16*19)))-2+m_SelectMoveYadd,170 +5+m_SelectMoveX*166,16+(20+((m_SelectMoveY *16)-(m_SelectMoveX*16*19))+m_SelectMoveYadd)),0);
    m_SelectMoveY = m_SelectMoveY -1;
	if (m_SelectMoveY == -1){m_SelectMoveY = 0;}
	if ((m_SelectMoveY == 2)||(m_SelectMoveY == 4)||(m_SelectMoveY == 11)||
			  (m_SelectMoveY == 13)||(m_SelectMoveY == 17)||(m_SelectMoveY == 20)||
			  (m_SelectMoveY == 27)||(m_SelectMoveY == 29)||
			  (m_SelectMoveY == 36)){m_SelectMoveY = m_SelectMoveY - 1;}
	if (m_SelectMoveY == 19){m_SelectMoveY = m_SelectMoveY - 1;}
	if (m_SelectMoveY == 18){m_SelectMoveX = m_SelectMoveX -1;}	
	if (m_SelectMoveY == 37)
	{m_SelectMoveX = m_SelectMoveX -1;
	 m_SelectMoveYadd = 0;}
	break;
	case VK_DOWN:
	memDC3.PatBlt(5+m_SelectMoveX*166,16 +((m_SelectMoveY *16)-(m_SelectMoveX*16*19))+m_SelectMoveYadd,170,22,WHITENESS);
	InvalidateRect(CRect(5+m_SelectMoveX*166,(20 + +((m_SelectMoveY *16)-(m_SelectMoveX*16*19)))-2+m_SelectMoveYadd,170 +5+m_SelectMoveX*166,16+(20+((m_SelectMoveY *16)-(m_SelectMoveX*16*19))+m_SelectMoveYadd)),0);
	m_SelectMoveY = m_SelectMoveY + 1;
	if(m_SelectMoveY ==40){m_SelectMoveY = 39;} 
	if ((m_SelectMoveY == 2)||(m_SelectMoveY == 4)||(m_SelectMoveY == 11)||
			  (m_SelectMoveY == 13)||(m_SelectMoveY == 17)||(m_SelectMoveY == 19)||
			  (m_SelectMoveY == 27)||(m_SelectMoveY == 29)||
			  (m_SelectMoveY == 36)){m_SelectMoveY = m_SelectMoveY +1;}
	if (m_SelectMoveY == 20){m_SelectMoveY = m_SelectMoveY + 1;}
	if (m_SelectMoveY == 21){m_SelectMoveX = m_SelectMoveX +1;}
	if (m_SelectMoveY == 38)
	{m_SelectMoveX = m_SelectMoveX +1;
	 m_SelectMoveYadd = 272;}
	break;
	case VK_LEFT:
	memDC3.PatBlt(5+m_SelectMoveX*166,16 +((m_SelectMoveY *16)-(m_SelectMoveX*16*19))+m_SelectMoveYadd,170,22,WHITENESS);
	InvalidateRect(CRect(5+m_SelectMoveX*166,(20 + +((m_SelectMoveY *16)-(m_SelectMoveX*16*19)))-2+m_SelectMoveYadd,170 +5+m_SelectMoveX*166,16+(20+((m_SelectMoveY *16)-(m_SelectMoveX*16*19))+m_SelectMoveYadd)),0);
    if(m_SelectMoveX == 1){
    m_SelectMoveX = 0;
    m_SelectMoveY = m_SelectMoveY - 19;
	if ((m_SelectMoveY == 2)||(m_SelectMoveY == 4)||(m_SelectMoveY == 11)||
			  (m_SelectMoveY == 13)||(m_SelectMoveY == 17)){
			  m_SelectMoveY = m_SelectMoveY +1;}
	}
    if(m_SelectMoveX == 2){
    m_SelectMoveX = 1;
    m_SelectMoveY = 37;
    m_SelectMoveYadd = 0;
	}
    break;
	case VK_RIGHT:
	memDC3.PatBlt(5+m_SelectMoveX*166,16 +((m_SelectMoveY *16)-(m_SelectMoveX*16*19))+m_SelectMoveYadd,170,22,WHITENESS);
	InvalidateRect(CRect(5+m_SelectMoveX*166,(20 + +((m_SelectMoveY *16)-(m_SelectMoveX*16*19)))-2+m_SelectMoveYadd,170 +5+m_SelectMoveX*166,16+(20+((m_SelectMoveY *16)-(m_SelectMoveX*16*19))+m_SelectMoveYadd)),0);
    if(m_SelectMoveX == 1){
    m_SelectMoveX = 2;
	if (m_SelectMoveY == 37){m_SelectMoveY = 39;}
    else m_SelectMoveY = 38;
    m_SelectMoveYadd =272;
	}
    if(m_SelectMoveX == 0){
    m_SelectMoveX = 1;
    m_SelectMoveY = m_SelectMoveY + 19;
	if ((m_SelectMoveY == 19)||(m_SelectMoveY == 27)||(m_SelectMoveY == 29)||
			  (m_SelectMoveY == 36)){
			  m_SelectMoveY = m_SelectMoveY +1;}
    if (m_SelectMoveY == 20){
			  m_SelectMoveY = m_SelectMoveY +1;}
	}
    break;
	}
	InvalidateRect(CRect(5+m_SelectMoveX*166,(20 + ((m_SelectMoveY *16)-(m_SelectMoveX*16*19))-2)+m_SelectMoveYadd,
			  170 +(5+m_SelectMoveX*166),16+(20+((m_SelectMoveY *16)-(m_SelectMoveX*16*19))+m_SelectMoveYadd)),0);
	}
    if (((MenuID=="Setting 1")&&(k != 0))||((MenuID=="Setting 2")&&(k != 0)))
	{
	switch (nChar)
	{
	case VK_LEFT:
		if ((CommondString.GetLength()-1)>=0)
		{
		EndCommondString += CommondString.GetAt(CommondString.GetLength()-1);
        CommondString.SetAt((CommondString.GetLength()-1),' ');
        CommondString.TrimRight();
		}
		break;
	case VK_RIGHT:
		if ((EndCommondString.GetLength()-1)>=0)
		{
		CommondString += EndCommondString.GetAt(EndCommondString.GetLength()-1);
        EndCommondString.SetAt((EndCommondString.GetLength()-1),' ');
        EndCommondString.TrimRight();
		}
		break;
		}
	    InvalidateRect(CRect(30,336,640,352),0);
	    InvalidateRect(CRect(5+m_SelectMoveX*166,(20 + ((m_SelectMoveY *16)-(m_SelectMoveX*16*19))-2)+m_SelectMoveYadd,
			  170 +(5+m_SelectMoveX*166),16+(20+((m_SelectMoveY *16)-(m_SelectMoveX*16*19))+m_SelectMoveYadd)),0);
	}

    if ((MenuID=="Setting 2")&&(k == 0)&&(m_HelpTextDisplay == false)) 
	{
	switch (nChar)
	{

	case VK_UP:
	memDC3.PatBlt(5+m_Set2SelectMoveX*166,16 +((m_Set2SelectMoveY *16)-(m_Set2SelectMoveX*16*19))+m_Set2SelectMoveYadd,170,22,WHITENESS);
	InvalidateRect(CRect(5+m_Set2SelectMoveX*166,(20 + +((m_Set2SelectMoveY *16)-(m_Set2SelectMoveX*16*19)))-2+m_Set2SelectMoveYadd,170 +5+m_Set2SelectMoveX*166,16+(20+((m_Set2SelectMoveY *16)-(m_Set2SelectMoveX*16*19))+m_Set2SelectMoveYadd)),0);
    if((m_Set2SelectMoveY == 0)||(m_Set2SelectMoveY == 1))
	{
    memDC3.PatBlt(5,16 +(m_Set2SelectMoveY *16),332,22,WHITENESS);
	InvalidateRect(CRect(5,20 + (m_Set2SelectMoveY *16),170 + 5 + 170,16+(20+(m_Set2SelectMoveY *16))),0);
	}
	m_Set2SelectMoveY--;
	if (m_Set2SelectMoveY == -1){m_Set2SelectMoveY = 0;}
	if ((m_Set2SelectMoveY == 2)||(m_Set2SelectMoveY == 27)||(m_Set2SelectMoveY == 33)||
			  (m_Set2SelectMoveY == 35)){m_Set2SelectMoveY--;}
	if (m_Set2SelectMoveY == 11){m_Set2SelectMoveY = m_Set2SelectMoveY - 3;}
	if (m_Set2SelectMoveY == 21){m_Set2SelectMoveX--;
	m_Set2SelectMoveY = m_Set2SelectMoveY - 3;}	
	break;

	case VK_DOWN:
	memDC3.PatBlt(5+m_Set2SelectMoveX*166,16 +((m_Set2SelectMoveY *16)-(m_Set2SelectMoveX*16*19))+m_Set2SelectMoveYadd,170,22,WHITENESS);
	InvalidateRect(CRect(5+m_Set2SelectMoveX*166,(20 + +((m_Set2SelectMoveY *16)-(m_Set2SelectMoveX*16*19)))-2+m_Set2SelectMoveYadd,
			  170 +5+m_Set2SelectMoveX*166,16+(20+((m_Set2SelectMoveY *16)-(m_Set2SelectMoveX*16*19))+m_Set2SelectMoveYadd)),0);
	if((m_Set2SelectMoveY == 0)||(m_Set2SelectMoveY == 1))
	{
    memDC3.PatBlt(5,16 +(m_Set2SelectMoveY *16),332,22,WHITENESS);
	InvalidateRect(CRect(5,20 + (m_Set2SelectMoveY *16),170 + 5 + 170,16+(20+(m_Set2SelectMoveY *16))),0);
	}
	m_Set2SelectMoveY++;
	if(m_Set2SelectMoveY ==38){m_Set2SelectMoveY = 37;} 
	if ((m_Set2SelectMoveY == 2)||(m_Set2SelectMoveY == 27)||
			  (m_Set2SelectMoveY == 33)||(m_Set2SelectMoveY == 35)){m_Set2SelectMoveY++;}
	if (m_Set2SelectMoveY == 9){m_Set2SelectMoveY = m_Set2SelectMoveY + 3;}
	if (m_Set2SelectMoveY == 19){m_Set2SelectMoveX++;
	m_Set2SelectMoveY = m_Set2SelectMoveY + 3;}
	break;

	case VK_LEFT:
	memDC3.PatBlt(5+m_Set2SelectMoveX*166,16 +((m_Set2SelectMoveY *16)-(m_Set2SelectMoveX*16*19))+m_Set2SelectMoveYadd,170,22,WHITENESS);
	InvalidateRect(CRect(5+m_Set2SelectMoveX*166,(20 + +((m_Set2SelectMoveY *16)-(m_Set2SelectMoveX*16*19)))-2+m_Set2SelectMoveYadd,170 +5+m_Set2SelectMoveX*166,16+(20+((m_Set2SelectMoveY *16)-(m_Set2SelectMoveX*16*19))+m_Set2SelectMoveYadd)),0);
    if(m_Set2SelectMoveX == 1){
    m_Set2SelectMoveX = 0;
    m_Set2SelectMoveY = m_Set2SelectMoveY - 19;
	if (m_Set2SelectMoveY == 11){m_Set2SelectMoveY++;}
	if (m_Set2SelectMoveY == 10){m_Set2SelectMoveY = m_Set2SelectMoveY + 2;}
	if (m_Set2SelectMoveY == 9){m_Set2SelectMoveY = m_Set2SelectMoveY + 3;}
	}
    break;
	
	case VK_RIGHT:
	memDC3.PatBlt(5+m_Set2SelectMoveX*166,16 +((m_Set2SelectMoveY *16)-(m_Set2SelectMoveX*16*19))+m_Set2SelectMoveYadd,170,22,WHITENESS);
	InvalidateRect(CRect(5+m_Set2SelectMoveX*166,(20 + +((m_Set2SelectMoveY *16)-(m_Set2SelectMoveX*16*19)))-2+m_Set2SelectMoveYadd,170 +5+m_Set2SelectMoveX*166,16+(20+((m_Set2SelectMoveY *16)-(m_Set2SelectMoveX*16*19))+m_Set2SelectMoveYadd)),0);

    if(m_Set2SelectMoveX == 0){
    m_Set2SelectMoveX = 1;
    if(m_Set2SelectMoveY >= 3)
	{
	m_Set2SelectMoveY = m_Set2SelectMoveY + 19;
	if((m_Set2SelectMoveY == 27)||(m_Set2SelectMoveY ==33)||
			  (m_Set2SelectMoveY == 35)){m_Set2SelectMoveY++;}
	}
	if(m_Set2SelectMoveY < 3){m_Set2SelectMoveY = 22;}
	}
    break;
	}
	InvalidateRect(CRect(5+m_Set2SelectMoveX*166,(20 + ((m_Set2SelectMoveY *16)-(m_Set2SelectMoveX*16*19))-2)+m_Set2SelectMoveYadd,
			  170 +(5+m_Set2SelectMoveX*166),16+(20+((m_Set2SelectMoveY *16)-(m_Set2SelectMoveX*16*19))+m_Set2SelectMoveYadd)),0);
    if((m_Set2SelectMoveY ==0)||(m_Set2SelectMoveY ==1))
	 {
	InvalidateRect(CRect(5,20 + (m_Set2SelectMoveY *16),
			  170 + 170,16+(20+(m_Set2SelectMoveY *16))),0);
	 }
	}
	
	if ((MenuID=="TimeData")&&(m_HelpTextDisplay == false)) 
	{
	switch (nChar)
	{
	case VK_UP:
			m_SelectTimeY--;
                if(m_SelectTimeY==-2){m_SelectTimeY=7;}
				if(m_SelectTimeY==0){m_SelectTimeY=-1;}
			    if(m_SelectTimeY==6){
				m_SelectTimeY--;
				m_SelectTimeY--;}
			  InvalidateRect(CRect(200,24,450,168),0);
	break;
	case VK_DOWN:
			  m_SelectTimeY++;
			  if(m_SelectTimeY==8){m_SelectTimeY=-1;}
              if(m_SelectTimeY==0){m_SelectTimeY++;}
			  if(m_SelectTimeY==5){
			  m_SelectTimeY++;
			  m_SelectTimeY++;}
			  InvalidateRect(CRect(200,24,450,168),0);
	break;
	case VK_LEFT:
		if ((CommondString.GetLength()-1)>=0)
		{
		EndCommondString += CommondString.GetAt(CommondString.GetLength()-1);
        CommondString.SetAt((CommondString.GetLength()-1),' ');
        CommondString.TrimRight();
		InvalidateRect(CRect(30,336,640,352),0);
		}
		break;
	case VK_RIGHT:
		if ((EndCommondString.GetLength()-1)>=0)
		{
		CommondString += EndCommondString.GetAt(EndCommondString.GetLength()-1);
        EndCommondString.SetAt((EndCommondString.GetLength()-1),' ');
        EndCommondString.TrimRight();
		InvalidateRect(CRect(30,336,640,352),0);
		}
		break;
	}
	}
	if(m_Exit == TRUE)
	{
   	switch (nChar)
	{
	case 'Y':
	b_Exit = TRUE;
	m_Exit = FALSE;
	memDC3.PatBlt(198,103,442,318,WHITENESS); 
	InvalidateRect(CRect(198,103,450,318),0);
	Execute = FALSE;
    break;
    case 'N':
    m_Exit = FALSE;
	if(MenuID == "Setting 2")
	   {
	   memDC3.PatBlt(58,103,402,318,WHITENESS);
	   InvalidateRect(CRect(58,103,402,318),0);
	   }
	   else
	   {
	   memDC3.PatBlt(198,103,442,318,WHITENESS);
	   InvalidateRect(CRect(198,103,450,318),0);
	   }
    break;
	}
	}
	if(m_HelpTextDisplay == true)	
	{
	switch (nChar)
	{
	case VK_UP:
	         currentLine3 = currentLine3 - 1;
	     if (currentLine3 < 0)
	         currentLine3 = 0;
	break;

	case VK_DOWN:
		 if (currentLine3 < l3->GetSize()-1)
		 currentLine3 = currentLine3 +1;
	break;

//	case VK_END:
//		     currentLine3 = l3->GetSize()-15;
//	break;

//	case VK_HOME:
//		     currentLine3 = 0;
//	break;

	case VK_PRIOR:
			 currentLine3 = currentLine3 - 6;
		 if (currentLine3 < 0)
			 currentLine3 = 0;
	break;

	case VK_NEXT:
			 currentLine3 = currentLine3 + 6;
		 if (currentLine3 > l3->GetSize())
			 currentLine3 = l3->GetSize()-6;
	break;
	}
			WhiteReDraw();	
	}
	OnStatBarChangString();
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CAMonitorView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	  if ((MenuID == "Setting 1")||(MenuID == "Setting 2"))
	  {
	  CString s1 = "0000";
	  CString s2 = "0000";
	  if (nChar == '\b')
      {
	  if (CommondString.GetLength() == 0)
	  {  
	  goto NEXT2;
	  }
	  CommondString.SetAt((CommondString.GetLength()-1),' ');
	  CommondString.TrimRight();
	  k = k - 1;
      goto NEXT2;
	  }
      if ((k<9)&&((nChar == '0')||(nChar == '1')||(nChar == '2')||(nChar == '3')||(nChar == '4')||
		  (nChar == '5')||(nChar == '6')||(nChar == '7')||(nChar == '8')||(nChar == '9')||(nChar == '.')))
	  {
	  CommondString += nChar;
      k = k + 1;
	  }
NEXT2: if (nChar == '\r')
	  {
        if((m_Set2SelectMoveY == 1)&&(MenuID == "Setting 2")&&(Execute == FALSE))
		{
		BYTE buf;

        CFileDialog dlgFile(FALSE ,"dat",NULL,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		"*.dat|*.dat|*.txt|*.txt|*.nc|*.nc|*.ddy|*.ddy|*.*|*.*|",NULL);
	    int nModal = dlgFile.DoModal();

	    if (nModal == IDOK) 
		{
		m_EditTextOutSide.GetWindowText(s_EditString);

		CFile file(dlgFile.GetPathName(),CFile::modeCreate | CFile::modeWrite);
		CArchive ar(&file,CArchive::store);

		RecSaveFileName = dlgFile.GetPathName();

		AfxGetApp()->BeginWaitCursor();

	       for (int j = 0; j < s_EditString.GetLength(); j++)
		   {
					buf = s_EditString.GetAt(j);
                    ar << buf;
		   }
		}
        AfxGetApp()->EndWaitCursor();

		}
		else
		{
		EndCommondString.MakeReverse();
		CommondString = CommondString + EndCommondString;		   

		if(k>=1){s1.SetAt(3,CommondString.GetAt(k-1));} 
    	if(k>=2){s1.SetAt(2,CommondString.GetAt(k-2));}
		if(k>=3){s1.SetAt(1,CommondString.GetAt(k-3));}
		if(k>=4){s1.SetAt(0,CommondString.GetAt(k-4));}

		for ( int l=0;l<k;l++ )
		   {
		if (CommondString.GetAt(l)  == '.')
		 {
	    s1 = "0000";
		if (l>=1){s1.SetAt(3,CommondString.GetAt(l-1));} 
			if (l>=2){s1.SetAt(2,CommondString.GetAt(l-2));}
			if (l>=3){s1.SetAt(1,CommondString.GetAt(l-3));}
			if (l>=4){s1.SetAt(0,CommondString.GetAt(l-4));}

			if (k-l>=2){s2.SetAt(0,CommondString.GetAt(l+1));}
			if (k-l>=3){s2.SetAt(1,CommondString.GetAt(l+2));}

			if (k-l>=4){s2.SetAt(2,CommondString.GetAt(l+3));}
			if (k-l>=5){s2.SetAt(3,CommondString.GetAt(l+4));}
           l = k;
			 }
 		}
		}
	       InvalidateRect(CRect(542,284,630,332),0);
		   CommondString.Empty();
		   EndCommondString.Empty();
	     k=0;
    if (MenuID == "Setting 1")
	{
	switch (m_SelectMoveY)
	{
	case 0:
         m_SysMaxV = atoi(s1);	
		 break;
	case 1:
         m_SysMaxA = atoi(s1);	
		 break;
	case 3:
			  if(s1 == "0001"){ChargeModel = 0;}
			  if(s1 == "0002"){ChargeModel = 1;}
			  if(s1 == "0003"){ChargeModel = 2;}
		 break;
	case 5:
         m_1ndLimV = (atoi(s1 + s2))/10000.;
		 break;
	case 6:
         m_2ndLimV = (atoi(s1 + s2))/10000.;
		 break;
	case 7:
         m_1ndLimA = (atoi(s1 + s2))/10000.;
		 break;
	case 8:
         m_2ndLimA = (atoi(s1 + s2))/10000.;
		 break;
	case 9:
         m_LAH = (atoi(s1 + s2))/10000.;
		 break;
	case 10:
         m_LT1 = (atoi(s1 + s2))/10000.;
		 break;
	case 12:
		 if(s1 == "0001"){m_CommuncationLink = 1;}
		 if(s1 == "0000"){m_CommuncationLink = 0;}
	     break;
	case 14:
		 if(s1 == "0001"){m_Radio = 2;}
		 if(s1 == "0002"){m_Radio = 1;}
		 if(s1 == "0003"){m_Radio = 0;}
		 m_Farq = pow(60.,m_Radio)/m_FreqAdj;
		 OnChangeProgrees();
		 memDC3.PatBlt(80,277,66,16,WHITENESS);
		 InvalidateRect(CRect(80,277,146,293),0);
		 break;
	case 15:
		 if(((atoi(s1 + s2))/10000.<60)&&((atoi(s1 + s2))/10000.>0)){
		 m_FreqAdj = atoi(s1 + s2)/10000.;
		 m_Farq = pow(60.,m_Radio)/m_FreqAdj;
		 OnChangeProgrees();
		 memDC3.PatBlt(80,277,66,16,WHITENESS);
		 InvalidateRect(CRect(80,277,146,293),0);}
		 break;
	case 16:
         if(((atoi(s1 + s2))/10000.<=3600.)&&((atoi(s1 + s2))/10000.>=0.017)){
		 m_Farq = (atoi(s1 + s2))/10000.;
		 if (m_Farq >=0.017){
         m_Radio = 0;
         m_FreqAdj = 1/m_Farq;}
		 if (m_Farq  >=1.017){
         m_Radio = 1;
         m_FreqAdj = 60/m_Farq;}
		 if (m_Farq >=61.017){
         m_Radio = 2;
         m_FreqAdj = 3600/m_Farq;}
		 memDC3.PatBlt(35,245,135,16,WHITENESS);
		 InvalidateRect(CRect(35,245,168,261),0);
		 memDC3.PatBlt(71,260,46,16,WHITENESS);
		 InvalidateRect(CRect(71,260,118,276),0);
         OnChangeProgrees();
			  }
		 break;
	case 18:
		 if(s1 == "0001"){m_PrinterLink = 1;}
		 if(s1 == "0000"){m_PrinterLink = 0;}
		 break;
	case 21:
         m_OutRata = atoi(s1);	
		 break;
	case 22:
		 if (s1 == "0001"){m_OutParity = "EVEN";}
		 if (s1 == "0002"){m_OutParity = "ODD";}
		 break;
	case 23:
         m_OutStopBit = atoi(s1);	
		 break;
	case 24:
         m_OutWordsLength = atoi(s1);	
		 break;
	case 25:
		 if (s1 == "0001"){m_OutCode = "ASCII";}
		 if (s1 == "0002"){m_OutCode = "NULL";}
		 break;
	case 26:
		 if (s1 == "0001"){m_OutComPort = "COM1";}
		 if (s1 == "0002"){m_OutComPort = "COM2";}
		 break;
	case 28:
		 if (s1 == "0001"){m_OutAutoXonoff = 1;}
		 if (s1 == "0000"){m_OutAutoXonoff = 0;}
		 break;
	case 30:
         m_InRata = atoi(s1);	
		 break;
	case 31:
		 if (s1 == "0001"){m_InParity = "EVEN";}
		 if (s1 == "0002"){m_InParity = "ODD";}
		 break;
	case 32:
         m_InStopBit = atoi(s1);	
		 break;
	case 33:
         m_InWordsLength = atoi(s1);	
		 break;
	case 34:
		 if (s1 == "0001"){m_InCode = "ASCII";}
		 if (s1 == "0002"){m_InCode = "NULL";}
		 break;
	case 35:
		 if (s1 == "0001"){m_InComPort = "COM1";}
		 if (s1 == "0002"){m_InComPort = "COM2";}
		 break;
	case 37:
		 if (s1 == "0001"){m_InAutoXonoff = 1;}
		 if (s1 == "0000"){m_InAutoXonoff = 0;}
		 break;

	case 38:
	     WorkedHour = atoi( s1 );
		 s1 = "00";
		 s1.SetAt(0,s2.GetAt(0));
		 s1.SetAt(1,s2.GetAt(1));
		 WorkedMinute = atoi( s1 );
		 s1.SetAt(0,s2.GetAt(2));
		 s1.SetAt(1,s2.GetAt(3));
		 WorkedSecond = atoi( s1 );		
		 break;
	case 39:
	     RemnantHour = atoi( s1 );
		 s1 = "00";
		 s1.SetAt(0,s2.GetAt(0));
		 s1.SetAt(1,s2.GetAt(1));
		 RemnantMinute = atoi( s1 );
		 s1.SetAt(0,s2.GetAt(2));
		 s1.SetAt(1,s2.GetAt(3));
		 RemnantSecond = atoi( s1 );
		 break;
		 }
	     memDC3.PatBlt(5+m_SelectMoveX*166,16 +((m_SelectMoveY *16)-(m_SelectMoveX*16*19))+m_SelectMoveYadd,170,22,WHITENESS);
	     InvalidateRect(CRect(5+m_SelectMoveX*166,(20 + ((m_SelectMoveY *16)-(m_SelectMoveX*16*19))-2)+m_SelectMoveYadd,
			  170 +(5+m_SelectMoveX*166),16+(20+((m_SelectMoveY *16)-(m_SelectMoveX*16*19))+m_SelectMoveYadd)),0);
	     InvalidateRect(CRect(30,336,640,352),0);
		 }
         if (MenuID == "Setting 2")
		 {
	     switch (m_Set2SelectMoveY)
		 {
	case 4:
         m_SaveTime = (atoi(s1 + s2))/10000.;	
		 break;
	case 3:
         m_SaveRec = atoi(s1);	
		 break;
	case 6:
         m_SaveCurr = (atoi(s1 + s2))/10000.;
		 break;
	case 5:
         m_SaveVolt = (atoi(s1 + s2))/10000.;
		 break;
	case 7:
         m_SaveAH = (atoi(s1 + s2))/10000.;
		 break;
	case 8:
         m_SaveTemp = (atoi(s1 + s2))/10000.;
		 break;
	case 12:
         ColAHBar = atoi(s1);
		 break;
	case 13:
         ColVoltBar = atoi(s1); 
		 break;
	case 14:
         ColCurrBar = atoi(s1);
		 ColMoveBar = atoi(s1);
		 break;
	case 15:
         ColMoveLine = atoi(s1); 
	     break;
	case 16:
         ColGroLine1 = atoi(s1); 
		 break;
	case 17:
         ColGroLine2 = atoi(s1); 
		 break;
	case 18:
              if (s1 == "0001"){m_EnglishChinese = 0;}
			  if (s1 == "0000"){m_EnglishChinese = 1;}

      if(MenuID != "NULL")
	  {
	   memDC3.PatBlt(0,0,640,356,WHITENESS);
	  }
	   Invalidate(0);
		 break;
	case 22:
			  if (s1 == "0001"){m_StartModle = 1;}
			  if (s1 == "0000"){m_StartModle = 0;} 	
		 break;
	case 23:
         m_StartTime = (atoi(s1 + s2))/10000.;
		 break;
	case 24:
         m_StartVolt = (atoi(s1 + s2))/10000.;	
		 break;
	case 25:
         m_StartCurr = (atoi(s1 + s2))/10000.;
		 break;
	case 26:
         StartConWord = s1; 	
		 break;
	case 28:
			  if (s1 == "0001"){m_StopModle = 1;}
			  if (s1 == "0000"){m_StopModle = 0;}
		 break;
	case 29:
         m_StopTime = (atoi(s1 + s2))/10000.;
		 break;
	case 30:
         m_StopVolt = (atoi(s1 + s2))/10000.;
		 break;
	case 31:
         m_StopCurr = (atoi(s1 + s2))/10000.;
		 break;
	case 32:
         StopConWord = s1; 
		 break;
	case 34:
			  if (s1 == "0001"){m_RecSound = 1;}
			  if (s1 == "0000"){m_RecSound = 0;} 	
		 break;
	case 36:
			  if (s1 == "0001"){m_AlarmSound = 1;}
			  if (s1 == "0000"){m_AlarmSound = 0;}
		 break;
    case 37:
	     if(Execute == FALSE)
		 {
		 CCommunicationDlg dlg;
	     dlg.m_OutputString = s_EditString;
 	     int result=dlg.DoModal();
		 }
		 break;
		 }
	     memDC3.PatBlt(5+m_Set2SelectMoveX*166,16 +((m_Set2SelectMoveY *16)-(m_Set2SelectMoveX*16*19))+m_Set2SelectMoveYadd,170,22,WHITENESS);
	     InvalidateRect(CRect(5+m_Set2SelectMoveX*166,(20 + ((m_Set2SelectMoveY *16)-(m_Set2SelectMoveX*16*19))-2)+m_Set2SelectMoveYadd,
			  170 +(5+m_Set2SelectMoveX*166),16+(20+((m_Set2SelectMoveY *16)-(m_Set2SelectMoveX*16*19))+m_Set2SelectMoveYadd)),0);
		 }
		 }
         InvalidateRect(CRect(30,336,640,352),0);
		 }
    	  
	  if (MenuID == "TimeData")
	  {
	  CString s1 = "0000";
	  CString s2 = "0000";
	  if (nChar == '\b')
      {
	  if (CommondString.GetLength() == 0)
	  {  
	  goto NEXT3;
	  }
	  CommondString.SetAt((CommondString.GetLength()-1),' ');
	  CommondString.TrimRight();
	  k = k - 1;
      goto NEXT3;
	  }
      if ((k<9)&&((nChar == '0')||(nChar == '1')||(nChar == '2')||(nChar == '3')||(nChar == '4')||
		  (nChar == '5')||(nChar == '6')||(nChar == '7')||(nChar == '8')||(nChar == '9')||(nChar == '.')))
	  {
	  CommondString += nChar;
	        k = k + 1;
	  }
NEXT3: if (nChar == '\r')
	  {
        EndCommondString.MakeReverse();
		CommondString = CommondString + EndCommondString;		   

		if(k>=1){s1.SetAt(3,CommondString.GetAt(k-1));} 
    	if(k>=2){s1.SetAt(2,CommondString.GetAt(k-2));}
		if(k>=3){s1.SetAt(1,CommondString.GetAt(k-3));}
		if(k>=4){s1.SetAt(0,CommondString.GetAt(k-4));}

		for ( int l=0;l<k;l++ )
		   {
				 if (CommondString.GetAt(l)  == '.')
			 {
	        s1 = "0000";
			if (l>=1){s1.SetAt(3,CommondString.GetAt(l-1));} 
			if (l>=2){s1.SetAt(2,CommondString.GetAt(l-2));}
			if (l>=3){s1.SetAt(1,CommondString.GetAt(l-3));}
			if (l>=4){s1.SetAt(0,CommondString.GetAt(l-4));}

			if (k-l>=2){s2.SetAt(0,CommondString.GetAt(l+1));}
			if (k-l>=3){s2.SetAt(1,CommondString.GetAt(l+2));}

			if (k-l>=4){s2.SetAt(2,CommondString.GetAt(l+3));}
			if (k-l>=5){s2.SetAt(3,CommondString.GetAt(l+4));}
           l = k;
			 }
 		}
		   CommondString.Empty();
		   EndCommondString.Empty();
	     k=0;

	switch (m_SelectTimeY)
	{
	case 1:
	     WorkedHour = atoi( s1 );
		 s1 = "00";
		 s1.SetAt(0,s2.GetAt(0));
		 s1.SetAt(1,s2.GetAt(1));
		 WorkedMinute = atoi( s1 );
		 s1.SetAt(0,s2.GetAt(2));
		 s1.SetAt(1,s2.GetAt(3));
		 WorkedSecond = atoi( s1 );		
		 break;
	case 2:
	     RemnantHour = atoi( s1 );
		 s1 = "00";
		 s1.SetAt(0,s2.GetAt(0));
		 s1.SetAt(1,s2.GetAt(1));
		 RemnantMinute = atoi( s1 );
		 s1.SetAt(0,s2.GetAt(2));
		 s1.SetAt(1,s2.GetAt(3));
		 RemnantSecond = atoi( s1 );
		 break;
	case 3:
	     AuxTim1Hour = atoi( s1 );
		 s1 = "00";
		 s1.SetAt(0,s2.GetAt(0));
		 s1.SetAt(1,s2.GetAt(1));
		 AuxTim1Minute = atoi( s1 ); 	
		 break;
	case 4:
         AuxTim2Hour = atoi( s1 );
		 s1 = "00";
		 s1.SetAt(0,s2.GetAt(0));
		 s1.SetAt(1,s2.GetAt(1));
		 AuxTim2Minute = atoi( s1 ); 
		 break;
    case 7:
         Stpart1TimHour = atoi( s1 );
		 s1 = "00";
		 s1.SetAt(0,s2.GetAt(0));
		 s1.SetAt(1,s2.GetAt(1));
		 Stpart1TimMinute = atoi( s1 ); 
		 break;
	}
	   }
	   InvalidateRect(CRect(30,336,640,352),0);
	   InvalidateRect(CRect(200,40,450,168),0);
	   }
	   CView::OnChar(nChar, nRepCnt, nFlags);
}

void CAMonitorView::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
//	CView::OnLButtonDblClk(nFlags, point);

//	CToolBar*pTool=(CToolBar*)AfxGetApp()->m_pMainWnd->GetDescendantWindow(AFX_IDW_TOOLBAR);;
//  pTool->SetButtonInfo(9,IDR_TOOLBAR1,NULL,9);
//	AfxGetMainWnd() ->ShowWindow(SW_MAXIMIZE);
//	ShellExecute(NULL,NULL,"LS21.txt",NULL,"c:\\WTCAM",
//			 SW_MAXIMIZE);
//       int i;
//	   i = AfxMessageBox("Error  Password ! Try Again?",MB_YESNO);
/*STARTUPINFO si;
        PROCESS_INFORMATION pi;
	    memset(&si,0,sizeof(si));
        si.cb = sizeof(si);

	    CreateProcess("C:\\NOTEPAD.exe",NULL,NULL,NULL,
			           TRUE,0,NULL,NULL,&si,&pi);  */  
}

void CAMonitorView::AlarmSound()
{
       if((m_AlarmSound == 1)&&(b_AlarmSound == FALSE)) 
	   {
		b_Timer2 = SetTimer(2,8000,NULL);
		PlaySound("Reminder.wav",NULL, SND_FILENAME | SND_ASYNC);
	    b_AlarmSound = TRUE;
	   }
}

void CAMonitorView::RecSound()
{
       if((m_RecSound == 1)&&(!b_Timer2)) 
//	   {PlaySound("c:\\CddyV3.0\\Ding.wav",NULL, SND_FILENAME | SND_ASYNC);}
	   {sndPlaySound("Ding.wav",SND_FILENAME | SND_ASYNC);}
}

void CAMonitorView::OnStatBarChangString()
{
        CStatusBar* pStatus=(CStatusBar*)
		AfxGetApp()->m_pMainWnd->GetDescendantWindow(AFX_IDW_STATUS_BAR);
	    if (pStatus) pStatus->SetPaneText(0, s_StatString[m_SelectMoveY]);
}

LRESULT CAMonitorView::OnGoodbye(WPARAM wParam, LPARAM lParam)
{
//	TRACE("CAMonitorView::OnGoodbye %x, %lx\n", wParam, lParam);
	s_EditString = m_pDlg->m_InputString;
	if(MenuID == "Setting 2")
	{
	m_EditTextOutSide.SetWindowText(s_EditString);
	}
	return 0L;
}

void CAMonitorView::OnChangeProgrees()
{
        CAMonitorApp *app = (CAMonitorApp *)AfxGetApp();
		if(m_Farq < 1.0){app->m_ProgreesRange =1;}
		else{app->m_ProgreesRange = m_Farq; }
}

void CAMonitorView::OnUpdateExec(CCmdUI* pCmdUI) 
{
        pCmdUI->Enable(!Execute);	
}

void CAMonitorView::OnUpdateStop(CCmdUI* pCmdUI) 
{
	    pCmdUI->Enable(Execute);
}

void CAMonitorView::OnOpenaedit() 
{
      STARTUPINFO si;
        PROCESS_INFORMATION pi;
	    memset(&si,0,sizeof(si));
        si.cb = sizeof(si);

	    CreateProcess("ADataEdit.exe",NULL,NULL,NULL,
			           FALSE,0,NULL,NULL,&si,&pi);
        
//	    WinExec("e:\\c++\\aedit\\debug\\aedit.exe",NULL);

//	    ShellExecute(NULL,NULL,_T("1.txt"),NULL,_T("c:\\temp"),SW_SHOWMAXMIZED); 	
}

void CAMonitorView::OnToolbar3() 
{
        b_ToolBar3 = TRUE;
		Invalidate(0);
}

void CAMonitorView::OnToolbar4() 
{
        b_ToolBar3 = FALSE;	
		Invalidate(0);
}

void CAMonitorView::OnInitialUpdate() 
{
////	SetTimer(3,2000,NULL);          //FOR AUTO SHOW
//	MessageBox("System Loading.......Pls. wait.");
		OnMonit();                      //Delete the line if autoshow
	CView::OnInitialUpdate(); 		
}
