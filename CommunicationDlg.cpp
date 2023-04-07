// CommunicationDlg.cpp : implementation file
//

#include "stdafx.h"
#include "AMonitor.h"
#include "CommunicationDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCommunicationDlg dialog


CCommunicationDlg::CCommunicationDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCommunicationDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCommunicationDlg)
	m_InputString = _T("");
	//}}AFX_DATA_INIT
}


void CCommunicationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCommunicationDlg)
	DDX_Control(pDX, IDC_BUTTON1, m_Send);
	DDX_Control(pDX, IDC_MSCOMM1, m_Comm);
	DDX_Control(pDX, IDC_RICHTEXTCTRL1, m_InputRichText);
	DDX_Control(pDX, IDC_RICHTEXTCTRL2, m_OutputRichText);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCommunicationDlg, CDialog)
	//{{AFX_MSG_MAP(CCommunicationDlg)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnInPut)
	ON_BN_CLICKED(IDC_BUTTON3, OnOpenOutputFile)
	ON_BN_CLICKED(IDC_BUTTON4, OnInputSaveAs)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCommunicationDlg message handlers

BOOL CCommunicationDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	CRect rect(247,18,30,13);
//    m_Send.Create("OUT",WS_DISABLED,rect,this,IDC_BUTTON1);
    UpdateData(false);	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CCommunicationDlg::OnOK() 
{
	        CDialog::OnOK();
			
}

BEGIN_EVENTSINK_MAP(CCommunicationDlg, CDialog)
    //{{AFX_EVENTSINK_MAP(CCommunicationDlg)
	ON_EVENT(CCommunicationDlg, IDC_MSCOMM1, 1 /* OnComm */, OnOnCommMscomm1, VTS_NONE)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

void CCommunicationDlg::OnOnCommMscomm1() 
{
     if(m_Comm.GetCommEvent()==2)
	 {
		  OnInPut();
	 }
     //OnButton1();

/*   VARIANT m_input1;
     COleVariant m_input2;
     LONG length,i;
     BYTE data[1024];
     CString str;
     if(m_Comm.GetCommEvent()==2)//½ÓÊÕ»º³åÇøÄÚÓÐ×Ö·û
	 {
     m_input1=m_Comm.Getinput();//¶ÁÈ¡»º³åÇøÄÚµÄÊý¾Ý
     m_input2=m_input1;//½«VARIANTÐÍ±äÁ¿×ª»»ÎªColeSafeArrayÐÍ±äÁ¿
     length=m_input2.GetOneDimSize();//È·¶¨Êý¾Ý³¤¶È
     for(i=0;i<length;++)
     m_input2.GetElement(&i,data+i);//½«Êý¾Ý×ª»»ÎªBYTEÐÍÊý×é
     for(i=0;i<length;i++)//½«Êý×é×ª»»ÎªCstringÐÍ±äÁ¿
      {
     char a=* (char *)(data+i);
     str.Format("%c"±,a);
     m_ReceiveData+=str;
      }
	 }

     UpdateData(FALSE);*/
}

void CCommunicationDlg::OnButton1()      //SEND OUT
{
    if( !m_Comm.GetPortOpen() )
    m_Comm.SetPortOpen(TRUE);
    UpdateData(TRUE);
    m_Comm.SetOutput(COleVariant(m_OutputString));
}

void CCommunicationDlg::OnInPut() 
{
     VARIANT m_input1;
     COleVariant m_input2;
     CString str;

   if( !m_Comm.GetPortOpen() )
     m_Comm.SetPortOpen(TRUE);

     m_input1=m_Comm.GetInput();
     m_input2=m_input1;
     str =m_input2.bstrVal;
     m_InputString += str; 
	 m_InputRichText.SetWindowText(m_InputString);
     UpdateData(FALSE);	
}

void CCommunicationDlg::OnOpenOutputFile() 
{
	BYTE buf;
	CString s;

	HICON hIcon=AfxGetApp() ->LoadIcon(IDI_ICON1);

	CFileDialog dlgFile(TRUE, "*.dat", "*.dat",0,"*.dat",NULL);

	int nModal = dlgFile.DoModal();

	if (nModal == IDOK) 
	{
        m_OutputString.Empty();
		CFile file(dlgFile.GetPathName(),CFile::modeRead);
		CArchive ar(&file,CArchive::load);
		AfxGetApp()->BeginWaitCursor();
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
			m_OutputString += buf;
		}
		m_OutputRichText.SetWindowText(m_OutputString);
        UpdateData(FALSE);
		AfxGetApp()->EndWaitCursor();

		if(!m_OutputString.IsEmpty())
		{
//			m_Send.SetState(1);
		}
	}
}

void CCommunicationDlg::OnInputSaveAs() 
{
		BYTE buf;

//	    CFileDialog dlgFile(false, "*.dat", "*.dat",0,"*.dat",NULL);
        CFileDialog dlgFile(FALSE ,"dat",NULL,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		"*.dat|*.dat|*.txt|*.txt|*.nc|*.nc|*.ddy|*.ddy|*.*|*.*|",NULL);
	    int nModal = dlgFile.DoModal();

	    if (nModal == IDOK) 
		{
		m_InputRichText.GetWindowText(m_InputString);

		CFile file(dlgFile.GetPathName(),CFile::modeCreate | CFile::modeWrite);
		CArchive ar(&file,CArchive::store);

			AfxGetApp()->BeginWaitCursor();

	       for (int j = 0; j < m_InputString.GetLength(); j++)
			{
					buf = m_InputString.GetAt(j);
                    ar << buf;
				}
	}
         AfxGetApp()->EndWaitCursor();
}
