; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CTipDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Calculator.h"

ClassCount=3
Class1=CCalculatorApp
Class2=CCalculatorDlg

ResourceCount=3
Resource2=IDD_CALCULATOR_DIALOG
Resource1=IDR_MAINFRAME
Class3=CTipDlg
Resource3=IDD_TIP_DIALOG

[CLS:CCalculatorApp]
Type=0
HeaderFile=Calculator.h
ImplementationFile=Calculator.cpp
Filter=N

[CLS:CCalculatorDlg]
Type=0
HeaderFile=CalculatorDlg.h
ImplementationFile=CalculatorDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_ADD_BUTTON



[DLG:IDD_CALCULATOR_DIALOG]
Type=1
Class=CCalculatorDlg
ControlCount=8
Control1=IDC_SUMMAND_STATIC,static,1342308865
Control2=IDC_SUMMAND_EDIT,edit,1350631552
Control3=IDC_ADDEND_STATIC,static,1342308352
Control4=IDC_ADDEND_EDIT,edit,1350631552
Control5=IDC_SUM_STATIC,static,1342308352
Control6=IDC_SUM_EDIT,edit,1350631552
Control7=IDC_ADD_BUTTON,button,1342242816
Control8=IDC_BUTTON3,button,1342242816

[DLG:IDD_TIP_DIALOG]
Type=1
Class=CTipDlg
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352

[CLS:CTipDlg]
Type=0
HeaderFile=TipDlg.h
ImplementationFile=TipDlg.cpp
BaseClass=CDialog
Filter=D

