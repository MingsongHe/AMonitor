// AMonitorDoc.h : interface of the CAMonitorDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_AMONITORDOC_H__7A056911_EB8C_11D3_9E6C_0000B48DF20F__INCLUDED_)
#define AFX_AMONITORDOC_H__7A056911_EB8C_11D3_9E6C_0000B48DF20F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CAMonitorDoc : public CDocument
{
protected: // create from serialization only
	CAMonitorDoc();
	DECLARE_DYNCREATE(CAMonitorDoc)

  	CPtrArray *lines;

// Attributes
public:
	CPtrArray *GetLines()	{ return lines; }
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAMonitorDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CAMonitorDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CAMonitorDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AMONITORDOC_H__7A056911_EB8C_11D3_9E6C_0000B48DF20F__INCLUDED_)
