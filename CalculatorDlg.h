// CalculatorDlg.h : header file
//

#if !defined(AFX_CALCULATORDLG_H__39C55E6E_FCB6_4DD7_A2F6_E83A321B71F9__INCLUDED_)
#define AFX_CALCULATORDLG_H__39C55E6E_FCB6_4DD7_A2F6_E83A321B71F9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCalculatorDlg dialog

class CCalculatorDlg : public CDialog
{
// Construction
public:
	CCalculatorDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCalculatorDlg)
	enum { IDD = IDD_CALCULATOR_DIALOG };
	double	m_editSummand;
	double	m_editAddend;
	double	m_editSum;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCalculatorDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCalculatorDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAddButton();
	afx_msg void OnOut();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CALCULATORDLG_H__39C55E6E_FCB6_4DD7_A2F6_E83A321B71F9__INCLUDED_)
