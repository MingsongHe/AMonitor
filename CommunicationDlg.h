//{{AFX_INCLUDES()
#include "mscomm.h"
#include "richtext.h"
//}}AFX_INCLUDES
#if !defined(AFX_COMMUNICATIONDLG_H__FED4BA81_E3AC_11D2_9E6E_0000B48DF20F__INCLUDED_)
#define AFX_COMMUNICATIONDLG_H__FED4BA81_E3AC_11D2_9E6E_0000B48DF20F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CommunicationDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCommunicationDlg dialog

class CCommunicationDlg : public CDialog
{
// Construction
public:
	CCommunicationDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCommunicationDlg)
	enum { IDD = IDD_DIALOG1 };
	CButton	m_Send;
	CMSComm	m_Comm;
	CString	m_InputString;
	CString m_OutputString;
	CRichText	m_InputRichText;
	CRichText	m_OutputRichText;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCommunicationDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCommunicationDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnOnCommMscomm1();
	afx_msg void OnButton1();
	afx_msg void OnInPut();
	afx_msg void OnOpenOutputFile();
	afx_msg void OnInputSaveAs();
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMMUNICATIONDLG_H__FED4BA81_E3AC_11D2_9E6E_0000B48DF20F__INCLUDED_)
