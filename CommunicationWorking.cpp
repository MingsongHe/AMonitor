// CommunicationWorking.cpp : implementation file
//

#include "stdafx.h"
#include "AMonitor.h"
#include "CommunicationWorking.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCommunicationWorking dialog


CCommunicationWorking::CCommunicationWorking(CWnd* pParent /*=NULL*/)
	: CDialog(CCommunicationWorking::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCommunicationWorking)
	//}}AFX_DATA_INIT
	m_pView = NULL;
}

CCommunicationWorking::CCommunicationWorking(CView* pView) // modeless constructor
{
	m_pView = pView;
}

BOOL CCommunicationWorking::Create()
{
	return CDialog::Create(CCommunicationWorking::IDD);
}

void CCommunicationWorking::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCommunicationWorking)
	DDX_Control(pDX, IDC_MSCOMM2, m_Comm2);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCommunicationWorking, CDialog)
	//{{AFX_MSG_MAP(CCommunicationWorking)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCommunicationWorking message handlers

BEGIN_EVENTSINK_MAP(CCommunicationWorking, CDialog)
    //{{AFX_EVENTSINK_MAP(CCommunicationWorking)
	ON_EVENT(CCommunicationWorking, IDC_MSCOMM2, 1 /* OnComm */, OnOnCommMscomm2, VTS_NONE)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()


void CCommunicationWorking::OnOK() 
{
	if (m_pView != NULL) {
		// modeless case -- do not call base class OnOK
		UpdateData(TRUE);
//		m_pView->PostMessage(WM_GOODBYE, IDOK);
        DestroyWindow();
	}
	else {
		CDialog::OnOK(); // modal case
	}
}	

void CCommunicationWorking::OnCancel() 
{
	if (m_pView != NULL) {
		// modeless case -- do not call base class OnCancel
//		m_pView->PostMessage(WM_GOODBYE, IDCANCEL);
        DestroyWindow();
	}
	else {
		CDialog::OnCancel(); // modal case
	} 	
}

void CCommunicationWorking::OnOnCommMscomm2() 
{
     if(m_Comm2.GetCommEvent()==2)
	 {
		  Input();
	 }	
}

void CCommunicationWorking::Input()
{
     VARIANT m_input1;
     COleVariant m_input2;
     CString str;

   if( !m_Comm2.GetPortOpen() )
     m_Comm2.SetPortOpen(TRUE);
     m_input1=m_Comm2.GetInput();
     m_input2=m_input1;
//	 ASSERT(m_input2.vt == VT_BSTR);
     str =m_input2.bstrVal;
//	 TRACE("%s\n", str);
     m_InputString += str;

	 	if (m_pView != NULL) {
		// modeless case -- do not call base class OnOK
		m_pView->PostMessage(WM_GOODBYE, IDOK);
//        DestroyWindow();
	}
}

BOOL CCommunicationWorking::OnInitDialog() 
{
	CDialog::OnInitDialog();

    PostMessage(WM_COMMAND, MAKEWPARAM(SW_MINIMIZE,0), 0); 	

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CCommunicationWorking::OnCommand(WPARAM wParam, LPARAM lParam) 
{
      if(SW_MINIMIZE)
      ShowWindow (SW_HIDE); 	
	  return CDialog::OnCommand(wParam, lParam);
}
