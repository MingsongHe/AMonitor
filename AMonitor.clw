; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CCommunicationDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "AMonitor.h"
LastPage=0

ClassCount=8
Class1=CAMonitorApp
Class2=CAMonitorDoc
Class3=CAMonitorView
Class4=CMainFrame

ResourceCount=14
Resource1=IDD_FORMVIEW (English (U.S.))
Class5=CAboutDlg
Class6=CSplashWnd
Resource2=IDR_FULLSCREEN
Resource3=IDD_DIALOG2
Class7=CCommunicationDlg
Resource4=IDR_TOOLBAR1
Class8=CCommunicationWorking
Resource5=IDR_MAINFRAME
Resource6=IDD_DIALOG1 (English (U.S.))
Resource7=IDD_DIALOG1
Resource8=IDR_TOOLBAR1 (English (U.S.))
Resource9=IDR_FULLSCREEN (English (U.S.))
Resource10=IDD_ABOUTBOX
Resource11=IDD_ABOUTBOX (English (U.S.))
Resource12=IDD_DIALOG2 (English (U.S.))
Resource13=IDR_MAINFRAME (English (U.S.))
Resource14=IDD_FORMVIEW

[CLS:CAMonitorApp]
Type=0
HeaderFile=AMonitor.h
ImplementationFile=AMonitor.cpp
Filter=N
BaseClass=CWinApp
VirtualFilter=AC
LastObject=CAMonitorApp

[CLS:CAMonitorDoc]
Type=0
HeaderFile=AMonitorDoc.h
ImplementationFile=AMonitorDoc.cpp
Filter=N

[CLS:CAMonitorView]
Type=0
HeaderFile=AMonitorView.h
ImplementationFile=AMonitorView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=CAMonitorView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=IDC_RICHTEXTCTRL1
BaseClass=CFrameWnd
VirtualFilter=fWC




[CLS:CAboutDlg]
Type=0
HeaderFile=AMonitor.cpp
ImplementationFile=AMonitor.cpp
Filter=D
LastObject=IDOK
BaseClass=CDialog
VirtualFilter=dWC

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=3
Control1=IDC_STATIC,static,1342308480
Control2=IDC_STATIC,static,1342308352
Control3=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
CommandCount=0

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_OPENAEDIT
Command2=ID_EXEC
Command3=ID_RESTART
Command4=ID_STOP
Command5=ID_MONIT
Command6=ID_BUTTON32786
Command7=ID_TOOLBAR3
Command8=ID_TOOLBAR4
Command9=ID_DATA
Command10=ID_AVAH
Command11=ID_TIMED
Command12=ID_SETT1
Command13=ID_SETT2
Command14=ID_ENGLISCHINESE
Command15=ID_FULLSCR
Command16=ID_HELPFILE
CommandCount=16

[TB:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_MONIT
Command2=ID_DATA
Command3=ID_AVAH
Command4=ID_TIMED
Command5=ID_SETT1
Command6=ID_SETT2
Command7=ID_FULLSCR
Command8=ID_HELPFILE
Command9=ID_BUTTON32786
CommandCount=9

[CLS:CSplashWnd]
Type=0
HeaderFile=Splash.h
ImplementationFile=Splash.cpp
BaseClass=CWnd

[TB:IDR_TOOLBAR1]
Type=1
Class=?
Command1=ID_MONIT
Command2=ID_DATA
Command3=ID_AVAH
Command4=ID_TIMED
Command5=ID_SETT1
Command6=ID_SETT2
Command7=ID_ENGLISCHINESE
Command8=ID_HELPFILE
Command9=ID_BUTTON32786
CommandCount=9

[DLG:IDD_DIALOG1]
Type=1
Class=CCommunicationDlg
ControlCount=9
Control1=IDC_BUTTON3,button,1342242816
Control2=IDC_RICHTEXTCTRL2,{3B7C8860-D78F-101B-B9B5-04021C009402},1342242816
Control3=IDC_BUTTON1,button,1342242817
Control4=IDC_BUTTON2,button,1342242816
Control5=IDC_RICHTEXTCTRL1,{3B7C8860-D78F-101B-B9B5-04021C009402},1342242816
Control6=IDC_BUTTON4,button,1342242816
Control7=IDCANCEL,button,1073807360
Control8=IDOK,button,1342242817
Control9=IDC_MSCOMM1,{648A5600-2C6E-101B-82B6-000000000014},1342242816

[CLS:CCommunicationDlg]
Type=0
HeaderFile=CommunicationDlg.h
ImplementationFile=CommunicationDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CCommunicationDlg

[DLG:IDD_DIALOG2]
Type=1
Class=CCommunicationWorking
ControlCount=4
Control1=IDC_MSCOMM2,{648A5600-2C6E-101B-82B6-000000000014},1342242816
Control2=IDC_STATIC,static,1342177283
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,button,1342177287

[CLS:CCommunicationWorking]
Type=0
HeaderFile=CommunicationWorking.h
ImplementationFile=CommunicationWorking.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CCommunicationWorking

[TB:IDR_FULLSCREEN]
Type=1
Class=CMainFrame
Command1=ID_BUTTON32811
CommandCount=1

[DLG:IDD_FORMVIEW]
Type=1
Class=?
ControlCount=0

[TB:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_MONIT
Command2=ID_DATA
Command3=ID_AVAH
Command4=ID_TIMED
Command5=ID_SETT1
Command6=ID_SETT2
Command7=ID_FULLSCR
Command8=ID_HELPFILE
Command9=ID_BUTTON32786
CommandCount=9

[TB:IDR_TOOLBAR1 (English (U.S.))]
Type=1
Class=?
Command1=ID_MONIT
Command2=ID_DATA
Command3=ID_AVAH
Command4=ID_TIMED
Command5=ID_SETT1
Command6=ID_SETT2
Command7=ID_ENGLISCHINESE
Command8=ID_HELPFILE
Command9=ID_BUTTON32786
CommandCount=9

[TB:IDR_FULLSCREEN (English (U.S.))]
Type=1
Class=?
Command1=ID_BUTTON32811
CommandCount=1

[MNU:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
CommandCount=0

[ACL:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_OPENAEDIT
Command2=ID_EXEC
Command3=ID_RESTART
Command4=ID_STOP
Command5=ID_MONIT
Command6=ID_BUTTON32786
Command7=ID_TOOLBAR3
Command8=ID_TOOLBAR4
Command9=ID_DATA
Command10=ID_AVAH
Command11=ID_TIMED
Command12=ID_SETT1
Command13=ID_SETT2
Command14=ID_ENGLISCHINESE
Command15=ID_FULLSCR
Command16=ID_HELPFILE
CommandCount=16

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=CAboutDlg
ControlCount=3
Control1=IDC_STATIC,static,1342308480
Control2=IDC_STATIC,static,1342308352
Control3=IDOK,button,1342373889

[DLG:IDD_DIALOG1 (English (U.S.))]
Type=1
Class=CCommunicationDlg
ControlCount=9
Control1=IDC_BUTTON1,button,1342242817
Control2=IDC_BUTTON2,button,1342242816
Control3=IDOK,button,1342242817
Control4=IDCANCEL,button,1342242816
Control5=IDC_EDIT1,edit,1352732740
Control6=IDC_EDIT2,edit,1352733892
Control7=IDC_STATIC,static,1342308864
Control8=IDC_STATIC,static,1342308864
Control9=IDC_MSCOMM1,{648A5600-2C6E-101B-82B6-000000000014},1342242816

[DLG:IDD_DIALOG2 (English (U.S.))]
Type=1
Class=CCommunicationWorking
ControlCount=4
Control1=IDC_MSCOMM2,{648A5600-2C6E-101B-82B6-000000000014},1342177280
Control2=IDC_STATIC,static,1342177283
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,button,1342177287

[DLG:IDD_FORMVIEW (English (U.S.))]
Type=1
Class=?
ControlCount=0

