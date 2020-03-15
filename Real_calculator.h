// Real_calculator.h : main header file for the REAL_CALCULATOR application
//

#if !defined(AFX_REAL_CALCULATOR_H__F029261F_62BC_42CB_804B_DAE454DBC292__INCLUDED_)
#define AFX_REAL_CALCULATOR_H__F029261F_62BC_42CB_804B_DAE454DBC292__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CReal_calculatorApp:
// See Real_calculator.cpp for the implementation of this class
//

class CReal_calculatorApp : public CWinApp
{
public:
	CReal_calculatorApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReal_calculatorApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CReal_calculatorApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REAL_CALCULATOR_H__F029261F_62BC_42CB_804B_DAE454DBC292__INCLUDED_)
