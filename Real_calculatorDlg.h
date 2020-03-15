// Real_calculatorDlg.h : header file
//

#if !defined(AFX_REAL_CALCULATORDLG_H__C04AA5AA_22ED_4668_8B84_96D4FA09F39F__INCLUDED_)
#define AFX_REAL_CALCULATORDLG_H__C04AA5AA_22ED_4668_8B84_96D4FA09F39F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CReal_calculatorDlg dialog

class CReal_calculatorDlg : public CDialog
{
// Construction
public:
	CReal_calculatorDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CReal_calculatorDlg)
	enum { IDD = IDD_REAL_CALCULATOR_DIALOG };
	CEdit	m_OutFont;
	CEdit	m_Font;
	CString	m_num;
	CString	m_out;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReal_calculatorDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL
	CFont my_Font;

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CReal_calculatorDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnNum1();
	afx_msg void OnNum2();
	afx_msg void OnNum3();
	afx_msg void OnNum4();
	afx_msg void OnNum5();
	afx_msg void OnNum6();
	afx_msg void OnNum7();
	afx_msg void OnNum8();
	afx_msg void OnNum9();
	afx_msg void OnNum0();
	afx_msg void OnAdd();
	afx_msg void OnSub();
	afx_msg void OnMul();
	afx_msg void OnDiv();
	afx_msg void OnLeft();
	afx_msg void OnRight();
	afx_msg void OnFloat();
	afx_msg void OnEnd();
	afx_msg void OnDelete();
	afx_msg void OnDelall();
	afx_msg void OnChanel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REAL_CALCULATORDLG_H__C04AA5AA_22ED_4668_8B84_96D4FA09F39F__INCLUDED_)
