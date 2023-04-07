// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "AMonitor.h"

#include "MainFrm.h"
#include "Splash.h"
#include "AMonitorDoc.h"
#include "AMonitorView.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_UPDATE_COMMAND_UI(ID_INDICATOR_DATE, OnUpdateDate)
	ON_UPDATE_COMMAND_UI(ID_INDICATOR_TIME, OnUpdateTime)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_WM_TIMER()
	ON_COMMAND(ID_FULLSCR, OnFullscr)
	ON_COMMAND(ID_BUTTON32811, OnButton32811)
	ON_UPDATE_COMMAND_UI(ID_FULLSCR, OnUpdateFullscr)
	ON_WM_QUERYENDSESSION()
	ON_COMMAND(ID_ENGLISCHINESE, OnEnglischinese)
	//}}AFX_MSG_MAP
	// Global help commands

	ON_COMMAND(ID_HELP_FINDER, CFrameWnd::OnHelpFinder)
	ON_COMMAND(ID_HELP, CFrameWnd::OnHelp)
	ON_COMMAND(ID_CONTEXT_HELP, CFrameWnd::OnContextHelp)
	ON_COMMAND(ID_DEFAULT_HELP, CFrameWnd::OnHelpFinder)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	
//	ID_INDICATOR_NUM,
//	ID_INDICATOR_SCRL,
};

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
    CAMonitorApp *app = (CAMonitorApp *)AfxGetApp();
	m_EnglishChinese = 1;
//	m_bFullScreen=TRUE;
	m_bFullScreen = FALSE;
	m_bFullScreenable = FALSE;
//	OnFullscr();

}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

    if(m_EnglishChinese == 0)
	{	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_TOOLBAR1))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}
	}
    else
	{
    if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}	
	}		  
	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable

	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	// CG: The following block was inserted by 'Status Bar' component.
	{	
		// Create an array for status bar indicators


		int nOrigSize = sizeof(indicators) / sizeof(UINT);

		UINT* pIndicators = new UINT[nOrigSize + 2];
		memcpy(pIndicators, indicators, sizeof(indicators));
//		UINT pIndicators[3] = { ID_SEPARATOR,ID_INDICATOR_CAPS,ID_INDICATOR_NUM};
		if (!m_wndStatusBar.Create(this) ||
			!InitStatusBar(indicators, nOrigSize, 60))
		{
			TRACE0("Failed to create Status Bar\n");
			return -1;
		}
        CenterWindow( GetDesktopWindow() ); 
        m_wndStatusBar.CreateProgressCtrl(1);

        m_wndStatusBar.m_Progress.SetRange(0, 100);
	    m_wndStatusBar.m_Progress.SetStep(2);
        m_wndStatusBar.m_Progress.SetPos(5);

        SetTimer(1,300,NULL);
		SetTimer(2,50,NULL);
		// TODO: If you have a call to EnableDocking() and DockControlBar()
		// before this line, move them to right after this comment.  This
		// insures that the docking area remains above the status bar.
	}
 
	    // CG: The following line was added by the Splash Screen component.
//	    CSplashWnd::ShowSplashScreen(this);
	    return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
//	    if( !CFrameWnd::PreCreateWindow(cs) )
//		return FALSE;
	    // TODO: Modify the Window class or styles here by modifying
	    //  the CREATESTRUCT cs
//cs.cx = 300;
//cs.cy = 200;
	    cs.style = WS_OVERLAPPED | WS_CAPTION | FWS_ADDTOTITLE
		         | WS_THICKFRAME  /*| WS_SYSMENU| WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_MAXIMIZE*/;
//        cs.dwExStyle = WS_EX_TOPMOST;   //Always in top
		cs.style &= ~WS_SIZEBOX;
//		return CFrameWnd::PreCreateWindow(cs);
			    if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	    return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	    CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	    CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


void CMainFrame::OnUpdateDate(CCmdUI* pCmdUI)
{
	// CG: This function was inserted by 'Status Bar' component.

	// Get current date and format it
	CTime time = CTime::GetCurrentTime();
	CString strDate = time.Format(_T("%x"));

	// BLOCK: compute the width of the date string
	CSize size;
	{
		HGDIOBJ hOldFont = NULL;
		HFONT hFont = (HFONT)m_wndStatusBar.SendMessage(WM_GETFONT);
		CClientDC dc(NULL);
		if (hFont != NULL) 
			hOldFont = dc.SelectObject(hFont);
		size = dc.GetTextExtent(strDate);
		if (hOldFont != NULL) 
		dc.SelectObject(hOldFont);
	}

	    // Update the pane to reflect the current date
	    UINT nID, nStyle;
	    int nWidth;
	    m_wndStatusBar.GetPaneInfo(m_nDatePaneNo, nID, nStyle, nWidth);
	    m_wndStatusBar.SetPaneInfo(m_nDatePaneNo, nID, nStyle, size.cx);
	    pCmdUI->SetText(strDate);
	    pCmdUI->Enable(TRUE);
}

void CMainFrame::OnUpdateTime(CCmdUI* pCmdUI)
{
	    // CG: This function was inserted by 'Status Bar' component.

	    // Get current date and format it
	    CTime time = CTime::GetCurrentTime();
	    CString strTime = time.Format(_T("%X"));

	    // BLOCK: compute the width of the date string
	    CSize size;
		{
		HGDIOBJ hOldFont = NULL;
		HFONT hFont = (HFONT)m_wndStatusBar.SendMessage(WM_GETFONT);
		CClientDC dc(NULL);
		if (hFont != NULL) 
			hOldFont = dc.SelectObject(hFont);
		size = dc.GetTextExtent(strTime);
		if (hOldFont != NULL) 
			dc.SelectObject(hOldFont);
	}

	    // Update the pane to reflect the current time
	    UINT nID, nStyle;
	    int nWidth;
	    m_wndStatusBar.GetPaneInfo(m_nTimePaneNo, nID, nStyle, nWidth);
	    m_wndStatusBar.SetPaneInfo(m_nTimePaneNo, nID, nStyle, size.cx);
	    pCmdUI->SetText(strTime);
	    pCmdUI->Enable(TRUE);
}

BOOL CMainFrame::InitStatusBar(UINT *pIndicators, int nSize, int nSeconds)
{
	    // CG: This function was inserted by 'Status Bar' component.
	    // Create an index for the DATE pane
	    m_nDatePaneNo = nSize++;
	    pIndicators[m_nDatePaneNo] = ID_INDICATOR_DATE;
	    // Create an index for the TIME pane
	    m_nTimePaneNo = nSize++;
 	    nSeconds = 1;
	    pIndicators[m_nTimePaneNo] = ID_INDICATOR_TIME;

	    // TODO: Select an appropriate time interval for updating
	    // the status bar when idling.
	    m_wndStatusBar.SetTimer(0x1000, nSeconds * 1000, NULL);

	    return m_wndStatusBar.SetIndicators(pIndicators, nSize);
}


BEGIN_MESSAGE_MAP(CComplexStatusBar, CStatusBar)
ON_WM_SIZE()
END_MESSAGE_MAP()

      //参数nPane是窗格的索引，函数将在该窗格内创建进度条控件
BOOL CComplexStatusBar::CreateProgressCtrl(int nPane)
{
      if(m_Progress.GetSafeHwnd()) //防止重复创建
      return FALSE;

      //设置该窗格的宽度为200
      SetPaneInfo(nPane,GetItemID(nPane),SBPS_NORMAL,200);
      CRect rect(0,0,1,1);
      if(!m_Progress.Create(WS_CHILD|WS_VISIBLE|PBS_SMOOTH,rect,this,
      ID_INDICATOR_PROGRESS))
      return FALSE;
      m_nProgressPane=nPane;
      return TRUE;
}

void CComplexStatusBar::OnSize(UINT nType, int cx, int cy) 
{
      CStatusBar::OnSize(nType, cx, cy);
      if(m_Progress.GetSafeHwnd()==NULL) return;

      CRect rect;
      GetItemRect(m_nProgressPane,&rect);
      m_Progress.MoveWindow(rect); //调整控件的位置和尺寸
}

void CMainFrame::OnTimer(UINT nIDEvent) 
{
	  CAMonitorApp *app = (CAMonitorApp *)AfxGetApp();
      if(nIDEvent == 1)
	  {
//	  m_wndStatusBar.m_Progress.SetRange(1, 155*(app->m_ProgreesRange));

//	  if(app->m_Progrees == 1)
	  {m_wndStatusBar.m_Progress.StepIt();}	

//	  if(app->m_ProgreesReStart == 1)
//	  {m_wndStatusBar.m_Progress.SetPos(0);
//	  app->m_ProgreesReStart = 0;}
	  }
      if(nIDEvent == 2)
	  {
      OnFullscr();
	  KillTimer(2);
	  }    
	  CFrameWnd::OnTimer(nIDEvent);
}

void CMainFrame::OnMenuFullscreen()
{
//全屏幕显示的处理函数
    RECT rectDesktop;
    WINDOWPLACEMENT wpNew;
    if (m_bFullScreen)
    {//全屏幕显示模式
      //隐藏工具条和状态条
      m_wndStatusBar.ShowWindow(SW_HIDE);
      m_wndToolBar.ShowWindow(SW_HIDE);
      //保存正常视图时的窗口位置信息以便恢复原来状态
      GetWindowPlacement (&m_wpPrev);
      m_wpPrev.length = sizeof m_wpPrev;
      //调整RECT为新的窗口尺寸
      ::GetWindowRect (::GetDesktopWindow(), &rectDesktop );
	  rectDesktop.right = rectDesktop.right - 373;
      rectDesktop.bottom = rectDesktop.bottom - 316;
      ::AdjustWindowRectEx(&rectDesktop + (0,20), GetStyle(), TRUE, GetExStyle());
      //保存RECT以便OnGetMinMaxInfo()使用
      m_FullScreenWindowRect = rectDesktop;
      wpNew = m_wpPrev;
      wpNew.showCmd = SW_SHOWNORMAL;
      wpNew.rcNormalPosition = rectDesktop;
      //生成新的工具条
      m_wndFullScreenBar=new CToolBar;
      if(!m_wndFullScreenBar->Create(this, CBRS_SIZE_DYNAMIC|CBRS_FLOATING)|| 
      !m_wndFullScreenBar->LoadToolBar(IDR_FULLSCREEN))
      {
        TRACE0("Failed to create toolbar\n");
        return; // fail to create
      }
      //不允许工具条停泊
/*
      m_wndFullScreenBar->EnableDocking(FALSE);
      m_wndFullScreenBar->SetWindowPos(0,100,100,0,0,SWP_NOSIZE|SWP_NOZORDER|SWP_NOACTIVATE|SWP_SHOWWINDOW);
      m_wndFullScreenBar->SetWindowText(_T("全屏幕显示"));
      FloatControlBar(m_wndFullScreenBar, CPoint(100,100));
*/
      m_bFullScreen=TRUE;

    }
    else
    {//正常显示模式
      //删除全屏幕工具条
      m_wndFullScreenBar->DestroyWindow();
      delete m_wndFullScreenBar;
      m_bFullScreen=FALSE;
      //恢复工具条和状态条
      m_wndStatusBar.ShowWindow(SW_SHOWNORMAL);
      m_wndToolBar.ShowWindow(SW_SHOWNORMAL);
      wpNew = m_wpPrev;
    }
    //设置窗口显示状态
    SetWindowPlacement ( &wpNew );

}

void CMainFrame::OnGetMinMaxInfo(MINMAXINFO FAR* lpMMI)
{
/*    CRect rectWindow; 
    GetWindowRect(&rectWindow); 
  
    CRect rectClient; 
    GetClientRect(&rectClient); 
  
      // get offset of toolbars, scrollbars, etc. 
    int nWidthOffset = rectWindow.Width() - rectClient.Width(); 
    int nHeightOffset = rectWindow.Height() - rectClient.Height(); 
  
    lpMMI->ptMinTrackSize.x = 140 + nWidthOffset; 
    lpMMI->ptMinTrackSize.y = 130 + nHeightOffset; 
    lpMMI->ptMaxTrackSize.x = 230 + nWidthOffset; 
    lpMMI->ptMaxTrackSize.y = 235 + nHeightOffset; */

if (m_bFullScreen)
    {
      lpMMI->ptMaxSize.y = m_FullScreenWindowRect.Height();
      lpMMI->ptMaxTrackSize.y = lpMMI->ptMaxSize.y;
      lpMMI->ptMaxSize.x = m_FullScreenWindowRect.Width();
      lpMMI->ptMaxTrackSize.x = lpMMI->ptMaxSize.x;
    }
}

void CMainFrame::OnUpdateViewFullScreen(CCmdUI* pCmdUI)
{//更新菜单的状态
//    pCmdUI->Enable();
//    pCmdUI->SetCheck(m_bFullScreen);
}

void CMainFrame::OnFullscr() 
{
	m_bFullScreenable =!m_bFullScreenable;
	if(m_bFullScreenable == TRUE)
	{
    m_bFullScreen = TRUE ;
	}
	else
	{
    m_bFullScreen = FALSE ;
	}
    OnMenuFullscreen();	
}

void CMainFrame::OnButton32811() 
{
    m_bFullScreen = FALSE;
    OnMenuFullscreen();		
}

void CMainFrame::OnUpdateFullscr(CCmdUI* pCmdUI) 
{
//	pCmdUI->Enable();
//	pCmdUI->SetCheck(m_bFullScreen);
}

BOOL CMainFrame::OnQueryEndSession() 
{
	if (!CFrameWnd::OnQueryEndSession())
		return FALSE;
	
/*	if( lEndReason =3D=3D ENDSESSION_LOGOFF ) {}
        // user is logging off
    else
        // Windows is going down

    return( bCanExit );*/
	
	return TRUE;
}

void CMainFrame::OnEnglischinese() 
{
    m_EnglishChinese = 0;
}
