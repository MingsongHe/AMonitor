//{{AFX_INCLUDES()
#include "mscomm.h"
//}}AFX_INCLUDES
#if !defined(AFX_COMMUNICATIONWORKING_H__11A6BD81_E609_11D2_9E6E_0000B48DF20F__INCLUDED_)
#define AFX_COMMUNICATIONWORKING_H__11A6BD81_E609_11D2_9E6E_0000B48DF20F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CommunicationWorking.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCommunicationWorking dialog
#define WM_GOODBYE WM_USER + 116  //skip over the first five message

class CCommunicationWorking : public CDialog
{
// Construction
private:
	CView* m_pView;
public:
	CCommunicationWorking(CView* pView);//Using the CView class 
	                              //rather than the CddyV2View
	BOOL Create();                //allow the dialog class to
	                              //be used with any view class

public:
	void Input();
	CCommunicationWorking(CWnd* pParent = NULL);   // standard constructor
CString m_InputString,m_OutputString;
// Dialog Data
	//{{AFX_DATA(CCommunicationWorking)
	enum { IDD = IDD_DIALOG2 };
	CMSComm	m_Comm2;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCommunicationWorking)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCommunicationWorking)
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnOnCommMscomm2();
	virtual BOOL OnInitDialog();
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMMUNICATIONWORKING_H__11A6BD81_E609_11D2_9E6E_0000B48DF20F__INCLUDED_)
