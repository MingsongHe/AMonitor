// AMonitor.h : main header file for the AMONITOR application
//

#if !defined(AFX_AMONITOR_H__7A05690B_EB8C_11D3_9E6C_0000B48DF20F__INCLUDED_)
#define AFX_AMONITOR_H__7A05690B_EB8C_11D3_9E6C_0000B48DF20F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols
//#include "Stdafx.h"
/////////////////////////////////////////////////////////////////////////////
// CAMonitorApp:
// See AMonitor.cpp for the implementation of this class
//

class CAMonitorApp : public CWinApp
{
public:

	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CAMonitorApp();
	BOOL    m_EnglishChinese,m_ProgreesReStart;
	int m_Progrees;
	int m_ProgreesRange;
	
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAMonitorApp)
	public:
	virtual BOOL InitInstance();
	virtual BOOL OnIdle(LONG lCount);
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CAMonitorApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
//	CCriticalSection m_Sellecting;
};
    

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AMONITOR_H__7A05690B_EB8C_11D3_9E6C_0000B48DF20F__INCLUDED_)
