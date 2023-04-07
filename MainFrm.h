// MainFrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINFRM_H__7A05690F_EB8C_11D3_9E6C_0000B48DF20F__INCLUDED_)
#define AFX_MAINFRM_H__7A05690F_EB8C_11D3_9E6C_0000B48DF20F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define ID_INDICATOR_PROGRESS 100
      class CComplexStatusBar : public CStatusBar
      {
      public:
      CProgressCtrl m_Progress;
      int m_nProgressPane;
      BOOL CreateProgressCtrl(int nPane);

      afx_msg void OnSize(UINT nType, int cx, int cy);
      DECLARE_MESSAGE_MAP()
      };

class CMainFrame : public CFrameWnd
{
	
protected: // create from serialization only
	 CMainFrame();
	 DECLARE_DYNCREATE(CMainFrame)

// Attributes
public:
	
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainFrame)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	CToolBar * m_wndFullScreenBar;
	WINDOWPLACEMENT m_wpPrev;
	CRect m_FullScreenWindowRect;
	BOOL m_bFullScreen;
	BOOL m_bFullScreenable;
	BOOL    m_EnglishChinese;
	int m_nDatePaneNo;
	int m_nTimePaneNo;
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CToolBar    m_wndToolBar;

// Generated message map functions
protected:
	CComplexStatusBar  m_wndStatusBar;
	afx_msg void OnUpdateDate(CCmdUI* pCmdUI);
	afx_msg void OnUpdateTime(CCmdUI* pCmdUI);
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnFullscr();
	afx_msg void OnButton32811();
	afx_msg void OnUpdateFullscr(CCmdUI* pCmdUI);
	afx_msg BOOL OnQueryEndSession();
	afx_msg void OnEnglischinese();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void OnUpdateViewFullScreen(CCmdUI* pCmdUI);
	void OnGetMinMaxInfo(MINMAXINFO FAR* lpMMI);
	void OnMenuFullscreen();
	BOOL InitStatusBar(UINT *pIndicators, int nSize, int nSeconds);
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINFRM_H__7A05690F_EB8C_11D3_9E6C_0000B48DF20F__INCLUDED_)
