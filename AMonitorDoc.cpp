// AMonitorDoc.cpp : implementation of the CAMonitorDoc class
//

#include "stdafx.h"
#include "AMonitor.h"

#include "AMonitorDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAMonitorDoc

IMPLEMENT_DYNCREATE(CAMonitorDoc, CDocument)

BEGIN_MESSAGE_MAP(CAMonitorDoc, CDocument)
	//{{AFX_MSG_MAP(CAMonitorDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAMonitorDoc construction/destruction

CAMonitorDoc::CAMonitorDoc()
{
	lines = NULL;
	try {
		lines = new CPtrArray();
	}
	catch (CMemoryException *e)
	{
		AfxMessageBox("Can't allocate memory for reading file contents");
		TRACE0("Unable to allocate memory for file contents\n");
		e->Delete();
	}

	TRACE0("Allocated lines array\n");

	EnableAutomation();

	AfxOleLockApp();
}

CAMonitorDoc::~CAMonitorDoc()
{
	AfxOleUnlockApp();

	int i = 0;
	if (lines != NULL)
	{
		while (i < lines->GetSize())
		delete (CString *) lines->GetAt(i++);
		lines->RemoveAll();
		delete lines;
		lines = NULL;
	}
	TRACE0("Deleted lines array\n");
}

BOOL CAMonitorDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	if (lines != NULL)
	{
		int i = 0;
		while (i < lines->GetSize())
			delete (CString *) lines->GetAt(i++);
		lines->RemoveAll();
	}

	return TRUE;
	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CAMonitorDoc serialization

void CAMonitorDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CAMonitorDoc diagnostics

#ifdef _DEBUG
void CAMonitorDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CAMonitorDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CAMonitorDoc commands
