// AMonitorView.h : interface of the CAMonitorView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_AMONITORVIEW_H__7A056913_EB8C_11D3_9E6C_0000B48DF20F__INCLUDED_)
#define AFX_AMONITORVIEW_H__7A056913_EB8C_11D3_9E6C_0000B48DF20F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

UINT CollectThreadProc(LPVOID WinObjPtr);

class CCommunicationWorking;
class CAMonitorView : public CView
{
private:
	CCommunicationWorking* m_pDlg;
private:

    CPtrArray *l2;
    CPtrArray *l3;
protected: // create from serialization only
	CAMonitorView();
	DECLARE_DYNCREATE(CAMonitorView)

	CRectTracker m_tracker;
//    CRect m_rectTracker; // logical coordinates
//    CSize m_sizeTotal;

	const CSize m_sizeEllipse; // logical
	CPoint m_pointTopLeft; // logical, top left of ellipse rectangle

	CSize  m_sizeOffset; // device, from rect top left to capture point
	BOOL   m_bCaptured;
    BOOL   m_vpoXable,m_vpoYable;



//	CRect m_rectEllipse;
	bool m_bmp2able,m_bmp8able,fCapture, fBoxing,DataFontCreate;

// 	HINSTANCE m_hInstance;
    CDC memDC0,memDC1,memDC2,memDC3,memDC4,memDC5,memDC6,memDC7,memDC8,memDC9,memDC10,memDC11,
	    memDC12,memDC13,memDC14,memDC15,memDC16,memDC17,memDCHelpTop,memDCHelpBottom,
		memDCHelpLeft,memDCHelpRight;
    int m_vpoX,m_vpoY,m_vpeX,m_vpeY,y;

	int m_SysMaxV,m_SysMaxA,m_Set2SelectMoveX,m_Set2SelectMoveY,m_Set2SelectMoveYadd,
			  m_SelectMoveX,m_SelectMoveY,m_SelectMoveYadd,m_SelectTimeY,
			  m_OutRata,m_OutStopBit,m_OutWordsLength,m_InRata,m_InStopBit,m_InWordsLength;
    int m_SaveRec,ColAHBar,ColVoltBar,ColCurrBar,ColMoveLine,ColGroLine1,ColGroLine2,ColMoveBar;

	float m_1ndLimV,m_2ndLimV,m_1ndLimA,m_2ndLimA,m_LT1,m_LAH,m_Farq,m_FreqAdj;
	float m_SaveTime,m_SaveCurr,m_SaveVolt,m_SaveAH,m_SaveTemp,
		  m_StartTime,m_StartCurr,m_StartVolt,m_StopTime,m_StopCurr,m_StopVolt;

	char m_str[100];
    int k;
 	CString CommondString,HeadCommondString,EndCommondString;    
    CString RecSaveFileName,StartConWord,StopConWord;
	int c_RecordingMLNo;

	CString c_RecordingL1N,c_RecordingL1Time,c_RecordingL1U,c_RecordingL1A;
	CString c_RecordingL1AH,c_RecordingL1T1,c_RecordingL1T2;
	CString c_RecordingL1CW;
	CString c_RecordingL2N,c_RecordingL2Time,c_RecordingL2U,c_RecordingL2A;
	CString c_RecordingL2AH,c_RecordingL2T1,c_RecordingL2T2;
	CString c_RecordingL2CW;
	CString c_RecordingL3N,c_RecordingL3Time,c_RecordingL3U,c_RecordingL3A;
	CString c_RecordingL3AH,c_RecordingL3T1,c_RecordingL3T2;
	CString c_RecordingL3CW;

    CString s_RecordingLine1,s_OutsideDataInput,s_OutsideDataInputML;
	CString MenuID,m_OutParity,m_OutCode,m_OutComPort,m_InParity,m_InCode,m_InComPort;
    CString m_SelectedMenuToolBar,s_AlarmSound,s_RecSound;
    int PrevTime1;

	int	WorkedSecond,WorkedMinute,WorkedHour;
    int RemnantSecond,RemnantMinute,RemnantHour;
	int	AuxTim1Minute,AuxTim1Hour,AuxTim2Minute,AuxTim2Hour;
    int SumSysTimMinute,SumSysTimHour;
	int Stpart1TimMinute,Stpart1TimHour;

    int maxX,maxY;    
    int ChargeModel;
    int m_Radio;
    int m_CommuncationLink,m_PrinterLink;
//	CPoint ptAnchor, ptOld;		

    int IT1SetCur,IT2SetCur,SpinSetPot,m_CollectHreq ;
    int TimeSetPAT;
	CString m_Edit1,m_Edit2;	

    int CursorY;
	CPtrArray *lines;
    CString SubEditString;
	CString *InsertString;
	int maxLineLength;
	int currentLine,currentLine3,F1BookMark,F2BookMark,F3BookMark,
		F4BookMark,F5BookMark,F6BookMark,EndBookMark;
	int margin;
    int EditLineNo;
    int VKDOWNi;
//	CFont *ourFont;
	CFont BigFont,DataFont,HelpTextFont;
	int lHeight,HelpTextHeight;
	int cWidth,HelpTextWidth;
	int saveLHeight, saveCWidth;
	int saveCurrentLine;
//	CRect printerRect;
    CString EditString,EndEditString;
	CButton m_smallButton;
    BOOL PicturePrepar;
	BOOL SettingBMPBitBlt,b_LoadFileData,b_LoadHelpFile;
    BOOL ChangLine;
    BOOL Dstinvert;
    BOOL m_TextEditCopyEnable;
	BOOL m_TextEditPasteEnable;
	BOOL b_ToolBar3;
	BOOL Execute,Button32778,Button32779,Button32780;
	int	m_XScale;
	int	m_YScale;
	BOOL	m_SelectV,m_OutAutoXonoff,m_InAutoXonoff;
	BOOL	m_SelectA;
	BOOL	m_SelectAH;
	BOOL	m_SelectT1;
	BOOL	m_SelectT2;
    BOOL    m_StartModle,m_StopModle,m_RecSound,m_AlarmSound;
	BOOL    m_EnglishChinese,m_Exit,m_HelpTextDisplay;
	BOOL    m_NonoNet;
	CString	m_TitleText;
	CString	m_XText;
	CString	m_YText;
	int		m_RadioLineType;
	
	double DrawV[10000];
    double TimeapartmV,VapartmV;
    int Timeapartm,Vapartm,n,m,c,k2,k3;
	int     m_Fly,i_MoveChart;
	
	CPoint  CaretPosition;
	bool    CaretCreated;
	int     CaretX,CaretY;
	CBitmap m_bmp6;
	CBitmap m_bmp2,m_bmp7,m_bmp8,m_bmp9,m_bmp10,m_bmp11,m_bmp12,
		m_bmp13,m_bmp15;
    BOOL TimeAddSub;

    CBrush RedBrush,GreenBrush,BlueBrush,YellowBrush,GrayBrush,HelpTextBoxBrush,ColorBrush[7];
    CPen RedPen,GreenPen,BluePen,ColorPen[7];
    
	CEdit m_EditTextOutSide;
	CString s_EditString;
    int AppComunication;
	CString s_StatString[200];
	BOOL b_Exit,b_PrepareExitBMP,b_Timer2,b_AlarmSound;
	int b_Timer4;
// Attributes
public:

	CAMonitorDoc* GetDocument();

// Operations
public:
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAMonitorView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:

	void OnStatBarChangString();
	void ComunicationMl();
	void OutsideDataInput();
	virtual ~CAMonitorView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	void OnChangeProgrees();
	void LoadHelpFile();
	void RecSound();
	void AlarmSound();
	void PreparePicture();
	void PrepareChartData();
	void LoadFileData();
	void WhiteReDraw();
    CPtrArray *GetLines()	{ return lines; }
	//{{AFX_MSG(CAMonitorView)
	afx_msg void OnMonit();
	afx_msg void OnUpdateMonit(CCmdUI* pCmdUI);
	afx_msg void OnData();
	afx_msg void OnUpdateData(CCmdUI* pCmdUI);
	afx_msg void OnAvah();
	afx_msg void OnUpdateAvah(CCmdUI* pCmdUI);
	afx_msg void OnTimed();
	afx_msg void OnUpdateTimed(CCmdUI* pCmdUI);
	afx_msg void OnSett1();
	afx_msg void OnUpdateSett1(CCmdUI* pCmdUI);
	afx_msg void OnSett2();
	afx_msg void OnUpdateSett2(CCmdUI* pCmdUI);
	afx_msg void OnButton32786();
	afx_msg void OnUpdateButton32786(CCmdUI* pCmdUI);
	afx_msg void OnDestroy();
	afx_msg void OnPaint();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnExec();
	afx_msg void OnStop();
	afx_msg void OnRestart();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnHelp();
	afx_msg void OnHelpfile();
	afx_msg void OnUpdateHelpfile(CCmdUI* pCmdUI);
	afx_msg void OnUpdateExec(CCmdUI* pCmdUI);
	afx_msg void OnUpdateStop(CCmdUI* pCmdUI);
	afx_msg void OnOpenaedit();
	afx_msg void OnToolbar3();
	afx_msg void OnToolbar4();
	//}}AFX_MSG
	afx_msg LRESULT OnGoodbye(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in AMonitorView.cpp
inline CAMonitorDoc* CAMonitorView::GetDocument()
   { return (CAMonitorDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AMONITORVIEW_H__7A056913_EB8C_11D3_9E6C_0000B48DF20F__INCLUDED_)
